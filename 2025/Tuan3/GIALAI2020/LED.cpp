#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

const int MAX_SIZE = 55;

int n, m;
// grid[i][j] stores existing connections: 1 for down, 2 for right
int grid[MAX_SIZE][MAX_SIZE];
int component_id[MAX_SIZE][MAX_SIZE];
int component_count = 0;

// DSU (Disjoint Set Union) parent array
int parent[MAX_SIZE * MAX_SIZE];

struct Edge {
    int u, v, cost;
    int r, c, dir; 

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

// --- DSU Functions ---
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

// --- Component Finding (DFS) ---
void dfs(int r, int c, int id) {
    if (r < 0 || r >= n || c < 0 || c >= m || component_id[r][c] != 0) {
        return;
    }
    component_id[r][c] = id;

    // Move down if path exists from current cell
    if ((grid[r][c] & 1) && r + 1 < n) {
        dfs(r + 1, c, id);
    }
    // Move right if path exists from current cell
    if ((grid[r][c] & 2) && c + 1 < m) {
        dfs(r, c + 1, id);
    }
    // Move up if path exists from cell above
    if (r > 0 && (grid[r - 1][c] & 1)) {
        dfs(r - 1, c, id);
    }
    // Move left if path exists from cell to the left
    if (c > 0 && (grid[r][c - 1] & 2)) {
        dfs(r, c - 1, id);
    }
}

int main() {
    // Fast I/O and file handling
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // freopen("LED.inp", "r", stdin);
    // freopen("LED.out", "w", stdout);

    // 1. Read input
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> grid[i][j];
            component_id[i][j] = 0; // Initialize component id
        }
    }

    // 2. Find all connected components
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (component_id[i][j] == 0) {
                component_count++;
                dfs(i, j, component_count);
            }
        }
    }

    if (component_count <= 1) {
        std::cout << 0 << " " << 0 << std::endl;
        return 0;
    }

    // 3. Generate potential edges to connect components
    std::vector<Edge> potential_edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Potential vertical connection (cost 1)
            if (i + 1 < n) {
                int comp1 = component_id[i][j];
                int comp2 = component_id[i + 1][j];
                if (comp1 != comp2) {
                    potential_edges.push_back({comp1, comp2, 1, i, j, 1});
                }
            }
            // Potential horizontal connection (cost 2)
            if (j + 1 < m) {
                int comp1 = component_id[i][j];
                int comp2 = component_id[i][j + 1];
                if (comp1 != comp2) {
                    potential_edges.push_back({comp1, comp2, 2, i, j, 2});
                }
            }
        }
    }

    // 4. Run Kruskal's algorithm on components
    std::sort(potential_edges.begin(), potential_edges.end());

    // Initialize DSU for components (from 1 to component_count)
    std::iota(parent + 1, parent + component_count + 1, 1);

    long long total_cost = 0;
    std::vector<Edge> added_edges;
    for (const auto& edge : potential_edges) {
        if (find_set(edge.u) != find_set(edge.v)) {
            unite_sets(edge.u, edge.v);
            total_cost += edge.cost;
            added_edges.push_back(edge);
            if (added_edges.size() == component_count - 1) {
                break; // Optimization: stop when all components are connected
            }
        }
    }

    // 5. Print the result
    std::cout << added_edges.size() << " " << total_cost << std::endl;
    for (const auto& edge : added_edges) {
        std::cout << edge.r + 1 << " " << edge.c + 1 << " " << edge.dir << std::endl;
    }

    return 0;
}
