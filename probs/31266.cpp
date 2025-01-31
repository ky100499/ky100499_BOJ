#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 2e5;
pi A[MAX], B[MAX], C[MAX], D[MAX], M[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first
            >> B[i].first
            >> C[i].first
            >> D[i].first;
        M[i].first = max(max(A[i].first, B[i].first), C[i].first);
        A[i].second = B[i].second = C[i].second = D[i].second = M[i].second = i;
    }
    sort(A, A+N, greater<pi>());
    sort(B, B+N, greater<pi>());
    sort(C, C+N, greater<pi>());
    sort(D, D+N, greater<pi>());
    sort(M, M+N, greater<pi>());

    int a, b, c, d, s = 0, ans = 0;
    for (int x = 0; x < 11; x++) {
        a = A[x].second;
        s += A[x].first;

        for (int y = 0; y < 11; y++) {
            b = B[y].second;
            if (a == b) continue;
            s += B[y].first;

            for (int z = 0; z < 11; z++) {
                c = C[z].second;
                if (a == c || b == c) continue;
                s += C[z].first;

                for (int w = 0; w < 11; w++) {
                    d = D[w].second;
                    if (a == d || b == d || c == d) continue;
                    s += D[w].first;

                    int tmp = s, cnt = 0;
                    for (int i = 0; cnt < 7; i++) {
                        if (M[i].second != a &&
                            M[i].second != b &&
                            M[i].second != c &&
                            M[i].second != d) {
                            tmp += M[i].first;
                            cnt++;
                        }
                    }
                    ans = max(ans, tmp);

                    s -= D[w].first;
                }
                s -= C[z].first;
            }
            s -= B[y].first;
        }
        s -= A[x].first;
    }

    cout << ans << '\n';

    return 0;
}
