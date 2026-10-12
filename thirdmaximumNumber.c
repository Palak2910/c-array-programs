int thirdMax(int* nums, int numsSize) {
    long long first = (long long)INT_MIN - 1;
    long long second = first;
    long long third = first;

    for (int i = 0; i < numsSize; i++) {
        long long num =  nums[i];

        if (num == first || num == second || num == third) {
            continue;
        }
        if (num > first) {
            third = second;
            second = first;
            first = num;
        }
        else if (num > second) {
            third = second;
            second = num;
        }
        else if (num > third) {
            third = num;
        }
    }

    if (third == (long long)INT_MIN - 1) {
        return (int)first;
    }

    return (int)third;
}
