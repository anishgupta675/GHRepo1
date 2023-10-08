#include<bits/stdc++.h>

using namespace std;

class Solution {
    int getMax(priority_queue<int> &process, int curr_thread) {
        int max_val = process.top();
        process.pop();
        cout << "Current Process: " << max_val << endl;
        for(int i = 1; i < 4; i++) {
            int curr_process = process.top();
            process.pop();
            cout << "Current Process: " << curr_process << endl;
            max_val = max(max_val, curr_process);
        }
        return curr_thread + max_val;
    }
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int res = 0;
        priority_queue<int> process;
        priority_queue<int, vector<int>, greater<int>> thread;
        for(int i = 0; i < tasks.size(); i++) process.push(tasks[i]);
        for(int i = 0; i < processorTime.size(); i++) thread.push(processorTime[i]);
        while(!thread.empty()) {
            int curr_thread = thread.top();
            thread.pop();
            cout << "Current Thread: " << curr_thread << endl;
            res = max(res, getMax(process, curr_thread));
        }
        return res;
    }
};

int main() {
    int n;
    Solution sol;
    cin >> n;
    vector<int> processorTime(n);
    vector<int> tasks(n * 4);
    for(int i = 0; i < n; i++) cin >> processorTime[i];
    for(int i = 0; i < n * 4; i++) cin >> tasks[i];
    cout << sol.minProcessingTime(processorTime, tasks) << endl;
}