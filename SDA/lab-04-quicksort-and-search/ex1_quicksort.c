#include <stdlib.h>

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void quick_sort(int values[], int lo, int hi) {
    if (lo >= hi) {
        return;
    }

    int random_idx = lo + rand() % (hi - lo + 1);
    swap(&values[lo], &values[random_idx]);

    int pivot = values[lo];
    int lt = lo;
    int gt = hi;
    int i = lo + 1;

    while (i <= gt) {
        if (values[i] < pivot) {
            swap(&values[lt], &values[i]);
            lt++;
            i++;
        } else if (values[i] > pivot) {
            swap(&values[i], &values[gt]);
            gt--;
        } else {
            i++;
        }
    }

    quick_sort(values, lo, lt - 1);
    quick_sort(values, gt + 1, hi);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize <= 1) {
        return nums;
    }
    quick_sort(nums, 0, numsSize - 1);
    return nums;
}
