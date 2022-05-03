#include <sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include"ArvBin_Int.h"



int insere_ArvBin(struct tNode* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct tNode* novo;
    novo = (struct tNode*) malloc(sizeof(struct tNode));
    if(novo == NULL)
        return 0;
    novo->data = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(raiz == NULL)
        raiz = novo;
    else{
        struct tNode *atual = raiz;
        struct tNode *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->data){
                free(novo);
                return 0;
            }

            if(valor > atual->data)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->data)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

void em_Order(struct tNode *root){
    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;

    while (!done)
    {

        if(current != NULL){
            push(&s, current);
            current = current->esq;
        }
        else{
            if (!isEmpty(s)){
                current = pop(&s);
                current = current->dir;
            }
            else
                done = 1;
        }
    }
}

int verificaFolha(struct tNode *no){
    if(no->esq == NULL && no->dir ==NULL){
        return 1;
    }
    return 0;
}
void libera_NO(struct tNode *no){
    if(verificaFolha(no) == 1)
        free(no);
}

int total_Nos(struct tNode *root){
    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = 0;
    int quant = 0;

    while (!done)
    {

        if(current != NULL)
        {
            quant++;
            push(&s, current);
            current = current->esq;
        }
        else
        {

            if (!isEmpty(s))
            {
                current = pop(&s);
                libera_NO(current);
                current = current->dir;
            }
            else
                done = 1;
        }
    }
    return quant;
}


/* UTILITY FUNCTIONS */
void push(struct sNode** top_ref, struct tNode *t){

    struct sNode* new_tNode =(struct sNode*) malloc(sizeof(struct sNode)); //

    if(new_tNode == NULL){
        printf("Stack Overflow \n");
        getchar();
        exit(0);
    }

    new_tNode->t = t;


    new_tNode->prox = (*top_ref);

    (*top_ref) = new_tNode;
    }

/* The function returns true if stack is empty, otherwise false */
bool isEmpty(struct sNode *top){
    return (top == NULL)? 1 : 0;
    }

struct tNode *pop(struct sNode** top_ref){
    struct tNode *res;
    struct sNode *top;


    if(isEmpty(*top_ref)){
        printf("Stack Underflow \n");
        getchar();
        exit(0);
    }
    else{
        top = *top_ref;
        res = top->t;
        *top_ref = top->prox;
        free(top);
        return res;
    }
}



struct tNode* newtNode(int data){
    struct tNode* tNode = (struct tNode*)
            malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->esq = NULL;
    tNode->dir = NULL;

    return(tNode);
    }
float timedifference_msec(struct timeval t0, struct timeval t1){
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
    }

