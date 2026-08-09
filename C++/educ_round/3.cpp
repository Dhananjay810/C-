#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        vector<pair<int,int>> runs;
        int i = 0;
        while(i < n){
            int j = i;
            while(j < n && a[j] == a[i]) j++;
            runs.push_back({a[i], j - i});
            i = j;
        }
        
        int m = runs.size();
        vector<long long> suf(m + 1, 0);
        for(int j = m - 1; j >= 0; j--)
            suf[j] = suf[j + 1] + runs[j].second;
        vector<int> suf_min(m + 1, INT_MAX);
        for(int j = m - 1; j >= 0; j--)
            suf_min[j] = min(suf_min[j + 1], runs[j].second);
        
        int ans = 0;
        
        ans = 0;
        vector<int> counts;
        for(auto& r : runs) counts.push_back(r.second);
        
        vector<int> thresholds = {0};
        for(int c : counts) thresholds.push_back(c);
        sort(thresholds.begin(), thresholds.end());
        thresholds.erase(unique(thresholds.begin(), thresholds.end()), thresholds.end());
        vector<pair<int,int>> sorted_runs = runs;
        vector<int> sorted_counts = counts;
        sort(sorted_counts.begin(), sorted_counts.end());
        vector<long long> prefix_sum(m + 1, 0);
        for(int j = 0; j < m; j++) prefix_sum[j+1] = prefix_sum[j] + sorted_counts[j];
        
        set<long long> seen_arrays; 
        int prev_elim = -1;
        for(int ti = 0; ti < (int)thresholds.size(); ti++){
            int d = thresholds[ti];
            int elim = (int)(upper_bound(sorted_counts.begin(), sorted_counts.end(), d) - sorted_counts.begin());
            
            if(elim == prev_elim) continue;
            prev_elim = elim;
            
            int surv = m - elim;
            if(surv == 0) continue;
            
            long long sum_surv = prefix_sum[m] - prefix_sum[elim];
            int min_surv = sorted_counts[elim]; 
            long long rem = (long long)k - sum_surv;
            if(rem % surv != 0) continue;
            long long delta = rem / surv;
            
            if(delta < 1 - min_surv) continue;
            
            long long L, U;
            long long min_d_for_elim = (elim > 0 ? sorted_counts[elim - 1] : 0);
            long long min_d_for_p = max(0LL, -delta);
            L = max(min_d_for_elim, min_d_for_p);
            U = (elim < m ? (long long)sorted_counts[elim] - 1 : (long long)2e18);
            
            if(L > U) continue;
            
            ans++;
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}