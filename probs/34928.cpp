#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    if (N%2) cout << "NO\n";
    else {
        int C[4] = {0,};
        for (int i = 0; i < N; i++) {
            char c; cin >> c;
            if (c == 'P' && i%2 == 0) C[0] = 1;
            if (c == 'A' && i%2 == 1 && C[0]) C[1] = 1;
            if (c == 'U' && i%2 == 0 && C[1]) C[2] = 1;
            if (c == 'L' && i%2 == 1 && C[2]) C[3] = 1;
        }

        cout << (C[3] ? "YES" : "NO") << '\n';
    }

    return 0;
}
