#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char type;        // 'S' for sheep, 'W' for wolf
    long long count;  // Number of sheep or wolves
    vector<int> children; // Children of this node
};

vector<Node> tree;

// DFS to calculate the number of sheep that reach the root node
long long dfs(int node) {
    long long totalSheep = 0;

    // Traverse all children of the current node
    for (int child : tree[node].children) {
        totalSheep += dfs(child); // Add sheep from the child node
    }

    if (tree[node].type == 'S') {
        totalSheep += tree[node].count; // Add sheep at the current node
    } else if (tree[node].type == 'W') {
        totalSheep -= tree[node].count; // Wolves reduce the number of sheep
    }

    // Return only the positive number of sheep
    return max(0LL, totalSheep);
}

int main() {
    int n;
    cin >> n;

    tree.resize(n + 1);

    for (int i = 2; i <= n; ++i) {
        char type;
        long long count;
        int parent;
        cin >> type >> count >> parent;

        tree[i].type = type;
        tree[i].count = count;
        tree[parent].children.push_back(i); // Add child to the parent's list
    }

    // Perform DFS starting from the root node (node 1)
    cout << dfs(1) << endl;

    return 0;
}
