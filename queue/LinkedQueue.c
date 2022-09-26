struct LinkedQueue* initLinkedQueue() {
    struct LinkedQueue* fila;
    fila = (struct LinkedQueue*) malloc(sizeof(struct LinkedQueue));
    fila->qtdade = 0;
    fila->tail = NULL;
    fila->head = NULL;
    return fila;
}

struct Node* alocarNovoNo(int valor) {
    struct Node* cabeca = (struct Node*) malloc(sizeof(struct Node));
    cabeca->val = valor;
    cabeca->next = NULL;
    return cabeca;
}

bool vazia(struct LinkedQueue* fila) {
    if( fila == NULL || fila->qtdade == 0){
        return true;
    }
    else{
        return false;
    }
}

//se a fila estiver nula, instancie a fila
//por causa da possibilidade de instanciacao usamos struct LinkedQueue**
void enfileirar(struct LinkedQueue** fila, int val) {
    if( (*fila) == NULL || (*fila)->qtdade == 0){
        (*fila) = initLinkedQueue();
        (*fila)->head = alocarNovoNo(val);
        (*fila)->tail = (*fila)->head;
    }
    else{
        struct Node* cabeca = (*fila)->tail;
        cabeca->next = alocarNovoNo(val);
        cabeca = cabeca->next;
        (*fila)->tail = cabeca;
    }
    (*fila)->qtdade++;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
//lembrem de desalocar o nó removido (free)
int desenfileirar(struct LinkedQueue* fila) {
    if ( fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        struct Node* aux = fila->head;
        int tmp = aux->val;
        if(aux->next != NULL){
            aux = aux->next;
            free(fila->head);
            fila->head = aux;
        }
        else{
            fila->head = NULL;
            fila->tail = NULL;
            free(fila->head);
        }
        fila->qtdade--;
        return tmp;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int head(struct LinkedQueue* fila) {
    if ( fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        return fila->head->val;
    }
}

void imprimirLista(struct LinkedQueue* fila) {
    //usamos o aux para percorrer a lista
    if (fila->head != NULL) {
        struct Node* aux = fila->head;
        //navega partindo da cabeça até chegar NULL
        printf("_\n");
        do {
            printf("%d", aux->val);
            aux = aux->next;
            if (aux != NULL) {
                printf("\n ");
            }
        } while (aux != NULL);
        printf("\n_\n");
    }
    else {
        printf("A lista está vazia!");
    }
}
Footer
