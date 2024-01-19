//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};



class Solution {
  public:
  vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
    map<int, int> mp;  // A map to store the frequency of each element
    vector<int> q(K + 1, 0);  // A vector to simulate a priority queue of size K
    vector<vector<int>> ans;  // The final result vector of vectors
    int index;  // Variable to store the index of the recently added element in the priority queue

    for (int i = 0; i < N; i++) {
        mp[arr[i]]++;  // Increment the frequency of the current element
        q[K] = arr[i];  // Add the current element to the end of the priority queue

        // Find the index of the recently added element in the priority queue
        for (int j = 0; j <= K; j++) {
            if (q[j] == arr[i]) {
                index = j;
                break;
            }
        }

        // Perform insertion sort-like operation to maintain sorted order based on frequency and values
        for (int j = index; j > 0; j--) {
            if (mp[q[j]] > mp[q[j - 1]]) {
                swap(q[j], q[j - 1]);  // Swap elements if the frequency is higher
            } else if (mp[q[j]] == mp[q[j - 1]] && q[j] < q[j - 1]) {
                swap(q[j], q[j - 1]);  // If frequencies are equal, swap based on values
            } else {
                break;  // Break the loop if the correct position is reached
            }
        }

        // Form the array for this iteration and add it to the result vector
        vector<int> temp;
        for (int j = 0; j < K && q[j] != 0; j++) {
            temp.push_back(q[j]);
        }
        ans.push_back(temp);
    }
    return ans;  // Return the final result vector of vectors
}

    
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

