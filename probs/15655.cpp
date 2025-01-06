#include <bits/stdc++.h>

using namespace std;

int A[10], N, M;

void bt(int i, int n, string s)
{
    if (n == M) cout << s << '\n';
    else if (i == N) return;
    else {
        bt(i+1, n+1, s+to_string(A[i])+' ');
        bt(i+1, n, s);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    bt(0, 0, "");

    return 0;
}
