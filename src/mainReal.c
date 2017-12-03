
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>
struct arrChar{
char string[10];
};

int main(){

 char ifilename[]= "entrada.txt";
    node_t *head = NULL;
    int tamanio=0; int tamanioMax=10; int hits=0; int fails=0;
    
    struct arrChar aux;int i=0,j=0,res; *aux.string=""; char *devf="";

    FILE *ifp;
    ifp=fopen(ifilename,"r");
    while (devf!=NULL)
       {
     
          
           devf = fgets(aux.string,10,ifp);
           if (devf!=NULL){
              j++;
               
              if(buscar2(&head,devf)==1){
                  enqueue(&head, devf);
                  hits++;
  

              }
              else if(tamanio>=tamanioMax){
                 dequeue(&head);
                 enqueue(&head, devf);
                 fails++;
                 
                  
              }
              else{
                  enqueue(&head, devf);
                  tamanio++;
                  fails++; 
     

              }
              
              
              //printf(" %s \n",devf); 
              
 
           } 

           else{
            
           }   
                 
 
        
        
        ;
        
       } 

    printf("Accesos: %d \n",j);
    printf("Hits: %d \n",hits);
    printf("miss: %d \n",fails);
    print_list(head);
    fclose (ifp);  


   return 0;
   

  

}
