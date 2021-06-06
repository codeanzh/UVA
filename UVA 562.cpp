#include <iostream>
#include <vector>

using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define VEC vector<ll>
#define V(a) vector<a>
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define repr(i, st, n) for (ll i = st; i >= n; i--)
#define wtc() ll tc; cin >> tc; for (ll t = 1; t <= tc; t++)

ll min_diff(VEC &arr)
{
    ll sum = 0, n = arr.size();

    rep (i, 0, n)
        sum += arr[i];
    
    V(V(bool)) DP(n + 1, V(bool)(sum + 1, false));
    
    rep (i, 0, n + 1)
        DP[i][0] = true;

    rep (i, 1, n + 1)
        rep (j, 1, sum + 1)
            if (j < arr[i - 1])
                DP[i][j] = DP[i - 1][j];
            else
                DP[i][j] = DP[i - 1][j] || DP[i - 1][j - arr[i - 1]];
    
    if (sum / 2 == 0)
        return sum;
    else
    {
        repr (i, sum / 2, 0)
            if (DP[n][i])
                return sum - 2 * i;
    }
}

void solve()
{
    wtc()
    {
        ll n;
        cin >> n;
        VEC arr(n);

        rep (i, 0, n)
            cin >> arr[i];
        
        cout << min_diff(arr) << "\n";
    }
}

int main()
{
    fastio

    solve();

    return 0;
}