#include<stdio.h>
#include<stdlib.h>

int Max( int A, int B)
{
    if(A>B) return A;
    return B;
}


// Every Node is a structe containing a value and the adress of the left and right child elements ( We are talking about binary tree here )


struct node
{
    int data;
    struct node * left;
    struct node *right;
};

// Function to create a new node 

struct node * new_node(int data)
{
    struct node * new_node;
    new_node=(struct node *)malloc(sizeof(struct node));

    new_node->data=data;

    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

// Function to print in NLR method

void Print_NLR( struct node * root)
{
    if(root==NULL) return;

    printf("%d ",root->data);
    Print_NLR(root->left);
    Print_NLR(root->right);

}

// Similarly for LNR and LRN  .....
//  NLR : Pre-order   LNR : In-order   Post-order : LRN 


// Function to find the diameter of tree : 
        // Height of a tree is important in this aspect 

        int Height( struct node* node)
        {
            
        }
        {
            struct node* temp;




        }


int Diameter(struct node * node)
{
    if(node==NULL) return ;

    int max;

    max=Ma


}

int main()
{

    // First creating a node with root value 3

    struct node* root;
    root=new_node(3);

    // Now let us add the left and right elements to it

    root->left=new_node(5);
    root->right=new_node(7);

    // Printing the tree normally 
    printf("%d\n%d %d",root->data,root->left->data,root->right->data);

    // Now let us add some more elements to the left and right of the tree and try different printing methods

    root->left->left=new_node(11);
    root->left->right=new_node(13);
    root->right->left=new_node(17);
    root->right->right=new_node(19);

    // Printing using differnet methods

    // clrscr();
    printf("\n");
    Print_NLR(root);

    

    return 0;

}