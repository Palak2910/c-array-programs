int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *ans = (int*)malloc(nums1Size * sizeof(int));
    int stack[1000];
    int top = -1;

    int next[10001];

    for (int i = 0; i <= 10000; i++) {
        next[i] = -1;
    }
    for (int i = nums2Size - 1; i >= 0; i--) {
        while (top != -1 && stack[top] <= nums2[i]) {
            top--;
        }

        if (top != -1) {
            next[nums2[i]] = stack[top];
        }
        stack[++top] = nums2[i];
    }
    for (int i = 0; i < nums1Size; i++) {
        ans[i] = next[nums1[i]];
    }
    *returnSize = nums1Size;
    return ans;
}
