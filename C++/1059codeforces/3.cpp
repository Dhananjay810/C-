#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int MAX_OPS = 3;

vector<int> find_sequence(int a, int b) {
    if (a == b) return {};
    
    // Queue stores pairs of (current_value, operations_so_far)
    queue<pair<int, vector<int>>> q;
    map<int, bool> visited;
    
    // Start with initial value and empty operations list
    vector<int> initial_ops;
    q.push({a, initial_ops});
    visited[a] = true;
    
    while (!q.empty()) {
        // Get the front element from queue
        pair<int, vector<int>> front_element = q.front();
        q.pop();
        
        // Extract the values from the pair
        int current = front_element.first;
        vector<int> ops = front_element.second;
        
        if (ops.size() > MAX_OPS) continue;
        
        // Try all possible x from 0 to current
        for (int x = 0; x <= current; x++) {
            int next = current ^ x;
            
            if (next == b) {
                // Found solution - add current x to operations and return
                vector<int> result_ops = ops;
                result_ops.push_back(x);
                return result_ops;
            }
            
            if (!visited[next] && ops.size() + 1 <= MAX_OPS) {
                visited[next] = true;
                vector<int> new_ops = ops;
                new_ops.push_back(x);
                q.push({next, new_ops});
            }
        }
    }
    
    return {}; // Not found
}

void solve() {
    int a, b;
    cin >> a >> b;
    
    auto result = find_sequence(a, b);
    if (result.empty()) {
        cout << "-1\n";
    } else {
        cout << result.size() << "\n";
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}