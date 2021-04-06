#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define V(a) vector<a>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define wtc() ll tc; cin >> tc; ll test_case = tc; while (tc--)

class DisjointSet
{
private:
    VEC parent, rank;

public:
    DisjointSet(ll n)
    {
        parent.resize(n);
        
        rep (i, 0, n)
            parent[i] = i;

        rank.resize(n, 0);
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
    ll weight;

    edge(ll i_in, ll j_in, ll wt)
    {
        i = i_in;
        j = j_in;
        weight = wt;
    }
};

pair<ll, VEC> kruskal(V(edge) edges, ll n, ll i_id)
{
    DisjointSet dset(n);
    ll sum = 0;
    VEC index;

    rep (i, 0, edges.size())
        if (i_id != i && dset.find(edges[i].i) != dset.find(edges[i].j))
        {
            index.pb(i);
            sum += edges[i].weight;
            dset.Union(edges[i].i, edges[i].j);
        }
    
    return mp(sum, index);
}

bool cmp(edge a, edge b) { return a.weight < b.weight; }

void solve()
{
    wtc()
    {
        ll n, m;
        cin >> n >> m;
        V(edge) edges;
        edge temp(0, 0, 0);

        rep (i, 0, m)
        {
            cin >> temp.i >> temp.j >> temp.weight;
            temp.i--;
            temp.j--;
            edges.pb(temp);
        }

        sort(edges.begin(), edges.end(), cmp);

        pair<ll, VEC> sum_index = kruskal(edges, n, -1);
        ll sum = sum_index.first;
        cout << sum_index.first << " ";
        ll min_sum = LLONG_MAX;

        rep (i, 0, sum_index.second.size())
        {
            ll min_sum_temp = kruskal(edges, n, sum_index.second[i]).first;
            min_sum = min_sum_temp < min_sum && min_sum_temp >= sum? min_sum_temp: min_sum;
        }

        cout << min_sum << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}