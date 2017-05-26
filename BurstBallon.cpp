// find the max score for a given input

// 1. check input and output requirement: can input be 0 or negative val? 
// 2. what is the restriction, extra space, allowed data structure
// 3. corner case: n = 0, return 1;
// 4. example: one naive, ? a_0 ? => a_0 ,  ?  
// 5. brutal force: exam all possible solution, O(n!)
// 6. clue: find the maximum value and the corresponding strategy, dynamic programming
// 7. what is the problem definator? start, end; D: D[st][nd]     D[st][nd] = max( D[st][mid] + D[mid][nd] + nums[st]*nums[nd]*nums[mid])
// 8. for DP, you need to build from small subproblems so that bigger can be calculated based on solution of small, what is small: (nd - st)
// 9. complexity: time O(n^3) space O(n^2)


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> vals(n + 2);
        vals[0] = vals[n+1] = 1;
        for(int i = 1; i <= n; i++) vals[i] = nums[i - 1];      // vals[0] = 1, nums[0] ... nums[n-1], vals[n+1] = 1
        
        vector<vector<int>> D;  // D[range][st],  range = nd - st;
        // D[range][st] = max( D[mid - st][st] + D[st + range - mid][mid] + nums[st]*nums[st+range]*nums[mid]);
        // here range >= mid - st , range - mid + st;
        D.resize(n + 2);
        int res = 0;
        for(int range = 1; range < n + 2; range ++){
            D[range].assign(n + 2 - range,0);
            for(int st = 0; st < n + 2 - range; st++){
                if(range <= 1) D[range][st] = 0;
                else{
                    for(int mid = st + 1; mid < st + range; mid++){
                        D[range][st] = max(D[range][st], D[mid-st][st] + D[st+range-mid][mid] + vals[st]*vals[st+range]*vals[mid]);
                    }
                }
            }
        }
        return D[n + 1][0];
    }
};
