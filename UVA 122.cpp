#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define ll long long int
#define rep(i, st, n) for (ll i = st; i < n; i++)

struct node
{
    string data;
    node * left = NULL, * right = NULL;
};

void solve()
{
    string str;

    while (cin >> str)
    {
        bool flag = true;
        node * root = new node;

        while (str != "()")
        {
            node * ptr = root;

            rep (i, str.find(",") + 1, str.size() - 1)
            {
                if (str[i] == 'L')
                {
                    if (ptr->left == NULL)
                        ptr->left = new node;
                    
                    ptr = ptr->left;
                }
                else
                {
                    if (ptr->right == NULL)
                        ptr->right = new node;
                    
                    ptr = ptr->right;
                }
            }

            if (ptr->data.size() == 0)
                ptr->data = str.substr(1, str.find(",") - 1);
            else
                flag = false;
            
            cin >> str;
        }

        if (flag)
        {
            queue<node *> Q;
            Q.push(root);
            string ans;

            while (!Q.empty())
            {
                queue<node *> Q1;

                while (!Q.empty())
                {
                    if (Q.front()->data.size() == 0)
                        flag = false;
                    
                    ans += Q.front()->data + " ";
                    
                    if (Q.front()->left != NULL)
                        Q1.push(Q.front()->left);
                    
                    if (Q.front()->right != NULL)
                        Q1.push(Q.front()->right);

                    Q.pop();
                }

                Q = Q1;
            }

            if (flag)
                cout << ans.substr(0, ans.size() - 1) + "\n";
            else
                cout << "not complete\n";
        }
        else
            cout << "not complete\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}