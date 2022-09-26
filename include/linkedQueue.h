struct Node
{
    int val;
    struct Node *next;
};

struct LinkedQueue
{
    struct Node *head;
    struct Node *tail;
    int qtdade;
};