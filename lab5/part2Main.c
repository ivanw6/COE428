#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern int isEmpty();

extern int heapDelete();
extern int heapSize();
extern void addHeap(int);
extern void heapify(int);
extern void printTree(int);

int main(int argc, char *argv[])
{
  int value;
  int count = 0;
  while (scanf("%d\n", &value) != EOF)
  {
    fprintf(stderr, "READING value: %d\n", value);
    addHeap(value); //adds inputs into the heap
    count++;
  }

  int start = (heapSize() - 1) / 2; //start point, about middle of the tree
  for(int i = start; i >= 0; i--)
  {
    heapify(i); //heapify until reaches root
  }

  printf("\n");
  printTree(0); //print the XML form of tree
  printf("\n");

  printf("Descending:\n");
  for(int i = 0; i < count; i++)
  {
    int deleted = heapDelete();
    push(deleted); //push the greatest values into the stack
    fprintf(stderr, "%d\n", deleted); //print out greatest values
  }

  printf("Ascending:\n");
  for(int i = 0; i < count; i++)
  {
    fprintf(stderr, "%d\n", pop()); //print each popped value
  }
  exit(0);
}
