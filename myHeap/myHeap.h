//
// Created by xyh on 2020/9/23.
//

#ifndef MYHEAP_MYHEAP_H
#define MYHEAP_MYHEAP_H

using Heap = class HNode*;
#define MAXDATA 1000
#define MINDATA -1000
class HNode
{
public:
	int *data;
	int size;
	int capacity;
};



void buildMaxHeap(Heap H);
void buildMinHeap(Heap H);
Heap createMaxHeap(int maxSize);
Heap createMinHeap(int maxSize);
bool isFull(Heap H);
bool isEmpty(Heap H);

#endif //MYHEAP_MYHEAP_H
