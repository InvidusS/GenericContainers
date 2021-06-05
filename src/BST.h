#include <iostream>

template <typename T>
class BST{
private:
    class Node{
    public:
        T value;
        BST<T>::Node* left;
        BST<T>::Node* right;
        Node() : value{0}, left{nullptr}, right{nullptr} {}
        Node(T value) : value{value}, left{nullptr}, right{nullptr} {}
    };

    BST<T>::Node* root;
public:
    BST() : root{nullptr} {}
    BST(const std::initializer_list<T> list) : root{nullptr} {
        for(const auto& element : list)
            BST<T>::push(element);
    }

    void push(T);
    bool search(T);
    void display(BST<T>::Node*);
    bool deleteNode(T);

    BST<T>::Node* getMinValue(BST<T>::Node* temp) const {
        while(temp->left != nullptr)
            temp = temp->left;
        return temp;
    }
    BST<T>::Node* getMaxValue(BST<T>::Node* temp) const {
        while(temp->right != nullptr)
            temp = temp->right;
        return temp;
    }
    BST<T>::Node* getRoot() const {
        return root;
    }
};

template <typename T>
void BST<T>::push(T value){
    if(root == nullptr)
        root = new BST<T>::Node(value);
    else{
        BST<T>::Node* temp = root;
        while(temp != nullptr){
            if(temp->value > value && temp->left == nullptr){
                temp->left = new BST<T>::Node(value);
                return;
            } else if(temp->value > value){
                temp = temp->left;
            } else if(temp->value <= value && temp->right == nullptr){
                temp->right = new BST<T>::Node(value);
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

template <typename T>
bool BST<T>::search(T value){
    BST<T>::Node* temp = root;
    while(temp != nullptr){
        if(temp->value == value)
            return true;
        else if(temp->value < value)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false;
}

template <typename T>
void BST<T>::display(BST<T>::Node* temp){
    if(temp != nullptr){
        display(temp->left);
        std::cout << temp->value << ' ';
        display(temp->right);
    }
}

template <typename T>
bool BST<T>::deleteNode(T value){
    BST<T>::Node* temp = root;
    BST<T>::Node* temp2 = nullptr;

    while(temp != nullptr && temp->value != value){
        temp2 = temp;
        if(temp->value > value)
            temp = temp->left;
        else
            temp = temp->right;
    }

    if(temp == nullptr)
        return false;
    
    if(temp->left == nullptr && temp->right == nullptr){
        if(temp != root){
            if(temp2->left == temp)
                temp2->left = nullptr;
            else
                temp2->right = nullptr;
        } else {
            root = nullptr;
        }
        delete temp;
    } else if(temp->left && temp->right){
        T minRightValue = getMinValue(temp->right)->value;

        deleteNode(minRightValue);
        temp->value = minRightValue;

    } else {
        BST<T>::Node* temp3 = (temp->left) ? temp->left : temp->right;

        if(temp != root)
            if(temp == temp2->left)
                temp2->left = temp3;
            else
                temp2->right = temp3;
        else
            root = temp3;
        delete temp;
    }
    return true;
}
