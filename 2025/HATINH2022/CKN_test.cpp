#include <bits/stdc++.h> // Includes all standard libraries (common in competitive programming)

using namespace std; 
// --- Global Variables ---
const int MAXN = 20005; // Maximum number of nodes

vector<int> adj[MAXN]; // Adjacency list to represent the graph
int n, m; // Number of nodes (n) and edges (m)

// Arrays for Tarjan's algorithm
int num[MAXN];    // Discovery time of each node during DFS
int low[MAXN];    // Low-link value: the earliest discovery time reachable from this node (including itself)
int parent[MAXN]; // Parent of each node in the DFS tree

bool visited[MAXN]; // Used for the initial component count
int timer = 0;      // Global timer for setting discovery times in Tarjan's

int base_components = 0; // Stores the initial number of connected components in the graph
int result[MAXN];        // Stores the final result for each node

/**
 * @brief A simple DFS used only to mark all nodes in a single connected component as visited.
 * @param u The starting node for the DFS.
 */
void dfs_count(int u) { 
    visited[u] = true; 
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_count(v); 
        }
    }
} 

/**
 * @brief Implements Tarjan's algorithm to find articulation points and calculate
 *        the number of new components created upon removal of each node.
 * @param u The current node being visited.
 * @param isRoot A boolean flag, true if 'u' is the root of a DFS tree for a component.
 */
void tarjan(int u, bool isRoot) { 
    // Set the discovery time and low-link value for the current node 'u'
    num[u] = low[u] = ++timer; 

    int childCount = 0;       // Counts children in the DFS tree whose subtrees are separate branches
    int separateBranches = 0; // The number of *additional* components created by removing 'u'

    // Iterate through all neighbors of 'u'
    for (int v : adj[u]) { 
        if (!num[v]) { // If neighbor 'v' has not been visited yet (it's a tree edge)
            parent[v] = u; // Set 'u' as the parent of 'v'
            
            // Recursively call tarjan for the child 'v'
            tarjan(v, false); 

            // After the recursive call, update the low-link of 'u'.
            // 'u' can reach everything 'v' can reach, so we take the minimum.
            low[u] = min(low[u], low[v]); 

            // --- Articulation Point Condition ---
            // If the earliest reachable ancestor from 'v' is 'u' or below 'u',
            // it means the subtree at 'v' has no back edge that goes "above" 'u'.
            // Therefore, removing 'u' would disconnect this subtree from the rest of the graph.
            if (low[v] >= num[u]) { 
                childCount++; 
                if (!isRoot) {
                    // For a non-root node, each such child forms one additional component.
                    separateBranches++; 
                }
            } 
        } else if (v != parent[u]) { // If 'v' is visited and not the immediate parent, it's a back edge
            // This back edge means 'u' can reach an earlier node in the DFS tree.
            // Update low-link of 'u' using the discovery time of 'v'.
            low[u] = min(low[u], num[v]); 
        }
    } 

    // --- Final Calculation for Node 'u' ---
    if (isRoot) {
        // A root of a DFS tree is an articulation point if it has more than one child.
        // Removing it creates 'childCount' components, which is an *increase* of 'childCount - 1'.
        separateBranches = max(0, childCount - 1); 
    }
    
    // The final result for node 'u' is the initial number of components
    // plus the number of *additional* components created by removing 'u'.
    result[u] = base_components + separateBranches; 
}

int main() { 
    // Fast I/O
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    // Redirect input and output to files (common in competitive programming)
    freopen("CKN.INP", "r", stdin); 
    freopen("CKN.OUT", "w", stdout);

    // 1. Read graph dimensions and edges
    cin >> n >> m; 
    for (int i = 0; i < m; i++) { 
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }

    // 2. Count the initial number of connected components
    // The original comment "Đếm số cụm liên thông ban đầu" is Vietnamese for "Count the initial connected components"
    for (int i = 1; i <= n; i++) { 
        if (!visited[i]) { 
            base_components++; 
            dfs_count(i); 
        } 
    } 

    // 3. Reset arrays to run Tarjan's algorithm
    // The original comment "Reset để chạy Tarjan" is Vietnamese for "Reset to run Tarjan"
    memset(num, 0, sizeof(num)); 
    memset(low, 0, sizeof(low)); 
    memset(parent, 0, sizeof(parent)); 
    timer = 0; 

    // 4. Run Tarjan's algorithm for each component of the graph
    for (int i = 1; i <= n; i++) {
        if (!num[i]) { // If node 'i' hasn't been visited by Tarjan's yet
            tarjan(i, true); // Start a new DFS, so 'i' is the root of this component's DFS tree
        }
    }

    // 5. Print the results
    for (int i = 1; i <= n; i++) {
        cout << result[i] << "\n"; 
    }

    return 0; 
}
