#include <bits/stdc++.h>

using namespace std;

string A[10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (A[i][j] != s[2*j] || A[i][j] != s[2*j+1]) {
                cout << "Not Eyfa\n";
                return 0;
            }
        }
    }
    cout << "Eyfa\n";

    return 0;
}
