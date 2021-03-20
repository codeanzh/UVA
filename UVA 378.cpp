#include <iostream>
#include <iomanip>

using namespace std;

#define ll long long int
#define rep(st, n) for (ll i = st; i < n; i++)

bool f (double x, double y, double x1, double y1, double x2, double y2) { return (y - y1) * (x2 - x1) - (y2 - y1) * (x - x1) == 0; }

double f_x(double x, double x1, double y1, double x2, double y2) { return y1 + (x - x1) * (y2 - y1) / (x2 - x1); }

void solve()
{   
    ll n;
    double x1, y1, x2, y2, x3, y3, x4, y4, x, y;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT\n";

    rep(0, n)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        if (y2 - y1 == 0 && y4 - y3 == 0 && y2 == y3)
            cout << "LINE\n";
        else if (y2 - y1 == 0 && y4 - y3 == 0 && y2 != y3)
            cout << "NONE\n";
        else if (x2 - x1 == 0 && x4 - x3 == 0 && x2 == x3)
            cout << "LINE\n";
        else if (x2 - x1 == 0 && x4 - x3 == 0 && x2 != x3)
            cout << "NONE\n";
        else if ((y2 - y1 == 0 && y4 - y3 != 0) || (y2 - y1 != 0 && y4 - y3 == 0) || (x2 - x1 == 0 && x4 - x3 != 0) || (x2 - x1 != 0 && x4 - x3 == 0))
        {
            cout << "POINT ";

            if (y2 - y1 == 0)
            {
                y = y1;
                x = x3 + (y1 - y3) * (x3 - x4) / (y3 - y4);
            }
            else if (y3 - y4 == 0)
            {
                y = y3;
                x = x1 + (y3 - y1) * (x1 - x2) / (y1 - y2);
            }
            else if (x1 - x2 == 0)
            {
                x = x1;
                y = y3 + (x1 - x3) * (y3 - y4) / (x3 - x4);
            }
            else
            {
                x = x3;
                y = y1 + (x3 - x1) * (y1 - y2) / (x1 - x2);
            }

            cout << fixed << setprecision(2) << x << " " << y << "\n";
        }
        else
        {
            if ((y2 - y1) * (x4 - x3) == (y4 - y3) * (x2 - x1))
            {
                if (f(x1, y1, x3, y3, x4, y4))
                    cout << "LINE\n";
                else
                    cout << "NONE\n";
            }
            else
            {
                cout << "POINT ";
                x = (y1 * (x4 - x3) * (x2 - x1) + x3 * (y4 - y3) * (x2 - x1) - x1 * (y2 - y1) * (x4 - x3) - y3 * (x2 - x1) * (x4 - x3)) / ((x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3));
                y = f_x(x, x1, y1, x2, y2);
                cout << fixed << setprecision(2) << x << " " << y << "\n";
            }
        }
    }

    cout << "END OF OUTPUT\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();

    return 0;
}