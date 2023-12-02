Tree- Collection of **nodes** starting at the root node and ending at the leaf node

Nodes connected to Childs via edges ( The connecting link between 2 nodes is called a edge)
No node points back to the root node - Meaning : child of any node must not be root node
	Siblings: All the nodes descending from the same parent 
	Degree:  The number of children of a node ( Leaf Degree : 0)
	Level:   **Root node level : 0**, Then increase each level by 1
	Length of a path : The number of edges it  covers ; Depth of a node is the length of  the path from the root  ( Depth of root is 0)
	**Depth and Height**  : Depth is the distance from the root node whereas the height is the distance from the leaf



Binary tree : Each node has at most 2 children
	**Full binary tree** : Each node has either 0 elements or 2
	Complete binary tree : 
	![[Pasted image 20221011193028.png | 450]]
	**Perfect binary tree** :  All leaves have same depth and all internal nodes have two childern ( It is perfectly symmetric)
	![[Pasted image 20221011214206.png | 500]]


## Balanced binary tree : Height of the tree is 0(logn) 
 Provide 0(logn) time for search, insert and delete 
 Examples are : AVL , Red-Black trees

Implementing a binary tree :
	Binary tree has 3 parts :
		1. Data for that particular node
		2. Address of the left child and the right child

	![[Pasted image 20221011215116.png | 500]]

There is no particular order in which the binary tree can be transverse so we define some types of transversal : NLR , LNR, LRN
### NLR : Pre-order
### LNR : In-order
### LRN : Post-order

**Remember them from the position in which the node is printed** 
Each of them  is just a recursive function 
 ex:  
	 ![[Pasted image 20221012010119.png]]


# Binary Search Trees

A binary tree in which  every node has a value at every node : 
	value of every node to every node on the left is less than the value at that node and value of every node on the right of the node is greater than the value of that node 



## Inserting in a binary search tree


![[Pasted image 20221012023152.png]]

##### Finding the maximum diameter of a tree
## Removing a node from a binary tree 


