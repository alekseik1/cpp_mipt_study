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

public:
    /*!
     @brief Делает ребро между двумя вершинами с заданным весом.
     @warning Заметьте, что связь делается и в том случае, если вершины уже связаны ребром.
     @param source Вершина, из которой исходит ребро.
     @param destination Вершина, куда идет ребро.
     @param weight Вес ребра.
     */
    void make_connection(T source, T destination, int weight)
    {
        _paths_from[source].push_back(
                std::pair<T, int>(destination, weight)  // Добавляем дорогу туда
        );
        _paths_from[destination].push_back(
                std::pair<T, int>(source, weight)       // И обратно
        );
        _orient_paths_from[source].push_back(
                std::pair<T, int>(destination, weight)  // Для орграфа создаем путь только в одну сторону
        );
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
        if(_paths_from.find(source) != _paths_from.end())
            return _paths_from[source];
        else
            return _empty_pair_array();
    }
};

int main()
{
    Graph<int> g = Graph<int>();
    g.add_node(2);
    g.add_node(1);
    g.make_connection(1, 2, 5);
    for(auto& x : g.get_nodes_from(1))
        std::cout << "Path to " << x.first << " with weight " << x.second << "\n";
}
