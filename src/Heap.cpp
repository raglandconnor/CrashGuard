//
// Created by Connor Ragland on 4/14/24.
//

#include "Heap.h"

void Heap::heapifyUp(int index){

}

void Heap::heapifyDown(int index){
    //the current parent to compare with the children 
	DataNode current = heap[index];

	//child1 and 2 are set to current by default, and indices are stored
	int child1Index = index*2 + 1;
	DataNode child1 = current;

	int child2Index = index*2 + 2;
	DataNode child2 = current;

	//if the indices are within the list, set the child to what it actually is
	if(child1Index < heap.size()){
		child1 = heap[child1Index];
	}
	if(child2Index < heap.size()){
		child2 = heap[child2Index];
	}

	//these cases wont be true if children dont exist bc
	//children will use currents value if not found
	if(current < child1){
		if(child2 > child1){
			//both children are greater than parent but child 2 greatest
			heap[index] = child2;
			heap[child2Index] = current;
		}
		else{
			//only child one is greater than parent
			heap[index] = child1;
			heap[child1Index] = current;
		}
	}
	else if(current < child2){
		//only child two is greater than parent
		heap[index] = child2;
		heap[child2Index] = current;
	}
}

Heap::Heap(){
    
}

bool Heap::empty(){
    return heap.size() == 0;
}

int Heap::size(){
    return heap.size();
}

DataNode Heap::top(){
    return heap[0];
}

void Heap::push(DataNode data){
    heap.push_back(data);
    heapifyUp(heap.size()-1);
}

void Heap::pop(){
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}