#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;

struct TrieNode {
    bool isEnd = false;
    unordered_map<char, TrieNode*> children;
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->children.count(ch)) {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEnd = true;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int k;
    cin >> k;

    TrieNode* root = new TrieNode();
    int maxWordLen = 0;

    for (int i = 0; i < k; ++i) {
        string word;
        cin >> word;
        insert(root, word);
        maxWordLen = max(maxWordLen, (int)word.size());
    }

    vector<int> dp(n + 1, 0);
    dp[n] = 1;  // Empty string has one way

    for(int i = n-1; i>= 0; i--)
    {
        TrieNode *node = root;
        for(int j = i; j< n;j++)
        {
            if(!node->children.count(s[j]))
            {
                break;
            }
            node = node->children[s[j]];
            if(node->isEnd == true)
            {
                dp[i] = (dp[i] %MOD + dp[j+1]%MOD) %MOD;
            }
        }
    }
    

    cout << dp[0] << "\n";
    return 0;
}
