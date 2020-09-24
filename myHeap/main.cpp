#include <iostream>
#include "myHeap.h"

int main()
{
	Heap H = createHeap(10);
	for (int i = 1; i < 11; ++i)
	{
		H->data[i] = i;
		++H->size;
	}

	buildHeap(H);

	for (int i = 1; i < 11; ++i)
	{
		std::cout << H->data[i] << "  ";
	}

	return 0;
}
