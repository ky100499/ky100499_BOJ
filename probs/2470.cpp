#include <bits/stdc++.h>

using namespace std;

int sol[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> sol[i];
    sort(sol, sol+N);

    int i = 0, j = N-1;
    int s = 2e9+1;
    pair<int, int> ans;
    while (i < j) {
        int ns = sol[i]+sol[j];
        if (abs(ns) < s) {
            s = abs(ns);
            ans = {sol[i], sol[j]};
        }

        if (ns > 0) j -= 1;
        else if (ns < 0) i += 1;
        else break;
    }

    cout << ans.first << ' ' << ans.second << '\n';

    return 0;
}
