#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define SIZE 10
struct node
{
    int key;
    int value;
    struct node *next;
};
struct node *hashTable[SIZE];
int hashCode(int key)
{
    return key % SIZE;
}
struct node *search(int key)
{
    int hashIndex = hashCode(key);
    struct node *temp = hashTable[hashIndex];
    while (temp != NULL && temp->key != key)
        temp = temp->next;
    return temp;
}
void insert(int key, int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    int hashIndex = hashCode(key);
    if (hashTable[hashIndex] == NULL)
        hashTable[hashIndex] = newNode;
    else
    {  
        //separate chaining put at the end of the list
        struct node *temp = hashTable[hashIndex];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void delete (int key)
{
    int hashIndex = hashCode(key);
    struct node *temp = hashTable[hashIndex];
    struct node *prev = NULL;
    if (temp == NULL)
        return;
    while (temp->next != NULL && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp->key == key)
    {
        if (prev == NULL)
        {
            hashTable[hashIndex] = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        free(temp);
    }
}
void display()
{
    int i = 0;
    for (i = 0; i < SIZE; i++)
    {
        printf("(%d):", i);
        struct node *temp = hashTable[i];
        while (temp != NULL)
        {
            printf(" -> %d", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    display();
    delete (37);
    delete (4);
    //print a gap
    printf("\n");
    display();
    return 0;
}