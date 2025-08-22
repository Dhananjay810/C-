#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        int max_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] > max_val) {
                    max_val = a[i][j];
                }
            }
        }

        vector<pair<int, int>> F;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == max_val) {
                    F.push_back({i, j});
                }
            }
        }

        if (F.empty()) {
            cout << max_val << '\n';
            continue;
        }

        set<int> distinct_rows, distinct_cols;
        for (const auto& p : F) {
            distinct_rows.insert(p.first);
            distinct_cols.insert(p.second);
        }
        int base_cols = distinct_cols.size();
        int base_rows = distinct_rows.size();

        vector<int> only_cols(n, 0);
        vector<int> col_count(m, 0);
        vector<int> col_single_row(m, -1);

        for (int j = 0; j < m; j++) {
            col_single_row[j] = -1;
        }

        for (const auto& p : F) {
            int i = p.first;
            int j = p.second;
            col_count[j]++;
            if (col_count[j] == 1) {
                col_single_row[j] = i;
            } else {
                col_single_row[j] = -2;
            }
        }

        for (int j = 0; j < m; j++) {
            if (col_count[j] == 1) {
                int row_index = col_single_row[j];
                if (row_index >= 0) {
                    only_cols[row_index]++;
                }
            }
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            if (base_cols - only_cols[i] <= 1) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << max_val - 1 << '\n';
            continue;
        }

        vector<int> only_rows(m, 0);
        vector<int> row_count_vec(n, 0);
        vector<int> row_single_col(n, -1);

        for (int i = 0; i < n; i++) {
            row_single_col[i] = -1;
        }

        for (const auto& p : F) {
            int i = p.first;
            int j = p.second;
            row_count_vec[i]++;
            if (row_count_vec[i] == 1) {
                row_single_col[i] = j;
            } else {
                row_single_col[i] = -2;
            }
        }

        for (int i = 0; i < n; i++) {
            if (row_count_vec[i] == 1) {
                int col_index = row_single_col[i];
                if (col_index >= 0) {
                    only_rows[col_index]++;
                }
            }
        }

        found = false;
        for (int j = 0; j < m; j++) {
            if (base_rows - only_rows[j] <= 1) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << max_val - 1 << '\n';
        } else {
            cout << max_val << '\n';
        }
    }

    return 0;
}