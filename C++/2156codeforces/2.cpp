#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        
        vector<int> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i];
        }
        for (int i = 0; i < q; i++) {
            long long a = queries[i];
            int steps = 0;
            int machine_index = 0;
            
            while (a > 0) {
                if (s[machine_index] == 'A') {
                    a = a - 1;
                } else {
                    a = a / 2;
                }
                
                steps++;
                machine_index = (machine_index + 1) % n;
            }
            
            cout << steps <<endl;
        }
    }
    
    return 0;
}