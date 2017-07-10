/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

Follow up:
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
*/

// key of this type of problem: assuming nd > st, mid := (st+nd)/2
// if nums[mid] < nums[nd]:  right side is sorted  mid -> nd
// if nums[mid] < nums[nd]:  left side is sorted   st -> mid
// with duplicates:
// if(nums[mid] == nums[nd])  try nd--


class Solution {
public:
    // no duplicates
    int search1(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int st = 0, nd = int(nums.size()) - 1;
        while(nd > st) {
            int mid = (st + nd) / 2;
            if(nums[mid] < nums[nd]){
                // right side is sorted
                if(target > nums[mid] && target <= nums[nd]) {
                    st = mid + 1;
                }
                else nd = mid;
            }
            else if(nums[mid] > nums[nd]) {
                // left side is sorted
                if(target >= nums[st] && target <= nums[mid]) {
                    nd = mid;
                }
                else st = mid + 1;
            }
        }
        if(nums[st] == target) return st;
        else return -1;
    }
    
    // with duplicates
    bool search2(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int st = 0, nd = int(nums.size()) - 1;
        while(nd > st) {
            int mid = (st + nd) / 2;
            if(nums[mid] < nums[nd]){
                // right side is sorted
                if(target > nums[mid] && target <= nums[nd]) {
                    st = mid + 1;
                }
                else nd = mid;
            }
            else if(nums[mid] > nums[nd]) {
                // left side is sorted
                if(target >= nums[st] && target <= nums[mid]) {
                    nd = mid;
                }
                else st = mid + 1;
            }
            else nd --;
        }
        if(nums[st] == target) return true;
        else return false;
    }
};
