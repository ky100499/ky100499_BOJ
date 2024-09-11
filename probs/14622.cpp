#include <iostream>
#include <cmath>
#include <vector>
#include <functional>
#include <queue>

#define MAX 5000000

using namespace std;

vector<int> primes(MAX, 1), hist(MAX);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    primes[0] = primes[1] = 0;
    for (int i = 2; i < sqrt(MAX); i++)
        if (primes[i])
            for (int j = i*i; j < MAX; j += i)
                primes[j] = 0;

    int N; cin >> N;
    long long p1, p2; p1 = p2 = 0;

    priority_queue<int, vector<int>, greater<int>> h1, h2;

    while (N--) {
        int a, b; cin >> a >> b;

        if (!primes[a]) {
            if (h2.size() == 3) p2 += h2.top();
            else p2 += 1000;
        }
        else if (hist[a]) {
            p1 -= 1000;
        }
        else {
            hist[a] = 1;
            h1.push(a);
            if (h1.size() > 3) h1.pop();
        }

        if (!primes[b]) {
            if (h1.size() == 3) p1 += h1.top();
            else p1 += 1000;
        }
        else if (hist[b]) {
            p2 -= 1000;
        }
        else {
            hist[b] = 1;
            h2.push(b);
            if (h2.size() > 3) h2.pop();
        }
    }

    if (p1 > p2) cout << "소수의 신 갓대웅\n";
    else if (p1 < p2) cout << "소수 마스터 갓규성\n";
    else cout << "우열을 가릴 수 없음\n";

    return 0;
}
