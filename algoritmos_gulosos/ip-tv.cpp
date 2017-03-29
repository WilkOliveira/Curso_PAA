// UVA 1174 - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3615

#include <iostream>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

#define MAX 200100

using namespace std;

/**
* Classe de arestas para representar as estradas
*/
struct Road {
    int v, c;
    Road(int v, int c) : v(v), c(c) {}
    inline bool operator < (const Road& that) const { return c > that.c; }
};

    vector<Road> G[MAX]; // vertor de estradas
    priority_queue<Road> Q; // define prioridades, para abertura das arestas
    int n, m; // linhas existentes e cidades
    bool V[MAX];
    map<string, int> M; // conjunto de vertices para representar as cidades

    /**
    * Função para varrer os vertices que representam as cidades
    */
    int city(string& s) {
        if (M.find(s) != M.end())
            return M[s];
        else
            return M[s]=M.size();
}

int main() {

    int t; cin >> t; t=0; // casos de teste

    while(cin >> n >> m) {
        memset(V, 0, sizeof(V));
        memset(G, 0, sizeof(G));
        M.clear();
        Q = priority_queue<Road>();

        for(int i=0; i<m; i++) {
            string p, q; int a, b, c; // nomes de cidades
            cin >> p >> q >> c;
            a = city(p); b=city(q);
            G[a].push_back(Road(b, c)); // distância entre uma cidade e outra
            G[b].push_back(Road(a, c));
        }

        int total = 0, totalc=0;

        Q.push(Road(1, 0));

        while(totalc < n){
            Road item = Q.top(); Q.pop();
            if (V[item.v]) continue;

            V[item.v] = true;
            total += item.c;
            totalc++;

            for(int j=0; j<G[item.v].size(); j++)
                if (!V[G[item.v][j].v])
                    Q.push(G[item.v][j]);
        }

        if (t++) cout << endl;
        cout << total << endl;
    }

    return 0;
}
