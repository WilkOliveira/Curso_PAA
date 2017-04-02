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
* Classe que cria o conjunto de areasyas para representar as linhas de velocidade
*/
class Linhas{
  public:
      int a; // linha a
      int b;
      int t;

      Linhas(int aa, int bb, int tt) : a(aa), b(bb), t(tt) {}
};

    /**
    * Vetor de arestas para representar as linhas
    */
    vector<Linhas> Elist;
    int n,m,w1,k,w2;
    int fa[maxn];

    /**
    * Espandi da menor para a maior
    */
    bool cmp(const Linhas& R1, const Linhas& R2) {return (R1.t<R2.t);}
    bool ok(Linhas R);

int main()
{
    int ntest = 0; // casos de teste

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

            /**
            * Percorre as arestas
            * O(n^2 - 1))
            */
            for (int i=1; i<=n; i++) fa[i] = i;
                for (int i=1; i<=n-1; i++)
                    {
                        cin >> x >> y >> value;
                        w1+=value;
                    }
            cin >> k;

            /**
            * Ordena a expande da maior para a menor
            * O(k)
            */
            for (int i=1; i<=k; i++)
                {
                    cin >> x >> y >> value;
                    Elist.push_back(Linhas(x,y,value));
                }

            cin >> m;

            /**
            * Implementação da arvore geradora minima
            * O(m log m)
            */
            for (int i=1; i<=m; i++)
                {
                    cin >> x >> y >> value;
                    Elist.push_back(Linhas(x,y,value)); // vertice 1, vertice 2 e custo
                }

            sort(Elist.begin(), Elist.end(), cmp);

            for (vector<Linhas>::size_type i=0; i<Elist.size(); i++)
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

/**
* Retorna o custo original e o novo custo
*/
bool ok(Linhas R){
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
