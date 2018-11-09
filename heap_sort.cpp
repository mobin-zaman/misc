#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int heap[],int heap_size, int i){
    int l,r,largest;
     l=2*i;
     r=2*i+1;

     if(l<=heap_size && heap[l]>heap[i]) largest=l;
     else largest=i;

     if(r<=heap_size && heap[r]>heap[largest])  largest=r;

     if(largest!=i) {
         swap(heap[i],heap[largest]);
         max_heapify(heap,heap_size,largest);
     }

}

void build_max_heap(int heap[], int heap_size){
    for(int i=heap_size/2;i>=1;i--){
        max_heapify(heap,heap_size,i);
    }
}

void heap_sort(int heap[],int heap_size){
    for(int i= heap_size;i>1;i--){
        swap(heap[1],heap[i]);
        heap_size--;
        build_max_heap(heap,heap_size);
    }
}