#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minMeetingRooms(vector<vector<int>> &intervals) {
        int n=intervals.size();
        vector<int> start(n);
        vector<int> end(n);
        for(int i=0; i<n; i++){
            start[i]=intervals[i][0];
            end[i]=intervals[i][1];
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int i=0;
        int j=0;
        int ans=0;
        while(i<n && j<n){
            if(start[i]<end[j]){
                ans++;
                i++;
            }
            else{
                j++;
                ans--;
            }
        }
        return ans;
    }

int main(){
    int n;
    cin>>n;
    vector<vector<int>> intervals(n,vector<int> (2));
    for(int i=0; i<n; i++){
        for(int j=0; j<2; j++) cin>>intervals[i][j]; 
    }
    cout<<minMeetingRooms(intervals);
}