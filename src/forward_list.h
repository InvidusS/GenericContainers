#include <iostream>

template <typename T> class List {
private:
    class Node {
    public:
        T value;
        List<T>::Node* next;
        Node(T value = 0) : value{value}, next{nullptr} {}
        ~Node() {delete next;}
    };
    List<T>::Node* first;

    friend std::ostream& operator << (std::ostream& os,const List<T>& l) {
        List<T>::Node* n = l.first;

        os << "[ ";
        while(n != nullptr) {
            os << n->value << ' ';
            n = n->next;
        }
        os << ']';

        return os;
    }
public:
    List() : first{nullptr} {}
    List(const std::initializer_list<T>& list) : first{nullptr} {
        for(const auto& element : list)
            List<T>::pushFront(element);
    }

    void pushFront(T);
    void popFront();
    void ereaseElement(T);
    bool search(T);
    void reverse();
    bool isEmpty() const;
    T frontOfList() const;

    bool operator == (const List<T>& l) const {
        List<T>::Node* temp1 = first;
        List<T>::Node* temp2 = l.first;

        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1->value != temp2->value)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        if(temp1 == nullptr && temp2 != nullptr || temp2 == nullptr && temp1 != nullptr)
            return false;
        
        return true;
    }
};

template <typename T> void List<T>::pushFront(T value) {
    List<T>::Node* newElement = new List<T>::Node;
    newElement->value = value;
    if(first == nullptr)
        first = newElement;
    else {
        newElement->next = first;
        first = newElement;
    }
}

template <typename T> void List<T>::popFront() {
    List<T>::Node* temp = first->next;
    first = temp;
}

template <typename T> void List<T>::ereaseElement(T value) {
    if(first->value == value) {
        List<T>::popFront();
        return;
    } else if(first->next == nullptr) {
        if(first->value == value) {
            first = nullptr;
            return;
        }
    } else {
        List<T>::Node* temp = first;
        while(temp->next != nullptr) {
            if(temp->next->value == value) {
                List<T>::Node* tempPtr = temp->next->next;
                temp->next = tempPtr;
                return;
            }
            temp = temp->next;
        }
    }

    std::cout << "There is not " << value << " element" << '\n';
}

template <typename T> bool List<T>::search(T value) {
    List<T>::Node* temp = first;
    while(temp != nullptr) {
        if(temp->value == value)
            return true;
        temp = temp->next;
    }
    return false;
}

template <typename T> void List<T>::reverse() {
    List<T>::Node* temp = first;
    List<T>::Node* previous = nullptr;
    List<T>::Node* next = nullptr;
    while(temp != nullptr) {
        next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    first = previous;
}

template <typename T> bool List<T>::isEmpty() const {
    return (first == nullptr) ? true : false;
}

template <typename T> T List<T>::frontOfList() const {
    return first->value;
}
