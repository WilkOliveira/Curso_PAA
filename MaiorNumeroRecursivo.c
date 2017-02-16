#include <stdio.h>

int maior(int *a, int i, int tam, int m){
    if (a[i] < tam){
        m = maior(a, i+1, tam, m);
        if (m < a[i]){
            return a[i];
        }
        else{
            return m;
        }
    }
}

int main()
{
	int array[10] = {2, 5, 6, 1, 10, 9, 8, 7, 3, 8};

	printf("O maior valor do array e: %d\n", maior(array, 0, 10, 1));

	return 0;
}
