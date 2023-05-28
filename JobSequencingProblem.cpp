// Given a set of N jobs where each jobi has a deadline and profit associated with it.

// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
//We earn the profit associated with job if and only if the job is completed by its deadline.

// Find the number of jobs done and the maximum profit.

// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b){
        a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {   
        //sort the array in decreasing order of profit
        sort(arr, arr + n, cmp);
        
        //find max deadline
        int maxDeadLine = INT_MIN;
        for(int i=0; i<n; i++){
            maxDeadLine = max(maxDeadLine, arr[i].dead);
        }
        //create a schdule array of maxdeadline size
        vector<int> schedule(maxDeadLine + 1, -1);
        
        //now traverse the job array and aasign schedule to job with max profit
        int totalProfit = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            int currProfit = arr[i].profit;
            int currJobID = arr[i].id;
            int currDeadLine = arr[i].dead;
            
            //checking slot for doing the job
            for(int k = currDeadLine; k > 0; k--){
                if(schedule[k] == -1){
                    count++;
                    totalProfit += currProfit;
                    schedule[k] = currJobID;
                    break;
                }
            }
        }
        
        
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(totalProfit);
        return ans;
    } 
};

class Solution2 
{
    public:
    static bool comp(Job a, Job b){
        return a.profit > b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.unction to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {   
        //sort the array in decreasing order of profit
         sort(arr, arr+n, comp);
        
        int maxDead = INT_MIN;
        for(int i=0; i<n; i++){
            maxDead = max(maxDead, arr[i].dead);
        }
        
        vector<int>scheduled(maxDead+1, -1);
        
        int count = 0;
        int totalProfit = 0;
        
        for(int i=0; i<n; i++){
            
            int currProfit = arr[i].profit;
            int currJobID = arr[i].id;
            int currDead = arr[i].dead;
            
            for(int k = currDead; k>0; k--){
                if(scheduled[k] == -1){
                    count++;
                    totalProfit += currProfit;
                    scheduled[k] = currJobID;
                    break;
                }
            }
        }
        
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(totalProfit);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends