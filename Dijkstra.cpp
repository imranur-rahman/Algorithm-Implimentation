#include<bits/stdc++.h>

#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii >
#define pb push_back
#define mp make_pair

const int MAX = 501;
const int MAXINT = 1000000000;

vector<vector<pair<int, int> > > ar(MAX);
vector<int>dist(MAX, MAXINT); // ei 2D array te <adjacent node, weight> evabe rakha ache

void dijkstra(int st)
{
    set<pii>s;

    dist[st] = 0;
    s.insert(pii(0, st)); // set er moddhe <weight, node> evabe rakhchi

    while(!s.empty()){

            pii top = *s.begin(); // begin(), end() egula function iterator return kore
            int weight = top.first;
            int node = top.second;
            s.erase(s.begin());

            for(vpii::const_iterator it = ar[node].begin(); it != ar[node].end(); ++it){

                    int now_node = it->first;
                    int cost = it->second;

                    if(dist[node] + cost < dist[now_node]){

                            if(dist[now_node] != MAXINT){

                                    s.erase(s.find(pii(dist[now_node], now_node))); // amar set er moddhe jodi <(MAXINT chara onno value), node> thake tahole oitar (MAXINT chara onno value) ke update korar jonno prothome muche porer line e addition korar por abar insert kora hoyeche
                            }

                            dist[now_node] = dist[node] + cost;
                            s.insert(pii(dist[now_node], now_node));
                    }
            }
    }

}

int main()
{
    int t, caseno = 0;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        for(int i=0; i<m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            ar[u].pb(pii(v, w));
            ar[v].pb(pii(u, w));
        }

        int s;
        cin >> s;
        dijkstra(s);
        printf("Case #%d:\n", ++caseno);
        for(int i=0; i<n; i++)
            cout << dist[i] << '\n';

    }

    return 0;
}

