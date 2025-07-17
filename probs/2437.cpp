#include <bits/stdc++.h>

using namespace std;

int A[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int s = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > s+1) break;
        s += A[i];
    }
    cout << s+1 << '\n';

    return 0;
}
