#include <bits/stdc++.h>

using namespace std;

int A[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    if (N == 1) cout << "A\n";
    else if (N == 2) {
        if (A[0] == A[1]) cout << A[0] << '\n';
        else cout << "A\n";
    }
    else {
        /*
        ** y = ax + b
        **
        ** A[1] = aA[0]+b
        ** A[2] = aA[1]+b
        **
        ** A[2] - A[1] = a(A[1] - A[0])
        **
        ** a = (A[2] - A[1]) / (A[1] - A[0])
        ** b = A[1] - aA[0]
        */

        int a = A[0] == A[1] ? 1 : (A[2] - A[1]) / (A[1] - A[0]),
            b = A[1] - a*A[0];

        for (int i = 0; i < N-1; i++) {
            if (a*A[i]+b != A[i+1]) {
                cout << "B\n";
                return 0;
            }
        }
        cout << a*A[N-1]+b << '\n';
    }

    return 0;
}
