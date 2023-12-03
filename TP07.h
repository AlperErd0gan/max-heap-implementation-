/* Macro function for swap process. You do not need to write any other function for the swap process.*/
static int _temp;
#define SWAP(a,b) do { \
  _temp = a; \
  a = b; \
  b = _temp; \
} while (0)

/* length of the array representing the heap */
static int SIZE = 10;

/* array: heap, size: current number of elements in the heap */
void print_heap(int *arr, int size);

/* The function, whose algorithm is given in the TP file and whose heap feature is corrupted, turns an array into a heap, direction: from root to leaf
 * array: heap, index: Index of the element that breaks the heap property, size: current number of elements in the heap */
void max_heapify_recursive(int *arr, int index, int size);

/* Recursive function that creates a binary heap preserving the max-heap property from an array it takes as a parameter
 * array: heap, size: current number of elements in the heap */
void build_max_heap(int *arr, int size);

/* Function that returns the maximum priority element in the priority queue and also removes the element from the queue and preserves the heap property
 * arr: heap, size: current number of elements in the heap */
int extractMax(int *arr, int size);

/* Function that converts an array whose heap property is corrupted into a heap, direction: from leaf to root
 * arr: heap, index: Index of the element that breaks the heap property */
void bubbleUp(int *arr, int index);

/* Function that adds elements to the priority queue and preserves the heap property
 * arr: heap, data: The value (or priority, in our case, both are the same) of the element to be added */
void insertData(int *arr, int data);

/* Function that removes the element at the given index from the priority queue and ensures that it preserves the heap property
 * arr: heap, index: index of the element to be removed */
void removeIndex(int *arr, int index);

/* Function that changes the value (priority) of the element whose index is given in the priority queue
 * arr: heap, index: Index of the element whose priority will be updated, priority: new priority value */
void changePriority(int *arr, int index, int priority);


