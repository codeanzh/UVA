#include <iostream>
#include <vector>

using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define VEC vector<ll>
#define rep(i, st, n) for (ll i = st; i < n; i++)

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve()
{
    ll n, c, a, gc;
    
    while (true)
    {
        cin >> n >> c;

        if (n == 0 && c == 0)
            break;
        
        VEC data(n);
        ll sum = 0;

        rep (i, 0, n)
            rep (j, 0, c)
            {
                cin >> a;

                if (j == c - 1)
                {
                    data[i] = a;
                    sum += a;
                }
            }

        rep (i, 0, n)
        {
            gc = gcd(data[i], sum);
            cout << (data[i] / gc) << " / " << (sum / gc) << "\n";
        }
    }
}

int main()
{
    fastio

    solve();

    return 0;
}