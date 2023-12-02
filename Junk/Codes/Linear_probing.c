//implemention of hashing in using linear probing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define SIZE 10
int hashTable[SIZE];//table initialized to 0
int hashCode(int key)
{
    return key % SIZE;
}
int search(int key)
{
    int hashIndex = hashCode(key);//10+>0
    int counter = 0;
    while(counter<SIZE){
        if(hashTable[hashIndex]==key)
            return hashIndex;
        ++counter;
        ++hashIndex;
        hashIndex%=SIZE;
    }
    return -1;//if not found
}
void insert(int key)
{
    int hashIndex = hashCode(key);
    int counter = 0;
    while(counter<SIZE){
        //if we find an empty spot insert there
        if(hashTable[hashIndex]==0){
            hashTable[hashIndex]=key;
            return;
        }// else move on to the next position XD
        ++counter;
        ++hashIndex;
        hashIndex%=SIZE;
    }
    //if we reach here that means the table is full
    printf("Hash table is full! did not insert key");
}
void delete(int key){
    int hashIndex=search(key);
    if(hashIndex==-1){
        printf("Key not found");
        return;
    }
    hashTable[hashIndex]=0;
}
void display(){
    int i;
    //display heading
    printf("Index\tValue\n");
    for(i=0;i<SIZE;i++){
        if(hashTable[i]!=0)
            printf("h[%d]=%d\n",i,hashTable[i]);
    }
}
int main (){
    //driver code
    insert(12);
    insert(25);
    insert(35);
    delete(25);
    insert(102);
    insert(26);
    display();
    return 0;
}