Ivan Wang
501086429

Everything Worked.

*QUESTIONS:

Suppose that towers(5, 2, 3) is invoked. 

1. How will the first recursive call to towers() be invoked? Answer this
question in the form: towers(x, y, z) where you give the actual values to the
three parameters.

2. How many recursive calls to towers() will be made before this first recursive
call actually returns to the initial invocation?

3. Once towers(5, 2, 3) has invoked its first recursive call to towers() and this
invocation has returned, what will be printed to stdout? (i.e. What actual
move will be made by towers(5, 2, 3) ?)

4. How will the second recursive call to towers() be invoked? Answer this
question in the form: towers(x, y, z) where you give the actual values to the
three parameters. 

5. Suppose that towers(8, 1, 2) is invoked. How many lines will be printed to stdout?

*ANSWERS:

1.  towers(4, 2, 1) will be the first recursive call invoked. 

2.  4 recursive calls will be made as the first recursive call n=4 and decrements by 1 until n=0 and returns back to the initial invocation.

3.  "Move #1: From Tower 1 to Tower 2" (1 2) will be printed to stdout.

4.  towers(3, 2, 3) will be the second recursive call invoked because towers(4,2,1) makes a recursive call to itself leading to the second recursive call of towers(3, 2, 3).

5. 2^8 - 1 = 255 lines will be printed to stdout.

**BUG FIXES & CHANGES (towersMain.c) :

Added #include <stdio.h> 

Added Lines 14 to 31
First added if statement
- Checks seperately for 'from' and 'dest' arguments and changes the variables respectively.
- This if statement is added so that the command still works with one argument.
- If 'from' and 'dest' were not implemented seperately and was combined with "if(argc > 1)" the program would try to read for 'from' and 'dest' arguments that did not exist when users tries to only input one argument which created another bug.
- With this implementation we do not have to worry about this bug as it only reads 'from' and 'dest' arguments if there are more than 2 arguments inputted.

Second added if statement
- Fixes bug where if the inputted 'from' and 'dest' arguments were greater than 3 or less than 1 the program will print an message stating that there are only 3 towers and exit.

Last added if statement
- Fixes bug where if the 'from' input argument was the same as the 'dest' input argument the program will print an message stating that the origin and destination cannot be the same and exit.



