#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, B, W; cin >> N >> B >> W;
    string S; cin >> S;

    int i = 0, j = 0, b = 0, w = 0, ans = 0;
    while (i < N) {
        if (b <= B) {
            if (S[i] == 'B') b++;
            else w++;
            i++;
        }
        if (b > B) {
            if (S[j] == 'B') b--;
            else w--;
            j++;
        }

        if (b <= B && w >= W) ans = max(ans, i-j);
    }

    cout << ans << '\n';

    return 0;
}
