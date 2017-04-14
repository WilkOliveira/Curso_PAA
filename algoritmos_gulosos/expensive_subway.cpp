#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;

struct Grafo
{
    int src;
    int dest;
    int wgt;
};

Grafo conjunto[79810];
int pai[410];

bool cmp(Grafo x,Grafo y){
    return x.wgt<y.wgt;
}

int busca(int x){
    while(pai[x]!=x)
    x=pai[x];
    return x;
}

int main(){
    int edge,no,i,w,u,v,aresta_controle,up,vp,cost;
    string str,s;
    map<string,int> map;
    while(true)
        {
            cin>>no>>edge;
            if(edge==0 && no==0)
            break;
            map.clear();

            for(i=1;i<=no;i++){
                    cin>>str;
                    map[str]=i;
            }

            for(i=0;i<edge;i++){
                cin>>str>>s>>w;
                conjunto[i].src=map[str];
                conjunto[i].dest=map[s];
                conjunto[i].wgt=w;
            }

    cin>>str;
    sort(conjunto,conjunto+edge,cmp);
    for(i=1;i<=no;i++)
    pai[i]=i;
    aresta_controle=no-1;
    cost=0;
    for(i=0;i<edge && aresta_controle>0;i++){
        u=conjunto[i].src;
        v=conjunto[i].dest;
        up=busca(u);
        vp=busca(v);
        if(up!=vp)
        {
            aresta_controle--;
            pai[vp]=up;
            cost+=conjunto[i].wgt;
        }
    }

    if(aresta_controle==0)
    cout << cost << endl;
    else
    cout << "Impossible" << endl;
}

return 0;
}
