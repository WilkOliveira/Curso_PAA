#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

const int dx[8] = {0,-1,-1,-1,0,1,1,1};
const int dy[8] = {-1,-1,0,1,1,1,0,-1};
const int maxn = 30;

bool isin(int, int);
void fill(int, int);

int a[30][30];
bool fre[30][30];
int n;

bool isin(int x, int y){
    return(x>=1 && y>=1 && x<=n && y<=n);
}

void fill(int x, int y){
    fre[x][y] = false;
    for (int k=0; k<8; k++)
    {
        int xx = x+dx[k];
        int yy = y+dy[k];
        if (isin(xx,yy)&& fre[xx][yy] && a[xx][yy]==1) fill(xx,yy);
    }
}

int main(){
    int test = 0;

    while (!cin.eof()){
        cin >> n;
        if (cin.eof()) break;
        test++;
        char ch;

    for (int i=1; i<=n; i++)

    for (int j=1; j<=n; j++){
        cin >> ch;

        a[i][j] = int(ch)-48;
              }
        memset(fre,true,sizeof(fre));
        int result = 0;

        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)

        if (a[i][j]==1 && fre[i][j]){
            result++;
            fill(i,j);
        }

        printf("Image number %d contains %d war eagles.\n",test,result);
      }

      return 0;
}
