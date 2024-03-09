#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        string t=s;
        string str;
        while(r--){
            str="";
            for(int i=0;i<s.length();i++){
                if(s[i]=='1'){
                    str+="10";
                }
                else{
                   str+="01";
                }
                if(str.size()>=t.size()) break;
            }
            s=str;
        }
        return s[n];
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
