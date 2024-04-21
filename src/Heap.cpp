//
// Created by Connor Ragland on 4/14/24.
//

#include "Heap.h"

template class Heap<less<int>>;
template class Heap<greater<int>>;

template<typename Compare>
void Heap<Compare>::heapifyUp(int index){

    //if index is 0, node has no parents, no need to heapify up
    if(index==0){
        return;
    }

    //else it has a parent with formula n-1/2
    int parent = (index - 1) / 2;

    //compare curr index w parent and swap accordingly, then recursively call heapify on that new parent
    if(comparator(heap[parent].numCrashes,heap[index].numCrashes)){
        swap(heap[parent],heap[index]);
        heapifyUp(parent);
    }

}

template<typename Compare>
void Heap<Compare>::heapifyDown(int index){

    //the current parent index to compare with the children 
    int largestOrSmallest = index;

    //the indices of the children of p are 2p+1 and 2p+2
    int child1Index = index*2 + 1;
    int child2Index = index*2 + 2;



    //check if index is valid, if it is, check if more crashes occur at the child or parent
    //user can use comparator to choose min or max heap.
    if(child1Index < heap.size() && comparator(heap[largestOrSmallest].numCrashes, heap[child1Index].numCrashes)){
        largestOrSmallest = child1Index;
    }

    //check if index is valid, if it is, check if more crashes occur at the child or parent
    //can also overwrite the previous if statement
    if(child2Index < heap.size() && comparator(heap[largestOrSmallest].numCrashes, heap[child2Index].numCrashes)){
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

template<typename Compare>
Heap<Compare>::Heap() : comparator(Compare()){
}


template<typename Compare>
bool Heap<Compare>::empty(){
    return heap.size() == 0;
}

template<typename Compare>
int Heap<Compare>::size(){
    return heap.size();
}

template<typename Compare>
AttributeData Heap<Compare>::top(){
    return heap[0];
}

template<typename Compare>
void Heap<Compare>::push(AttributeData data){
    heap.push_back(data);
    heapifyUp(heap.size()-1);
}

template<typename Compare>
void Heap<Compare>::pop(){
    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

template<typename Compare>
void Heap<Compare>::topK(int k){
    for(int i = 0; i < k; i++){
        //grab the most dangerous
        AttributeData data = top();

        //remove it from heap
        pop();

        //print the data
        cout << data.attributeName << ": " << data.numCrashes << " total crashes" << endl;
    }
}