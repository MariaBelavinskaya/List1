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
    @brief �������� ������� �������
    */
    List()
        : head(nullptr), size(0) {}


    /*
    @brief �������� ����������� ��� ������ ������ ��� �������� �������
    */
    ~List();

    /*
    @brief ��������� ������� � ������
    @param data �������,���. ���������
    */
    void pushBack(T data);

    /*
    @brief ����������� ������ � ������
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