#include <iostream>

template <typename T>
class Node{
public:
    T value;
    Node<T>* next;
    Node() : next{nullptr} {}
};

template <typename T>
class List{
private:
    Node<T>* first;

    friend std::ostream& operator << (std::ostream& os,const List<T>& l){
        Node<T>* n = l.first;

        os << "[ ";
        while(n != nullptr){
            os << n->value << ' ';
            n = n->next;
        }
        os << ']';

        return os;
    }
public:
    List() : first{nullptr} {}

    void pushFront(T value){
        Node<T>* newElement = new Node<T>;
        newElement->value = value;
        if(first == nullptr)
            first = newElement;
        else {
            newElement->next = first;
            first = newElement;
        }
    }
    void popFront(){
        Node<T>* temp = first->next;
        delete first;
        first = temp;
    }
    void ereaseElement(int value){
        if(first->value == value){
            popFront();
            return;
        } else if(first->next == nullptr){
            if(first->value == value){
                delete first;
                first = nullptr;
                return;
            }
        } else {
            Node<T>* temp = first;
            while(temp->next != nullptr){
                if(temp->next->value == value){
                    Node<T>* tempPtr = temp->next->next;
                    delete temp->next;
                    temp->next = tempPtr;
                    return;
                }
                temp = temp->next;
            }
        }

        std::cout << "There is not " << value << " element" << '\n';
    }
    bool isEmpty(){
        return (first == nullptr) ? true : false;
    }
    T frontOfList(){
        return first->value;
    }
};
