void dfs(int node,int par)
{
  dp[node]=arr[node];
  for(auto it:tree[node])
   { 
       if(it==par)
          continue;
          dfs(it,node);
          dp[node]+=dp[it];
   }
}
