#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 100009

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
}ed[maxn];

int f[10009],pen[10009],ans,cnt;

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
         int x=busca(ed[i].u);
         int y=busca(ed[i].v);

            if(x!=y){
                f[x]=y;
                pen[cnt++]=ed[i].w;
                ans+=ed[i].w;
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
        ans=num=cnt=0;
        memset(pen,0,sizeof pen);

        for(int i=1;i<=n;i++)f[i]=i;
            for(int i=0;i<m;i++)
            scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);

            sort(ed,ed+m); // ordenação

            /**
            * Chamada do Kruskal
            */
            kruskal();
                for(int i=1;i<=n;i++)if(i==busca(i))num++;
                for(int i=0;i<=cnt;i++)
                    if(pen[i]>=a){
                        num++;
                        ans-=pen[i];
                    }

            ans+=num*a;
            printf("Case #%d: %d %d\n",ca++,ans,num); // saída
     }
     return 0;
}
