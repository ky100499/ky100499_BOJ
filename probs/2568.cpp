#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<int> A(MAX+1, 0);
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        A[a] = b;
    }

    vector<int> LIS, idx(MAX+1, -1);
    int l = 0;
    for (int i = 1; i <= MAX; i++) {
        if (!A[i]) continue;

        int x = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
        if (x == l) {
            LIS.push_back(A[i]);
            l++;
        }
        else {
            LIS[x] = A[i];
        }
        idx[i] = x;
    }

    int a = N-l;
    cout << a << '\n';

    vector<int> ans(a);
    for (int i = MAX; i > 0; i--) {
        if (l > 0 && idx[i] == l-1)
            l--;
        else if (idx[i] != -1) ans[--a] = i;
    }

    for (int a : ans) cout << a << '\n';
}
