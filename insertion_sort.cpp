/**
* O(n^2)
*/

#include<iostream>
#include<fstream>

using namespace std;

#define MAX 10

int tam = MAX;

int * insertionSort(int array[], int tam) {

    for(int i=1; i < tam; i++) {
		int chave = array[i];
		int j = i - 1;
		while((j >= 0) && (array[j] > chave)) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = chave;
	}

	for(int k=0; k<tam; k++){
        printf("%d", array[k]);
	}

}

int main()
{

    int array[tam] = {2, 6, 3, 7, 5, 9, 6, 3, 1, 3};
    insertionSort(array, tam);

    return 0;
}
