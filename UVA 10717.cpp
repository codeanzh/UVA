#include <iostream>
#include <vector>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define rep(i, st, n) for (ll i = st; i < n; i++)

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void solve()
{
    ll N, T;

    while (true)
    {
        cin >> N >> T;

        if (N == 0 && T == 0)
            break;

        VEC coins(N);
        VEC chairs(T);

        rep (i, 0, N)
            cin >> coins[i];
        
        rep (i, 0, T)
            cin >> chairs[i];
        
        rep (t, 0, T)
        {
            ll min = -1, max = -1;

            rep (i, 0, N)
            {
                rep (j, i + 1, N)
                {
                    rep (k, j + 1, N)
                    {
                        rep (l, k + 1, N)
                        {
                            ll len = lcm(lcm(lcm(coins[i], coins[j]), coins[k]), coins[l]);

                            if (len < chairs[t])
                            {
                                if (min == -1)
                                    min = (chairs[t] / len) * len;
                                else
                                    min = min > ((chairs[t] / len) * len)? min: ((chairs[t] / len) * len);
                                
                                if (max == -1)
                                {
                                    if (chairs[t] % len != 0)
                                        max = (1 + chairs[t] / len) * len;
                                    else
                                        max = (chairs[t] / len) * len;
                                }
                                else
                                {
                                    if (chairs[t] % len != 0)
                                        max = max < ((1 + chairs[t] / len) * len)? max: ((1 + chairs[t] / len) * len);
                                    else
                                        max = (chairs[t] / len) * len;
                                }
                            }
                            else if (len == chairs[t])
                                min = max = len;
                            else
                            {
                                if (min == -1)
                                    min = 0;
                                
                                if (max == -1)
                                    max = len;
                                else
                                    max = max < len? max: len;
                            }
                        }
                    }
                }
            }

            cout << min << " " << max << "\n";
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