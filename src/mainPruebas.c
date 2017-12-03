#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>
#include <hash.h>
int main(){
   node_t *head = NULL; 
   char *s="carino\n";
   int x='a'*3,acum=0,i=0;
   
   node_t *prueba = malloc(sizeof(node_t));
   strcpy(prueba->val,"cincah");
   enqueue(&head, "hola");
   enqueue(&head, "jello");
   enqueue(&head, "copmcha");
   enqueue2(&head, prueba);
   //printf("%s\n", prueba->val);
   //printf("%d \n ",x);
   print_list(head);
   /*while(free){
      if((*(s+i)!='\0') || (*(s+i)!='\n')){
         break;
      }
      else{
         acum = acum + ((*(s+i)) * (i+1));  
         i++; 
      }   
    
   }*/

   while((*(s+i)!='\0') && (*(s+i)!='\n')){
       printf("%c \n ",*(s+i));
       acum = acum + ((*(s+i)) * (i+1));  
       i++; 
      
   }
   printf("%d \n ",acum);


}
