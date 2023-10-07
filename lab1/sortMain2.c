#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"
/*
  Ivan Wang
  501086429
  2023-01-21
*/
int main(int argc, char *argv[])
{
  int data[100000]; /* Array of ints to sort */
  int nDataItems;   /* number of actual items in the array */
  int i;
  int count = 0;

  nDataItems = 4;
  data[0] = 10;
  data[1] = 20;
  data[2] = 30;
  data[3] = 40;
  if (argc > 1)
  {
    nDataItems = 0;
    fprintf(stderr, "The sequence to be sorted:\n");
    for (int i = 1; i < argc; i++)
    {
      fprintf(stderr, "%d\n", atoi(argv[i]));
      data[i-1] = atoi(argv[i]);
      nDataItems++;
    }
    fprintf(stderr, "\nThe sorted sequence:\n");
    mySort(data, nDataItems);
    exit(0);
  }
  else
  {
    mySort(data, nDataItems);
  }
  /* Check that the data arary is sorted. */

  for (i = 0; i < nDataItems - 1; i++)
  {
    if (data[i] > data[i + 1])
    {
      fprintf(stderr, "Sort error: data[%d] (= %d)"
                      " should be <= data[%d] (= %d) - -aborting\n",
              i, data[i], i + 1, data[i + 1]);
      exit(1);
    }
  }

  /* Print sorted array to stdout */
  for (i = 0; i < nDataItems; i++)
  {
    printf("%d\n", data[i]);
  }
  exit(0);
}
