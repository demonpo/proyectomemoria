#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue.h>
#include <hash.h>
struct arrChar{
char string[10];
};

int main(){
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->data = NULL;  
    strcpy(dummyItem->key,"dumm"); 
    const char *s;
    char ifilename[]= "entrada.txt";
    node_t *head = NULL;
    node_t *temp1, *temp2;
    int tamanio=0; int tamanioMax=10; int hits=0; int fails=0;
    
    struct arrChar aux;int i=0,j=0,res; *aux.string=""; char *devf="";

    FILE *ifp;
    ifp=fopen(ifilename,"r");
    while (devf!=NULL)
       {
     
          
           devf = fgets(aux.string,10,ifp);
           if (devf!=NULL){
              j++;
               
              if(search(devf)!=NULL){
                  printf("busqueda\n");
                  temp1=search(devf)->data;
                  printf("busqueda2\n");
                  if(temp1->previus==NULL){
                      printf("temp1 previus: NULL\n"); 
                  }
                  if(temp1->next==NULL){
                      printf("temp1 next: NULL\n"); 
                  }
                  printf("%s\n",temp1->val);
                  temp1->previus->next=temp1->next;
                  temp1->next->previus=temp1->previus;
                  printf("busqueda3\n");
                  enqueue2(&head, temp1);
                  hits++;
  

              }
              else if(tamanio>=tamanioMax){
                 printf("dequeue\n");
                 node_t *esto= malloc(sizeof(node_t));
                 strcpy(esto->val,devf);
                 s=dequeue(&head);
                 printf("dequeue2\n");
                
                 
                 
                 printf("dequeue: %s\n",s);
                 if (search(s)==NULL){
                    printf("NULL\n");

                 }

                 delete(search(s));
                 printf("dequeue3\n");
                 
                 enqueue2(&head, esto);
                 insert(devf,esto);
                 fails++;
                 
                  
              }
              else{ 
                  printf("insercion\n");
                  node_t *esto2= malloc(sizeof(node_t));
                  strcpy(esto2->val,devf);
                  enqueue2(&head, esto2);
                  insert(devf,esto2);
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
