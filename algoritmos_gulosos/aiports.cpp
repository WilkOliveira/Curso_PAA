#include<cstdio>
#include<cstring>
#include<algorithm>

#define maxn 100009

using namespace std;

int n,m,a;

struct edge{

int u,v,w;

    bool operator<(const edge& t)const{
        return w<t.w;
    }
}ed[maxn];

int f[10009],pen[10009],ans,cnt;

int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}

bool kruskal(){
    for(int i=0;i<m;i++){
         int x=find(ed[i].u);
         int y=find(ed[i].v);

            if(x!=y){
                f[x]=y;
                pen[cnt++]=ed[i].w;
                ans+=ed[i].w;
            }
     }
 }

int main(){

    int ca=1,num,t;
    scanf("%d",&t);

    while(t--){
        scanf("%d%d%d",&n,&m,&a);
        ans=num=cnt=0;
        memset(pen,0,sizeof pen);

        for(int i=1;i<=n;i++)f[i]=i;
            for(int i=0;i<m;i++)
            scanf("%d%d%d",&ed[i].u,&ed[i].v,&ed[i].w);

            sort(ed,ed+m);

            kruskal();
                for(int i=1;i<=n;i++)if(i==find(i))num++;
                for(int i=0;i<=cnt;i++)
                    if(pen[i]>=a){
                        num++;
                        ans-=pen[i];
                    }

            ans+=num*a;
            printf("Case #%d: %d %d\n",ca++,ans,num);
     }
     return 0;
}
