#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse the first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // If k is 0, no modification is needed, so return the original queue.
        if (k == 0)
            return q;

        // Create a queue to store the modified elements.
        queue<int> answer;

        // Enqueue the first k elements into the 'answer' queue.
        for (int i = 0; i < k; ++i) {
            answer.push(q.front());
            q.pop();
        }

        // Reverse the first k elements in the 'answer' queue using a stack.
        stack<int> s;
        for (int i = 0; i < k; ++i) {
            s.push(answer.front());
            answer.pop();
        }
        while (!s.empty()) {
            answer.push(s.top());
            s.pop();
        }

        // Enqueue the remaining elements from the original queue into the 'answer' queue.
        while (!q.empty()) {
            answer.push(q.front());
            q.pop();
        }

        // Return the modified 'answer' queue.
        return answer;
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}