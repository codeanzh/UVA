#include <iostream>
#include <unordered_map>

using namespace std;

#define ll long long int
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define wtc() ll tc; cin >> tc; while (tc--)

class DisjointSet
{
private:
    unordered_map<string, pair<string, ll>> parent;
    unordered_map<string, ll> rank;

public:
    void check_make(string data1, string data2)
    {
        if (parent.find(data1) == parent.end())
        {
            parent[data1] = mp(data1, 1);
            rank[data1] = 0;
        }

        if (parent.find(data2) == parent.end())
        {
            parent[data2] = mp(data2, 1);
            rank[data2] = 0;
        }
    }

    string find(string str)
    {
        if (parent[str].first != str)
            parent[str].first = find(parent[str].first);
        
        return parent[str].first;
    }

    ll Union(string str1, string str2)
    {
        string i_id = find(str1), j_id = find(str2);

        if (i_id == j_id)
            return parent[i_id].second;
        
        if (rank[i_id] > rank[j_id])
        {
            parent[j_id] = mp(i_id, parent[j_id].second);
            parent[i_id] = mp(i_id, parent[j_id].second + parent[i_id].second);

            return parent[i_id].second;
        }
        else
        {
            parent[i_id] = mp(j_id, parent[i_id].second);
            parent[j_id] = mp(j_id, parent[j_id].second + parent[i_id].second);

            if (rank[i_id] == rank[j_id])
                rank[j_id]++;
            
            return parent[j_id].second;
        }
    }
};

void solve()
{
    wtc()
    {
        ll n;
        cin >> n;
        string friend1, friend2;
        DisjointSet dset;

        rep (i, 0, n)
        {
            cin >> friend1 >> friend2;
            dset.check_make(friend1, friend2);
            cout << dset.Union(friend1, friend2) << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}