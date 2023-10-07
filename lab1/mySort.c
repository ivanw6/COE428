#include <stdio.h>
#include <stdlib.h>

void mySort(int d[], unsigned int n)
{
  int temp, j;
  for (int i = 1; i < n; i++)
  {
    temp = d[i];
    j = i - 1;
    while (j >= 0 && d[j] > temp)
    {
      d[j+1] = d[j];
      j = j - 1;
    }
    d[j+1] = temp;      
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", d[i]);
  }
  exit(0);
}
