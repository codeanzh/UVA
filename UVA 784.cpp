#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ll long long int
#define VECS vector<string>
#define PAIR pair<ll, ll>
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define rep(i, st, n) for (ll i = st; i < n; i++)

bool check_end(string line)
{
    rep (i, 0, line.size())
        if (line[i] != '_')
            return false;
    
    return true;
}

void dfs_color(VECS &maze, PAIR coordinate)
{
    if (maze[coordinate.first][coordinate.second] == ' ' || maze[coordinate.first][coordinate.second] == '*')
    {
        maze[coordinate.first][coordinate.second] = '#';
        dfs_color(maze, mp(coordinate.first - 1, coordinate.second));
        dfs_color(maze, mp(coordinate.first - 1, coordinate.second - 1));
        dfs_color(maze, mp(coordinate.first - 1, coordinate.second + 1));
        dfs_color(maze, mp(coordinate.first, coordinate.second - 1));
        dfs_color(maze, mp(coordinate.first, coordinate.second + 1));
        dfs_color(maze, mp(coordinate.first + 1, coordinate.second - 1));
        dfs_color(maze, mp(coordinate.first + 1, coordinate.second));
        dfs_color(maze, mp(coordinate.first + 1, coordinate.second + 1));
    }
}

void solve()
{   
    ll tc;
    cin >> tc;
    string temp;
    getline(cin, temp);

    while (tc--)
    {
        VECS maze;
        string line;
        PAIR start;

        while (true)
        {
            getline(cin, line);
            maze.pb(line);

            rep (i, 0, line.size())
                if (line[i] == '*')
                    start = mp(maze.size(), i);

            if (check_end(line))
                break;
        }

        dfs_color(maze, mp(start.first - 1, start.second));
        dfs_color(maze, mp(start.first - 1, start.second - 1));
        dfs_color(maze, mp(start.first - 1, start.second + 1));
        dfs_color(maze, mp(start.first, start.second - 1));
        dfs_color(maze, mp(start.first, start.second + 1));
        dfs_color(maze, mp(start.first + 1, start.second - 1));
        dfs_color(maze, mp(start.first + 1, start.second));
        dfs_color(maze, mp(start.first + 1, start.second + 1));

        rep (i, 0, maze.size())
            cout << maze[i] + "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}