#include<stdio.h>
#include<stdlib.h>

struct temp
{
    int x;
    int y;
};

int main()
{
     struct temp *nvoi;

     struct temp *p =(struct temp*)malloc(sizeof(struct temp));
     p->x=3;
     p->y=4;

     nvoi->x=3;
     nvoi->y=99;



    printf("%d",nvoi->x);
    return 0;
} 
