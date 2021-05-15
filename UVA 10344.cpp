#include <iostream>
#include <vector>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define V(a) vector<a>
#define rep(i, st, n) for (ll i = st; i < n; i++)

bool pos(ll sum, VEC &arr, V(bool) &choosen)
{
    bool flag = true;

    rep(i, 0, 5)
        if (!choosen[i])
        {
            choosen[i] = true;
            flag = false;
            
            if (pos(sum + arr[i], arr, choosen) || pos(sum - arr[i], arr, choosen) || pos(sum * arr[i], arr, choosen))
                return true;
            
            choosen[i] = false;
        }
    
    if (flag && sum == 23)
        return true;
    
    return false;
}

void solve()
{
    VEC arr(5);

    while (true)
    {
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

        if (arr[0] == 0)
            break;
        
        V(bool) choosen(5, false);
        bool flag = false;

        rep (i, 0, 5)
        {
            choosen[i] = true;

            if (pos(arr[i], arr, choosen))
            {
                flag = true;
                break;
            }

            choosen[i] = false;
        }

        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}