#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    scanf("%d", &N);

    int min = 1000000, max = 2;
    while (N--) {
        int ipt;
        scanf("%d", &ipt);
        if (ipt < min) min = ipt;
        if (ipt > max) max = ipt;
    }
    printf("%d\n", min * max);
}
