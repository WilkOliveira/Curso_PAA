// UVA 1234 - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3675

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>

#define Max 100000  + 5
#define P pair<int, double>
#define INF 1000000000

#define FOR(i, N) for( int i = 0 ; i < N ; i++ )

using namespace std;

typedef struct Ruas {
    int a, b, custo; // arestas e custo

    bool operator < (const Ruas &e) const {
        return custo > e.custo;
    }
}E;

class UnionFind {
public:
    int Parent[Max];
    int tamanho;
public:
    void Intialize(int N) {

        for(int i = 0; i < N; i++)      Parent[i] = i;
        tamanho = N;
    }
    int FindSet(int Index) {
        return Parent[Index] == Index ? Index : (Parent[Index] = FindSet(Parent[Index]));
    }
    bool IsEqual(int X, int Y) {
        return FindSet(X) == FindSet(Y);
        return false;
    }
    void Union(int X, int Y) {
        if(!IsEqual(X, Y))
            Parent[FindSet(X)] = FindSet(Y), tamanho--;
    }
    int GetTamanho() {
        return tamanho;
    }
};

int Cmp(const void* X, const void* Y) {
    if(((E*)X)->custo < ((E*)Y)->custo) return -1;
    if(((E*)X)->custo > ((E*)Y)->custo) return 1;
    if(((E*)X)->custo == ((E*)Y)->custo) return 0;
}

int c; // casos de teste
int NumberOfJunctions, NumberOfRoads;
int a, b, custo;
E Edges[Max];
int Index;

int main(int argc, char** argv) {

    scanf("%d", &c);

    while(c--) {
        UnionFind X;
        Index = 0;
        scanf("%d %d", &NumberOfJunctions, &NumberOfRoads);

        /**
        * O(n)
        */
        FOR(i, NumberOfRoads) {
            scanf("%d %d %d", &a, &b, &custo);
            Edges[Index].a = a - 1;
            Edges[Index].b = b - 1;
            Edges[Index].custo = custo;
            Index++;
        }

        X.Intialize(NumberOfJunctions);
        sort(Edges, Edges + Index);
        int CustoMinimo = 0;
        FOR(i, NumberOfRoads)   CustoMinimo += Edges[i].custo;

        /**
        * O(n)
        */
        for(int i = 0; i < Index && X.GetTamanho() > 0; i++) {
            if(!X.IsEqual(Edges[i].a, Edges[i].b)) {
                X.Union(Edges[i].a, Edges[i].b);
                CustoMinimo -= Edges[i].custo;
            }
        }

        printf("%d\n", CustoMinimo);
    }

    return 0;
}
