#include <bits/stdc++.h>

using namespace std;

int check[][4] = {
    {0, 2, 5, 7},
    {0, 3, 6, 10},
    {7, 8, 9, 10},
    {1, 2, 3, 4},
    {1, 5, 8, 11},
    {4, 6, 9, 11},
};

string prt[5] = {
    "....x....",
    ".x.x.x.x.",
    "..x...x..",
    ".x.x.x.x.",
    "....x....",
};

int star[12],
    V[13];

bool bt(int i)
{
    if (i == 12) {
        for (auto chk : check) {
            int s = 0;
            for (int j = 0; j < 4; j++) s += star[chk[j]];
            if (s != 26) return 0;
        }
        return 1;
    }

    if (star[i]) return bt(i+1);
    else {
        for (int j = 1; j <= 12; j++) {
            if (!V[j]) {
                V[j] = 1;
                star[i] = j;
                if (bt(i+1)) return 1;
                V[j] = 0;
                star[i] = 0;
            }
        }
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int idx = 0;
    memset(V, 0, sizeof V);
    for (int i = 0; i < 5; i++) {
        string ipt; cin >> ipt;
        for (auto c : ipt) {
            if (c == '.') continue;
            else if (c == 'x') star[idx++] = 0;
            else {
                star[idx] = c - 'A' + 1;
                V[star[idx++]] = 1;
            }
        }
    }

    bt(0);

    idx = 0;
    for (auto p : prt) {
        for (auto c : p) {
            if (c == '.') cout << '.';
            else cout << (char)(star[idx++]+'A'-1);
        }
        cout << '\n';
    }

    return 0;
}
