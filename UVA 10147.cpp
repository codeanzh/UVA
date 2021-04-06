#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define VECV vector<VEC>
#define VECS vector<string>
#define PAIR pair<ll, ll>
#define VECP vector<PAIR>
#define V(a) vector<a>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define repr(i, st, n) for (ll i = st; i >= n; i--)
#define fora(i, a) for(auto i: a)
#define wtc() ll tc; cin >> tc; ll test_case = tc; while (tc--)

struct hash_pair 
{ 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

#define PAIR_MAP(a) unordered_map<PAIR, a, hash_pair>

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

ll mod_pow(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    else if (y % 2 == 0)
    {
        ll pow2 = mod_pow(x, y / 2, m);

        return (pow2 * pow2) % m;
    }
    else
    {
        ll pow2 = mod_pow(x, y / 2, m);

        return (((pow2 * pow2) % m) * x) % m;
    }
}

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

VECP kruskal(VECP &coordinates)
{
    DisjointSet dset(coordinates);
    ll m;
    cin >> m;
    PAIR temp;

    rep (i, 0, m)
    {
        cin >> temp.first >> temp.second;
        dset.Union(temp.first - 1, temp.second - 1);
    }

    V(edge) edges = make_edge(coordinates);
    VECP mst;

    rep (i, 0, edges.size())
        if (dset.find(edges[i].i) != dset.find(edges[i].j))
        {
            mst.pb(mp(edges[i].i, edges[i].j));
            dset.Union(edges[i].i, edges[i].j);
        }
    
    return mst;
}

void solve()
{
    wtc()
    {
        if (tc != test_case - 1)
            cout << "\n";

        ll n;
        cin >> n;
        VECP coordinates(n);

        rep (i, 0, n)
            cin >> coordinates[i].first >> coordinates[i].second;

        VECP mst = kruskal(coordinates);

        if (mst.size() == 0)
            cout << "No new highways need\n";
        else
            rep (i, 0, mst.size())
                cout << mst[i].first + 1 << " " << mst[i].second + 1 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);

    #endif

    solve();

    return 0;
}