#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define pb(a) push_back(a)
#define repr(i, st, n) for (ll i = st; i >= n; i--)

ll func(VEC &coff, ll x)
{
    ll num = 1, sum = 0;

    repr (i, coff.size() - 1, 0)
    {
        sum += num * coff[i];
        num *= x;
    }

    return sum;
}

void solve()
{
    string str1, str2;

    while (getline(cin,str1))
    {
        getline(cin, str2);
        VEC coff;
        stringstream ss1(str1);
        string str_num;

        while (ss1 >> str_num)
        {
            stringstream ss_num(str_num);
            ll num;
            ss_num >> num;
            coff.pb(num);
        }

        stringstream ss2(str2);
        bool flag = false;
        
        while (ss2 >> str_num)
        {
            if (flag)
                cout << " ";

            stringstream ss_num(str_num);
            ll x;
            ss_num >> x;
            cout << func(coff, x);
            flag = true;
        }

        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}