
int* runningSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(numsSize * sizeof(int));

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = sum + nums[i];
        ans[i] = sum;
    }

    return ans;
}
