#include <bits/stdc++.h>

using namespace std;

int razao = 0;
int razaoOF = 0;
int element1 = 0;

void missingElementAux(vector<int> &vetor){

    if(vetor.size()>=2){
        int meio = vetor.size() / 2;
        vector<int> esquerdo(vetor.begin(), vetor.begin()+meio);
        vector<int> direito(vetor.begin()+meio, vetor.end());
        missingElementAux(esquerdo);

        if(razao == 0){

        razao = direito[0] - esquerdo[esquerdo.size()-1];
        razaoOF = razao;
        }
        else

            if(razao != (direito[0] -  esquerdo[esquerdo.size()-1]) && razaoOF != razao){
                razao = direito[0] - esquerdo[esquerdo.size()-1];
                razaoOF = razao;
            }
            else{
                razaoOF = razao;
                    if(razao != (direito[0] -  esquerdo[esquerdo.size()-1])){
                    element1 = direito[0]-razao;
                    }
            }

            missingElementAux(direito);

    }
    else{

    }

}

int missingElement(vector<int> &vetor)
{

    if(vetor.size() == 2){
            if ((vetor[1] - vetor[0]) != razao){
                printf(" Razao %d", razao);
                return  vetor[0] + razao;
            }

    }
    else if(vetor.size() == 3){
            if ((vetor[1] - vetor[0]) != razao){
                printf(" Razao %d", razao);
                return  vetor[0] + razao;
            }else if((vetor[2] - vetor[1]) != razao){
                printf(" Razao %d", razao);
                return  vetor[1] + razao;
            }

    }
    else{
        int meio = vetor.size() / 2;
        vector<int> esquerdo(vetor.begin(), vetor.begin()+meio);
        vector<int> direito(vetor.begin()+meio, vetor.end());

        if ((esquerdo[1] - esquerdo[0]) == razao && (razao != 0)){

        }
        else{

        }

        razao = (direito[1] - direito[0]);
        missingElement(direito);
    }
}

int main()
{
    int n, x, t;

    printf("Digite a quantidade de casos de teste\n");
    scanf("%d", &t);

    for(int k = 0; k < t; k++){
        vector<int> a;
        printf("Digite o tamanho do vetor\n");
        scanf("%d", &n);

        for (int i = 0; i < n; ++i)
        {
            printf("Digite a posicao %d do vetor\n", i+1);
            scanf("%d",&x);
            a.push_back(x);
        }

    missingElementAux(a);

    printf("Razão %d", razao);
    printf("\n");
    printf("Elemento faltante %d", element1);
    a.clear();
    element1 = 0;
    razao = 0;

    printf("\n");
    }

    return 0;
}
