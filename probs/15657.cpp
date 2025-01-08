#include <bits/stdc++.h>

using namespace std;

int N, M, A[9];

void bt(int i, int n, string s)
{
    if (n == M) cout << s << '\n';
    else
        for (int j = i; j < N; j++)
            bt(j, n+1, s+to_string(A[j])+' ');
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
