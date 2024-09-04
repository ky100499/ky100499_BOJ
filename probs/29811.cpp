#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;

    priority_queue<pair<int, int>> A, B;
    vector<int> V(N+M+1);

    for (int i = 1; i <= N+M; i++) {
        int v; cin >> v;
        V[i] = -v;
        (i > N ? B : A).push({-v, -i});
    }

    int K; cin >> K;
    while (K--) {
        char q; cin >> q;

        if (q == 'U') {
            int i, v; cin >> i >> v;
            (i > N ? B : A).push({V[i] = -v, -i});
        }
        else {
            while (A.top().first != V[-A.top().second]) A.pop();
            while (B.top().first != V[-B.top().second]) B.pop();
            cout << -A.top().second << ' ' << -B.top().second << '\n';
        }
    }
}
