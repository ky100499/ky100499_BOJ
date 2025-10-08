#include <bits/stdc++.h>

using namespace std;

map<string, int> dp;
vector<string> A;

int solve(string S)
{
    if (S.empty()) return 1;

    if (dp.find(S) == dp.end()) {
        for (auto a : A) {
            string s = S.substr(0, a.size());
            if (s == a) dp[S] += solve(S.substr(a.size()));
        }
    }
    return dp[S] > 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;
    int N; cin >> N; A.resize(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    cout << solve(S) << '\n';

    return 0;
}
