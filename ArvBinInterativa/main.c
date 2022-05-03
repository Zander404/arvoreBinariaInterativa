#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "ArvBin_Int.h"

int main()
{
    struct timeval t0;
    struct timeval t1;
    float elapsed;

    int flag = 10000;

    struct tNode *root = newtNode(1);

    for(int i = 0 ; i< 50000;i++) {
        insere_ArvBin(root, rand());
        if(i == flag){
            printf("foi 10.000 %d\n",i);
            flag += 10000;
        }
    }


    gettimeofday(&t0, 0);


    em_Order(root);

    gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);

    printf("\nCodigo executado em   %f millisegundos.\n", elapsed);
    return 0;
}