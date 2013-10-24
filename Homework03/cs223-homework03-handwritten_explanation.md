In this assignment you will create two separate programs (**avltree** and **btree**) that have a common theme: to read a file containing ASCII text of names of people. The file name should be specified on the command line as an argument. Each line should contain a name.

> **Billy Bob**
> **Johnny Sue**
> **Sarah**

Each line is considered to only contain a single name (spaces and other ASCII characters are considered valid for that name). I.E. each line can be considered to be unique and no parsin is required.

## 1. **(50 Points)**
The program should build an AVL Tree from this input. The program would be run as:

> **avltree filename.txt**

After the file is read and the tree is constructed, the program should accept user input (case insensitive):

- PRINT
    - Prints all names in tree using breadth first approach. Each name should be printed on a separate line.
- HEIGHT
    - Prints the maximum height of the tree.
- FIND
    - Finds tthe name, and prints the name followed by the balance factor of the node containing the name. The name and the balance factor should be separated by a comma. Right sub-tree heights are always positive.  
        - Sarah, 1

## 2. **(50 Points)**

This program should build a B-Tree from this input. This program should also accept the order of the B-Tree as the second argument. The program whould be run as:

> btree filename.txt 4

The tree would construct an order 4 B-Tree. After the file is read and the tree is constructed, the program should accept user input (case insensitive):

- PRINT
    - Prints all anmes in tree using a **depth** first approach (i.e. all the names should be printed in alphabetical order). Each name shoul dbe printed on a separate line.
- HEIGHT
    - Prints the maximum height of the tree
- FIND
    - Finds the name, and prints and names contained in the tree node. Names should be displayed on separate lines and in order.

> Johnny Sue
> Sarah
> Tom

