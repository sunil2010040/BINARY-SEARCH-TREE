# BINARY-SEARCH-TREE

Binary Search Tree is a node-based binary tree data structure which has the following properties:

The left subtree of a node contains only nodes with keys lesser than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
The left and right subtree each must also be a binary search tree.


INSERTION:
Check the value to be inserted (say X) with the value of the current node (say val) we are in:
If X is less than val move to the left subtree.
Otherwise, move to the right subtree.
Once the leaf node is reached, insert X to its right or left based on the relation between X and the leaf node’s value.

SEARCHING:
Start from the root. 
Compare the searching element with root, if less than root, then recursively call left subtree, else recursively call right subtree. 
If the element to search is found anywhere, return true, else return false. 
