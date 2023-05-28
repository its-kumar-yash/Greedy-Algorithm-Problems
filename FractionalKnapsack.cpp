// Given weights and values of N items, we need to put these items in a 
//knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool cmp(pair<double, Item> &a, pair<double, Item> &b){
        return a.first > b.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> vec;
        
        //find per unit value
        for(int i = 0; i < n; i++){
            double perUnitVal = arr[i].value/(double)arr[i].weight;
            vec.push_back({perUnitVal, arr[i]});
        }
        
        //sort the vector in decreasing order
        sort(vec.begin(), vec.end(), cmp);
        
        //now traverse the vector and check which item can be included
        double maxi = 0.0;
        for(auto &v : vec){
            if(v.second.weight <= W){
                maxi += v.second.value;
                W -= v.second.weight;
            }
            else{
                maxi += W * v.first;
                W = 0;
            }
        }
        
        return maxi;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
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
// } Driver Code Ends