#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        deque<char> Q1, Q2;
        for (char c : S) {
            if (c == '<') {
                if (!Q1.empty()) Q2.push_front(Q1.back()), Q1.pop_back();
            }
            else if (c == '>') {
                if (!Q2.empty()) Q1.push_back(Q2.front()), Q2.pop_front();
            }
            else if (c == '-') {
                if (!Q1.empty()) Q1.pop_back();
            }
            else Q1.push_back(c);
        }

        for (char c : Q1) cout << c;
        for (char c : Q2) cout << c;
        cout << '\n';
    }

    return 0;
}
