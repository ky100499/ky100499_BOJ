#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 1e9;

vector<pair<string, int>> CMD;
stack<ll> S;

bool exec(string s, int n)
{
    ll a, b, sign;

    if (s == "NUM") {
        S.push(n);
    }
    else if (s == "POP") {
        if (S.empty()) return 0;
        else S.pop();
    }
    else if (s == "INV") {
        if (S.empty()) return 0;
        else {
            a = S.top();
            S.pop();
            S.push(-a);
        }
    }
    else if (s == "DUP") {
        if (S.empty()) return 0;
        else S.push(S.top());
    }
    else if (s == "SWP") {
        if (S.size() < 2) return 0;
        a = S.top(); S.pop();
        b = S.top(); S.pop();
        S.push(a);
        S.push(b);
    }
    else if (s == "ADD") {
        if (S.size() < 2) return 0;
        a = S.top(); S.pop();
        b = S.top(); S.pop();
        S.push(a+b);
    }
    else if (s == "SUB") {
        if (S.size() < 2) return 0;
        a = S.top(); S.pop();
        b = S.top(); S.pop();
        S.push(b-a);
    }
    else if (s == "MUL") {
        if (S.size() < 2) return 0;
        a = S.top(); S.pop();
        b = S.top(); S.pop();
        S.push(a*b);
    }
    else if (s == "DIV") {
        if (S.size() < 2 || S.top() == 0) return 0;
        a = S.top(); S.pop();
        b = S.top(); S.pop();
        sign = (a / abs(a)) * (b / abs(b));
        a = abs(a); b = abs(b);
        S.push(b/a*sign);
    }
    else if (s == "MOD") {
        if (S.size() < 2 || S.top() == 0) return 0;
        a = S.top(); S.pop();
        b = S.top(); S.pop();
        sign = b / abs(b);
        a = abs(a); b = abs(b);
        S.push(b%a*sign);
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    while (1) {
        CMD.clear();
        int n; string s;
        while (1) {
            cin >> s;
            if (s == "END" || s == "QUIT") break;
            else if (s == "NUM") cin >> n;
            else n = 0;

            CMD.emplace_back(s, n);
        }
        if (s == "QUIT") break;

        int N; cin >> N;
        while (N--) {
            while (!S.empty()) S.pop();
            cin >> n; S.push(n);
            for (auto [s, x] : CMD) {
                if (!exec(s, x) || (!S.empty() && abs(S.top()) > MAX)) {
                    while (!S.empty()) S.pop();
                    break;
                }
            }

            if (S.size() == 1) cout << S.top() << '\n';
            else cout << "ERROR\n";
        }
        cout << '\n';
    }

    return 0;
}
