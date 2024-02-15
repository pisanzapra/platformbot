#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>     

int main (int argc, char *argv[])
{

 int randSayi;
 int i;
 int a;
 
  srand (time(NULL));

   
   if(argc < 2){  
      printf("Komut Satırına Herhangi Bir Argüman Girilmedi.\n");  
   }  
   else {
    a = atoi(argv[1]);
    for (i = 0; i < a; i++) 
     
     {
     
     randSayi = rand() % 10000 + 1;
     
     printf("%d \n", randSayi);
     
     }
   }
   
   
  return 0;
}
