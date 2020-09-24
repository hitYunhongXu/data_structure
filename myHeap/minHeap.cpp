//
// Created by xyh on 2020/9/24.
//
#include "myHeap.h"

#include "myHeap.h"

Heap createMinHeap(int maxSize)
{
	Heap H = new HNode;
	H->data = new int[maxSize + 1];
	H->size = 0;
	H->capacity = maxSize;
	H->data[0] = MINDATA;
	return H;
}



int deleteMin (Heap H)
{
	int parent, child;
	int minItem,x;
	if (isEmpty(H))
		return -1;
	minItem = H->data[1];
	for( parent = 1; parent*2 <= H->size; parent=child)
	{
		child = parent*2;
		if((child!=H->size) && (H->data[child] > H->data[child+1]))
			child++;
		if (x < H->data[child])
			break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = x;
	return minItem;
}

bool insertOfMin(Heap H, int x)
{
	int i;
	if (isFull(H))
		return false;
	i = ++H->size;
	for (; H->data[i/2] > x; i/=2)
		H->data[i] = H->data[i/2];
	H->data[i] = x;
	return true;
}

/*----------- 建造最小堆 -----------*/
void percDownMin(Heap H, int p)
{
	int parent, child;
	int x;
	x = H->data[p];
	for ( parent = p; parent*2 <= H->size; parent = child)
	{
		child = parent*2;
		if ((child != H->size) && (H->data[child] > H->data[child+1]))
			child++;
		if ( x<H->data[child]) break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = x;
}


void buildMinHeap(Heap H)
{
	int i;
	for (i = H->size/2; i>0; i--)
		percDownMin(H, i);
}



