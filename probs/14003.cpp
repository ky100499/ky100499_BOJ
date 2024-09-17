#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> LIS(1, A[0]), idx(N);
    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(LIS.begin(), LIS.end(), A[i]);

        idx[i] = iter - LIS.begin();

        if (iter == LIS.end()) {
            LIS.push_back(A[i]);
        }
        else {
            *iter = A[i];
        }
    }

    int l = LIS.size();
    cout << l << '\n';

    vector<int> ans(l);
    for (int i = N-1; l > 0 && i >= 0; i--) {
        if (idx[i] == l-1) ans[--l] = A[i];
    }
    for (int a : ans) cout << a << ' '; cout << '\n';

    return 0;
}
