#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;

vector<int> pm, nm, pw, nw;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int h; cin >> h;
        h > 0 ? pm.push_back(h) : nm.push_back(-h);
    }
    for (int i = 0; i < N; i++) {
        int h; cin >> h;
        h > 0 ? pw.push_back(h) : nw.push_back(-h);
    }
    sort(pm.begin(), pm.end());
    sort(nm.begin(), nm.end());
    sort(pw.begin(), pw.end());
    sort(nw.begin(), nw.end());

    int j = 0, ans = 0;
    for (int i = 0; i < pm.size(); i++) {
        while (j < nw.size() && pm[i] >= nw[j]) j++;
        if (j == nw.size()) break;
        ans++; j++;
    }
    j = 0;
    for (int i = 0; i < pw.size(); i++) {
        while (j < nm.size() && pw[i] >= nm[j]) j++;
        if (j == nm.size()) break;
        ans++; j++;
    }

    cout << ans << '\n';

    return 0;
}
