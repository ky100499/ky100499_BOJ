#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    string S; cin >> S;

    stack<char> P;
    vector<int> N[20];
    int depth = 0, valid = 1;
    for (char c : S) {
        if (c == '(' || c == '[') {
            P.push(c);
            depth++;
        }
        else if (c == ')' && P.size() && P.top() == '(') {
            int s = 0;
            for (int n : N[depth+1]) s += n;
            N[depth+1].clear();
            N[depth--].push_back(s ? s*2 : 2);
            P.pop();
        }
        else if (c == ']' && P.size() && P.top() == '[') {
            int s = 0;
            for (int n : N[depth+1]) s += n;
            N[depth+1].clear();
            N[depth--].push_back(s ? s*3 : 3);
            P.pop();
        }
        else {
            valid = 0;
            break;
        }
    }

    if (valid) {
        int s = 0;
        for (int n : N[1]) s += n;
        cout << s << '\n';
    }
    else cout << "0\n";

    return 0;
}
