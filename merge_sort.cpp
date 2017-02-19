/**
* O(n lg n)
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> mergeSort(const vector<int> &vetor)
{
    if (vetor.size() <= 1) {
        return vetor;
    }

    int meio = vetor.size() / 2;
    vector<int> esquerdo(vetor.begin(), vetor.begin()+meio);
    vector<int> direito(vetor.begin()+meio, vetor.end());

    esquerdo = mergeSort(esquerdo);
    direito = mergeSort(direito);

    vector<int> resultado(vetor.size());

    merge(esquerdo.begin(), esquerdo.end(), direito.begin(), direito.end(), resultado.begin());

    return resultado;
}

int main()
{
    int n, x;
    vector<int> a;

    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        printf("Digite a posicao %d do vetor\n", i+1);
        scanf("%d",&x);
        a.push_back(x);
    }

    printf("\n");
    printf("Vetor ordenado: ");

    vector<int> resultado = mergeSort(a);
    for (int i = 0; i < resultado.size(); ++i)
    {
        printf("%d ", resultado[i]);
    }

    return 0;
}
