#include <iostream>

template <typename T> class Vector {
private:
    T* vector;
    int size;
    int capacity;

    friend std::ostream& operator << (std::ostream& os, const Vector<T>& v) {
        os << "[ ";
        for(int i = 0; i < v.size; i++)
            os << v.vector[i] << ' ';
        os << ']';
        return os;
    }
public:
    Vector() : size{}, capacity{5}, vector{new T[capacity]} {}
    Vector(const Vector<T>& other) : size{other.size}, capacity{other.capacity}, vector{new T[capacity]} {
        for(int i = 0; i < other.sizeOfVector(); i++) {
            vector[i] = other.vector[i];
        }
    }
    Vector(int elements, T value = 0) : size{elements}, capacity{elements + 5}, vector{new T[capacity]} {
        for(int i = 0; i < size; i++) {
            vector[i] = value;
        }
    }
    Vector(const std::initializer_list<T>& list) : size{0}, capacity(list.size() + 5), vector(new T[capacity]) {
        for(const auto& i : list)
            pushBack(i);
    }
    ~Vector() {delete[] vector;}

    T& operator[](int it) const {
        return vector[it];
    }
    T& frontElement() const;
    T& backElement() const;
    bool isEmpty() const;
    int sizeOfVector() const;
    int capacityOfVector() const;
    void clearVector();
    void insertElement(int, T);
    void ereaseElement(int);
    void pushBack(T);
    void popBack();
    bool search(T);
};

template <typename T> T& Vector<T>::frontElement() const {
    return vector[0];
}

template <typename T> T& Vector<T>::backElement() const {
    return vector[size - 1];
}

template <typename T> bool Vector<T>::isEmpty() const {
    return size == 0;
}

template <typename T> int Vector<T>::sizeOfVector() const {
    return size;
}

template <typename T> int Vector<T>::capacityOfVector() const {
    return capacity;
}

template <typename T> void Vector<T>::clearVector(){
    size = 0;
}

template <typename T> void Vector<T>::insertElement(int it, T value) {
    if(it < 0 || it >= size) {
        throw std::out_of_range("Error: it out of range");
    } else if(size != capacity) {
        for(int i = size - 1; i >= it; i--)
            vector[i + 1] = vector[i];
        vector[it] = value;
        size++;
    }
}

template <typename T> void Vector<T>::ereaseElement(int it) {
    if(it < 0 || it >= size) {
        throw std::out_of_range("Error: it out of range");
    } else {
        for(int i = it; i < size - 1; i++)
            vector[i] = vector[i + 1];
    }
    size--;
}

template <typename T> void Vector<T>::pushBack(T value) {
    if(size < capacity) {
        vector[size] = value;
        size++;
    } else {
        capacity += 5;
        T* newVector = new T[capacity];

        for(int i = 0; i < size; i ++) {
            newVector[i] = vector[i];
        }

        newVector[size] = value;
        size++;

        delete[] vector;
        vector = newVector;
    }
}

template <typename T> void Vector<T>::popBack() {
    if(size == 0) {
        throw std::out_of_range("Error: vector is already empty");
    } else {
        size--;
    }
}

template <typename T> bool Vector<T>::search(T value) {
    for(int i = 0; i < size - 1; i++) {
        if(vector[i] == value)
            return true;
    }
    return false;
}
