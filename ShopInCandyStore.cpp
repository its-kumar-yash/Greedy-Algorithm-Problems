//LC - 2144

// In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
// You are now provided with an attractive offer.
// For every candy you buy from the store and get at most K other candies ( all are different types ) for free.
// Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
// In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution
{
public:
    //My Code
    vector<int> candyStore(int candies[], int N, int K)
    {
        //sort the candy array
        sort(candies, candies + N);
        
        //finding minimum cost
        int mini = 0;
        //start buying from 0th index, and take free candies from last index
        int j = N - 1;

        for(int i = 0; i < N; i++){
            if(i > j){
                break;
            }
            
            //take cheapest candy
            mini += candies[i];
            
            //take free candies from end
            j -= K;
        }
        
        // cout<<mini<<endl;
        
        //finding maximum cost
        int maxi = 0;
        //start buying from N - 1 th index, and take free candies from 0th index
        j = 0;

        for(int i = N - 1; i >= 0 ; i--){
            if(i < j){
                break;
            }
            
            //take expensive candy
            maxi += candies[i];
            
            //take free candies from end
            j += K;
        }
        
        // cout<< maxi<<endl;
        
        return {mini, maxi};
    }

    //Babbar Code
    vector<int> candyStore2(int candies[], int N, int K)
    {
        //sort the candy array
        sort(candies, candies + N);
        
        //finding minimum cost
        int mini = 0;
        int buy = 0;
        int freeC = N - 1;
        
        while(buy <= freeC){
            mini += candies[buy];
            buy++;
            freeC -= K;
        }
        
        //finding maximum cost
        int maxi = 0;
        buy = N - 1;
        freeC = 0;
        
        while(freeC <= buy){
            maxi += candies[buy];
            buy--;
            freeC += K;
        }
        
        return {mini, maxi};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends