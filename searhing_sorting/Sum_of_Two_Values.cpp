#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void helper(int i, vector<vector<char>> &chess)
{

}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    // int tc; 
    // cin >> tc;    
    // while (tc--) 
    // {            
            int n , x;
            cin >> n >> x;

            vector<pair<int,int>> nums(n);
            for(int i = 0; i<n;i++) 
            {
                int val;
                cin >> val;
                nums[i] = {val,i};
            }

            sort(nums.begin(), nums.end());

            int i = 0, j = n-1;
            bool flag = false;
            while(i < j)
            {
                int sum = nums[i].first + nums[j].first;

                if(sum == x)
                {
                    flag = true;
                    break;

                }

                if(sum < x) i++;
                else if(sum > x) j--;
            }

            if(!flag) cout << "IMPOSSIBLE";
            else
            {
                cout << nums[i].second+1 << " " << nums[j].second+1;
            }

    // }
}
