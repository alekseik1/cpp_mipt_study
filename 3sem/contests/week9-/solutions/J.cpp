//
// Created by aleksei on 02.11.17.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*!
	\brief Класс графа
	Данный класс имеет только одну простую цель: проиллюстрировать то,
	как Doxygen документирует наследование
*/
template<typename T>
// TODO: Было бы неплохо результаты Дейкстры куда-нибудь записывать, ибо я уже написал много функций, которые ими пользуются
class Graph {
private:

    bool _is_orientated;
    /// Вершины графа. Произвольный тип
    std::vector<T> _nodes;
    /// Словарь вида {вершина : вектор_из( пара(куда, стоимость) )}
    std::map<T, std::vector<std::pair<T, int>>> _paths_from;
    // Пара - это кортеж
    /// Та же матрица смежности, но для орграфа (я буду заполнять обе)
    std::map<T, std::vector<std::pair<T, int>>> _orient_paths_from;

    std::vector<std::pair<T, int>> _empty_pair_array() {
        return std::vector<std::pair<T, int>>();
    };

    bool _contains(const std::vector<T> &v, const T &value) {
        return std::find(v.begin(), v.end(), value) != v.end();
    }

    int _indexof(const std::vector<T> &v, const T &value) {
        return std::find(v.begin(), v.end(), value) - v.begin();
    }

    std::vector<T> _recoverPath(const int finish, const int start, const std::vector<int> &parents){
        std::vector<T> path;
        for (int v=finish; v!=start; v=parents[v])
            path.push_back(_nodes[v]);
        path.push_back(_nodes[start]);
        std::reverse (path.begin(), path.end());
        return path;
    }

public:

    explicit Graph(bool is_or = false) {
        _is_orientated = is_or;
    }

    /*!
     * Геттер ориентированности
     * @return Возвращает true, если граф является ориентированным
     */
    bool is_orientated() {
        return _is_orientated;
    }

    /*!
     @brief Делает ребро между двумя вершинами с заданным весом.
     @warning Заметьте, что связь делается и в том случае, если вершины уже связаны ребром.
     @param source Вершина, из которой исходит ребро.
     @param destination Вершина, куда идет ребро.
     @param weight Вес ребра.
     */
    void make_connection(const T &source, const T &destination, int weight) {
        if (!_is_orientated) {
            _paths_from[source].push_back(
                    std::pair<T, int>(destination, weight)  // Добавляем дорогу туда
            );
            _paths_from[destination].push_back(
                    std::pair<T, int>(source, weight)       // И обратно
            );
        } else {
            _orient_paths_from[source].push_back(
                    std::pair<T, int>(destination, weight)  // Для орграфа создаем путь только в одну сторону
            );
        }
    }

    /*!
     * @brief Добавляет вершину в граф.
     * Можно передавать списки связей, а можно этого не делать.
     * @param _Node Объект вершины
     * @param edges Вектор из пар (вершина_назначения, вес_пути).
     * @return Возвращает true, если непустая вершина была добавлена, false в противном случае (если что-то пошло не так)
     */
    bool add_node(const T &_Node, const std::vector<std::pair<T, int>> &edges) // По-умолчанию передаем пустой вектор
    {
        _nodes.push_back(_Node);
        for (std::pair<T, int> pair : edges) // Для каждой пары
        {
            make_connection(_Node, pair.first, pair.second);    // Создаем путь
        }
        return true;
    }

    /*!
    * @brief Добавляет вершину в граф.
    * Можно передавать списки связей, а можно этого не делать.
    * @param _Node Объект вершины
    * @return Возвращает true, если непустая вершина была добавлена, false в противном случае (если что-то пошло не так)
    */
    bool add_node(const T &_Node) {
        return add_node(_Node, _empty_pair_array());
    }

    /*!
     * Получает массив вершин, куда можно придти из указанной вершины
     * @param source Вершина, из который искать ребра
     * @return Вектор из пар[pair] (вершина, вес)
     */
    std::vector<std::pair<T, int>> get_nodes_from(const T &source) {
        if (!_is_orientated) {
            if (_paths_from.find(source) != _paths_from.end())
                return _paths_from[source];
            else
                return _empty_pair_array();
        } else {
            if (_orient_paths_from.find(source) != _orient_paths_from.end())
                return _orient_paths_from[source];
            else
                return _empty_pair_array();
        }
    }

