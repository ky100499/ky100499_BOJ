#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K; N -= K;
    string M; cin >> M;

    deque<char> S;
    for (char m : M) {
        while (K && !S.empty() && S.back() < m) {
            S.pop_back();
            K--;
        }
        S.push_back(m);
    }

    S.resize(N);
    for (char c : S) cout << c;
    cout << '\n';

    return 0;
}
