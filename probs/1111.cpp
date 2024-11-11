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
        int a = A[1]/A[0], b = A[1]-A[0]*a;
        cout << a << ' ' << b << '\n';
    }

    return 0;
}
