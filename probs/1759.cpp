#include <bits/stdc++.h>

#define isVowel(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')

using namespace std;

vector<char> A;
int L, C;

void bt(int i, int n, int c, int v, string s)
{
    if (n == L) {
        if (c >= 2 && v >= 1) cout << s << '\n';
        return;
    }
    if (i == C) return;

    isVowel(A[i]) ? bt(i+1, n+1, c, v+1, s+A[i]) : bt(i+1, n+1, c+1, v, s+A[i]);
    bt(i+1, n, c, v, s);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> L >> C; A.resize(C);
    for (int i = 0; i < C; i++) cin >> A[i];
    sort(A.begin(), A.end());

    bt(0, 0, 0, 0, "");

    return 0;
}
