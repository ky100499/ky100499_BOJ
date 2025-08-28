#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+1;

int A[MAX], C[MAX], ans[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    memset(C, 0, sizeof C);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        C[A[i]]++;
    }

    stack<int> S;
    for (int i = N-1; i >= 0; i--) {
        while (!S.empty() && C[S.top()] <= C[A[i]]) S.pop();
        ans[i] = S.empty() ? -1 : S.top();
        S.push(A[i]);
    }

    for (int i = 0; i < N; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
