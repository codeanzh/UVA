#include <iostream>
#include <vector>

using namespace std;

#define ll long long int
#define VECS vector<string>
#define VECB vector<bool>
#define VECVB vector<VECB>
#define rep(st, n) for (ll i = st; i < n; i++)
#define REP(st, n) for (ll j = st; j < n; j++)

ll n, m;
char sym;

bool alpha_equal(char a, char b) 
{
    char c;

    if (b > 'a')
        c = b - ('a' - 'A');
    else
        c = b + ('a' + 'A');

    return a == b || a == c;
}

ll land_dfs(ll i, ll j, VECS &world_map, VECVB &traversed)
{
    ll count = 0;
    traversed[i][j] = true;

    if (alpha_equal(world_map[i][j - 1 < 0? m - 1: j - 1], sym) && !traversed[i][j - 1 < 0? m - 1: j - 1])
        count += 1 + land_dfs(i, j - 1 < 0? m - 1: j - 1, world_map, traversed);
    
    if (alpha_equal(world_map[i][j + 1 == m? 0: j + 1], sym) && !traversed[i][j + 1 == m? 0: j + 1])
        count += 1 + land_dfs(i, j + 1 == m? 0: j + 1, world_map, traversed);
    
    if (i > 0 && alpha_equal(world_map[i - 1][j], sym) && !traversed[i - 1][j])
        count += 1 + land_dfs(i - 1, j, world_map, traversed);
    
    if (i < n - 1 && alpha_equal(world_map[i + 1][j], sym) && !traversed[i + 1][j])
        count += 1 + land_dfs(i + 1, j, world_map, traversed);

    return count;
}

void solve()
{   
    while (cin >> n)
    {
        ll x, y, max = 0;
        cin >> m;
        VECS world_map(n);
        VECVB traversed(n, VECB(m, false));

        rep(0, n)
            cin >> world_map[i];

        cin >> x >> y;
        sym = world_map[x][y];
        land_dfs(x, y, world_map, traversed);

        rep(0, n)
            REP(0, m)
                if (!traversed[i][j] && alpha_equal(world_map[i][j], sym))
                {
                    ll temp_max = 1 + land_dfs(i, j, world_map, traversed);
                    max = max > temp_max? max: temp_max;
                }

        cout << max << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}