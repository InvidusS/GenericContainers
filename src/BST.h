#include <iostream>

template <typename T>
class treeNode{
public:
    T value;
    treeNode<T>* left;
    treeNode<T>* right;
    treeNode() : value{0}, left{nullptr}, right{nullptr} {}
    treeNode(T value) : value{value}, left{nullptr}, right{nullptr} {}
};

template <typename T>
class BST{
public:
    treeNode<T>* root = nullptr;
    void push(T value){
        if(root == nullptr)
            root = new treeNode<T>(value);
        else{
            treeNode<T>* temp = root;
            while(temp != nullptr){
                if(temp->value > value && temp->left == nullptr){
                    temp->left = new treeNode<T>(value);
                    return;
                } else if(temp->value > value){
                    temp = temp->left;
                } else if(temp->value < value && temp->right == nullptr){
                    temp->right = new treeNode<T>(value);
                    return;
                } else {
                    temp = temp->right;
                }
            }
        }
    }
    bool search(T value){
        treeNode<T>* temp = root;
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
    void display(treeNode<T>* temp){
        if(temp != nullptr){
            display(temp->left);
            std::cout << temp->value << ' ';
            display(temp->right);
        }
    }
};
