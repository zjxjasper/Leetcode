/*
Backtracking is a strategy to travel all state without marking visited state,
a general process in pseudo code is

0: DEFINE STATE VARIABLES {Ai}
DFS_BACKTRACK({Ai})
    CHECK END
        IF END + GOOD: OUTPUT+RETURN (reaching leaves, maxdepth etc, output if needed)
        ELSE:  RETURN
    FIND ALL ADJECENT STATE, 1, ..., N
    LOOP I = 1,...,N
        UPDATE STATE VARIABLES {Ai} -> {Ai'} BASED ON I
        DFS_BACKTRACK({Ai'})
        RECOVER STATE VARIABLES {Ai'} -> {Ai}
    RETURN
*/



/* Example1
Combination Sum III  Find all possible combinations of k numbers that add up to a number n,
given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
numbers should be unique, and orderes does not matter
*/
class CombinationSumIII {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(k > 9) return res;
        vector<int> curr;
        int sum = 0;
        dfs(n,k,curr,sum, res);
        return res;
    }
private:
    void dfs(int n, int k, vector<int> &curr, int sum, vector<vector<int>> &res){
        if(curr.size() == k){
            if(sum == n) res.push_back(curr);
            return;
        }
        int st;
        if(curr.size() == 0) st = 1;
        else st = curr.back() + 1;
        for(int i = st; i < 10; i++){
            curr.push_back(i);
            sum += i;
            dfs(n, k, curr, sum, res);
            curr.pop_back();
            sum -= i;
        }
    }
};
