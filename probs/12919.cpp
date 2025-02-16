#include <bits/stdc++.h>

using namespace std;

string S, T;

bool solve(int s, int e, int rev)
{
    if (e-s == S.size()) {
        if (rev) {
            for (int i = 0; i < e-s; i++)
                if (S[i] != T[e-i-1])
                    return 0;
        }
        else {
            for (int i = 0; i < e-s; i++)
                if (S[i] != T[s+i])
                    return 0;
        }

        return 1;
    }

    if (rev) {
        if (T[s] == 'A' && solve(s+1, e, 1)) return 1;
        if (T[e-1] == 'B' && solve(s, e-1, 0)) return 1;
    }
    else {
        if (T[e-1] == 'A' && solve(s, e-1, 0)) return 1;
        if (T[s] == 'B' && solve(s+1, e, 1)) return 1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> S >> T;
    cout << solve(0, T.size(), 0) || solve(0, T.size(), 1) << '\n';

    return 0;
}
