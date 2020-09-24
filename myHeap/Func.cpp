//
// Created by xyh on 2020/9/24.
//
#include "myHeap.h"


bool isFull(Heap H)
{
	return (H->size == H->capacity);
}



bool isEmpty(Heap H)
{
	return (H->size == 0);
}

