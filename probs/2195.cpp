#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S, P; cin >> S >> P;
    int i = 0, cnt = 0;
    while (i < P.size()) {
        string str = "";
        while (i < P.size() && S.find(str+P[i]) != string::npos) {
            str += P[i++];
        }
        cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
