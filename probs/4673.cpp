#include <bits/stdc++.h>

using namespace std;

int A[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    memset(A, 0, sizeof A);
    for (int i = 1; i <= 10000; i++) {
        if (!A[i]) cout << i << '\n';

        int x = i;
        while (x <= 10000 && !A[x]) {
            A[x]++;

            int nx = x;
            while (x) {
                nx += x%10;
                x /= 10;
            }
            x = nx;
        }
    }

    return 0;
}
