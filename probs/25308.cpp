#include <bits/stdc++.h>

using namespace std;

int A[8], O[8], ans = 0;

bool convex(int a, int b, int c)
{
    return c >= sqrt(2)*a*b/(a+b);
}

void solve(int i)
{
    if (i == 8) {
        int a = 1;
        for (int j = 0; j < 8; j++)
            a &= convex(A[O[j]], A[O[(j+2)%8]], A[O[(j+1)%8]]);
        ans += a;
    }
    else {
        for (int j = 0; j < 8; j++) {
            if (O[j] == -1) {
                O[j] = i;
                solve(i+1);
                O[j] = -1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 8; i++) cin >> A[i];

    memset(O, -1, sizeof O);
    solve(0);
    cout << ans << '\n';

    return 0;
}
