#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int fail[MAX+1] = {};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string T, P;
    getline(cin, T, '\n');
    getline(cin, P, '\n');

    /*
    ** 0012340
    ** ABABABC  6
    **   ABABA  4 -> 2 = fail[3]
    **     ABA  2 -> 0 = fail[1]
    **       A  0
    */
    int j = 0;
    for (int i = 1; i < P.size(); i++) {
        while (j && P[i] != P[j]) j = fail[j-1];
        if (P[i] == P[j]) fail[i] = ++j;
    }

    vector<int> ans;
    j = 0;
    for (int i = 0; i < T.size(); i++) {
        while (j && T[i] != P[j]) j = fail[j-1];
        if (T[i] == P[j]) j++;

        if (j == P.size()) {
            ans.push_back(i-j+2);
            j = fail[j-1];
        }
    }

    cout << ans.size() << '\n';
    for (int a : ans) cout << a << ' ';
    cout << '\n';

    return 0;
}
