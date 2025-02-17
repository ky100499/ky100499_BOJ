#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pi = pair<int, int>;

const int MAX = 1e5;

pi A[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; ll S = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        S += A[i].second;
    }
    sort(A, A+N);

    ll s = 0;
    for (int i = 0; i < N; i++) {
        s += A[i].second;
        if (s*2 >= S) {
            cout << A[i].first << '\n';
            break;
        }
    }

    return 0;
}
