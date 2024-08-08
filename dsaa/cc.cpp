#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string> l;
    while (t--) {
        int n, s, m;
        cin >> n >> s >> m;

        vector<pair<int, int>> intervals(n);
        for (int i = 0; i < n; i++) {
            cin >> intervals[i].first >> intervals[i].second;
        }

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Check if there is a gap of size s between any two intervals
        bool can_shower = false;
        for (int i = 0; i < n - 1; i++) {
            if (intervals[i + 1].first - intervals[i].second >= s) {
                can_shower = true;
                break;
            }
        }

        // Check if there is enough time at the beginning or end of the day
        if (!can_shower) {
            can_shower = intervals[0].first >= s || m - intervals[n - 1].second >= s;
        }

        if(can_shower==false) l.push_back("NO");
        else l.push_back("YES");
    }
    for(int i=0; i<l.size(); i++) cout<<l[i]<<endl;

    return 0;
}