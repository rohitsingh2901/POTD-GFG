#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minValue(string s, int k) {
        unordered_map<char,int> m;
        // Count frequency of each character
        for(auto x : s)
            m[x]++;
        
        // Priority queue to store frequencies in descending order
        priority_queue<int> pq;
        for(auto e : m)
            pq.push(e.second);
        
        // Remove k characters by decrementing their frequencies
        while(k--) {
            int t = pq.top();
            pq.pop();
            t--;
            pq.push(t);
        }
        
        // Calculate the sum of squares of the remaining frequencies
        int ans = 0;
        while(!pq.empty()) {
            int e = pq.top();
            pq.pop();
            ans += e * e;
        }
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
