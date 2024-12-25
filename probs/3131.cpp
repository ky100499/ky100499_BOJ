#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e5,
          INF = 2e9;

ll S1[MAX+1] = {}, S2[MAX+1] = {}, arr[MAX+1] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int A, B, N; cin >> A >> B >> N;
    for (int i = 1; i < N; i++) cin >> arr[i]; arr[0] = INF;

    for (int i = 1; i < N; i++) {
        if (i%2) S1[i] = S1[i+1] = S1[i-1]+arr[i];
        else S2[i] = S2[i+1] = S2[i-1]+arr[i];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        ll l = arr[i+1]+1, h = arr[i];

        ll old = S1[i] - S1[0] + S2[N-1] - S2[i],
           young = S2[i] - S2[0] + S1[N-1] - S1[i];

        // 홀수 - 동생이 가져감
        if (i%2) {
            // A <= old - (young + x) <= B
            // x <= old - young - A
            // x >= old - young - B
            l = max(l, old - young - B);
            h = min(h, old - young - A);
        }
        // 짝수 - 형이 가져감
        else {
            // A <= old + x - young <= B
            // x >= A - old + young
            // x <= B - old + young
            l = max(l, A - old + young);
            h = min(h, B - old + young);
        }

        if (h >= l) cnt += h - l + 1;
    }

    cout << cnt << '\n';

    return 0;
}
