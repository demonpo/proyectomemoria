#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue.h>
#define SIZE 2017

struct DataItem {
   node_t *data;   
   char key[20];
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(char *key) {
   int i=0;
   int acum=0;
   printf("llego\n");
   while( (*(key+i)!='\0') && (*(key+i)!='\n') ){
      acum = acum + ((*(key+i)) * (i+1)); 
      i++;    
   }
   printf("termino: %d \n",acum % SIZE);
   return acum % SIZE;
}

struct DataItem *search(char *key) {
   //get the hash 
   int hashIndex = hashCode(key);  
   
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(strcmp(hashArray[hashIndex]->key,key) == 0)
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(char* key,node_t *data) {

   struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
   item->data = data;  
   strcpy(item->key,key);

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && strcmp(hashArray[hashIndex]->key,"dumm") != 0) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
   char key[20];
   printf("*\n");
   strcpy(key, item->key);
   //get the hash 
   int hashIndex = hashCode(key);
    printf("*\n");
   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(strcmp(hashArray[hashIndex]->key,key) == 0) {
         struct DataItem* temp = hashArray[hashIndex]; 
	 		
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%s)",hashArray[i]->key,hashArray[i]->data->val);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

/*int main() {
   dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
   dummyItem->data = -1;  
   dummyItem->key = -1; 

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
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search(37);

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
}*/
