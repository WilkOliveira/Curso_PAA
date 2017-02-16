#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>

using namespace std;

#define MAX 3

vector< vector<int> > ikjalgoritmo(vector< vector<int> > A,
								   vector< vector<int> > B,
								   vector< vector<int> > &C, int n) {

					for (int i = 0; i < n; i++) {
                            for (int k = 0; k < n; k++) {
                                for (int j = 0; j < n; j++) {
                                    C[i][j] += A[i][k] * B[k][j];
                                }
                            }
                    }
            return C;
}

void mostrarMatriz(vector< vector<int> > matriz, int n){
    for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                if (j != 0) {
                cout << "\t";
                }
            cout << matriz[i][j];
            }
        cout << endl;
    }
}

int main()
{
    int tam = MAX;

    int matrizA[MAX][MAX]={1, 2, 3,
                           4, 5, 6,
                           7, 8, 9};

    int matrizB[MAX][MAX]={9, 8, 7,
                           6, 5, 4,
                           3, 2, 1};

    int matrizC[MAX][MAX];

    ikjalgoritmo(matrizA, matrizB, matrizC, tam);
    mostrarMatriz(matrizC, tam);

    return 0;
}
