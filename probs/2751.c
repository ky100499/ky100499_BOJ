#include <stdio.h>
#include <stdlib.h>

void quickSort(int *arr, int low, int high);

int main(int argc, char **argv)
{
    int N;
    scanf("%d", &N);

    int *ipt = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", ipt + i);
    }
    quickSort(ipt, 0, N-1);
    for (int i = 0; i < N; i++) {
        printf("%d\n", *(ipt + i));
    }
}

void quickSort(int *arr, int low, int high)
{
    if (high < low) return;

    int pivot = high;
    int i = low, j = low;
    while (j < pivot) {
        if (arr[j] < arr[pivot]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
        }
        j++;
    }
    int temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;
    quickSort(arr, low, i-1);
    quickSort(arr, i+1, high);
}
