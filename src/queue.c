#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    char val[20];
    struct node *next,*previus;
} node_t;

void enqueue(node_t **head, char s[]) {
    node_t *current;
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) return;

    
    strcpy(new_node->val, s);
    //new_node->val = val;
    new_node->next = *head;
    if(*head==NULL){
        printf("NULL\n");
    }
    else{
        (*head) -> previus = new_node;
        //printf("previus: %s\n", (*head) -> previus->val);
    }
    new_node->previus=NULL;
    
   
   
   
   
    

    *head = new_node;
}

void enqueue2(node_t **head, node_t *nuevo) {
    node_t *new_node = nuevo;
    if (!new_node) return;

    new_node->next = *head;
    if(*head==NULL){
        printf("NULL\n");
    }
    else{
        (*head) -> previus = new_node;
        printf("previus: %s\n", (*head) -> previus->val);
    }
    new_node->previus=NULL;
    
   

    *head = new_node;

}

const char *dequeue(node_t **head) {
    node_t *current, *prev = NULL;
    static char retval[20] = "";

    if (*head == NULL) return "0";

    current = *head;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    strcpy(retval, current->val);
    //retval = current->val;
    printf("retval= %s \n",  retval);
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;
    //printf("retval= %s \n",  retval);
    return retval;
}

/*void buscar(node_t *head, char s[] ){
    node_t *current = head;

    while (current != NULL) {
        if(current->val == s ){

           printf("encontrado: %s\n", current->val);
           return 0;
           
        }
        current = current->next;
    }

	

   printf("no se encontro nada\n");

}*/
int buscar2(node_t **head, char s[] ){
    node_t *current, *prev = NULL,*primernodo;
    node_t *temp;
    primernodo=*head;
    int retval = -1;

    if (*head == NULL) return -1;
    
    current = *head;
    while (current->next != NULL) {
	if(strcmp(current->val,s) == 0 ){
           
           temp=current;
           //printf("temp: %d\n", temp->val);
           prev->next=(current->next);
           //printf("temp: %d\n", temp->val);
           printf("encontrado: %s\n", current->val);
           

           
           return 1;
           
        }
        prev = current;
        current = current->next;
    }

    return 0;
/*
    retval = current->val;
    free(current);
    
    if (prev)
        prev->next = NULL;
    else
        *head = NULL;

    return retval;*/
}


void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%s\n", current->val);
        
        current = current->next;
       
    }
   /*current=current->previus;
   printf("%s\n", current->val);
   while (current != NULL) {
        printf("%s\n", current->val);
        
        current = current->previus;
        
    }*/




}
