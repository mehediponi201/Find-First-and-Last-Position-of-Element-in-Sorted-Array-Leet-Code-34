
/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

#include<stdio.h>
int findFirst(int nums[],int len,int target)
{
    int left=0,right=len-1;
    int index = -1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid] == target)
        {
            index = mid;
            right = mid - 1;
        }
        else if(nums[mid]<target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return index;
}
int findLast(int nums[],int len,int target)
{
    int left=0,right=len-1;
    int index = -1;
    while(left<=right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid] == target)
        {
            index = mid;
            left = mid + 1;
        }
        else if(target<nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return index;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;

    int* result = (int*)malloc(sizeof(int)*2);

    result[0] = findFirst(nums,numsSize,target);
    result[1] = findLast(nums,numsSize,target);

    return result;
}
int main()
{
    int arr[] = {5,7,7,8,8,10};
    int target = 8;
    int len = sizeof(arr)/sizeof(arr[0]);
    int size;

    int* result = searchRange(arr,len,target,&size);
    printf("[%d %d] ",result[0],result[1]);
    free(result);
}
