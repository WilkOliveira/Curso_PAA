#include<stdio.h>
#include<iostream>
#include<string.h>

#define MAX 1000

using namespace std;

int V[MAX][MAX];

/**
* Implementação da mochila
*/
int mochila(int v[], int w[], int n,int W)
{
    int i,j; // fazer duas iterações

    for(i=0; i<=W; i++)
    {
        V[0][i]=0;
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=W; j++)
        {
            if(w[i]<=j)
            {
                int p= V[i-1][j];
                int q=v[i]+V[i-1][j-w[i]];
                if(p>q)
                {
                    V[i][j]=p;
                }
                else
                {
                    V[i][j]=q;
                }
            }
            else
            {
                V[i][j]=V[i-1][j];
            }
        }
    }

    return V[n][W] ;
}

int main()
{
    int v[MAX], w[MAX], W, cliente, solution, i, n, m, testes;

    scanf("%d",&testes); // lê casos de teste
    while(testes--)
    {

        scanf("%d",&n);

        for(i=1; i<=n; i++)
        {
            scanf("%d %d",&v[i],&w[i]);
        }
        W=0;

        scanf("%d",&cliente);
        for(i=1;i<=cliente;i++)
        {
            scanf("%d",&m);
            W+=mochila(v,w,n,m);
        }

        cout << W << ""; //printf("%d\n",W);
    }
}
