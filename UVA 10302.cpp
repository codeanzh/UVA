#include <iostream>

using namespace std;

#define ll long long int

void solve()
{
    ll n;

    while (cin >> n)
        cout << (((n * (n + 1)) / 2) * ((n * (n + 1)) / 2)) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}