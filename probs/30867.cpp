#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int L, N; cin >> L >> N;
    string S; cin >> S;

    int cnt = 0;
    for (int i = 0; i < L; i++) {
        if (S[i] == 'h') {
            while (cnt-- > N) cout << 'w';
            cnt++;
            cout << 'h';
        }
        else if (S[i] == 'w') {
            cnt++;
        }
        else {
            while (cnt--) cout << 'w';
            cout << S[i];
            cnt = 0;
        }
    }

    while (cnt-- > 0) cout << 'w';
    cout << '\n';

    return 0;
}
