
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans = 0;
        int j = 1;
            for(int i=s.length()-1;i>0;i--){
                if(s[i]<'0' || s[i]>'9'){
                    return -1;
                }
                ans+=(s[i]-'0')*j;
                j*=10;
            }
        if(s[0]=='-'){
            return ans*-1;
        }
        else{
            ans+=(s[0]-'0')*j;
        }
        return ans;
        
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
