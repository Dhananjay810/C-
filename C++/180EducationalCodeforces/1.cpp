#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, x, y;
        cin >> a >> x >> y;
        
        int dxa = abs(x - a);
        int dya = abs(y - a);
        
        int lower_x = x - dxa + 1;
        int upper_x = x + dxa - 1;
        int lower_y = y - dya + 1;
        int upper_y = y + dya - 1;
        int lower = max(lower_x, lower_y);
        int upper = min(upper_x, upper_y);
        
        bool possible = false;
        
        if (lower <= upper) {
            if (a >= lower && a <= upper) {
                if (upper - lower + 1 > 1) {
                    possible = true;
                }
            } else {
                possible = true;
            }
        }
        
        cout << (possible ? "YES" : "NO") << endl;
    }
    return 0;
}