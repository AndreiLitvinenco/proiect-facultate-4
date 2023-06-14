#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int min;
    int max;
} MinMax;

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;
    int mid;

    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
}

int main() {
    int n;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    int arr[n];
    printf("Introdu elementele:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    MinMax result = findMinMax(arr, 0, n - 1);

    printf("Valoarea minima: %d\n", result.min);
    printf("Valoarea maxima: %d\n", result.max);

    return 0;
}
