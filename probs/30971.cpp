#include <iostream>

using namespace std;

int N, K, A[10], B[10], C[10], V[10] = { 0, };

int bt(int i, int t, int n)
{
    if (n == N) return t;
    else {
        int ret = -1;
        for (int j = 0; j < N; j++) {
            if (!V[j] && C[i]*C[j] <= K) {
                V[j] = 1;
                ret = max(ret, bt(j, t+A[i]*B[j], n+1));
                V[j] = 0;
            }
        }
        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];

    int ans = -1;
    for (int i = 0; i < N; i++) {
        V[i] = 1;
        ans = max(ans, bt(i, 0, 1));
        V[i] = 0;
    }
    cout << ans << '\n';

    return 0;
}
