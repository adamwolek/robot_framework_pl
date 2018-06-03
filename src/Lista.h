//
// Created by kinga on 03.05.18.
//

#ifndef VECTOR_LIBRARY_VECTOR_H
#define VECTOR_LIBRARY_VECTOR_H


#include <iostream>

template <class TYPE>
class ArduinoVector {
    int type = 1; // 1 - standard; 2 - bigger
    int capacityChanger;
    int capacity = 10;
    int currentCapacity = 0;
    TYPE *T; //pointer to dynamic array

    public:
    ArduinoVector(int type);
    ~ArduinoVector();

    int getCurrentCapacity();
    void add(TYPE newElement);
    void remove(int index);
    void remove();
    TYPE getElement(int index);
};


template<class TYPE>
int ArduinoVector<TYPE>::getCurrentCapacity() {
    return currentCapacity;
}

template<class TYPE>
ArduinoVector<TYPE>::ArduinoVector(int type) {
    (*this).type = type;
   switch(type) {
       case 1: {
           capacityChanger = 10;
           break;
       }
       case 2: {
           capacityChanger = 100;
           break;
       }
   }
    T = new TYPE[capacity];
}


template<class TYPE>
ArduinoVector<TYPE>::~ArduinoVector() {}

template<class TYPE>
void ArduinoVector<TYPE>::add(TYPE& newElement) {
    if (currentCapacity < capacity) {
        T[currentCapacity] = newElement;
        currentCapacity++;
    } else {
        int oldCapacity = capacity;
        capacity += capacityChanger;
        TYPE *newArray = new TYPE[capacity];
        for(int i = 0; i < oldCapacity; i++) {
            newArray[i] = T[i];
        }
        T = new TYPE[capacity];
        T = newArray;
        T[currentCapacity] = newElement;
        currentCapacity++;
    }
}

template<class TYPE>
TYPE& ArduinoVector<TYPE>::getElement(int index) {
    return T[index];
}

template<class TYPE>
void ArduinoVector<TYPE>::remove(int index) {
    for (int i = index; i < currentCapacity; i++) {
        T[i] = T[i+1];
    }
    currentCapacity--;
}

template<class TYPE>
void ArduinoVector<TYPE>::remove() {
    TYPE *newArray = new TYPE[capacity];
    for(int i = 0; i < currentCapacity-1; i++) {
        newArray[i] = T[i];
    }
    T = newArray;
    currentCapacity--;
}

#endif //VECTOR_LIBRARY_VECTOR_H
