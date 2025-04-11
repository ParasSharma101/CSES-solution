#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int INF = LLONG_MAX >> 1;

// bool helper(vector<int> &ans, int n, vector<bool> &picked)
// {
//     if(ans.size() == n)
//         return true;

//     for(int i = 1; i<= n; i++)
//     {
//         if(!ans.empty() || ((i- ans.back() != 1) && !picked[i]))
//         {
//             ans.push_back(i);
//             picked[i] = true;
//             if(helper(ans, n , picked)) return true;
//             ans.pop_back();
//             picked[i] = false;
//         }
//     }
//     return false;
// }

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(nullptr);

    int n;
    cin >> n;

    // vector<bool> picked(n+1, false);
    // vector<int> ans;
    // bool res = helper(ans, n, picked);

    // if(res)
    // {
    //     for(int i = 0; i< ans.size(); i++)
    //     {
    //         cout << ans[i] << " ";
    //     }
    // }
    // else
    // {
    //     cout << "NO SOLUTION";
    // }
    
    if(n == 1) cout << 1 ;
    else if(n == 2 || n == 3) cout << "NO SOLUTION";
    else
    {
        for(int i = 2; i <= n; i+=2) cout << i << " ";
        for(int i = 1; i<= n; i+= 2) cout << i << " ";
    }

    return 0;
}
