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

    int s = 0, ans = 0;
    set<int> player;
    for (int x = 0; x < 11; x++) {
        player.insert(A[x].second);
        s += A[x].first;

        for (int y = 0; y < 11; y++) {
            if (player.find(B[y].second) == player.end()) player.insert(B[y].second);
            else continue;
            s += B[y].first;

            for (int z = 0; z < 11; z++) {
                if (player.find(C[z].second) == player.end()) player.insert(C[z].second);
                else continue;
                s += C[z].first;

                for (int w = 0; w < 11; w++) {
                    if (player.find(D[w].second) == player.end()) player.insert(D[w].second);
                    else continue;
                    s += D[w].first;

                    int tmp = s, cnt = 0;
                    for (int i = 0; cnt < 7; i++) {
                        if (player.find(M[i].second) == player.end()) {
                            tmp += M[i].first;
                            cnt++;
                        }
                    }
                    ans = max(ans, tmp);

                    player.erase(D[w].second);
                    s -= D[w].first;
                }
                player.erase(C[z].second);
                s -= C[z].first;
            }
            player.erase(B[y].second);
            s -= B[y].first;
        }
        player.erase(A[x].second);
        s -= A[x].first;
    }

    cout << ans << '\n';

    return 0;
}
