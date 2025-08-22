#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int count = 0;
        for (char c : s) {
            if (c == '1') count++;
        }
        // cout<<count<<endl;

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int y = count;
            if (s[i] == '0') {
                y += 1; // simulate flipping '0' to '1'
            }
            else y=y-1;
            ans += y;
            // cout<<ans<<endl;
        }

        cout << ans << endl;
    }
    return 0;
}
