
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};



class Solution
{
    public:
    static bool cmp(Item a, Item b){
        return  ((double)a.value/(double)a.weight)> ((double)b.value/(double)b.weight);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double Vsum = 0.0;
        int Wsum = 0;
        for(int i=0;i<n;i++){
            if(Wsum+arr[i].weight<W){
                Vsum+=arr[i].value;
                Wsum+=arr[i].weight;
            }
            else{
                Vsum+=((arr[i].value/(double)arr[i].weight)*(double)(W-Wsum));
                break;
            }
        }
        return Vsum;
        
    }
        
};



int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}