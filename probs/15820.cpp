#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;

    while (N--) {
        int a, b; cin >> a >> b;
        if (a != b) break;
    }
    while (M--) {
        int a, b; cin >> a >> b;
        if (a != b) break;
    }

    if (N == -1 && M == -1) cout << "Accepted\n";
    else if (N != -1) cout << "Wrong Answer\n";
    else cout << "Why Wrong!!!\n";

    return 0;
}
