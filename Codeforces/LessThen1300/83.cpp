#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<string> v(2 * n);
    for (int i = 0; i < 2 * n; i++) cin >> v[i];

    vector<string> k(2*n);
    for(int i=0; i<2*n; i++) k[i]=v[i];
    sort(k.begin(),k.end());
    for(int i=0; i<2*n; i += 2){
        if(k[i]!=k[i+1]){
            cout<<"-1";
            return 0;
        }
    }

    unordered_map<string, int> indexMap;
    for (int i = 0; i < 2 * n; i++) {
        if (indexMap.find(v[i]) != indexMap.end()) {
            cout << indexMap[v[i]] + 1 << " " << i + 1 << endl;
            indexMap.erase(v[i]);
        } else {
            indexMap[v[i]] = i;
        }
    }

    // if (!indexMap.empty()) {
    //     cout << "-1" << endl; // Added endl for proper output
    // }

    return 0; // Added return statement
}