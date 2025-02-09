#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4;

int A[MAX];

void solve(int s, int e)
{
    if (e <= s) return;
    else if (s+1 == e) {
        cout << A[s] << '\n';
        return;
    }

    int idx = lower_bound(A+s+1, A+e, A[s])-A;
    solve(s+1, idx);
    solve(idx, e);

    cout << A[s] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int len = 0;
    while (1) {
        cin >> A[len];
        if (cin.eof()) break;
        len++;
    }

    solve(0, len);

    return 0;
}
