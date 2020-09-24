#include <iostream>
#include "myHeap.h"

int main()
{
	Heap H = createMinHeap(10);
	for (int i = 1; i < 11; ++i)
	{
		H->data[i] = 10-i;
		++H->size;
	}

	buildMinHeap(H);

	for (int i = 1; i < 11; ++i)
	{
		std::cout << H->data[i] << "  ";
	}

	return 0;
}
