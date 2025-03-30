#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int scheduleCourse(vector<vector<int>>& co) {
    int n = co.size();
    int curr = 0;
    priority_queue<int> maxHeap;
    
    // Sort courses by their deadlines
    sort(co.begin(), co.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    for(int i=0; i<n; i++){
        cout<<co[i][0]<<" "<<co[i][1]<<endl;
    }

    for (int i = 0; i < n; i++) {
        curr += co[i][0];
        maxHeap.push(co[i][0]);
        
        // If current time exceeds the deadline, remove the longest course
        if (curr > co[i][1]) {
            curr -= maxHeap.top();
            maxHeap.pop();
        }
    }
    
    return maxHeap.size();
}

int main() {
    vector<vector<int>> courses = {{5, 5}, {4, 6}, {2, 6}};
    cout << scheduleCourse(courses) << endl;
    return 0;
}
