#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1111];
int n, f[1111][1111];

/**
* Implementação da busca em profundidade
*/
int dfs(int l,int r)
{
    if (f[l][r]!=-1) return f[l][r];
    if (r-l<1) return 0;
    int ret=0;
    if (s[l]==s[r])
    {
        ret=dfs(l+1,r-1);
    }
    else
    {
        ret=min( dfs(l+1,r), dfs(l,r-1) )+1;
    }
    f[l][r]=ret;
    return ret;
}

int main()
{
    int testes;
    scanf("%d",&testes);
    getchar();
    while (testes--)
    {
        memset(f,-1,sizeof(f));

        gets(s+1);
        n=strlen(s+1);
        int ans=dfs(1,n);
        printf("%d\n",n-ans);
    }
    return 0;
}
