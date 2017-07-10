/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
*/

/* Analysis:
job i is the most frequent job appears k times, then ans = (k - 1) * (n+1) + 1
assume there are t jobs also appears k times, then ans = (k - 1) * (n+1) + t
at mean time, ans >= tasks.size();
thus: ans = max(tasks.size(), (k - 1) * (n+1) + t)
becareful  return type of *.size() is unsigned integer, so here should use:
ans = max( (int) tasks.size(), (k - 1) * (n+1) + t)
*/


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans;
        vector<int> count(26,0);
        for(int i = 0; i < tasks.size(); i++) {
            if(tasks[i] >= 'A' && tasks[i] <= 'Z') {
                count[tasks[i] - 'A'] ++;
            }
        }
        int maxCount = 0;
        for(int i = 0; i < 26; i++) {
            maxCount = max(maxCount, count[i]);
        }
        int nMax = 0;
        for(int i = 0; i < 26; i++) {
            if(count[i] == maxCount) nMax++;
        }
        return max( (int)tasks.size(), (n + 1) * (maxCount - 1) + nMax);
    }
};
