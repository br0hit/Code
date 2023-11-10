/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   // Lab Test 02

   Question 01: Mirror the odd levels of a perfect binary tree 

*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;

	int height;

};

struct node* createNode(int data)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));

	temp->key=data;

	temp->left=NULL;
	temp->right=NULL;

	return temp;
}


struct node* create_tree(int A[])
{
	struct node* root=createNode(A[0]);

	root->left = createNode(A[1]);
	root->right = createNode(A[2]);
	root->left->left = createNode(A[3]);
	root->left->right = createNode(A[4]);	
	root->right->left = createNode(A[5]);
	root->right->right = createNode(A[6]);
	root->left->left->left= createNode(A[7]);	
	root->left->left->right= createNode(A[8]);
	root->left->right->left= createNode(A[9]);
	root->left->right->right= createNode(A[10]);
	root->right->left->left= createNode(A[11]);	
	root->right->left->right= createNode(A[12]);
	root->right->right->left= createNode(A[13]);
	root->right->right->right= createNode(A[14]);


	return root;

}

// Function to assign heights of the nodes

void Assign_height(struct node* root)
{
	if(root->left!=NULL) root->left->height=1+root->height;
	if(root->right!=NULL) root->right->height=1+root->height;


	if(root->left!=NULL) Assign_height(root->left);
	if(root->right!=NULL) Assign_height(root->right);

}

void probe(struct node* root, int height)
{

	if(root->height==height) printf("%d ",root->key);

	if(root->left!=NULL) probe(root->left,height);
	if(root->right!=NULL)probe(root->right,height);
}


void Level_Order_transversal(struct node* root,int h_max)
{
	int height=0;
	int i;

	h_max=3;

	for(i=0;i<h_max+1;i++)
	{
		probe(root,height);
		height++;
	}

}

void Mirror_Tree(struct node* root)
{
	/* Logic : 
		Go to each odd height which we found out using the heigt function and then find the compliment for each of the elements at the same odd height  and then transverse the tree and then 
		 interchange them */
}

int main()
{
	// Let the Array containing the Input elements be A 

	int A[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	// Function used to create a tree and return the pointer of the root :

	struct node* root;

	root=create_tree(A);
	root->height=0;

	// Assigning height to the nodes :

	Assign_height(root);

	// Printing the Level Order Transversal of the tree :
	int h_max;

	h_max=3;

	Level_Order_transversal(root,h_max);

	return 0;
}
