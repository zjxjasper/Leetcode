/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.
You need to find the shortest such subarray and output its length.
Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //return method1(nums);   // time: O(nlogn), space O(n)
        return method2(nums);     // time: O(n), space O(1)
    }
    
    int method1(vector<int> nums) {
        vector<int> sorted = nums;
        sort(nums.begin(),nums.end());
        int st = -1, nd = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]!=sorted[i]) {
                st = i;
                break;
            }
        }
        if(st == -1) return 0;
        
        for(int i = nums.size()-1; i >= 0; i--) {
            if(nums[i]!=sorted[i]) {
                nd = i;
                break;
            }
        }
        return nd - st + 1;
    }
    
    int method2(vector<int> nums) {
        stack<int> s_val;
        stack<int> s_index;
        int index_last_pop = nums.size();
        int st, nd;
        for(int i = 0; i < nums.size(); i++){
            if(s_val.empty() || nums[i] > s_val.top()) {
                s_val.push(nums[i]);
                s_index.push(i);
            }
            else {
                while(s_val.empty() == false && s_val.top() > nums[i]) {
                    index_last_pop = min(index_last_pop, s_index.top());
                    s_val.pop();
                    s_index.pop();                    
                }
                s_val.push(nums[i]);
                s_index.push(i);
            }
        }
        if(index_last_pop == nums.size()) {
            return 0;
        }
        else {
            st = index_last_pop;
        }
        
        index_last_pop = -1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(s_val.empty() || nums[i] < s_val.top()) {
                s_val.push(nums[i]);
                s_index.push(i);
            }
            else {
                while(s_val.empty() == false && s_val.top() < nums[i]) {
                    index_last_pop = max(index_last_pop, s_index.top());
                    s_val.pop();
                    s_index.pop();                    
                }
                s_val.push(nums[i]);
                s_index.push(i);
            }
        }
        if(index_last_pop == -1) {
            return 0;
        }
        else {
            nd = index_last_pop;
        }
        return nd - st + 1;
    }
    
};
