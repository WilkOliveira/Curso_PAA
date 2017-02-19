/**
* O(n^2)
*/

#include<iostream>
#include<fstream>

using namespace std;

#define MAX 10

int tam = MAX;

int * insertionSort(int a[], int tam) {

    for(int i=1; i < tam; i++) {
		int chave = a[i];
		int j = i - 1;
		while((j >= 0) && (a[j] > chave)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = chave;
	}

	for(int k=0; k<tam; k++){
        printf("%d", a[k]);
	}

}

int main()
{

    int a[tam] = {2, 6, 3, 7, 5, 9, 6, 3, 1, 3};
    insertionSort(a, tam);

    return 0;
}
