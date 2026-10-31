#include <stdlib.h>

static void sort_range(int values[], int buffer[], int lo, int hi) {
    if (hi - lo <= 1) {
        return;
    }

    int mid = lo + (hi - lo) / 2;
    sort_range(values, buffer, lo, mid);
    sort_range(values, buffer, mid, hi);

    int left = lo;
    int right = mid;
    for (int output = lo; output < hi; output++) {
        if (left < mid && (right == hi || values[left] <= values[right])) {
            buffer[output] = values[left++];
        } else {
            buffer[output] = values[right++];
        }
    }

    for (int output = lo; output < hi; output++) {
        values[output] = buffer[output];
    }
}


int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    if (numsSize <= 1) {
        return nums;
    }

    int *buffer = (int*)malloc(numsSize * sizeof(int));
    if (buffer == NULL) {
        return nums;
    }

    sort_range(nums, buffer, 0, numsSize);
    free(buffer);
    return nums;
}
