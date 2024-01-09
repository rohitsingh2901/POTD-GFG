
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> prefixFun(string s){
    int n = s.length();
    vector<int> pi(n); // Initializing an array to store prefix function values
    for(int i = 1; i < n; i++){
        int j = pi[i - 1]; // Set j to the previous prefix function value
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1]; // Update j based on the previously calculated prefix values
        }
        if(s[i] == s[j]){
            j++; // Increment j if characters match
        }
        pi[i] = j; // Store the prefix function value for the current index
    }
    return pi; // Return the computed prefix function array
}

vector<int> search(string pat, string txt)
{
    string look = pat + '?' + txt; // Combine the pattern, a separator, and the text
    vector<int> kmp = prefixFun(look); // Compute prefix function for the combined string
    vector<int> ans; // Initialize a vector to store indices of pattern occurrences
    int start = pat.size() - 1; // Set the starting index for checking occurrences

    for (int i = start; i < look.size(); i++)
    {
        if (kmp[i] == pat.size())
        {
            ans.push_back(i - 2 * pat.size() + 1); // Adjust index for original text
        }
    }
    return ans; // Return the vector containing the starting indices of pattern occurrences
}

};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}