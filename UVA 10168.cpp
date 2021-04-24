#include <iostream>
#include <vector>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define V(a) vector<a>
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)

void solve()
{
    ll n;
    V(bool) is_prime(1e7 + 1, true);
    VEC primes;
    is_prime[0] = is_prime[1] = false;

    for (ll i = 2; i * i <= 1e7; i++)
        for (ll j = 2 * i; j <= 1e7; j += i)
            is_prime[j] = false;
    
    rep (i, 0, 1e7 + 1)
        if (is_prime[i])
            primes.pb(i);
    
    while (cin >> n)
    {
        if (n < 8)
            cout << "Impossible.\n";
        else if (n % 2 == 0)
        {
            n -= 4;
            ll num = -1;

            for (ll i = 0; i < primes.size() && n - primes[i] >= primes[i]; i++)
                if (is_prime[n - primes[i]])
                {
                    num = primes[i];
                    break;
                }
            
            if (num == -1)
                cout << "Impossible.\n";
            else
                cout << 2 << " " << 2 << " " << num << " " << n - num << "\n";
        }
        else
        {
            n -= 5;
            ll num = -1;

            for (ll i = 0; i < primes.size() && n - primes[i] >= primes[i]; i++)
                if (is_prime[n - primes[i]])
                {
                    num = primes[i];
                    break;
                }
            
            if (num == -1)
                cout << "Impossible.\n";
            else
                cout << 2 << " " << 3 << " " << num << " " << n - num << "\n";
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