#include <stdio.h>

int buscaSimples(int *a, int i, int tam, int x){

    for(i=0; i<tam; i++){
        if(a[i] == x){
            return 1;
        }
        else{
            return -1;
        }
    }

}

int main()
{
    int array[10] = {2, 5, 6, 1, 4, 9, 8, 7, 3, 10};
    int procurado = 2;
    printf("Resultado %d\n",buscaSimples(array, 0, 10, procurado));

	return 0;
}
