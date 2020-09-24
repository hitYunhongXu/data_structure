//
// Created by xyh on 2020/9/23.
//

#ifndef MYHEAP_MYHEAP_H
#define MYHEAP_MYHEAP_H

using Heap = class HNode*;
class HNode
{
public:
	int *data;
	int size;
	int capacity;
};

#define MAXDATA 1000

Heap createHeap(int maxSize)
{
	Heap H = new HNode;
	H->data = new int[maxSize+1];
	H->size = 0;
	H->capacity = maxSize;
	H->data[0] = MAXDATA;
	return H;
}

bool isFull(Heap H)
{
	return (H->size == H->capacity);
}

bool insert(Heap H, int x)
{
	int i;
	if (isFull(H))
		return false;
	i = ++H->size;
	for (; H->data[i/2] < x; i/=2)
		H->data[i] = H->data[i/2];
	H->data[i] = x;
	return true;
}

bool isEmpty(Heap H)
{
	return (H->size == 0);
}

int deleteMax (Heap H)
{
	int parent, child;
	int maxItem, x;
	if (isEmpty(H))
		return -1;

	maxItem = H->data[1];
	x = H->data[H->size--];
	for ( parent = 1; parent*2<=H->size; parent=child)
	{
		child = parent*2;
		if ((child != H->size) && (H->data[child] < H->data[child+1]))
			child++;
		if (x > H->data[child]) break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = x;
	return maxItem;
}

void percDown(Heap H, int p)
{
	int parent, child;
	int x;

	x = H->data[p];
	for (parent = p; parent*2 <= H->size; parent = child)
	{
		child = parent*2;
		if ((child != H->size) && (H->data[child] < H->data[child+1]))
			child++;
		if (x>H->data[child]) break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = x;
}

void buildHeap(Heap H)
{
	int i;
	for (i = H->size/2; i>0; i--)
		percDown(H, i);
}



#endif //MYHEAP_MYHEAP_H
