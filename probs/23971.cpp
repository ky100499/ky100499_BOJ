#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int H, W, N, M; cin >> H >> W >> N >> M;
    cout << ((H+N)/(N+1)) * ((W+M)/(M+1)) << '\n';

    return 0;
}
