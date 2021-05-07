#include <iostream>
#include <map>

using namespace std;

#define ll long long int

void solve()
{
    ll n, a, b;

    while (cin >> n)
    {
        if (n == 0)
            break;
        
        cin >> a >> b;
        map<ll, ll> nums;
        ll x = 0, suc = 0;
        nums[x]++;

        while (true)
        {
            x = ((((((a % n) * (x % n)) % n) * (x % n)) % n) + (b % n)) % n;
            nums[x]++;

            if (nums[x] == 3)
                break;
            else if (nums[x] == 2)
                suc++;
        }

        cout << n - suc << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}