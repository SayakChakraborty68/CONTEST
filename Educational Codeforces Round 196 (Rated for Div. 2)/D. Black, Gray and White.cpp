
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> adj(n+1);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(n%2==0){
			cout<<n+1<<"\n";
			continue;
		}
		int ele[3][2]={
			{n,n},
			{n+1,(n+1)/2},
			{n+2,1}
		};
		int ans=n+1;
		for(int i=0;i<3;i++){
			int k=ele[i][0];
			int M=ele[i][1];
			vector<int> comp(n+1,0);
			for(int child:adj[M]){
				queue<int> q;
				q.push(child);
				comp[child]=child;
				while(!q.empty()){
					int u=q.front();
					q.pop();
					for(int v:adj[u]){
						if(v!=M && comp[v]==0){
							comp[v]=child;
							q.push(v);
						}
					}
				}
			}
			bool f=false;
			for(int i=1;i<=n;i++){
				int j=k-i;
				if(i<j && j<=n){
					if(comp[i]!=comp[j]){
						f=true;
						break;
					}
				}
			}
			if(f){
				ans=k;
				break;
			}
		}
 
		cout<<ans<<endl;
	}
 
	return 0;
}
