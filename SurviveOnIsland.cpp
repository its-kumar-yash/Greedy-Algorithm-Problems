//Check if it is possible to survive on Island

// Ishika got stuck on an island. There is only one shop on this island and it is open on all days of the week except for Sunday. Consider following constraints:

// N – The maximum unit of food you can buy each day.
// S – Number of days you are required to survive.
// M – Unit of food required each day to survive.
// Currently, it’s Monday, and she needs to survive for the next S days.
// Find the minimum number of days on which you need to buy food from the shop so that she can survive the next S days, or determine that it isn’t possible to survive./

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int sundays = S/7;
        
        int buyingDay = S - sundays;
        int ans = 0;
        int totalFood = S * M; // itna food to chhahie use jinda rhne ke lie
        
        
        if(totalFood%N == 0){
            ans = totalFood/N;
        }
        else{
            ans = totalFood/N + 1;
        }
        // agar N=1 M=1 S=10  means sunday ko hm nhi buy kr skte to 1 din 
        // km ho gya or 1 din men 1 din ka bojan hi buy kr skte hen to fir to mr jaega vo
        
        if(ans <= buyingDay){
            return ans;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends