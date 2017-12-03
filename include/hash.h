#define SIZE 2017
struct DataItem {
   node_t *data;   
   char key[20];
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(char *key);
struct DataItem *search(char *key) ;
struct DataItem *search(char *key) ;
void insert(char *key,node_t *data);
struct DataItem* delete(struct DataItem* item);
void display();

