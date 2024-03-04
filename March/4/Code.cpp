#include <iostream>
using namespace std;


/*Function to swap array elements
* arr : array input
* n : number of elements in array
*/
class Solution{
  public:
    void swapElements(int arr[], int n){
        
        // Your code here
        int i=0;
        int j=i+2;
        while(j<n){
            swap(arr[i],arr[j]);
            i++;j++;
        }
        
    }
};


int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int n;
	    cin >> n;
	    
	    int arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
        Solution obj;
        // calling function to swap the array swap elements
	    obj.swapElements(arr, n);
	    
	    // Printing the modified array
	    for(int i = 0;i<n;i++){
            cout << arr[i] << " ";
        }
	    
	    cout << endl;
	}
	
	return 0;
}
