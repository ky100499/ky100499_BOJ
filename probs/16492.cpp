#include <bits/stdc++.h>

using namespace std;

const int MAX = 60000;

int A[MAX];
string S, tmp, T;
map<char, string> G;
vector<string> D;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    while (1) {
        string q; cin >> q;

        if (q == "gen:") {
            char x; cin >> x;
            string y; cin >> y >> y;
            G[x] = y;
        }
        else if (q == "del:") {
            string x; cin >> x;
            D.push_back(x);
        }
        else {
            cin >> T;
            break;
        }
    }

    S = "A";
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        tmp = "";
        for (int j = 0; j < S.size(); j++) {
            if (G.find(S[j]) == G.end()) tmp += S[j];
            else tmp += G[S[j]];
        }

        memset(A, 0, sizeof A);
        for (string d : D) {
            int j = -1;
            while ((j = tmp.find(d, j+1)) != string::npos)
                for (int k = 0; k < d.size(); k++) A[j+k] = 1;
        }

        S = "";
        for (int i = 0; i < tmp.size(); i++)
            if (!A[i]) S += tmp[i];

        if (S == T) {
            ans = 1;
            break;
        }
    }

    cout << (ans ? 'O' : 'X') << '\n';

    return 0;
}
