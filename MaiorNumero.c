#include <stdio.h>

int maior(int *a, int i, int tam, int m)
{
    for (i=0; i<tam; i++){
        if (a[i] >= m){
            m = a[i];
        }
    }
    return m;
}

int main()
{
	int array[10] = {2, 5, 6, 1, 4, 9, 8, 7, 3, 4};

	printf("O maior valor do array e: %d\n", maior(array, 0, 10, 1));

	return 0;
}
