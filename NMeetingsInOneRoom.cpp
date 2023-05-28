//Based on Activity Selection Concept

// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    static bool cmp(pair<int, int> &a, pair<int, int>&b){
        return a.second < b.second;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> mp;
        //creating interval mapping
        for(int i = 0; i < n; i++){
            mp.push_back({start[i], end[i]});
        }
        
        //sort according to increasing order of end time
        sort(mp.begin(), mp.end(), cmp);
        // for(int i = 0; i < n; i++){
        //     cout<<mp[i].first<<" "<<mp[i].second<<endl;
        // }
        
        int count = 1; // count of meeting performed
        int ansStartTime = mp[0].first; //start time of first meeting
        int ansEndTime = mp[0].second; // end time of first meeting
        
        for(int i = 1; i < n; i++){
            //start time of next meeting should be greater than end time of prev meeting
            if(mp[i].first > ansEndTime){
                count++;
                ansEndTime = mp[i].second;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends