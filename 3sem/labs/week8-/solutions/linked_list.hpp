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
void list_insert_back(List<DataType> &lst, const DataType &value)   // Вставляет в конец списка значение value
{
    lst.size += 1;
    lst.end = insert_node_back(lst.end, value);
}

template<typename DataType>
void list_insert(List<DataType>& l, const DataType &value,  int pos)    // Вставляет в произвольное место значение value
{
    if(pos == 0)  // Вставляем в начало, если pos == 0
    {
        list_insert(l, value);
        return;
    } else if(pos == l.size) // Вставляем в конец, если pos == l.size (я нумерую ноды листа с нуля и этого вам советую)
    {
        list_insert_back(l, value);
        return;
    }

    tNode<DataType> *node = l.begin;    // Сначала на старте
    for(int i = 0; i < pos-1; i++) {
        node = node->next;  // pos-1 раз идем дальше
    }
    // Вот мы и на месте. Теперь надо ПОСЛЕ node поставить наш новый элемент
    // Сделаем хитро: создадим новую ноду, сделаем ей next - следующий после node элемент, а самому node в качестве следующего запишем созданный newNode
    // Не понятно? Представьте все это в голове и станет ясно. Я не зря в цикле дошел до pos-1, а не до pos
    tNode<DataType> *newNode = new tNode<DataType>;
    newNode->data = value;
    newNode->next = node->next;
    node->next = newNode;
    // Йа-Йа, увеличиваем длину списка
    l.size += 1;
}

template<typename DataType>
bool list_swap(List<DataType>& l, int i, int j) // Свапает i-ый и j-ый элементы. Нумерация идет с НУЛЯ
{
    if(i > l.size || i < 0 || j > l.size || j < 0)    // Плохой ввод, нельзя его пустить
    {
        return false;
    }

    if(i == j) {    // Идиотизм, но вдруг кто-то так сделает?
        return true;
    }

    if(i > j)   // Наведем порядок: хочу, чтобы j >= i
    {
        i = i + j;
        j = i - j;
        i = i - j;
    }

    tNode<DataType> *first = l.begin;
    tNode<DataType> *last = l.begin;
    for(int k = 0; k < j-1; k++) {
        if(i != 0 && k < i-1)
        {
            first = first->next;    // Двигаем first, пока не прогуляемся i-1 раз
        }
        last = last->next;          // То же самое с last
    }
    // Мы опять прогулялись до предыдущего в first и last

    if(i != 0)
    {
        if(first->next == last) // Если они соседи
        {
            tNode<DataType>* prev1 = first;  // i-1 -ая нода
            first = first->next;    // i-ая нода
            //tNode<DataType>* next1 = first->next;   // i+1 -ая нода
            // Эти две не нужны в таком случае
            //tNode<DataType>* prev2 = last;   // j-1 -ая нода
            last = last->next;  // j-ая нода
            tNode<DataType>* next2 = last->next; // j+1 -ая нода

            prev1->next = last;
            last->next = first;
            first->next = next2;
        } else  // Если они не соседи. Тут начинается веселье
        {
            tNode<DataType>* prev1 = first;  // i-1 -ая нода
            first = first->next;    // i-ая нода
            tNode<DataType>* next1 = first->next;   // i+1 -ая нода

            tNode<DataType>* prev2 = last;   // j-1 -ая нода
            last = last->next;  // j-ая нода
            tNode<DataType>* next2 = last->next; // j+1 -ая нода
            // УЖАС! О нашей перестановке узнают соседи (впрочем, они всегда узнают, когда такой движ)

            prev1->next = last;
            last->next = next1;
            prev2->next = first;
            first->next = next2;
            // Рисуйте рисунки. На них сразу все ясно
        }
    } else if(i == 0)   // first ссылается на l.begin, поэтому нужна отдельная реализация. Эх, если б список был двусвязный...
    {
        if(j == 1) // Если они соседи
        {
            last = first->next;
            first->next = last->next;
            last->next = first;
            l.begin = last;
        } else  // Если они не соседи. Тут начинается веселье
        {
            tNode<DataType>* next1 = first->next;   // 1 -ая нода

            tNode<DataType>* prev2 = last;   // j-1 -ая нода
            last = last->next;  // j-ая нода
            tNode<DataType>* next2 = last->next; // j+1 -ая нода
            // УЖАС! О нашей перестановке узнают соседи (впрочем, они всегда узнают, когда такой движ)

            prev2->next = first;
            last->next = next1;
            first->next = next2;
            l.begin = last;
            // Рисуйте рисунки. На них сразу все ясно
        }
    }
    return true;    // Все хорошо, возвращаем true
}

template<typename DataType>
bool list_remove(List<DataType>& l, int pos)  // Удаляет элемент на pos позиции
{
    if(pos < 0 || pos >= l.size)     // Плохой ввод -- в помойку
        return false;
    if(pos == 0)      // Опять, 0 - особый случай
    {
        tNode<DataType>* prev = l.begin;
        l.begin = l.begin->next;    // Сдвигаемся на 1
        delete prev;
    } else
    {
        tNode<DataType> *node = l.begin;    // Сначала на старте
        for(int i = 0; i < pos-1; i++) {
            node = node->next;  // pos-1 раз идем дальше
        }
        tNode<DataType>* toDelete = node->next; // Его удалим
        node->next = node->next->next;  // "Перепрыгиваем" через удаляемый элемент
        delete toDelete;    // И удаляем сам элемент
    }
    l.size -= 1;        // Не забываем уменьшить длину списка
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
void list_sort(List<DataType> &l)   // Сортировка дураком (она проще всего).
{
    tNode<DataType> *p = l.begin;
    tNode<DataType> *prev;
    int i = 0;

    while(p) {
        prev = p;
        p = p->next;
        if(p == nullptr)
            return;
        if(p->data < prev->data) {
            list_swap(l, i, i+1);
            p = l.begin;
            prev = nullptr;
            i = -1;
        }
        i++;
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