    /*!
    * Получает массив вершин, откуда можно придти в указанную вершину
    * @param source Вершина, в которую искать ребра
    * @return Вектор из пар[pair] (вершина, вес)
    */
    std::vector<std::pair<T, int>> get_nodes_to(const T &destination) {
        std::vector<std::pair<T, int>> result;
        if (!_is_orientated) {
            for (T &Node : _nodes) {     // Для каждой из нод
                for (std::pair<T, int> &pair : _paths_from[Node]) {   // Для всех пар этой ноды
                    if (pair.first == destination) {  // Если пара ведет в destination
                        result.push_back(std::pair<T, int>(Node, pair.second));
                    }
                }
            }
        } else {
            for (T &Node : _nodes) {     // Для всех нод
                for (std::pair<T, int> &vec : _orient_paths_from[Node]) {
                    if (vec.first == destination) {
                        result.push_back(std::pair<T, int>(Node, vec.second));
                    }
                }
            }
        }
        return result;
    }

    /*!
     * @brief Дейкстра без восстановления пути. Веса кратчайших путей до всех вершин от начальной вершины
     * @param source Вершина, с которой начинать
     * @return Возвращает map<T, int> - словарь вида (вершина1, стоимость)
     */
    std::map<T, int> get_shortest_weights_from(const T &source) {
        std::sort(_nodes.begin(), _nodes.end());    // Костыльная сортировка
        if (!_is_orientated) {
            int s = _indexof(_nodes, source);
            const int INF = 1000000000;
            unsigned long n = _nodes.size();
            std::vector<int> d(n, INF), p(n);
            d[s] = 0;
            std::vector<char> u(n);        // Тут должен быть вектор из bool, но вектор из char работает быстрее. WTF??
            for (unsigned i = 0; i < n; ++i) {
                int v = -1;
                for (unsigned j = 0; j < n; ++j)
                    if (!u[j] && (v == -1 || d[j] < d[v]))
                        v = j;
                if (d[v] == INF)
                    break;
                u[v] = true;

                for (size_t j = 0; j < _paths_from[_nodes[v]].size(); ++j) {
                    T to1 = (_paths_from[_nodes[v]])[j].first;
                    int to = _indexof(_nodes, to1);
                    int len = (_paths_from[_nodes[v]])[j].second;
                    if (d[v] + len < d[to]) {
                        d[to] = d[v] + len;
                        p[to] = v;
                    }
                }
            }
            std::map<T, int> result;
            for (unsigned i = 0; i < d.size(); i++) {
                result[_nodes[i]] = d[i];
            }
            return result;
        } else {
            int s = _indexof(_nodes, source);
            const int INF = 1000000000;
            unsigned long n = _nodes.size();
            std::vector<int> d(n, INF), p(n);
            d[s] = 0;
            std::vector<char> u(n);        // Тут должен быть вектор из bool, но вектор из char работает быстрее. WTF??
            for (unsigned i = 0; i < n; ++i) {
                int v = -1;
                for (unsigned j = 0; j < n; ++j)
                    if (!u[j] && (v == -1 || d[j] < d[v]))
                        v = j;
                if (d[v] == INF)
                    break;
                u[v] = true;

                for (size_t j = 0; j < _orient_paths_from[_nodes[v]].size(); ++j) {
                    T to1 = (_orient_paths_from[_nodes[v]])[j].first;
                    int to = _indexof(_nodes, to1);
                    int len = (_orient_paths_from[_nodes[v]])[j].second;
                    if (d[v] + len < d[to]) {
                        d[to] = d[v] + len;
                        p[to] = v;
                    }
                }
            }
            std::map<T, int> result;
            for (unsigned i = 0; i < d.size(); i++) {
                result[_nodes[i]] = d[i];
            }
            return result;
        }
    }

    /*!
     * Считает вес пути между ребрами, описанными в path.
     * @param path Вектор с вершинами, через которые проходит путь
     * @return Возвращает суммарный вес пути, либо -1, если заданный путь имеет разрывы
     */
    int get_path_weight(std::vector<T> path) {
        // TODO: Реализуй меня
    }

