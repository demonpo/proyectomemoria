

typedef struct node {
     char val[20];
    struct node *next,*previus;
} node_t;

void enqueue2(node_t **head, node_t *nuevo) ;
void enqueue(node_t **head, char *s);
const char *dequeue(node_t **head);
void print_list(node_t *head);
int buscar2(node_t **head, char s[] );
