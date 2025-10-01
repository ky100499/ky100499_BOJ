#include <bits/stdc++.h>

using namespace std;

vector<string> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N; S.resize(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    sort(S.begin(), S.end(), [](string a, string b) {
        return a+b > b+a;
    });

    if (S[0][0] == '0') cout << '0';
    else for (auto s : S) cout << s;
    cout << '\n';

    return 0;
}
