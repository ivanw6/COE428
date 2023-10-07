Ivan Wang
501086429

***
Generated State Machine:
A E C
B C H
C F A
D A B
E D F
F G F
G B H
H D E

Your starting state is: B
***

The file "FSM_Diagram.pdf" is the drawing of my state machine diagram.

No Commands: Works.

One/Zero Commands: Works

Change command: Works.

Print command: Works.

Garbage Identify command: Works.

Delete command: Only works for if 'd' is invoked alone. Did not figure how to get the second line argument to read into the switch case so the delete command only works for solo invoked 'd'.
Still if 'd' is inputted, it does delete the indentified garbage and prints out "Deleted: <deleted state>" and if there are no states that are garbage then it will print out "No states deleted."
Note> The delete command leaves behind an empty space because the way I implemented the deletion of the garbage state is setting each index (name, zero, one) to a blank character - was not sure how to delete the state in any other way.
