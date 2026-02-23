#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(const string& str) {
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool isNonDecreasing(const string& str) {
    for (int i = 1; i < str.length(); i++) {
        if (str[i] < str[i - 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    // Try all possible subsequences
    for (int mask = 0; mask < (1 << n); mask++) {
        string p = "";  // subsequence to remove
        string z = "";  // remaining string
        vector<int> indices;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                p += s[i];
                indices.push_back(i + 1);  // 1-based indexing
            } else {
                z += s[i];
            }
        }
        
        // Check if p is non-decreasing and z is palindrome
        if (isNonDecreasing(p) && isPalindrome(z)) {
            cout << indices.size() << "\n";
            if (!indices.empty()) {
                for (int idx : indices) {
                    cout << idx << " ";
                }
                cout << "\n";
            }
            return;
        }
    }
    
    // If no valid subsequence found
    cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}