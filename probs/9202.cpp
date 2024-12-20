#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

typedef struct trie {
    char c;
    bool end;
    string s;
    int chk;
    struct trie* children[26] = {};
} Trie;

char boggle[4][4];
int V[4][4],
    mv[8][2] = {
        {1,0},
        {1,1},
        {0,1},
        {-1,1},
        {-1,0},
        {-1,-1},
        {0,-1},
        {1,-1}
    },
    pts[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
int ansp, ansc; string anss;

void dfs(int x, int y, Trie *ptr, int B)
{
    if (ptr->children[boggle[x][y]-'A'] == nullptr) return;
    ptr = ptr->children[boggle[x][y]-'A'];

    if (ptr->end && ptr->chk != B) {
        ptr->chk = B;
        int l = ptr->s.size();
        ansp += pts[l];
        ansc++;
        if (l > anss.size()) anss = ptr->s;
        else if (l == anss.size()) anss = min(anss, ptr->s);
    }

    for (auto [dx, dy] : mv) {
        int nx = x+dx, ny = y+dy;
        if (0 <= nx && nx < 4 && 0 <= ny && ny < 4 && !V[nx][ny]) {
            V[nx][ny] = 1;
            dfs(nx, ny, ptr, B);
            V[nx][ny] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int W; cin >> W;
    Trie root;

    while (W--) {
        string ipt; cin >> ipt;
        Trie *ptr = &root;
        for (char c : ipt) {
            if (ptr->children[c-'A'] == nullptr) {
                Trie *child = new Trie();
                child->c = c;
                child->end = 0;
                ptr->children[c-'A'] = child;
            }
            ptr = ptr->children[c-'A'];
        }
        ptr->end = 1;
        ptr->s = ipt;
        ptr->chk = -1;
    }

    int B; cin >> B;
    while (B--) {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                cin >> boggle[i][j];

        ansp = ansc = 0; anss = "";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                memset(V, 0, sizeof V); V[i][j] = 1;
                dfs(i, j, &root, B);
            }
        }
        cout << ansp << ' ' << anss << ' ' << ansc << '\n';
    }

    return 0;
}
