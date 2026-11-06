#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> dp,h,p;
vector<vector<int>> adj;
void dfs(int u){
	dp[u]=1;
	int mx1=0,mx2=0;
	for(auto v:adj[u]){
		dfs(v);
		if(mx1<h[v]){
			mx2=mx1;
			mx1=h[v];
		}
		else if(mx2<h[v]) mx2=h[v];
		dp[u]+=dp[v];
	}
	h[u]=mx1+1;
	dp[u]+=min(mx1,mx2);
}
 
signed main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		dp.assign(n,0);
		h.assign(n,0);
		p.assign(n,0);
		adj.assign(n,{});
		for(int i=1;i<n;i++){
			int x;
			cin >> x;
			x--;
			p[i]=x;
			adj[x].push_back(i);
		}
		dfs(0);
		cout << dp[0] << endl;
	}
}