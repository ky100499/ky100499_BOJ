#include <bits/stdc++.h>

using namespace std;

int A[7], N, M;

void bt(int n, string res)
{
    if (n == M) {
        cout << res << '\n';
    }
    else {
        for (int i = 0; i < N; i++) {
            bt(n+1, res + to_string(A[i]) + ' ');
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) A[i] = i+1;

    bt(0, "");

    return 0;
}
