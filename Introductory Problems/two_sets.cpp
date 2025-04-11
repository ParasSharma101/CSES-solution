#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int INF = LLONG_MAX >> 1;

signed main(){
    ios :: sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int totalSum = 0;
    for(int i = 1; i<= n;i++)
    {
        totalSum += i;
    }
    if(totalSum % 2) cout << "NO";
    else
    {
        int half = totalSum/2;
        vector<bool> track(n+1, false);
        vector<int > s1, s2;

        for(int i =n; i>=1;i--)
        {
            if(half == 0) break;
            if(half - i >= 0)
            {
                s1.push_back(i);
                track[i] = true;
                half -= i;
            }
        }
        half = totalSum/2;
        for(int i = 1; i < track.size();i++)
        {
            if(!track[i]) s2.push_back(i);
        }

        cout << "YES" << endl;
        cout << s1.size() << endl;
        for(int i =0; i< s1.size();i++)
            cout << s1[i] << " ";

        cout << endl;
        cout << s2.size() << endl;
        for(int i = 0; i < s2.size(); i++)
            cout << s2[i] << " ";
        
        
    }

}