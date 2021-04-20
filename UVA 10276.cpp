#include <iostream>
#include <vector>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define rep(i, st, n) for (ll i = st; i < n; i++)
#define wtc() ll tc; cin >> tc; while (tc--)

bool check_sqrt(ll n)
{
    ll i = 1;
    for (; i * i <= n; i++);
    i--;
    
    return i * i == n;
}

void solve()
{
    wtc()
    {
        ll n, ans = 1;
        cin >> n;
        VEC pegs(n, 0);

        while (true)
        {
            bool flag = true;

            rep (i, 0, n)
                if (pegs[i] == 0 || check_sqrt(pegs[i] + ans))
                {
                    pegs[i] = ans++;
                    flag = false;
                    break;
                }
            
            if (flag)
                break;
        }

        cout << ans - 1 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}