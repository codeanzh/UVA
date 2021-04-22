#include <iostream>
#include <vector>

using namespace std;

#define ll long long int
#define PAIR pair<ll, ll>
#define VECP vector<PAIR>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

void solve()
{
    ll n;
    vector<bool> primes(20000001, true);
    primes[0] = false;
    primes[1] = false;
    VECP twin_prime;

    for (ll i = 2; i * i < 20000001; i++)
    {
        for (ll j = 2 * i; j < 20000001; j += i)
            primes[j] = false;
    }

    for (ll i = 3; i < 20000001; i++)
        if (primes[i] && primes[i + 2])
            twin_prime.pb(mp(i, i + 2));

    while (cin >> n)
        cout << "(" << twin_prime[n - 1].first << ", " << twin_prime[n - 1].second << ")\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}