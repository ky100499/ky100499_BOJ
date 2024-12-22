#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

typedef struct trie {
    char c;
    int cnt;
    string s;
    struct trie* children[26] = {};
} Trie;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    Trie root;

    while (N--) {
        string ipt; cin >> ipt;
        Trie *ptr = &root;
        string ans = ""; bool end = 0;
        for (char c : ipt) {
            if (!end) ans += c;
            if (ptr->children[c-'a'] == nullptr) {
                Trie *child = new Trie();
                child->c = c;
                child->cnt = 0;
                ptr->children[c-'a'] = child;
                end = 1;
            }
            ptr = ptr->children[c-'a'];
        }
        ptr->cnt++;
        ptr->s = ipt;

        cout << (end || ptr->cnt <= 1 ? ans : ipt+to_string(ptr->cnt)) << '\n';
    }

    return 0;
}
