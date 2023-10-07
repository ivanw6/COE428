#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */
static int size = 0;
static int heap[100];

/**
 * heapify(int value) max-heapifys the tree
 * 
 */
void heapify(int value)
{
	int left = (2 * value) + 1;
	int right = (2 * value) + 2;
	int max = value;

	if((left < size) && (heap[left] > heap[max]))
		max = left;

	if((right < size) && (heap[right] > heap[max]))
		max = right;

	if(max != value) {
		int temp = heap[max];
		heap[max] = heap[value];
		heap[value] = temp;
		heapify(max);
	}
}
/**
 * printTree(int value) prints the heap in XML format
 * 
 */
void printTree(int value){
	int left = (2 * value) + 1;
	int right = (2 * value) + 2;

	printf("<node id=\"%d\">", heap[value]);
	if(left<size)
		printTree(left);

	if(right<size)
		printTree(right);

	printf("</node>");
}

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */
int heapDelete(){
	size--;
	int temp = heap[0];
	heap[0] = heap[size];
	heap[size] = temp;
	heapify(0);
	return heap[size];
}


/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
  heap[size] = thing2add;
  size++;
}

/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize()
{
  return size;
}