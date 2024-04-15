//
// Created by Connor Ragland on 4/14/24.
//

#include "Heap.h"

void Heap::heapifyUp(){

}

void Heap::heapifyDown(){

}

Heap::Heap(){
    _size = 0;

}

bool Heap::empty(){
    return _size == 0;
}

int Heap::size(){
    return _size;
}

DataNode Heap::top(){
    return heap[0];
}

void Heap::pop(){

}