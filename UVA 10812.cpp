#include <iostream>

using namespace std;

#define ll long long int
#define wtc() ll tc; cin >> tc; while (tc--)

void solve()
{
    wtc()
    {
        ll s, d;
        cin >> s >> d;

        if ((s + d) % 2 == 0 && (s - ((s + d) / 2)) >= 0)
            cout << ((s + d) / 2) << " " << (s - ((s + d) / 2)) << "\n";
        else
            cout << "impossible\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}