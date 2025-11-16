#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x <= b)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<pair<int, char>> V; V.reserve(N);
    for (int i = 0; i < N; i++) {
        string S; int I, D; cin >> S >> I >> D;
        V.emplace_back(I, in(S[D-1], 'a', 'z') ? S[D-1]-32 : S[D-1]);
    }
    sort(V.begin(), V.end());

    for (auto [_, c] : V) cout << c;
    cout << '\n';

    return 0;
}
