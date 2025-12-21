#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+1;

int SO[MAX], SE[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    memset(SO, 0, sizeof SO);
    memset(SE, 0, sizeof SE);
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        if (i%2) SO[i] = SO[i+1] = SO[i-1] + a;
        else SE[i] = SE[i+1] = SE[i-1] + a;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(
            ans,
            SO[i-1] - SE[i-1] + SE[N-1+i%2]
        );
    }

    cout << ans << '\n';

    return 0;
}
