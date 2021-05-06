#include <iostream>

using namespace std;

#define ll long long int

void solve()
{
    ll n, m;
    
    while (cin >> n >> m)
        cout << (n ^ m) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();

    return 0;
}