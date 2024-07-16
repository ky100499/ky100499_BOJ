#include <iostream>

using namespace std;

int N, P[50], dp[50] = { 0, }, D, root;

int dfs(int n);

int main()
{
    freopen("input.txt", "rt", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        if (P[i] == -1)
            root = i;
    }
    cin >> D;

    dfs(root);

    cout << dp[root] - dp[D] + (D != root && dp[P[D]] == dp[D]) << endl;
}

int dfs(int n)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
        if (P[i] == n)
            cnt += dfs(i);
    if (cnt == 0) cnt = 1;

    dp[n] = cnt;
    return cnt;
}
