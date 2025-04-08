#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;

const int MAX = 1e9+1, INF = 1e9+2;

map<string, ll> P;
map<string, vector<map<string, int>>> C;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    while (N--) {
        string s; int p; cin >> s >> p;
        P[s] = p;
    }

    while (M--) {
        string s; cin >> s;

        int i = 0; string lhs;
        while (s[i] != '=') lhs += s[i++];
        i++;
        if (P.find(lhs) == P.end()) P[lhs] = INF;

        int qty; string name;
        C[lhs].push_back(map<string, int>());
        while (i <= s.size()) {
            if (in(s[i], '0', '9'+1)) qty = s[i]-'0';
            else if (s[i] == '+' || i == s.size()) {
                C[lhs].back()[name] += qty;
                if (P.find(name) == P.end()) P[name] = INF;
                name.clear();
            }
            else name += s[i];

            i++;
        }
    }

    int flag = 1;
    while (flag) {
        flag = 0;

        for (auto [n, p] : P) {
            for (auto f : C[n]) {
                int tmp = 0;
                for (auto [name, qty] : f) {
                    if (P[name] == INF) {
                        tmp = INF;
                        break;
                    }
                    else if (tmp + P[name] * qty > MAX)
                        tmp = MAX;
                    else
                        tmp += P[name] * qty;
                }

                if (P[n] > tmp) {
                    P[n] = tmp;
                    flag = 1;
                }
            }
        }
    }

    cout << (P.find("LOVE") == P.end() || P["LOVE"] == INF ? -1 : P["LOVE"]) << '\n';

    return 0;
}
