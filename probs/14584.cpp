#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; int N; cin >> S >> N;
    vector<string> D(N);
    for (int i = 0; i < N; i++) cin >> D[i];

    for (int i = 0; i < 26; i++) {
        int a = 0;
        for (auto d : D) a |= S.find(d) != string::npos;
        if (a) break;

        for (int j = 0; j < S.size(); j++) S[j] = (S[j]-'a'+1)%26+'a';
    }

    cout << S << '\n';

    return 0;
}
