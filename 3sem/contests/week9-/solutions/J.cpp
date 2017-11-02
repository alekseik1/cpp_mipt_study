//
// Created by aleksei on 02.11.17.
//
#include <iostream>
#include <vector>
#include <map>


/*!
	\brief Класс графа
	Данный класс имеет только одну простую цель: проиллюстрировать то,
	как Doxygen документирует наследование
*/
template<typename T>
class Graph {
private:

    bool _is_orientated;
    /// Вершины графа. Произвольный тип
    std::vector<T> _nodes;
    /// Словарь вида {вершина : вектор_из( пара(куда, стоимость) )}
    std::map<T, std::vector<std::pair<T, int>>>  _paths_from;
    // Пара - это кортеж
    /// Та же матрица смежности, но для орграфа (я буду заполнять обе)
    std::map<T, std::vector<std::pair<T, int>>>  _orient_paths_from;

    std::vector<std::pair<T, int>> _empty_pair_array() {
        return std::vector<std::pair<T, int>>();
    };

    bool _contains(const std::vector<T>& v, const T& value)
    {
        return std::find(v.begin(), v.end(), value) != v.end();
    }

public:

    explicit Graph(bool is_or=false) {
        _is_orientated = is_or;
    }

    /*!
     * Геттер ориентированности
     * @return Возвращает true, если граф является ориентированным
     */
    bool is_orientated()
    {
        return _is_orientated;
    }

    /*!
     @brief Делает ребро между двумя вершинами с заданным весом.
     @warning Заметьте, что связь делается и в том случае, если вершины уже связаны ребром.
     @param source Вершина, из которой исходит ребро.
     @param destination Вершина, куда идет ребро.
     @param weight Вес ребра.
     */
    void make_connection(const T& source, const T& destination, int weight) {
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
    bool add_node(const T& _Node, const std::vector<std::pair<T, int>>& edges) // По-умолчанию передаем пустой вектор
    {
        if(_Node == NULL)
            return false;
        _nodes.push_back(_Node);
        for(std::pair<T, int> pair : edges) // Для каждой пары
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
    bool add_node(const T& _Node)
    {
        return add_node(_Node, _empty_pair_array());
    }

    /*!
     * Получает массив вершин, куда можно придти из указанной вершины
     * @param source Вершина, из который искать ребра
     * @return Вектор из пар[pair] (вершина, вес)
     */
    std::vector<std::pair<T, int>> get_nodes_from(const T& source)
    {
        if(!_is_orientated) {
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
    std::vector<std::pair<T, int>> get_nodes_to(const T& destination)
    {
        std::vector<std::pair<T, int>> result;
        if(!_is_orientated) {
            for(T& Node : _nodes) {     // Для каждой из нод
                for(std::pair<T, int>& pair : _paths_from[Node]) {   // Для всех пар этой ноды
                    if(pair.first == destination) {  // Если пара ведет в destination
                        result.push_back(std::pair<T, int>(Node, pair.second));
                    }
                }
            }
        } else{
            for(T& Node : _nodes) {     // Для всех нод
                for(std::pair<T, int>& vec : _orient_paths_from[Node]) {
                    if(vec.first == destination) {
                        result.push_back(std::pair<T, int>(Node, vec.second));
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Graph<int> g = Graph<int>(true);
    g.add_node(2);
    g.add_node(1);
    g.add_node(3);
    g.make_connection(1, 2, 5);
    g.make_connection(1, 3, 2);
    g.make_connection(3, 1, 4);
    for(auto& x : g.get_nodes_from(1))
        std::cout << "Path to " << x.first << " with weight " << x.second << "\n";
    std::cout << "=====\n";
    for(auto& y : g.get_nodes_to(1))
        std::cout << "Path from " << y.first << " with weight " << y.second << "\n";
}
