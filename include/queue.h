

typedef struct node {
    int val;
    struct node *next;
} node_t;

void enqueue(node_t **head, char *s);
char *dequeue(node_t **head);
void print_list(node_t *head);
int buscar2(node_t **head, char s[] );
