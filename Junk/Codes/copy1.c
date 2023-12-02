
#include <stdio.h>

int match(char *p)
{
   int count = 0;
   for (; *p != '\0'; p++)
   {
      if ((*p) == 'a' || (*p) == 'e' || (*p) == 'i' || (*p) == 'o' || (*p) == 'u')
      {
         count++;
      }
   }
   return count;
}
int main()
{
   char p[30];
   
   scanf("%s",p);

   printf("%d", match(p));
   
   return 0;
}