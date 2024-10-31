#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    list<int> A(N);
    vector<list<int>::iterator> A_it(N+1);
    int i = 1;
    for (auto iter = A.begin(); iter != A.end(); iter++) {
        A_it[i] = iter;
        *iter = i++;
    }

    while (M--) {
        char op; int x, y; cin >> op >> x >> y;
        A.erase(A_it[x]);
        A_it[x] = A.insert(op == 'A' ? A_it[y] : next(A_it[y]), x);
    }
    vector<int> B; B.reserve(N);
    for (auto iter = A.begin(); iter != A.end(); iter++) B.push_back(*iter);

    int l = 0;
    vector<int> LIS, idx(N);
    for (int i = 0; i < N; i++) {
        int x = lower_bound(LIS.begin(), LIS.end(), B[i]) - LIS.begin();
        if (x == l) {
            LIS.push_back(B[i]);
            idx[i] = l++;
        }
        else {
            LIS[x] = B[i];
            idx[i] = x;
        }
    }
    cout << N-l << '\n';

    vector<int> res(l);
    for (int i = N-1; i >= 0; i--) {
        if (idx[i] == l-1) {
            res[--l] = B[i];
        }
    }

    int n = 1;
    for (auto r : res) {
        while (n < r) {
            cout << "A " << n++ << ' ' << r << '\n';
        }
        n++;
    }
    while (n <= N) {
        cout << "B " << n << ' ' << n++-1 << '\n';
    }

    return 0;
}
