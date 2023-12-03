#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "TP07.h"

void print_heap(int *arr, int size)
{
   for (int i = 0; i < size; i++)
   {
      printf("%d ", arr[i]);
   }
}

void max_heapify_recursive(int *arr, int index, int size)
{  // We control the left side and thr right side of the index we are currently in if it's against the heap structure we swap 
   int greatest = index;
   int leftSide = 2 * index + 1;
   int rightSide = 2 * index + 2;

   if (leftSide < size && arr[leftSide] > arr[greatest])
      greatest = leftSide;

   if (rightSide < size && arr[rightSide] > arr[greatest])
      greatest = rightSide;

   if (greatest != index)
   {
      SWAP(arr[greatest], arr[index]);
      max_heapify_recursive(arr, greatest, size);
   }
}

void build_max_heap(int *arr, int size)
{
   for (int i = (size / 2) - 1; i >= 0; i--)
   {
      max_heapify_recursive(arr, i, size);
   }
}

int extractMax(int *arr, int size)
{
   if (size <= 0)
   {
      printf("Heap is empty");
   }
   // We swap the element with the last element and than we extract from the end of the array 
   int max = arr[0];
   SWAP(arr[0], arr[size - 1]);
   // Decrement size before calling max_heapify_recursive
   size--;
   SIZE--;
   max_heapify_recursive(arr, 0, size);

   return max;
}

void bubbleUp(int *arr, int index)
{  // It is the shiftup function where we change the element with it's parent if it is necessary. We do this to protect heap structure
   int parentIndex;
   while (index > 0)
   {
      parentIndex = (index - 1) / 2;
      if (arr[index] > arr[parentIndex])
      {
         SWAP(arr[index], arr[parentIndex]);
         index = parentIndex;
      }
      else
      {
         break;
      }
   }
}

void insertData(int *arr, int data)
{  // we directly inset to the end of the array than we call the bubbleup to protect heap structure
   int index = SIZE;
   arr[index] = data;
   SIZE++;
   bubbleUp(arr, index);
}

void removeIndex(int *arr, int index)
{  // we check for the invalid cases 
   if (index < 0 || index >= SIZE)
   {
      printf("Invalid index\n");
      return;
   }
   // get the last elment to the element we want to change and decrease the size
   arr[index] = arr[SIZE - 1];
   SIZE--;

   if (index > 0 && arr[index] > arr[(index - 1) / 2])
   {   // if it is bigger than it's parent we buble up 
      bubbleUp(arr, index);
   }
   else
   {  // else we will heapify 
      max_heapify_recursive(arr, index, SIZE);
   }
}

void changePriority(int *arr, int index, int priority)
{  // We can directly change the priority by changing the value
   arr[index] = priority;
   bubbleUp(arr, index);
}
