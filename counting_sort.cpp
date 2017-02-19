/**
* O(n)
*/

#include<iostream>
#include<fstream>

using namespace std;

#define MAX 9

int tam = MAX;
int i, j;

int countingSort(int a[], int b[], int c[]){
    a[tam];
    b[tam+1];
    c[tam];

    for(i=0; i<=tam; i++){
        b[i]=0;
        cout << b[i] << "";
    }
    cout << endl;

    for(i=0;i<tam;i++){
        b[a[i]]+=1;
        cout << b[i] << "";
    }
    cout << endl;

    for(i=0;i<tam;i++){
        b[i]+= b[i+1];
        cout << b[i] << "";
    }
    cout << endl;

    for(j=tam; j>1; j--){
        // para implementar
    }

}

int main()
{
    int a[tam]={5, 4, 3, 6, 5, 2, 4, 8, 1};
    int b[tam+1];
    int c[tam];

    countingSort(a,b,c);

    return 0;
}
