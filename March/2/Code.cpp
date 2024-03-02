#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[a[i]]++;
            if(m[a[i]]>=k){
                return a[i];
            }
        }
        return -1;
    } 
};

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(n, k, a)<<endl;
	}
	
	return 0;
}
