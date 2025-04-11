#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int INF = LLONG_MAX >> 1;

class SegmentTree {
    private: 
        vector<int> t;
        int len;
    public: 
    SegmentTree() {}

    SegmentTree(int n)
    {
        len = n;
        t.resize(4*n);
    }

    void build(vector<int>&a, int v,int tl, int tr)
    {
        if(tl == tr)
        {
            t[v] = a[tl];
            return;
        }
        int tm = (tl + tr)/2;
        build(a,v*2, tl, tm);
        build(a,v*2+1, tm+1, tr);
        t[v] = min(t[v*2] ,t[v*2+1]);
    }

    int query(int v, int tl, int tr, int l , int r)
    {
        // No overlap
        if(tr < l || tl > r) return INF;

        // total overlap
        if(tl >= l && tr <= r) return t[v];

        //partial overlap
        int tm = (tl + tr)/2;
        int leftans = query(v*2, tl, tm, l, r);
        int rightans = query(v*2+1, tm+1, tr, l, r);
        return min(leftans , rightans);
    }

    void build(vector<int>&a)
    {
        build(a,1,0,len-1);
    }

    int query(int l , int r)
    {
        return query(1,0,len-1 , l, r);
    }
};



signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i< n;i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> que;
    for(int i = 0; i< q;i++)
    {
        int l , r;
        cin >> l >> r;
        que.push_back({l,r});
    }

    SegmentTree st(n);
    
    st.build(arr);

    for(auto x : que)
    {
        int l = x[0]-1;
        int r = x[1]-1;
        cout << st.query(l,r) << endl;
    }
    return 0;
}
