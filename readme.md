# Trees and points

This project was dev by Sylvia Lehmann and Nicolas Gayet

## Introduction

Here, we implemented a point storage in a binary tree structure.

Instructions were:
- Make arbre.h (arbre = tree) with a structure of binary tree to store the points.
- In a arbre.c:
  + implement an insert function where we put points ordered according to the distance from origin order,
  + implement a delete function,
  + implement a print function,
  + implement a test function to test the code.

- Make a fifo based on a circular table, who can store nodes of a tree.
- Make a print with a traversal using fifo structure.

## Feature

We can add a point to the tree.  
We can generate random points with coordinates x, y and z ranging from 0 to 5.  
We can delete a point.  
We can print the tree in natural order. (depth-first order)  
We can know if a point is present.  
We can print the tree like a real tree.  
We can reset the whole tree.  

The "print like a real tree" feature print the point like this: distance from origin time 10, truncated to integer. We print only the first 6 lines to prevent terminal width limit.

## Note

We have setup comments to generate html documentation through Doxygen.
Please, run your terminal in full screen mode for the pretty print of the tree.
