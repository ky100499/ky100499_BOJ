#include <iostream>

using namespace std;

int S[20][20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];

    int ans = 1000000;
    for (int t = 1; t < (1<<(N-1)); t++) {
        int diff = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (t&(1<<i) && t&(1<<j))
                    diff += S[i][j] + S[j][i];
                else if (!(t&(1<<i) || t&(1<<j)))
                    diff -= S[i][j] + S[j][i];
            }
        }
        ans = min(ans, diff > 0 ? diff : -diff);
    }
    cout << ans << '\n';
}
