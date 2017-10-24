#ifndef __linked_list_hpp
#define __linked_list_hpp

#include <ostream>

#define nullptr NULL


template<typename DataType>
struct tNode {
    DataType data;
    tNode* next;
};


template<typename DataType>
struct List {
    tNode<DataType> *begin;
    int size;
    tNode<DataType> *end;
};

template<typename DataType>
void list_init(List<DataType> &lst)
{
    lst.begin = nullptr;
    lst.size = 0;
    lst.end = nullptr;
}

template<typename DataType>
tNode<DataType> * insert_node(tNode<DataType> *p_begin, DataType data)
{
    tNode<DataType> *p = new tNode<DataType>;
    p->data = data;
    p->next = p_begin;
    return p;
}

template<typename DataType>
tNode<DataType> * insert_node_back(tNode<DataType> *p_begin, DataType data)
{
    tNode<DataType> *p = new tNode<DataType>;
    p->data = data;
    p_begin->next = p;
    return p;
}

template<typename DataType>
void list_insert(List<DataType> &lst, const DataType &value)
{
    lst.size += 1;
    lst.begin = insert_node(lst.begin, value);
    if(lst.size == 1)
    {
        lst.end = lst.begin;
    }
}

template<typename DataType>
void list_insert_back(List<DataType> &lst, const DataType &value)
{
    lst.size += 1;
    lst.end = insert_node_back(lst.end, value);
}

template<typename DataType>
void list_insert(List<DataType>& l, const DataType &value,  int pos)
{
    if(pos == 0)  // Вставляем в начало, если pos == 0
    {
        list_insert(l, value);
        return;
    } else if(pos == l.size) // Вставляем в конец, если pos == l.size (я нумерую ноды листа с нуля и этого вам советую
    {
        list_insert_back(l, value);
        return;
    }

    tNode<DataType> *node = l.begin;    // Сначала на старте
    for(int i = 0; i < pos-1; i++) {
        node = node->next;  // POS раз идем дальше
    }
    // Вот мы и на месте. Теперь надо ПОСЛЕ node поставить наш новый элемент
    // Сделаем хитро: создадим новую ноду, сделаем ей next - следующий после node элемент, а самому node в качестве следующего запишем созданный newNode
    // Не понятно? Представьте все это в голове и станет ясно. Я не зря в цикле дошел до pos-1, а не до pos
    tNode<DataType> *newNode = new tNode<DataType>;
    newNode->data = value;
    newNode->next = node->next;
    node->next = newNode;
}

template<typename DataType>
void list_print(const List<DataType> &lst, std::ostream &out)
{
    tNode<DataType> *p = lst.begin;
    for(; p; p = p->next)
    {
        out << p->data << '\t';
    }
}

template<typename DataType>
void list_destroy(List<DataType> &lst)
{
    tNode<DataType> *p = lst.begin;
    tNode<DataType> *prev;
    while (p) {
        prev = p;
        p = p->next;
        delete prev;
    }
    lst.size = 0;
    lst.begin = nullptr;
    lst.end = nullptr;
}


#endif