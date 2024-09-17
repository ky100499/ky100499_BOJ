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

    vector<int> LIS(1, A[0]);
    for (int i = 0; i < N; i++) {
        auto iter = lower_bound(LIS.begin(), LIS.end(), A[i]);

        if (iter == LIS.end()) {
            LIS.push_back(A[i]);
        }
        else {
            *iter = A[i];
        }
    }
    cout << LIS.size() << '\n';

    return 0;
}
