#include<cstdio>
#include<algorithm>
#include<cstring>

#define maxn 100010

using namespace std;

int m,n,a; // estradas, locais e custos

/**
* Definição da classe Grafo
*/
struct Grafo{

int u,v,w;

    bool operator<(const Grafo& t)const{
        return w<t.w;
    }
}arestas[maxn];

int f[10010],pen[10010],resp,contador;

/**
* Função recursiva que busca o subconjunto de um determnado elemento "x" do grafo
* O(x)
*/
int busca(int x){
    return x==f[x]?x:f[x]=busca(f[x]);
}

/**
* Função que implementa o algoritmo de Kruskal
* O(E log V)
*/
bool kruskal(){
    for(int i=0;i<m;i++){
         int x=busca(arestas[i].u);
         int y=busca(arestas[i].v);

            if(x!=y){
                f[x]=y;
                pen[contador++]=arestas[i].w;
                resp+=arestas[i].w;
            }
     }
 }

int main(){

    int ca=1,num,t;
    scanf("%d",&t); // leitura dos casos de teste

    /**
    * Enquanto houver casos de teste
    */
    while(t--){
        scanf("%d%d%d",&n,&m,&a);
        resp=num=contador=0;
        memset(pen,0,sizeof pen);

        for(int i=1;i<=n;i++)f[i]=i;
            for(int i=0;i<m;i++)
            scanf("%d%d%d",&arestas[i].u,&arestas[i].v,&arestas[i].w);

            sort(arestas,arestas+m); // ordenação

            /**
            * Chamada do Kruskal
            */
            kruskal();
                for(int i=1;i<=n;i++)if(i==busca(i))num++;
                for(int i=0;i<=contador;i++)
                    if(pen[i]>=a){
                        num++;
                        resp-=pen[i];
                    }

            resp+=num*a;

            printf("Case #%d: %d %d\n",ca++,resp,num); // saída
     }
     return 0;
}
