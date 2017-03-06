#include <bits/stdc++.h>

using namespace std;

int countZeros(vector<int> &vetor)
{

    if(vetor.back() == 1){
        return 0;
    }

    else{
        if(vetor.size() >= 2){
            int meio = vetor.size() / 2;
            vector<int> esquerdo(vetor.begin(), vetor.begin()+meio);
            vector<int> direito(vetor.begin()+meio, vetor.end());

            return countZeros(esquerdo) + countZeros(direito);

        }
        else{

            return 1;
        }
    }
}

int main()
{
    int n, x, t;

    printf("Digite a quantidade de casos de teste\n");
    scanf("%d", &t);

    for(int k=0; k < t; k++){
        vector<int> a;
        printf("Digite o tamanho do vetor\n");
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
        {
            printf("Digite a posicao %d do vetor\n", i+1);
            scanf("%d",&x);
            a.push_back(x);
        }

    printf("Zeros :%d", countZeros(a));
    printf("\n");

    }

    return 0;
}
