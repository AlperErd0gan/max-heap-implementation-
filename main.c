#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "TP07.h"

int main()
{

	int arr1[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
	int arr2[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
	int heap[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

	// Call the max heapify recursive function for the element of arr1 that breaks the max-heap property
	printf(">> max_heapify_recursive called for arr1\n");
	int size = sizeof(arr1) / sizeof(arr1[0]);

	for (int i = (size / 2) - 1; i >= 0; i--)
	{
		max_heapify_recursive(arr1, i, size);
	}

	// print the updated heap to the screen
	printf("heap: ");
	print_heap(arr1, SIZE);

	// Test case for max heapify recursive

	printf("\n>> max_heapify_recursive is working smoothly, continue on your way...\n");

	// Transform arr2 to a heap with build_max_heap
	printf(">> build_max_heap called for arr2\n");
	build_max_heap(arr2, SIZE);

	// Print the heap
	printf("heap: ");
	print_heap(arr2, SIZE);

	// Test case for build_max_heap

	printf("\n>> build_max_heap is working smoothly, continue on your way...\n");

	// We will perform the next operations using priority queue functions on the heap array.
	printf("----- Priority Queue -----\n");

	// In the priority queue, pull the highest priority element from the queue, print the updated
	// queue structure and the value of the element you have drawn on the screen.
	
	int max = extractMax(heap, SIZE);
	SIZE--;
	printf(">> extracted max = %d\nqueue: ", max);
	print_heap(heap,SIZE);

	// repeat previous action
	int max2 = extractMax(heap, SIZE);
	SIZE--;
	printf("\n>> extracted max = %d\nqueue: ", max2);
	print_heap(heap, SIZE);
	printf("\n");

	// Add an element with a value (priority) of 35 to the priority queue and print the queue
	insertData(heap, 35);
	SIZE++;
	printf(">> 35 is added\nqueue: ");
	print_heap(heap, SIZE);
	printf("\n");

	// remove the element with index 5 from the priority queue and print the queue
	printf(">> The element with priority %d is removed from the queue\nqueue: ", heap[5]);
	removeIndex(heap, 5);
	SIZE--;
	print_heap(heap, SIZE);
	printf("\n");

	// Set the priority of the 3-index element of the priority queue to 41 and print the queue
	printf(">> The priority of the element with priority %d has been updated\nqueue: ",
		   heap[3]);
    changePriority(heap, 3, 41);
	print_heap(heap, SIZE);

	return 0;
}