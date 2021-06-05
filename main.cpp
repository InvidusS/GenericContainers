#include <iostream>
#include "src/vector.h"
#include "src/forward_list.h"
#include "src/BST.h"

void genericVector1(){
    std::cout << "Vector:" << '\n';
    std::cout << "Creating vector of 10 'a' objects..." << '\n';
    Vector<char> v(10, 'a');
    std::cout << "Displaying vector: " << v << '\n';
    std::cout << "Pushing 2 elements..." << '\n';
    v.pushBack('b');
    v.pushBack('c');
    std::cout << "Displaying vector: " << v << '\n';
    std::cout << "Testing copy constructor: " << '\n';
    Vector<char> v2 {v};
    std::cout << "Displaying vector2: " << v2 << '\n';
    std::cout << "Pushing 2 elements..." << '\n';
    v2.pushBack('d');
    std::cout << "Displaying vector2: " << v2 << '\n';
}

void genericVector2(){
    std::cout << "Creating vector of usign initializer_list..." << '\n';
    Vector<int> v3 {1,2,3,4,5};
    std::cout << "Displaying vector3: " << v3 << '\n';

    std::cout << "Pushing 10 elements..." << '\n';
    for(size_t i = 0; i < 10; i++)
        v3.pushBack(i * 10);
    std::cout << "Displaying vector3: " << v3 << '\n';

    std::cout << "Removing last element..." << '\n';
    v3.popBack();
    std::cout << "Displaying vector3: " << v3 << '\n';
    
    std::cout << "v3[2] = " << v3[2] << '\n';

    std::cout << "Front element = " << v3.frontOfVector() << '\n';
    std::cout << "Back element = " << v3.backOfVector() << '\n';

    std::cout << "Ereasing 3 and 9..." << '\n';
    v3.ereaseElementOfVector(3);
    v3.ereaseElementOfVector(9);
    std::cout << "Displaying vector3: " << v3 << '\n';

    std::cout << "Inserting 7 on 4th position..." << '\n';
    v3.insertIntoVector(4,7);
    std::cout << "Displaying vector3: " << v3 << '\n';

    std::cout << "Checking if vector is empty: " << std::boolalpha << v3.isEmpty() << '\n';
    std::cout << "Clearing vector..." << '\n';
    v3.clearVector();
    std::cout << "Checking if vector is empty: " << std::boolalpha << v3.isEmpty() << '\n';
}

void genericFirwardList1(){
    std::cout << "List:" << '\n';
    std::cout << "Creating list and pushing 5 elements..." << '\n';
    List<int> l;
    l.pushFront(1);
    l.pushFront(2);
    l.pushFront(3);
    l.pushFront(4);
    l.pushFront(5);
    std::cout << "Displaying list: " << l << '\n';
    std::cout << "Searching for 2: " << l.search(2) << '\n';
    std::cout << "Ereasing 5 and 3..." << '\n';
    l.ereaseElement(5);
    l.ereaseElement(3);
    std::cout << "Displaying list: " << l << '\n';
    std::cout << "Poping front twice..." << '\n';
    l.popFront();
    l.popFront();
    std::cout << "Displaying list: " << l << '\n';
    std::cout << "Checking if list is empty: " << l.isEmpty() << '\n';
    std::cout << "Displaying list: " << l << '\n';
    std::cout << "Removing last element..." << '\n';
    l.popFront();
    std::cout << "Checking if list is empty: " << l.isEmpty() << '\n';
    std::cout << "Pushing new element..." << '\n';
    l.pushFront(3);
    std::cout << "Displaying list: " << l << '\n';
    std::cout << "Front element: " << l.frontOfList() << '\n';

    List<int> l1;
    l1.pushFront(1);
    l1.pushFront(2);
    l1.pushFront(3);
    List<int> l2;
    l2.pushFront(1);
    l2.pushFront(2);
    l2.pushFront(3);

    std::cout << "l1 == l2 ?= " << std::boolalpha << (l1 == l2) << '\n';
}

void genericBST(){
    std::cout << "BST:" << '\n';
    std::cout << "Pushing 4 elements..." << '\n';
    BST<int> t;
    t.push(7);
    t.push(3);
    t.push(2);
    t.push(24);
    std::cout << "Displaying tree: " << '\n';
    t.display(t.root);
    std::cout << '\n';
    std::cout << "Pushing 3 elements..." << '\n';
    t.push(16);
    t.push(14);
    t.push(9);
    std::cout << "Displaying tree: " << '\n';
    t.display(t.root);
    std::cout << '\n';
    std::cout << "Searching for 14: " << std::boolalpha << t.search(14) << '\n';
}

int main(){
    //genericVector1();
    std::cout << '\n';
    //genericVector2();
    std::cout << '\n';
    genericFirwardList1();
    std::cout << '\n';
    //genericBST();
    return 0;
}
