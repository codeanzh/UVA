#include <iostream>
#include<iomanip>

using namespace std;

#define ll long long int

ll cube_root(ll n)
{
    ll i = 1;
    for (; i * i * i <= n; i++);

    return --i;
}

double cal_dx(double n, double a) { return (n - a * a * a) / (3 * a * a); }

void solve()
{
    double n;

    while (cin >> n)
    {
        if (n == 0)
            break;
        
        double a = cube_root(n);
        double dx = cal_dx(n, a);

        while (dx > 0)
        {
            a += dx;
            dx = cal_dx(n, a);
        }

        cout << fixed << setprecision(4) << a << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}