#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii >
#define pb push_back
#define mp make_pair
#define ll long long

const int MAX = 1e5 + 1;
const ll MAXINT = 1e18;

vector<vector<pair<int, int> > > ar(MAX);
vector<ll>dist(MAX, MAXINT); // ei 2D array te <weight, adjacent node> evabe rakha ache
vector<int>parent(MAX, 0);

void dijkstra(int st)
{
    set<pii>s;

    dist[st] = 0;
    s.insert(pii(0, st)); // set er moddhe <weight, node> evabe rakhchi

    while(!s.empty()){

            pii top = *s.begin(); // begin(), end() egula function iterator return kore
            //int weight = top.first;
            int father = top.second;
            s.erase(s.begin());

            for(vpii::const_iterator it = ar[father].begin(); it != ar[father].end(); ++it){

                    int cost = it -> first;
                    int child = it -> second;

                    if(dist[father] + cost < dist[child]){

                            if(dist[child] != MAXINT){

                                    s.erase(s.find(pii(dist[child], child))); // amar set er moddhe jodi <(MAXINT chara onno value), node> thake tahole oitar (MAXINT chara onno value) ke update korar jonno prothome muche porer line e addition korar por abar insert kora hoyeche
                            }

                            dist[child] = dist[father] + cost;
                            parent[child] = father;
                            s.insert(pii(dist[child], child));
                    }
            }
    }

}

int main()
{
    int n, m;

    while(cin >> n >> m){

        int u, v, w;
        for(int i=0; i<m; i++){

            cin >> u >> v >> w;
            ar[u].pb(pii(w, v));
            ar[v].pb(pii(w, u));
        }

        dijkstra(1);

        if(dist[n] == MAXINT) puts("-1");
        else{
            //int mother;
            vector<int>result;
            //result.pb(n);


            while(n){
                result.pb(n);
                n = parent[n];
            }

            for(int i=result.size()-1; i>=0; i--)
                cout << result[i] << " " ;

        }

    }

    return 0;
}
