#include<iostream>
#include<fstream>

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
    int i, j;

    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            matrizC[i][j] = matrizA[i][j]+matrizB[i][j];

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
