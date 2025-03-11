#include <bits/stdc++.h>

using namespace std;

string res[] = {"false", "true"};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string A, B; cin >> A >> B;

    if (A == "null") cout << "NullPointerException\nNullPointerException\n";
    else if (B == "null" || A.size() != B.size()) cout << "false\nfalse\n";
    else {
        int eq = 1, eqi = 1;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) eq = 0;
            if (
                ('0' <= A[i] && A[i] <= '9' && A[i] != B[i]) ||
                (A[i]|32) != (B[i]|32)
            ) eqi = 0;
        }
        cout << res[eq] << '\n'
             << res[eqi] << '\n';
    }

    return 0;
}
