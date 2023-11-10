/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Question 01: Printing the inOrderSuccessor for each node

   printf("***");
 
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;

	struct node* inOrderSuccessor;
};

// Utility function :
		// Used to find the key of the leftmost element from the node

struct node* Left_end(struct node* root)
{
	if(root->left==NULL)
	{
		return root;
	}

	else 
	{
			while(root->left!=NULL)
		{
			root=root->left;
		}

		return root;
	}
}

struct node* createNode(int data)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));

	temp->key=data;

	temp->left=NULL;
	temp->right=NULL;

	temp->inOrderSuccessor=NULL;

	return temp;
}

void inorder(struct node* root, struct node* prev, int val)
{

	if(val==0 && root->right!=NULL)
	{
		    // struct node* prev;
    		// prev = (struct node*)malloc(struct node);

  	  root->inOrderSuccessor=Left_end(root->right);
      // return;

      prev=root;

     // printf("%d \n",count1++);

	}

	if(val==1 )
	{
		root->inOrderSuccessor=prev;
		prev=root;

		//printf("%d \n",count2++ );
	}

      if(root->right!=NULL) inorder(root->right,prev,0);

      if(root->left!=NULL ) inorder(root->left,prev,1);

}

int main()
{
	 //  printf("***\n");


	// First Creating the tree using the input

	struct node * root;
	root= createNode(5);

	root->left = createNode(9);
	root->right = createNode(7);
	root->left->left = createNode(3);
	root->right->left = createNode(4);
	root->right->right = createNode(1);
	root->right->right->left = createNode(6);
	root->right->right->right = createNode(2);


	// Filling the pointer of the InOrderSuccessor :

	  // First filling the pointer inOrderSuccessor for each node :

	struct node* prev;
	prev= (struct node*)malloc(sizeof(struct node));


		inorder(root,prev,0);

		// Printing them starting from the left end :

	struct node *temp;  // As the inOrder Transversal starts from the left end of the tree we first find the pointer to that particular node

	temp= Left_end(root->left);


	// Printing :

	while(temp->inOrderSuccessor!=NULL)
	{
		printf("The inorder successor of %d is %d\n",temp->key,temp->inOrderSuccessor->key);

		temp=temp->inOrderSuccessor;

	} 

	return 0;
}
