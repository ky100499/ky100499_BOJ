#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

int A[MAX], B[MAX], C[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int a, b, c; cin >> a >> b >> c;
    for (int i = 0; i < a; i++) cin >> A[i];
    for (int i = 0; i < b; i++) cin >> B[i];
    for (int i = 0; i < c; i++) cin >> C[i];
    sort(A, A+a); sort(B, B+b); sort(C, C+c);

    int i = 0, j = 0, k = 0, ans = 1e9;
    while (i < a && j < b && k < c) {
        int x;
        if (A[i] <= B[j] && A[i] <= C[k]) {
            x = max(B[j], C[k]) - A[i];
            i++;
        }
        else if (B[j] <= A[i] && B[j] <= C[k]) {
            x = max(C[k], A[i]) - B[j];
            j++;
        }
        else {
            x = max(A[i], B[j]) - C[k];
            k++;
        }
        ans = min(ans, x);
    }
    cout << ans << '\n';

    return 0;
}
