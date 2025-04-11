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

    void update(int v, int tl, int tr, int id, int val)
    {
        if(id == tl && id == tr)
        {
            t[v] = val;
            return;
        }

        if(id > tr || id < tl) return;

        int tm = (tl+ tr)/2;

        update(2*v, tl, tm, id, val);
        update(2*v+1, tm+1, tr, id, val);

        t[v] = min(t[2*v] , t[v*2+1]);
    }

    void build(vector<int>&a)
    {
        build(a,1,0,len-1);
    }

    void update(int id, int val)
    {
        update(1, 0, len-1, id, val);
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
        int t;
        int l , r;
        cin >> t;
        cin >> l >> r;
        que.push_back({t, l, r});
    }

    SegmentTree st(n);
    
    st.build(arr);

    for(auto x : que)
    {
        int t = x[0];
        if(t == 1)
        {
            int k = x[1]-1;
            int u = x[2];
            st.update(k, u);
        }
        else if(t == 2)
        {
            int l = x[1]-1;
            int r = x[2]-1;
            cout << st.query(l,r) << endl;
        }
        
    }
    return 0;
}

