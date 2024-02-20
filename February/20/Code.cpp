#include <bits/stdc++.h>
using namespace std;

//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:

    bool help(string s,vector<string> &B,int index){
        if(index==s.length()) return 1;
        string temp = "";
        bool a = 0;
        for(int i=index;i<s.length();i++){
            temp+=s[i];
            for(int j=0;j<B.size();j++){
                if(B[j]==temp){
                    a = a | help(s,B,i+1);
                    break;
                }
            }
        }
        return a;
    }

    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        return help(s,dictionary,0);
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}
