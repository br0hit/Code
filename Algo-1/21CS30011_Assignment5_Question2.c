/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Question 02: Printing the nth-hop away nodes
 
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node* left;
	struct node* right;

};

struct node* createNode(int key)
{
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));

	temp->key=key;

	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

// Defing a function Max_height to find the maximuim number of hops possible for a given tree

int Max_height(struct node* node)
{

	// Using recusrion to find maximum height


    if (node == NULL)
        return 0;

    else 
    {
        // Solve the left and right subtree

        int Depth1 = Max_height(node->left);
        int Depth2 = Max_height(node->right);
 
        if (Depth1 > Depth2)
            return (Depth1 + 1);
        else
            return (Depth2 + 1);
    }
}

// For storing the values of the n-1th hop let us define a global 2D array in which the the nth Row consists the values of the nth hop

 int data[50][50];
 int z;


int check_prev_hop(struct node * root)
{

}

// Printing all the nodes which are 0 hop away : 

// void hops_0(struct node* root)
// {
// 		//	   printf("***\n");

// 	if( ((root->left!=NULL) && (root->left->left== NULL && root->left->right== NULL)) || ((root->right!=NULL) &&(root->right->left== NULL && root->right->right== NULL)) )
// 	{
// 		printf("%d, ",root->key);

// 	}

// 	if(root->left!=NULL) hops_0(root->left);
// 	if(root->right!=NULL) hops_0(root->right);

// }

void hops(struct node* root, int n)
{
	int i;

	if(n==0)
	{
		// To find the elements which are 0-hops away from the leaf ; we need to find all the nodes such that if we transverse twice along the leaf we get a NULL pointer

		if( ((root->left!=NULL) && (root->left->left== NULL && root->left->right== NULL)) || ((root->right!=NULL) &&(root->right->left== NULL && root->right->right== NULL)) )

		{
			printf("%d ",root->key);

			data[0][z]=root->key;
			z++;
		}

		if(root->left!=NULL) hops(root->left,n);
		if(root->right!=NULL) hops(root->right,n);
	}

	else
	{
		if(root->left!=NULL)
		{
			for(i=0;data[n-1][i]!=-999;i++)
			{
				if(root->left->key==data[n-1][i])
				{
					printf("%d ",root->key);
					data[n][z]=root->key;
					z++;
				}
			}
		}

		if(root->right!=NULL)
		{
			for(i=0;data[n-1][i]!=-999;i++)
			{
				if(root->right->key==data[n-1][i])
				{
					printf("%d ",root->key);
					data[n][z]=root->key;
					z++;
				}
			}
		}

		if(root->left!=NULL) hops(root->left,n);
		if(root->right!=NULL) hops(root->right,n);
	}
}


int main()
{
	// Considering the same tree as the one shown in the Question 

		// Creating the tree : 

	struct node* root;
	root = createNode(10);

	root->left = createNode(7);
	root->right = createNode(2);
	root->left->left = createNode(11);
	root->right->left = createNode(5);
	root->right->right = createNode(16);
	root->left->left->right= createNode(17);
	root->right->right->left = createNode(9);
	root->right->right->right = createNode(21);


	// First let us initialize the global array to some random value 
	// ** Note : We are assuming this random value -999 does not appear in the key value of the ndoes


	int i,j;

	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++) { data[i][j]= -999; }
	}

		
		// Finding the maximum number of hops possible : 

		int max_hops;

		max_hops= Max_height(root)-1;

		// As here the hops are starting from 0


	/* Logic :

		Maximum number of hops will be equal to the maximum depth of the leaf 

		For finding the maximum height let us define a function named Max_height

		For finding the nth hop away node from a particular leaf we now that if we transverse the node (n+1 )times
		in the direction of the leaf then we get a NULL value on both left and right side 

		Ex : Let us consider the branch of 17 , 11 , 7

		Now to find the 1 hop away from 17 instead of equating 2 transverse = NULL, we can just equate 1 transverse = 0 hop value

		Therefore ; We can basically use the n^th hop values to find the n+1^th hop values

	*/

		// Printing the nth hop away nodes from the leaf nodes : 


		for(i=0;i<max_hops;i++)
		{
			z=0;

			printf("%d-hop away nodes from the leaf nodes: ",i);
			hops(root,i);
			printf("\n");
		}

		return 0;

}
