#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char palavra[1000];
int tam_original;
int f[1000][1000];

/**
* Implementação da busca em profundidade
*/
int dfs(int esquerdo,int direito)
{
    if (f[esquerdo][direito]!=-1)
        return f[esquerdo][direito];
    if (direito-esquerdo<1)
        return 0;

    int ret=0;

    if(palavra[esquerdo]==palavra[direito])
    {
        ret=dfs(esquerdo+1,direito-1);
    }
    else
    {
        ret=min(dfs(esquerdo+1,direito), dfs(esquerdo,direito-1) )+1;
    }
    f[esquerdo][direito]=ret;

    return ret;
}

int main()
{
    int testes;

    scanf("%d",&testes);
    getchar(); // após receber o número de casos de teste, já pega os testes

    while (testes--)
    {
        memset(f,-1,sizeof(f));

        gets(palavra+1);
        tam_original=strlen(palavra+1);
        int palindromo=dfs(1,tam_original);
        printf("%d\n",tam_original-palindromo);
    }
    return 0;
}
