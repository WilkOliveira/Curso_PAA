#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

const int eixo_x[8] = {0,-1,-1,-1,0,1,1,1};
const int eixo_y[8] = {-1,-1,0,1,1,1,0,-1};
const int maxn = 30;

int a[30][30];
bool espaco[30][30];
int n;

bool instalacao_militar(int x, int y){
    return(x>=1 && y>=1 && x<=n && y<=n);
}

/**
* Implementação do flood fill
*/
void flood_fill(int x, int y){
    espaco[x][y] = false;
    for (int k=0; k<8; k++)
    {
        int xx = x+eixo_x[k];
        int yy = y+eixo_y[k];
        if (instalacao_militar(xx,yy) && espaco[xx][yy] && a[xx][yy]==1) flood_fill(xx,yy);
    }
}

int main(){
    int testes = 0; // casos de teste

    while (!cin.eof()){
        cin >> n; // dimensão quadrada da imagem
        if (cin.eof()) break;
        testes++;
        char pixel;

    for (int i=1; i<=n; i++)

    for (int j=1; j<=n; j++){
        cin >> pixel;

        a[i][j] = int(pixel)-48;
    }
        memset(espaco,true,sizeof(espaco));
        int qtd_instalacoes = 0;

        for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)

        if (a[i][j]==1 && espaco[i][j]){
            qtd_instalacoes++;
            flood_fill(i,j);
        }

        printf("Image number %d contains %d war eagles.\n",testes,qtd_instalacoes);
    }

      return 0;
}
