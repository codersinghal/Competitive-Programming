/**
 * Description: Find the diameter of the tree.
 * Using double dfs.
 * Usage: getDiameter O(V + E)
 * Source: https://github.com/dragonslayerx 
 */

#include<bits/stdc++.h>
using namespace std;


 
//       An approach for structured trees
    /*int ans;
    public int diameterOfBinaryTree(TreeNode root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
    public int depth(TreeNode node) {
        if (node == null) return 0;
        int L = depth(node.left);
        int R = depth(node.right);
        ans = Math.max(ans, L+R+1);
        return Math.max(L, R) + 1;
    }*/
 
vector<vector<int> > g;
int n;
 
pair<int, int> bfs(int root){
    vector<int> dist(n+1, 0);
    dist[root] = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int curr = q.front();
        for(auto it : g[curr]){
            if(dist[it] != 0){
                continue;
            }
            q.push(it);
            dist[it] = dist[curr] + 1;
        }
        q.pop();
    }
    int mx = INT_MIN, vertex = -1;
    for(int i=1 ; i<=n ; i++){
        if(mx < dist[i]){
            mx = dist[i];
            vertex = i;
        }
    }
    return make_pair(mx, vertex);
}
 
int diameter(int root){
    pair<int, int> p1 = bfs(root), p2;
    p2 = bfs(p1.second);
    return p2.first;
}
 
int main(){
    cin >> n;
    g.resize(n+1);
    for(int i=0, u, v ; i<n-1 ; i++){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
// choosing arbitrary node to be 1.
    cout << diameter(1) ;
    return 0;
}
