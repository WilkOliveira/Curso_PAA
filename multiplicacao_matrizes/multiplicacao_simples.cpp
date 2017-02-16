#include<iostream>
#include<fstream>
#include <stdio.h>

using namespace std;

#define MAX 3

int main()
{
    int matrizA[MAX][MAX]={1, 2, 3,
                           4, 5, 6,
                           7, 8, 9};

    int matrizB[MAX][MAX]={9, 8, 7,
                           6, 5, 4,
                           3, 2, 1};

    int matrizC[MAX][MAX];
    int i, j, k = 0;

    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            for(k=0;k<MAX;k++){
                matrizC[i][j] = matrizC[i][j] + matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    for (i=0; i<MAX; i++) {
        for (j=0; j<MAX; j++) {
            printf("%d ", matrizC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
