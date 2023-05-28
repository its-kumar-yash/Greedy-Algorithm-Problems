// There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) 
//where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. 
//The task is to find the maximum number of meetings that can be accommodated in the meeting room.
//You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

// Note: If two meetings can be chosen for the same slot then choose meeting with smaller index in the given array.

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
        if(a.second.second == b.second.second){
            return a.first < b.first; 
        }
        return a.second.second <  b.second.second;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int, pair<int, int>>> v;
        
        for(int i = 0; i < N; i++){
            v.push_back({i + 1, {S[i], F[i]}});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        
        vector<int> res;
        int firstMeet = v[0].first;
        int ansStart = v[0].second.first;
        int ansEnd = v[0].second.second;
        
        res.push_back(firstMeet);
        
        for(int i = 1; i < N ; i++){
            if(v[i].second.first > ansEnd){
                ansEnd = v[i].second.second;
                res.push_back(v[i].first);
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends