#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long int
#define VEC vector<ll>
#define VECV vector<VEC>
#define PAIR pair<ll, ll>
#define VECP vector<PAIR>
#define V(a) vector<a>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)

bool check_point(set<PAIR> board, ll n, ll m)
{
    for (set<PAIR>::iterator itr = board.begin(); itr != board.end(); itr++)
    {
        if (n - m - ((*itr).first - (*itr).second) == 0)
            return false;
        else if (n + m - ((*itr).first + (*itr).second) == 0)
            return false;
    }

    return true;
}

VECV complete_ans;

bool cmp(PAIR a, PAIR b) { return a.second < b.second; }

void back_queen(ll n, ll i, V(bool) &taken, set<PAIR> &board, VEC &posibility)
{
    if (i == 9)
    {
        VECP ans;

        rep(j, 1, 9)
            ans.pb(mp(j, posibility[j]));
        
        sort(ans.begin(), ans.end(), cmp);

        VEC ans_;

        rep (j, 0, 8)
            ans_.pb(ans[j].first);

        complete_ans.pb(ans_);
    }
    if (i == n)
        back_queen(n, i + 1, taken, board, posibility);
    else
    {
        rep (j, 1, 9)
        {
            if (!taken[j] && check_point(board, i, j))
            {
                board.insert(mp(i, j));
                taken[j] = true;
                posibility[i] = j;
                back_queen(n, i + 1, taken, board, posibility);
                board.erase(mp(i, j));
                taken[j] = false;
            }
        }
    }
}

void solve()
{
    ll tc;
    cin >> tc;

    rep (t, 0, tc)
    {
        complete_ans = VECV();
        if (t)
            cout << "\n";

        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
        ll n, m;
        cin >> n >> m;
        V(bool) taken(9, false);
        set<PAIR> board;
        taken[m] = true;
        board.insert(mp(n, m));
        VEC posibility(9);
        posibility[n] = m;

        if (n != 1)
        {
            rep (j, 1, 9)
            {
                if (!taken[j] && check_point(board, 1, j))
                {
                    board.insert(mp(1, j));
                    taken[j] = true;
                    posibility[1] = j;
                    back_queen(n, 2, taken, board, posibility);
                    board.erase(mp(1, j));
                    taken[j] = false;
                }
            }
        }
        else
            back_queen(n, 2, taken, board, posibility);

        sort(complete_ans.begin(), complete_ans.end());

        rep (i, 0, complete_ans.size())
        {
            if (i < 9)
                cout << " ";
            
            cout << i + 1 << "      ";

            rep (j, 0, 8)
                if (j)
                    cout << " " << complete_ans[i][j];
                else
                    cout << complete_ans[i][j];
            
            cout << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}