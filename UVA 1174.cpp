#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long int
#define VECS vector<string>
#define V(a) vector<a>
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define fora(i, a) for(auto i: a)
#define wtc() ll tc; cin >> tc; ll test_case = tc; while (tc--)

class DisjointSet
{
private:
    map<string, string> parent;
    map<string, ll> rank;

public:
    DisjointSet(VECS &data)
    {
        rep (i, 0, data.size())
        {
            parent[data[i]] = data[i];
            rank[data[i]] = 0;
        }
    }

    string find(string i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }

    void Union(string i, string j)
    {
        string i_id = find(i);
        string j_id = find(j);

        if (i_id == j_id)
            return;
        
        if (rank[i_id] > rank[j_id])
            parent[j_id] = i_id;
        else
        {
            parent[i_id] = j_id;

            if (rank[i_id] == rank[j_id])
                rank[j_id] = 1 + rank[j_id];
        }
    }
};

struct edge
{
    string i, j;
    double weight;
};

bool cmp(edge a, edge b) { return a.weight < b.weight; }

ll kruskal(VECS &towns, V(edge) &edges)
{
    DisjointSet dset(towns);
    ll cost = 0;
    sort (edges.begin(), edges.end(), cmp);

    rep (i, 0, edges.size())
        if (dset.find(edges[i].i) != dset.find(edges[i].j))
        {
            cost += edges[i].weight;
            dset.Union(edges[i].i, edges[i].j);
        }
    
    return cost;
}

void solve()
{
    wtc()
    {
        ll m, n;
        cin >> m >> n;
        V(edge) edges(n);
        map<string, bool> town;
        VECS towns;

        rep (i, 0, n)
        {
            cin >> edges[i].i >> edges[i].j >> edges[i].weight;
            town[edges[i].i] = true;
            town[edges[i].j] = true;
        }

        fora(itr, town)
            towns.pb(itr.first);

        ll total_weight = kruskal(towns, edges);
        cout << total_weight << "\n";

        if (tc != 0)
            cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}