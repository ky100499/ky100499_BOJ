#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        if (S == "KBS1") a = i;
        if (S == "KBS2") b = i;
    }
    if (a > b) b++;

    cout << string(a, '1') + string(a, '4') + string(b, '1') + string(b-1, '4') << '\n';

    return 0;
}
