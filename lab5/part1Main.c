#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char *argv[])
{
  int ch;
  int popped;
  while ((ch = getchar()) != EOF)
  {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
    {
      continue;
    }
    else if (ch == '<') //checks if the start character is '<'
    {
      ch = getchar(); //get the next character
      if (isalpha(ch)) //checks to see if the next character is letter
      {
        push(ch); //if so, push character to stack
      }
      else if (ch == '/') //checks if the next character is '/'
      {
        ch = getchar(); //get the character after '/'
        popped = pop(); //pop a character from stack

        if (popped != ch) //if the popped character is not equal to character after '/', then it is invalid
        {
          fprintf(stderr, "INVALID!\n");
          exit(1);
        }
        else //otherwise it is valid
        {
          fprintf(stdout, "VALID!\n");
          exit(0);
        }
      }
    }
  }
  exit(0);
}