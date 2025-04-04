#include <bits/stdc++.h>

using namespace std;

map<int, int> A;
int ans[51], N;

int dfs(int i)
{
    if (i == N+1) return 1;

    for (auto it = A.begin(); it != A.end(); it++) {
        if (it->second && ans[i-1]+1 != it->first) {
            it->second--;
            ans[i] = it->first;
            if (dfs(i+1)) return 1;
            it->second++;
        }
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        A[n]++;
    }

    ans[0] = -2;
    dfs(1);

    for (int i = 1; i <= N; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
