#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = LLONG_MAX >> 1;
int MOD = 1e9+7;

class SegmentTree{
    private:
        vector<int> t;
        int len;

    public:

        SegmentTree() {}
        SegmentTree(int n){
            len = n;
            t = vector<int>(4*n);
        }

        void build(vector<int> &a, int v, int tl, int tr)
        {
            if(tl == tr)
            {
                t[v] = a[tl];
                return;
            }

            int tm = (tl + tr)/2;

            build(a, v*2, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            t[v] = t[v*2] ^ t[v*2+1];
        }

        int query(int v, int l, int r,int tl,int tr)
        {
            //no overlap
            if(tl > r || tr < l) return 0;

            //full overlap

            if(tl >= l && tr <= r) return t[v];

            //partial overlap

            int tm = (tl + tr)/2;
            int lhs = query(v*2, l, r, tl, tm);
            int rhs = query(v*2+1, l, r, tm+1, tr);

            return lhs ^ rhs;
        }

        void build(vector<int> &a)
        {
            return build(a, 1, 0, len-1);
        }

        int query(int l, int r)
        {
            return query(1, l, r, 0, len-1);
        }

};


signed main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
        int l = x[0]--;
        int r = x[1]--;
        cout << st.query(l,r) << endl;
    }


    return 0;
}