#include <bits/stdc++.h>

using namespace std;

int V[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; string S; getline(cin, S); N = stoi(S);
    memset(V, 0, sizeof V);
    while (N--) {
        getline(cin, S);

        size_t i = 0;
        while (1) {
            if (!V[(S[i]|32)-'a']) {
                V[(S[i]|32)-'a'] = 1;
                break;
            }
            i = S.find(' ', i);
            if (i == string::npos) break;
            i++;
        }

        if (i == string::npos) {
            for (i = 0; i < S.size(); i++) {
                if (S[i] != ' ' && !V[(S[i]|32)-'a']) {
                    V[(S[i]|32)-'a'] = 1;
                    break;
                }
            }
        }

        for (int j = 0; j < S.size(); j++) {
            if (i == j) cout << '[';
            cout << S[j];
            if (i == j) cout << ']';
        }
        cout << '\n';
    }

    return 0;
}
