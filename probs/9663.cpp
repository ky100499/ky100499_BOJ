#include <bits/stdc++.h>

using namespace std;

int N, V[15][15] = {}, ans = 0;

void bt(int i)
{
    if (i == N) ans++;
    else {
        for (int j = 0; j < N; j++) {
            if (!V[i][j]) {
                for (int k = i+1; k < N; k++) V[k][j] += 1;
                for (int k = 1; i+k < N && j+k < N; k++) V[i+k][j+k] += 1;
                for (int k = 1; i+k < N && k <= j; k++) V[i+k][j-k] += 1;
                bt(i+1);
                for (int k = i+1; k < N; k++) V[k][j] -= 1;
                for (int k = 1; i+k < N && j+k < N; k++) V[i+k][j+k] -= 1;
                for (int k = 1; i+k < N && k <= j; k++) V[i+k][j-k] -= 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    bt(0);
    cout << ans << '\n';

    return 0;
}
