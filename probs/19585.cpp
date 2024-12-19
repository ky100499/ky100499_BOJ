#include <bits/stdc++.h>

using namespace std;

typedef struct trie {
    char c;
    bool end;
    struct trie* children[26] = {};
} Trie;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int C, N; cin >> C >> N;
    Trie root;
    set<string> suffix;

    while (C--) {
        string ipt; cin >> ipt;
        Trie *ptr = &root;
        for (char c : ipt) {
            if (ptr->children[c-'a'] == nullptr) {
                Trie *child = new Trie();
                child->c = c;
                child->end = 0;
                ptr->children[c-'a'] = child;
            }
            ptr = ptr->children[c-'a'];
        }
        ptr->end = 1;
    }

    while (N--) {
        string ipt; cin >> ipt;
        suffix.insert(ipt);
    }

    int Q; cin >> Q;
    while (Q--) {
        string ipt; cin >> ipt;
        int ans = 0;
        Trie *ptr = &root;
        for (int i = 0; i < ipt.size() && !ans; i++) {
            if (ptr->children[ipt[i]-'a'] == nullptr) break;
            ptr = ptr->children[ipt[i]-'a'];

            if (ptr->end && suffix.find(ipt.substr(i+1)) != suffix.end()) ans = 1;
        }
        cout << (ans ? "Yes" : "No") << '\n';
    }

    return 0;
}
