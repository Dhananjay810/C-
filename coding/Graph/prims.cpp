#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<unordered_set>
#include<climits>
#include<queue>
#define pp pair<int,int>
using namespace std;

vector<list<pp>> graph;

void build(int src, int dest, int wt) {
    graph[src].push_back({dest, wt});
    graph[dest].push_back({src, wt});
}

long long prims(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_set<int> vis;
    vector<int> par(n + 1, -1);
    vector<int> key(n + 1, INT_MAX);

    pq.push({0, src});
    key[src] = 0;

    long long result = 0;

    while (!pq.empty()) {
        pp curr = pq.top();
        pq.pop();
        int u = curr.second;
        if (vis.find(u) != vis.end()) continue;
        vis.insert(u);
        result += curr.first;
        for (auto neig : graph[u]) {
            int v = neig.first;
            int weight = neig.second;  
            if (vis.find(v) == vis.end() && key[v] > weight) {
                key[v] = weight;
                pq.push({weight, v});
                par[v] = u;
            }
        }
    }  
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        build(s, d, w);
    }
    int src;
    cin >> src;
    cout << prims(src, n) << endl;

    return 0;
}
