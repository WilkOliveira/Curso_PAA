// UVA 908 - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=849

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1000100;

/**
* Classe que cria o conjunto de arestas
*/
class Aresta{
  public:
      int a;
      int b;
      int t;

      Aresta(int aa, int bb, int tt) : a(aa), b(bb), t(tt) {}
};

    /**
    * Vetor de arestas
    */
    vector<Aresta> Elist;
    int n,m,w1,k,w2;
    int fa[maxn];

    bool cmp(const Aresta& R1, const Aresta& R2) {return (R1.t<R2.t);}
    bool ok(Aresta R);

int main()
{
    int ntest = 0;

    while (!cin.eof())
        {
            cin >> n; // número de sites
            if (cin.eof()) break;
            Elist.clear();
            ntest++;
            if (ntest>1) cout << endl;
            int x, y, value, cnt = 0;
            w1 = 0;
            w2 = 0;

            for (int i=1; i<=n; i++) fa[i] = i;
                for (int i=1; i<=n-1; i++)
                    {
                        cin >> x >> y >> value;
                        w1+=value;
                    }
            cin >> k;

            for (int i=1; i<=k; i++)
                {
                    cin >> x >> y >> value;
                    Elist.push_back(Aresta(x,y,value));
                }

            cin >> m;

            /**
            * Começa a implementar a arvore geradora minima
            */
            for (int i=1; i<=m; i++)
                {
                    cin >> x >> y >> value;
                    Elist.push_back(Aresta(x,y,value));
                }

            sort(Elist.begin(), Elist.end(), cmp);

            for (vector<Aresta>::size_type i=0; i<Elist.size(); i++)
                if (ok(Elist[i]))
                {
                    w2+=Elist[i].t;
                    cnt++;
                    if (cnt==n-1) break;
                }

            cout << w1 << endl << w2 << endl;

      }

      return 0;
}

bool ok(Aresta R){
    int a = R.a, b = R.b;
    while (a!=fa[a]) a = fa[a];
        while (b!=fa[b]) b = fa[b];
        if (a==b) return(false);
        else
        {
            a<b? fa[b] = a : fa[a] = b;
            return(true);
        }
}
