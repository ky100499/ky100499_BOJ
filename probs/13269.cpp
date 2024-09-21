#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<vector<int>> B(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            cin >> B[i][j];
    vector<int> F(M), S(N), CF(M), CS(N);
    for (int i = 0; i < M; i++) cin >> F[i];
    for (int i = N-1; i >= 0; i--) cin >> S[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (B[i][j]) {
                if (S[i] < F[j]) {
                    CS[i] = 1;
                    B[i][j] = S[i];
                }
                else if (S[i] > F[j]) {
                    CF[j] = 1;
                    B[i][j] = F[j];
                }
                else {
                    CS[i] = CF[j] = 1;
                    B[i][j] = S[i];
                }
            }
        }
    }

    if (
        all_of(CF.begin(), CF.end(), [](int x) {return x;}) &&
        all_of(CS.begin(), CS.end(), [](int x) {return x;})
    ) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << B[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    else cout << "-1\n";

    return 0;
}
