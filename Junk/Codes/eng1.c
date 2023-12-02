#include <stdio.h>
int main(){unsigned int n,i;scanf("%d",&n);i=n;while(1){if(i%n%1000==0){printf("%d",n%1000);break;}n=n/10;}}