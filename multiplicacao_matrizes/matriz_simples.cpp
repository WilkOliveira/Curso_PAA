#include<iostream>
#include<fstream>

using namespace std;

#define MAX 3

int main()
{
    int matriz[MAX][MAX]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j;

    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d\n", matriz[i][j]);
        }
    }

    return 0;
}
