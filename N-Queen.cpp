// find # of unique solutions of N-Queen problem

// 1. check input and output requirement: output # of solution or detailed configuration
// 2. what is the restriction, time/space complexity
// 3. corner case: n = 0
// 4. problem type: search for all solutions, therefore its exausted search, DFS

class Solution {
public:
    int totalNQueens(int n) {
        if(n == 0) return 0;
        vector<int> Q;
        int res = 0;
        do_DFS(n, Q, res);
        return res;
    }
private:
    void do_DFS(int n, vector<int> &Q, int &res) {
        int curr = Q.size();
        if(curr == n) {
            res++;
            return;
        }
        vector<bool> allow(n,true);
        for(int i = 0; i < curr; i++){
            allow[Q[i]] = false;
            if(Q[i] + curr - i < n)  allow[Q[i] + curr - i] = false;
            if(Q[i] - curr + i >= 0) allow[Q[i] - curr + i] = false;
        }
        for(int i = 0; i < n; i++){
            if(allow[i] == true){
                Q.push_back(i);
                do_DFS(n, Q, res);
                Q.pop_back();
            } 
        }
    }
};
