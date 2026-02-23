#include<iostream>
#include<vector>
using namespace std;

bool canReach(int x, int y) {
    int diff = x - 2*y;
    if (diff < 0 || diff % 3 != 0) {
        return false;
    }
    
    int target = diff / 3;
    int min_c = max(0, -y);
    int max_c = target / 2;
    
    return min_c <= max_c;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        if (canReach(x, y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}