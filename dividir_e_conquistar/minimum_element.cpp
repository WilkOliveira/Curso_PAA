#include <bits/stdc++.h>

using namespace std;

int menor_esq, menor_dir, menor;
int i, j = 0;

void minimunElement(vector<int> &vetor)
{

    if(vetor.size()>=2){
        int meio = vetor.size() / 2;
        vector<int> esquerdo(vetor.begin(), vetor.begin()+meio);
        vector<int> direito(vetor.begin()+meio, vetor.end());

        menor_esq = esquerdo[i];
        menor_dir = direito[j];

            if(esquerdo[i] < menor_esq || direito[j] < menor_dir){

                menor_esq = esquerdo[i];
                menor_dir = direito[j];
                i++;
                j++;
                minimunElement(esquerdo);
                minimunElement(direito);
            }
            else

                if(menor_esq <= menor_dir){
                    menor = menor_esq;
                }
                else{
                menor = menor_dir;

                }
    }
}

int main()
{
    int n, x, t;

    vector<int> a;

    printf("Digite a quantidade de casos de teste\n");
    scanf("%d", &t);

    for(int k = 0; k < t; k++){
        printf("Digite o tamanho do vetor\n");
        scanf("%d", &n);

        for (int l = 0; l < n; l++)
        {
            printf("Digite a posicao %d do vetor\n", k+1);
            scanf("%d",&x);
            a.push_back(x);
        }

    minimunElement(a);
    printf("\n");
    printf("Menor elemento :%d\n", menor);

    }

    return 0;
}
