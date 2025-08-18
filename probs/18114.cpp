#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000;

vector<int> A;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, C; cin >> N >> C; A.reserve(N);
    for (int i = 0; i < N; i++) {
        int w; cin >> w;
        if (w == C) {
            cout << "1\n";
            return 0;
        }
        A.push_back(w);
    }
    sort(A.begin(), A.end());

    int i = 0, j = N-1, ans = 0;
    while (i < j) {
        int s = A[i]+A[j];

        if (s == C) {
            ans = 1;
            break;
        }
        else if (s < C) {
            int x = lower_bound(A.begin(), A.end(), C-s) - A.begin();
            if (x != N && A[x] == C-s && x != i && x != j) {
                ans = 1;
                break;
            }
            i++;
        }
        else j--;
    }

    cout << ans << '\n';

    return 0;
}
