#include <stdio.h>

int hist[1<<(25-5)] = {0,};

int main()
{
    freopen("./input.txt", "rt", stdin);

    int n;
    while (scanf("%d", &n) != EOF) {
        int r = n / 32, c = n % 32;
        if ((hist[r] & (1<<c)) == 0) {
            printf("%d ", n);
            hist[r] |= (1<<c);
        }
    }
}
