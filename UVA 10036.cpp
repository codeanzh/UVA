#include <iostream>
#include <vector>

using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define VEC vector<ll>
#define V(a) vector<a>
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define wtc() ll tc; cin >> tc; for (ll t = 1; t <= tc; t++)

V(V(bool)) DP;

void divisible(VEC &arr, ll i, ll k, ll sum)
{
    if (i == arr.size())
        return;

    ll add = (((sum + arr[i]) % k) + k) % k, sub = (((sum - arr[i]) % k) + k) % k;
    
    if (!DP[i][add])
    {
        DP[i][add] = true;
        divisible(arr, i + 1, k, add);
    }
    
    if (!DP[i][sub])
    {
        DP[i][sub] = true;
        divisible(arr, i + 1, k, sub);
    }
}

void solve()
{
    wtc()
    {
        ll n, k;
        cin >> n >> k;
        VEC arr(n);

        rep (i, 0, n)
            cin >> arr[i];
        
        DP = *(new V(V(bool))(n, V(bool)(k, false)));
        DP[0][((arr[0] % k) + k) % k] = true;
        
        divisible(arr, 1, k, ((arr[0] % k) + k) % k);

        if (DP[n - 1][0])
            cout << "Divisible\n";
        else
            cout << "Not divisible\n";
    }
}

int main()
{
    fastio

    solve();

    return 0;
}