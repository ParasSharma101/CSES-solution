#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int INF = LLONG_MAX >> 1;

int helper(int k){
    int totalways = (k*k)*(k*k -1)/2;
    int attackingways = 4*(k-1)*(k-2);

    return totalways - attackingways;
}

signed main(){
    ios :: sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        int res = helper(i);
        cout << res << endl;
    }

    return 0;
}