#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    stack<int> S;
    while (N--) {
        int q; cin >> q;
        switch (q) {
            case 1:
                int x; cin >> x;
                S.push(x);
                break;
            case 2:
                if (S.empty()) cout << "-1\n";
                else cout << S.top() << '\n', S.pop();
                break;
            case 3:
                cout << S.size() << '\n';
                break;
            case 4:
                cout << S.empty() << '\n';
                break;
            case 5:
                cout << (S.empty() ? -1 : S.top()) << '\n';
                break;
        }
    }

    return 0;
}
