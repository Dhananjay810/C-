#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compute_gcd(const vector<int>& nums) {
    int res = nums[0];
    for (int num : nums) {
        res = __gcd(res, num);
        if (res == 1) break;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Try all possible single-element splits
        bool found = false;
        vector<int> best_partition;

        // Try putting first element in B, rest in C
        for (int split = 1; split < n; split++) {
            vector<int> B(a.begin(), a.begin() + split);
            vector<int> C(a.begin() + split, a.end());
            
            int gcd_B = compute_gcd(B);
            int gcd_C = compute_gcd(C);
            
            if (gcd_B != gcd_C) {
                found = true;
                best_partition.resize(n, 1);
                fill(best_partition.begin() + split, best_partition.end(), 2);
                break;
            }
        }

        if (!found) {
            // Try putting last element in C, rest in B
            for (int split = n-1; split >= 1; split--) {
                vector<int> B(a.begin(), a.begin() + split);
                vector<int> C(a.begin() + split, a.end());
                
                int gcd_B = compute_gcd(B);
                int gcd_C = compute_gcd(C);
                
                if (gcd_B != gcd_C) {
                    found = true;
                    best_partition.resize(n, 1);
                    fill(best_partition.begin() + split, best_partition.end(), 2);
                    break;
                }
            }
        }

        if (!found) {
            // Try putting one distinct element in one group
            // Find two elements with different GCD contributions
            int overall_gcd = compute_gcd(a);
            for (int i = 0; i < n; i++) {
                vector<int> temp = a;
                temp.erase(temp.begin() + i);
                int other_gcd = compute_gcd(temp);
                if (other_gcd != a[i]) {
                    found = true;
                    best_partition.resize(n, 2);
                    best_partition[i] = 1;
                    break;
                }
            }
        }

        if (found) {
            cout << "Yes\n";
            for (int num : best_partition) {
                cout << num << " ";
            }
            cout << "\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}