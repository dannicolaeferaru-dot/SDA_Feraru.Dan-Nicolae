/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int boundary = 0;

    for (int scan = 0; scan < numsSize; scan++) {
        if (nums[scan] % 2 == 0) {
            int temp = nums[boundary];
            nums[boundary] = nums[scan];
            nums[scan] = temp;
            boundary++;
        }
    }

    return nums;
}
