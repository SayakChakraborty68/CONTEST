#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> a(n);
	    int m=-1;
	    for(int i=0;i<n;i++){
	        cin >> a[i];
	        m=max(m,a[i]);
	    }
	    vector<int> dist(2*n,-1);
	    queue<int> q;
	    for(int i=0;i<n;i++){
	        if(a[i]==m){
	            dist[2*i]=0;
	            q.push(2*i);
	        }
	    }
	    while(!q.empty()){
	        int u=q.front();
	        q.pop();
	        int i=u/2;
	        int c=u%2;
	        int left=(i-1+n)%n;
	        int v1=2*left+(1-c);
	        if(dist[v1]==-1){
	            dist[v1]=dist[u]+1;
	            q.push(v1);
	        }
	        int right=(i+1)%n;
	        int v2=2*right+(1-c);
	        if(dist[v2]==-1){
	            dist[v2]=dist[u]+1;
	            q.push(v2);
	        }
	    }
	    int mx0=0,mx1=0;
	    bool f=true;
	    for(int i=0;i<n;i++){
	        if(dist[2*i]==-1){
	            f=false;
	            break;
	        }
	        mx0=max(mx0,dist[2*i]);
	        if(dist[2*i+1]==-1){
	            f=false;
	            break;
	        }
	        mx1=max(mx1,dist[2*i+1]);
	    }
	    if(!f) cout << -1 << endl;
	    else cout << min(mx0,mx1) << endl;
	    
	}
	return 0;
}