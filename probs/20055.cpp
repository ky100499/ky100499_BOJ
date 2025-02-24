#include <bits/stdc++.h>

using namespace std;

deque<int> A, R;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;
    for (int i = 0; i < 2*N; i++) {
        int a; cin >> a;
        A.push_back(a);
    }
    R.resize(N, 0);

    int T = 0, cnt = 0;
    while (++T) {
        // step 1
        A.push_front(A.back()); A.pop_back();
        R.push_front(0); R.pop_back();
        if (R.back()) R.back() = 0;

        // step 2
        for (int i = N-2; i; i--) {
            if (R[i] && A[i+1] && !R[i+1]) {
                R[i] = 0;
                R[i+1] = 1;
                if (--A[i+1] == 0) cnt++;
            }
        }

        // step 3
        if (A[0]) {
            R[0] = 1;
            if (--A[0] == 0) cnt++;
        }

        // step 4
        if (cnt >= K) break;
    }

    cout << T << '\n';

    return 0;
}
