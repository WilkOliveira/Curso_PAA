#include <stdio.h>
#define TAM 10

int main()
{
    int array[TAM] = {2, 5, 6, 1, 4, 9, 8, 7, 3, 10};
    int arrayEsquerdo[TAM/2];
    int arrayDireito[TAM/2];
    int i=0;
    int j=0;
    int k=TAM/2;
    int l=TAM/2;

    while (i<TAM/2){
        arrayEsquerdo[j]= array[i];
        printf("%d ",arrayEsquerdo[j]);
        i++;
        j++;
    }

    printf("\n");

    while (k<TAM){
        arrayDireito[l]= array[k];
        printf("%d ",arrayDireito[l]);
        k++;
        l++;
    }

	return 0;
}
