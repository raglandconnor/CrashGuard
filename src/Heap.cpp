//
// Created by Connor Ragland on 4/14/24.
//

#include "Heap.h"

void Heap::heapifyUp(int index){
    
}

void Heap::heapifyDown(int index){

    //the current parent index to compare with the children 
	int largestOrSmallest = index;

	//the indices of the children of p are 2p+1 and 2p+2
	int child1Index = index*2 + 1;
	int child2Index = index*2 + 2;



	//check if index is valid, if it is, check if more crashes occur at the child or parent
	if(child1Index < heap.size() && heap[child1Index].numCrashes > heap[largestOrSmallest].numCrashes){
        largestOrSmallest = child1Index;
    }

    //check if index is valid, if it is, check if more crashes occur at the child or parent
    //can also overwrite the previous if statement
    if(child2Index < heap.size() && heap[child2Index].numCrashes > heap[largestOrSmallest].numCrashes){
        largestOrSmallest = child2Index;
    }

    //if the index has changed, a switch is necessary
    if(largestOrSmallest!=index){
        //swap and recurisvely call heapify down on the new subtrees root
        swap(heap[largestOrSmallest],heap[index]);
        heapifyDown(largestOrSmallest);
    }

/*

source: I looked at https://builtin.com/software-engineering-perspectives/heapify-heap-tree-cpp
to find a way to make a simple recrusive function for heapify

*/

}

Heap::Heap(){
    
}

bool Heap::empty(){
    return heap.size() == 0;
}

int Heap::size(){
    return heap.size();
}

AttributeData Heap::top(){
    return heap[0];
}

void Heap::push(AttributeData data){
    heap.push_back(data);
    heapifyUp(heap.size()-1);
}

void Heap::pop(){
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}