// inout dp used for diameter of tree ,max sum between two nodes.
ll dfs1(ll node, ll par){
	in[node] = 0LL;
	for(auto child: g[node]){
		if(child == par)continue;
		dfs1(child, node);
		in[node] = max(in[node], 1+in[child]);
	}
}

// compute out[] array
ll dfs2(ll node, ll par){
	ll mx1 = -1;
	ll mx2 = -1;
	
	for(auto child: g[node]){
		if(child == par) continue;
		if(in[child] >= mx1) mx2 = mx1, mx1 = in[child];
		else if(in[child] > mx2) mx2 = in[child];
	}
	
	for(auto child: g[node]){
		if(child == par) continue;
		ll use = mx1;
		if(mx1 == in[child]) use = mx2;		
		out[child] = max(1LL+out[node], 2LL+use);
		dfs2(child, node);
	}
}
