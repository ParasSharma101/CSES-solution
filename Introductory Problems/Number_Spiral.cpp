#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int INF = LLONG_MAX >> 1;

signed main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    vector<pair<int,int>> test;
    while(t--)
    {
        int x, y;
        cin >> y >> x;

        if(y > x)
        {
            if(y % 2)
            {
                int res = (y-1)*(y-1) + 1 + (x-1);
                cout << res << endl;
            }
            else
            {
                int res = (y*y) - (x-1);
                cout << res << endl;
            }
            
        }
        else
        {
            if(x % 2)
            {
                int res = (x * x) - (y-1);
                cout << res << endl;
            }
            else
            {
                int res = (x-1)*(x-1)+1 +(y-1);
                cout << res << endl;
            }
        }

    }

}