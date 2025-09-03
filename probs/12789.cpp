#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, n = 1; cin >> N;
    stack<int> S;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (a == n) n++;
        else if (S.empty() || S.top() > a) S.push(a);
        else break;

        while (!S.empty() && S.top() == n) S.pop(), n++;
    }

    cout << (n == N+1 ? "Nice" : "Sad") << '\n';

    return 0;
}
