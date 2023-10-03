#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class List {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        clear();
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void clear() {
        while (!isEmpty()) {
            popBack();
        }
    }

    void pushBack(const T& value) {
        Node<T>* newNode = new Node<T>(value);

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        size++;
    }

    void popBack() {
        if (isEmpty()) {
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* temp = tail->prev;
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }

        size--;
    }

    void print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};



int main() {
    List<int> myList;

    myList.pushBack(1);
    myList.pushBack(2);
    myList.pushBack(3);

    std::cout << "Current List: ";
    myList.print();

    std::cout << "List size: " << myList.getSize() << std::endl;

    myList.popBack();
    std::cout << "List after popBack(): ";
    myList.print();

    myList.clear();
    std::cout << "List after clear(): ";
    myList.print();

    return 0;
}