// UVA 11733 - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2833

#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 100010

using namespace std;

<<<<<<< HEAD
int m,n,a; // estradas, locais e custos
=======
int n,m,a; // locais, estradas e custos
>>>>>>> origin/master

/**
* Definição da classe Grafo
*/
struct Grafo{

int u,v,w;

<<<<<<< HEAD
    bool operator<(const Grafo& t)const{
=======
    /**
    * Trata da ordenação do Kruskal
    */
    bool operator<(const edge& t)const{
>>>>>>> origin/master
        return w<t.w;
    }
}ed[maxn];

int f[10009],pen[10009],ans,cnt;

/**
<<<<<<< HEAD
* Função recursiva que busca o subconjunto de um determnado elemento "x" do grafo
=======
* Função recursiva que busca o subconjunto de um determnado elemento do grafo
>>>>>>> origin/master
* O(x)
*/
int busca(int x){
    return x==f[x]?x:f[x]=busca(f[x]);
}

/**
<<<<<<< HEAD
* Função que implementa o algoritmo de Kruskal
=======
* Implementação do algoritmo de Kruskal
>>>>>>> origin/master
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

<<<<<<< HEAD
    int ca=1,num,t;
    scanf("%d",&t); // leitura dos casos de teste

    /**
    * Enquanto houver casos de teste
=======
    int t; // casos de teste
    int ca=1,num;
    scanf("%d",&t);

    /**
    * Lê os casos de teste
>>>>>>> origin/master
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
