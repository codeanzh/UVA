#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define VEC vector<ll>
#define VECV vector<VEC>
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)

ll get_index(VEC &bitarr, ll a)
{
    rep (i, 0, bitarr.size())
        if (bitarr[i] & (1 << a))
            return i;
}

void solve()
{
    ll n, a, b, num, indexa, indexb;
    cin >> n;
    VECV arr(n);
    VEC bitarr(n, 0);
    stack<ll> to_push;

    rep (i, 0, n)
    {
        arr[i].pb(i);
        bitarr[i] |= (1 << i);
    }

    string cmd, first, second;
    getline(cin, cmd);

    while (getline(cin, cmd))
    {
        if (cmd == "quit")
            break;
        
        stringstream ss(cmd);
        ss >> first; ss >> a; ss >> second; ss >> b;
        indexa = get_index(bitarr, a);
        indexb = get_index(bitarr, b);

        if (a == b || indexa == indexb)
            continue;
        
        if (first == "move")
        {
            for (int i = (ll)arr[indexa].size() - 1; arr[indexa][i] != a; i--)
            {
                num = arr[indexa][i];
                bitarr[indexa] ^= (1 << num);
                bitarr[num] |= (1 << num);
                arr[indexa].pop_back();
                arr[num].pb(num);
            }
        }

        if (second == "onto")
        {
            for (int i = (ll)arr[indexb].size() - 1; arr[indexb][i] != b; i--)
            {
                num = arr[indexb][i];
                bitarr[indexb] ^= (1 << num);
                bitarr[num] |= (1 << num);
                arr[indexb].pop_back();
                arr[num].pb(num);
            }
        }

        do
        {
            num = arr[indexa][(ll)arr[indexa].size() - 1];
            bitarr[indexa] ^= (1 << num);
            bitarr[indexb] |= (1 << num);
            arr[indexa].pop_back();
            to_push.push(num);
        } while (num != a);
        
        while (!to_push.empty())
        {
            arr[indexb].pb(to_push.top());
            to_push.pop();
        }
    }

    rep (i, 0, n)
    {
        cout << i << ":";

        rep (j, 0, arr[i].size())
            cout << " " << arr[i][j];
        
        cout << "\n";
    }
}

int main()
{
    fastio

    solve();

    return 0;
}