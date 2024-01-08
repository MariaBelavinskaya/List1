#include <memory>
#include <iostream>
#include <sstream>

template<typename T>
class List
{
private:
    template<typename T>
    struct Node
    {
        T data;
        std::unique_ptr<Node> next;
    };
    size_t size;

    std::unique_ptr<Node> head;
public:
    /*
    @brief Создание пустого объекта
    */
    List()
        : head(nullptr), size(0) {}


    /*
    @brief Создание деструктора для чистки памяти при удалении объекта
    */
    ~List();

    /*
    @brief Добавление элемента в список
    @param data Элемент, который добавляем
    */
    void pushBack(T data);

    /*
    @brief Преобразуем список в строку
    */
    std::string toString() const noexcept;
};

template<typename T>
List<T>::~List()
{
    while (head==nullptr)
    {
        auto next = std::move(head->next_node);
        head = std::move(next);
    }
}

template<typename T>
void List<T>::pushBack(T data)
{
    head = std::unique_ptr<Node<T>>(new Node{ data, std::move(head) });
}

template<typename T>
std::string List<T>::toString() const noexcept
{
    std::stringstream buffer;
    auto current = std::move(head);
    while (current != nullptr)
    {
        buffer << current->data << ' ';
        current = std::move(current->next);
    }
    return buffer.str();
}
