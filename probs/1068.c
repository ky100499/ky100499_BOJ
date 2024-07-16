#include <stdio.h>

int N, P[50], dp[50] = { 0, }, D, root;

int dfs(int n);

int main()
{
    freopen("input.txt", "rt", stdin);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
        if (P[i] == -1)
            root = i;
    }
    scanf("%d", &D);

    dfs(root);

    printf("%d\n", dp[root] - dp[D] + (D != root && dp[P[D]] == dp[D]));
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
