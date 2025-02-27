#include <bits/stdc++.h>

using namespace std;

int N, ans = -0x7fffffff;
string F;
deque<string> res;

int calc(int a, char op, int b)
{
    if (op == '+') return a+b;
    if (op == '-') return a-b;
    if (op == '*') return a*b;
    return 0;
}

void bt(int i)
{
    if (i == N) {
        int v = stoi(res[0]);
        for (int j = 1; j < res.size(); j+=2)
            v = calc(v, res[j][0], stoi(res[j+1]));
        ans = max(ans, v);
        return;
    }

    if (F[i] == '*') {
        string b = res.back(); res.pop_back();

        if (i+2 < N && F[i+2] != '*') {
            res.push_back(to_string(stoi(b)*calc(F[i+1]-'0', F[i+2], F[i+3]-'0')));
            bt(i+4);
            res.pop_back();
        }

        res.push_back(to_string(stoi(b)*(F[i+1]-'0')));
        bt(i+2);
        res.pop_back();

        res.push_back(b);
    }
    else {
        res.push_back(string(1, F[i]));

        if (i+2 < N && F[i+2] != '*') {
            res.push_back(to_string(calc(F[i+1]-'0', F[i+2], F[i+3]-'0')));
            bt(i+4);
            res.pop_back();
        }

        res.push_back(string(1, F[i+1]));
        bt(i+2);
        res.pop_back();

        res.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> F;
    F = "0+"+F; N += 2;
    res.push_back("0");
    bt(1);
    cout << ans << '\n';

    return 0;
}
