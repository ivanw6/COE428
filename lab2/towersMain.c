#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;
    if (argc > 1)
    {
        n = atoi(argv[1]);
    }
    if (argc > 2)
    {
        from = atoi(argv[2]);
        dest = atoi(argv[3]);
    }
    if (from < 1 || from > 3 || dest < 1 || dest > 3)
    {
        fprintf(stderr, "Invalid. There are only 3 Towers.\n");
        exit(1);
    }
    if (from == dest)
    {
        fprintf(stderr, "Invalid. Origin and Destination cannot be the same.\n");
        exit(1);
    }
    towers(n, from, dest);
    exit(0);
}
