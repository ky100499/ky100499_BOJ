#include <bits/stdc++.h>

using namespace std;

typedef struct trie {
    string name;
    map<string, struct trie *> children;
} Trie;

void printTrie(int depth, Trie *node)
{
    if (depth) {
        for (int i = 1; i < depth; i++) cout << "--";
        cout << node->name << '\n';
    }

    for (auto [_, child] : node->children) printTrie(depth+1, child);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    Trie root;

    while (N--) {
        int K; cin >> K;
        Trie* cursor = &root;
        while (K--) {
            string ipt; cin >> ipt;
            if (cursor->children.find(ipt) == cursor->children.end()) {
                Trie *child = new Trie();
                child->name = ipt;
                cursor->children[ipt] = child;
            }
            cursor = cursor->children[ipt];
        }
    }

    printTrie(0, &root);

    return 0;
}