    /*!
     * @brief Дейкстра с восстановлением пути. Пути и суммарные их веса до всех вершин от начальной вершины
     * @param source Вершина, с которой начинать
     * @param destination Вершина, куда придти
     * @return Возвращает vector<T> - пары вида (вектор_пути, суммарный вес) )
     */
    std::vector<T> get_shortest_paths_between(const T &source, const T &destination) {
        std::sort(_nodes.begin(), _nodes.end());    // Костыльная сортировка
        if (!_is_orientated) {
            int s = _indexof(_nodes, source);
            const int INF = 1000000000;
            unsigned long n = _nodes.size();
            std::vector<int> d(n, INF), p(n);
            d[s] = 0;
            std::vector<char> u(n);        // Тут должен быть вектор из bool, но вектор из char работает быстрее. WTF??
            for (unsigned i = 0; i < n; ++i) {
                int v = -1;
                for (unsigned j = 0; j < n; ++j)
                    if (!u[j] && (v == -1 || d[j] < d[v]))
                        v = j;
                if (d[v] == INF)
                    break;
                u[v] = true;

                for (size_t j = 0; j < _paths_from[_nodes[v]].size(); ++j) {
                    T to1 = (_paths_from[_nodes[v]])[j].first;
                    int to = _indexof(_nodes, to1);
                    int len = (_paths_from[_nodes[v]])[j].second;
                    if (d[v] + len < d[to]) {
                        d[to] = d[v] + len;
                        p[to] = v;
                    }
                }
            }
            std::map<T, int> result;
            for (unsigned i = 0; i < d.size(); i++) {
                result[_nodes[i]] = d[i];
            }

            int sourse_ind = _indexof(_nodes, source);
            int dest_ind = _indexof(_nodes, destination);
            return _recoverPath(dest_ind, sourse_ind, p);
        } else {
            int s = _indexof(_nodes, source);
            const int INF = 1000000000;
            unsigned long n = _nodes.size();
            std::vector<int> d(n, INF), p(n);
            d[s] = 0;
            std::vector<char> u(n);        // Тут должен быть вектор из bool, но вектор из char работает быстрее. WTF??
            for (unsigned i = 0; i < n; ++i) {
                int v = -1;
                for (unsigned j = 0; j < n; ++j)
                    if (!u[j] && (v == -1 || d[j] < d[v]))
                        v = j;
                if (d[v] == INF)
                    break;
                u[v] = true;

                for (size_t j = 0; j < _orient_paths_from[_nodes[v]].size(); ++j) {
                    T to1 = (_orient_paths_from[_nodes[v]])[j].first;
                    int to = _indexof(_nodes, to1);
                    int len = (_orient_paths_from[_nodes[v]])[j].second;
                    if (d[v] + len < d[to]) {
                        d[to] = d[v] + len;
                        p[to] = v;
                    }
                }
            }
            std::map<T, int> result;
            for (unsigned i = 0; i < d.size(); i++) {
                result[_nodes[i]] = d[i];
            }

            int sourse_ind = _indexof(_nodes, source);
            int dest_ind = _indexof(_nodes, destination);
            return _recoverPath(dest_ind, sourse_ind, p);
        }
    }
};

int main()
{
    Graph<std::pair<int, std::string>> g = Graph<std::pair<int, std::string>>();

    std::pair<int, std::string> s1 = std::pair<int, std::string>(0, "Aleksei");
    std::pair<int, std::string> s2 = std::pair<int, std::string>(1, "Vova");
    std::pair<int, std::string> s3 = std::pair<int, std::string>(2, "Gosha");

    g.add_node(s1);
    g.add_node(s2);
    g.add_node(s3);
    g.make_connection(s1, s2, 5);
    g.make_connection(s1, s3, 2);
    std::cout << "Getting nodes from 1:\n";
    for(auto& x : g.get_nodes_from(s1))
        std::cout << "Path to " << x.first.second << " with number " << x.first.first << " with weight " << x.second << "\n";
    std::cout << "=====\n";
    std::cout << "Getting nodes to 1:\n";
    for(auto& x : g.get_nodes_to(s1))
        std::cout << "Path from " << x.first.second << " with number " << x.first.first << " with weight " << x.second << "\n";
    for(auto& x: g.get_shortest_weights_from(s1))
        std::cout << "Shortest path to " << x.first.second << " with number " << x.first.first << " with weight " << x.second << "\n";
    for(auto& x: g.get_shortest_paths_between(s1, s2))
        std::cout << "GOTO " << x.second << " ";
}
