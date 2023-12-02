#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

// Seperate_chaining is creating a array of linked lists to store the data

struct node
{
    int key;
    int value;

    struct node* next;
};

// Creating an array of of linked lists to store the values ; This array is called hashtable as it stores all the data after the index is obtained from the hash function

struct node* hashTable[SIZE];

// struct node** hashTable;
// hashTable= (struct node **)malloc(SIZE*sizeof(struct node*));  // -- THIS DOES NOT WORK, Don't know why



// Creating the hash function which will give the index on which the data is stored in the hashTable once we supply it the key

int hash_function(int key)
{
    return key%SIZE;
}


// Creating a insert function which will insert a new data into the hashTable

void insert(int key, int value)
{
    struct node* new_node;
    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->key=key;
    new_node->value=value;
    new_node->next=NULL;

    int hash_index;
    hash_index=hash_function(new_node);

    struct node* temp;

    temp=hashTable[hash_index];

    if(temp==NULL) { temp= new_node ;}

    else
    {
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new_node;
    }
}

// Function to print the complete hashTable

void print_hashTable()
{
    int i;

    for(i=0;i<SIZE;i++)
    {
        if(hashTable[i]==NULL) printf("----\n");
        else
        {
            struct node* temp;
            temp=hashTable[i];

            while(temp->next!=NULL)
            {
                printf("%d-->\n",temp->value);
            }
        }
    }
}

// Searching for a particular value in the hashTable

void search(int key)
{
    int hash_index;
    hash_index = hash_function(key);

    if(hashTable[hash_index]!=NULL) printf("Data found\n");
    else
    {
        struct node* temp;
        temp=hashTable[hash_index];

        while(temp!=NULL)
        {
            if(temp->key==key) printf("Data found\n");
            temp=temp->next;
        }
    }
}

void delete(int key)

