#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long int
#define VEC vector<ll>
#define VECV vector<VEC>
#define rep(i, st, n) for (ll i = st; i < n; i++)

ll lcs(string str1, string str2)
{
    VECV DP(str1.size() + 1, VEC(str2.size() + 1, 0));

    rep (i, 1, (ll)str1.size() + 1)
        rep (j, 1, (ll)str2.size() + 1)
            if (str1[i - 1] == str2[j - 1])
                DP[i][j] = 1 + DP[i - 1][j - 1];
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
    
    return DP[str1.size()][str2.size()];
}

void solve()
{
    string str1, str2;
    int t = 1;

    while (getline(cin, str1))
    {
        if (str1[0] == '#')
            break;
        
        getline(cin, str2);
        cout << "Case #" << t << ": you can visit at most " << lcs(str1, str2) << " cities.\n";
        t++;
    }
}

int main()
{
    fastio

    solve();

    return 0;
}