#include <bits/stdc++.h>

using namespace std;

int O[3] = {
    0b101010,
    0b010101,
    0b001001,
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    int C[] = { N/2, (N+1)/2, (N+2)/3 };

    set<int> ans;
    for (int i = 0; i < 1<<3; i++) {
        int m = 0, s = 0;
        for (int j = 0; j < 3; j++) {
            if (i & (1<<j)) {
                m += C[j];
                s ^= O[j];
            }
        }
        if (m <= M) ans.insert(s & ((1<<min(N, 6))-1));
    }

    cout << ans.size() << '\n';

    return 0;
}
