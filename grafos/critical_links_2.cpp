#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

#define ll long long
#define INF 2*1000000000

const int MAXN = 200; // pontos
const int MAXM = 50000; // arestas

/**
* Estrutura
*/
struct Grafo
{
    int de,para; // para montagem do grafo
}grafo[MAXM];

int pai[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];//Belong数组的值是1~scc
int Index,top;
int scc;//强连通分量的个数
bool Instack[MAXN];
int num[MAXN];//各个强连通分量包含点的个数，数组编号1~scc //num数组不一定需要，结合实际情况
int sum;

/**
* Estrutura para representar os nós da rede de servidores
*/
struct no{
  int x,y;
}a[MAXM];

/**
* Função que verifica as conexões
*/
bool conexao(no a, no b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

/**
* Função que preenche o grafo bi-direcional e monta suas posições
*/
void addgrafo(int u,int v)
{
    grafo[tot].de = v;
    grafo[tot].para = pai[u];
    pai[u] = tot++;
}

/**
* Implementação do algoritmo de Tarjan para procurar elementos com ligações críticas
*/
void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son=0;
    for(int i = pai[u];i != -1;i = grafo[i].para)
    {
        v = grafo[i].de;
        if(v==pre) continue;
        if( !DFN[v] )
        {
            son++;
            Tarjan(v,u);
            if( Low[u] > Low[v] )
                Low[u] = Low[v];
            if(Low[v]>DFN[u])
            {
                a[sum].x=min(u,v),a[sum].y=max(u,v);
                sum++;
            }
        }
        else if(Low[u] > DFN[v]) Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        scc++;
        do
        {
            v = Stack[--top];
            Instack[v] = false;
            Belong[v] = scc;
            num[scc]++;
        }
        while( v != u);
    }
}

void solve(int n)
{
    conjunto(DFN,0,sizeof(DFN));
    conjunto(Instack,false,sizeof(Instack));
    conjunto(num,0,sizeof(num));

    Index = scc = top = 0;

    for(int i = 1;i <= n;i++)
        if(!DFN[i])    Tarjan(i,i);
    sort(a,a+sum,conexao);

    int ans=sum;

    for(int i=0;i<sum;i++)
        if(i!=0&&a[i].x==a[i-1].x&&a[i].y==a[i-1].y) ans--;
    cout<<ans<<" critical links"<<endl;

    for(int i=0;i<sum;i++)
    {
        if(i!=0&&a[i].x==a[i-1].x&&a[i].y==a[i-1].y) continue;
        cout<<a[i].x-1<<" - "<<a[i].y-1<<endl;
    }
    cout<<endl;
}

void init()
{
    tot = 0;
    conjunto(pai,-1,sizeof(pai));
}
int n,g[105],f[105],x,y,m;

char c;

int main()
{
    /**
    * Leitura dos casos de entrada e chamada das funções
    */
    while(~scanf("%d",&n)){
        init();sum=0;

        for(int i=0;i<n;i++){
            scanf("%d (%d)",&x,&m);
            x++;

            while(m--){
                scanf("%d",&y);y++;
                if(y<=x) continue;
                addgrafo(x,y);
                addgrafo(y,x);
            }
        }
        solve(n);
    }
    return 0;
}
