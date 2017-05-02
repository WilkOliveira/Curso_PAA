#include <iostream>
#include <vector>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define N 201

bool ligacao[N][N]; // matriz de ligação de arestas
int entrada[N], d[N];// guarda a maior profundidade, onde d é a profundidade de N
int no[N], num_ligacoes; // para verificar número de de ligações

vector<int> g[N];

/**
* Implementação da bsuca em profundidade
*/
void dfs(int u, int pai, int profundidade)
{
    no[u] = 1;
    d[u] = entrada[u] = profundidade;
    for(int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if(no[v] == 1 && v != pai)
            entrada[u] = entrada[u] < d[v] ? entrada[u] : d[v];

        if(no[v] == 0)
        {
            dfs(v, u, profundidade + 1);
            entrada[u] = entrada[u] < entrada[v] ? entrada[u] : entrada[v];

            if(entrada[v] > d[u]) // ligação entre u e v
            {
                num_ligacoes++;
                ligacao[u][v] = ligacao[v][u] = 1;
            }
        }
    }
    no[u] = 2;
}

int main()
{
    int n;
    while(scanf("%d", &n))// leitura dos casos de teste
    {
        memset(ligacao, false, sizeof(ligacao));
        num_ligacoes = 0;

        for(int i = 0; i < N; i++)
        {
            no[i] = 0;
            g[i].clear(); // limpa aqui
        }

        for(int i = 0; i < n; i++)
        {
            int a, b, c;
            scanf("%d (%d)", &a, &c);
            for(int j = 0; j < c; j++)
            {
                scanf("%d", &b);
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(!no[i]) dfs(i, 0, 0);
        }

        printf("%d critical links\n", num_ligacoes); // quantidade de ligações críticas

        /**
        * Loop para mostrar quais as ligações críticas
        */
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(ligacao[i][j]) printf("%d - %d\n", i, j);
            }
        }
        printf("\n");
    }
    return 0;
}
