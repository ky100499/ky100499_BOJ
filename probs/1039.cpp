#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string N; int K; cin >> N >> K;

    set<string> S; S.insert(N);
    int l = N.size();
    while (K--) {
        set<string> tmp;
        for (auto s : S) {
            for (int i = 0; i < l; i++) {
                for (int j = i+1; j < l; j++) {
                    swap(s[i], s[j]);
                    if (s[0] != '0') tmp.insert(s);
                    swap(s[i], s[j]);
                }
            }
        }
        S = tmp;
    }

    cout << (S.empty() ? "-1" : *S.rbegin()) << '\n';

    return 0;
}
