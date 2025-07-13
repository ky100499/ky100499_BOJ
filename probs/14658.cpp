#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x <= b)

using namespace std;

pair<int, int> S[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, L, K; cin >> N >> M >> L >> K;
    for (int i = 0; i < K; i++) cin >> S[i].first >> S[i].second;

    int ans = K;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            int x = S[i].first, y = S[j].second, cnt = 0;
            for (int k = 0; k < K; k++) {
                if (
                    in(S[k].first - x, 0, L) &&
                    in(S[k].second - y, 0, L)
                ) cnt++;
            }

            ans = min(ans, K-cnt);
        }
    }

    cout << ans << '\n';

    return 0;
}
