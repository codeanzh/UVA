#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define PAIR pair<ll, ll>
#define VECP vector<PAIR>
#define V(a) vector<a>
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define wtc() ll tc; cin >> tc; ll test_case = tc; while (tc--)

class DisjointSet
{
private:
    VEC parent, rank;

public:
    DisjointSet(VECP data)
    {
        parent.resize(data.size());
        
        rep (i, 0, data.size())
            parent[i] = i;

        rank.resize(data.size(), 0);
    }

    ll find(ll i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }

    void Union(ll i, ll j)
    {
        ll i_id = find(i);
        ll j_id = find(j);

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
    ll i, j;
    double weight;

    edge(ll i_in, ll j_in, double wt)
    {
        i = i_in;
        j = j_in;
        weight = wt;
    }
};

double dist(PAIR coor1, PAIR coor2){return sqrt(pow(coor1.first - coor2.first, 2) + pow(coor1.second - coor2.second, 2));}

bool cmp(edge a, edge b) { return a.weight < b.weight; }

V(edge) make_edge(VECP &coordinates)
{
    V(edge) edges;

    rep (i, 0, coordinates.size() - 1)
        rep (j, i + 1, coordinates.size())
            edges.pb(edge(i, j, dist(coordinates[i], coordinates[j])));
    
    sort(edges.begin(), edges.end(), cmp);

    return edges;
}

V(edge) kruskal(VECP &coordinates)
{
    DisjointSet dset(coordinates);
    V(edge) edges = make_edge(coordinates);
    V(edge) mst;

    rep (i, 0, edges.size())
        if (dset.find(edges[i].i) != dset.find(edges[i].j))
        {
            mst.pb(edges[i]);
            dset.Union(edges[i].i, edges[i].j);
        }
    
    return mst;
}

void solve()
{
    wtc()
    {
        ll n, m;
        cin >> m >> n;
        VECP coordinates(n);

        rep (i, 0, n)
            cin >> coordinates[i].first >> coordinates[i].second;

        V(edge) mst = kruskal(coordinates);
        cout << fixed << setprecision(2) << mst[n - 1 - m].weight << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}