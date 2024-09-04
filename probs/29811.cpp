#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;

    set<pair<int, int>> A, B;
    vector<int> V(N+M+1);

    for (int i = 1; i <= N+M; i++) {
        int v; cin >> v;
        V[i] = v;
        (i > N ? B : A).insert({v, i});
    }

    int K; cin >> K;
    while (K--) {
        char q; cin >> q;

        if (q == 'U') {
            int i, v; cin >> i >> v;
            auto& S(i > N ? B : A);
            S.erase({V[i], i});
            S.insert({V[i] = v, i});
        }
        else
            cout << (*A.begin()).second << ' ' << (*B.begin()).second << '\n';
    }
}
