#include "stdlib.h"
#define bool int

struct tNode
{
    int data;
    struct tNode* esq;
    struct tNode* dir;
};

struct sNode
{
    struct tNode *t;
    struct sNode *prox;
};

struct tNode *pop(struct sNode** top_ref);
bool isEmpty(struct sNode *top);
void push(struct sNode** top_ref, struct tNode *t);


int insere_ArvBin(struct tNode* raiz, int valor);
void libera_NO(struct tNode *no);
int verificaFolha(struct tNode *no);
int total_Nos(struct tNode *root);
void em_Order(struct tNode *root);


float timedifference_msec(struct timeval t0, struct timeval t1);
struct tNode* newtNode(int data);
