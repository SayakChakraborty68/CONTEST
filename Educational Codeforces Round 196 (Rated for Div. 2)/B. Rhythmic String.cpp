signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		int mxcnt=0;
		for(int i=0;i<n;i++) {
			int cnt=0;
			for(int j=0;j<n;j++) if(a[j]%a[i]==0) cnt++;
		    mxcnt=max(mxcnt,cnt);
		}
		cout<<n-mxcnt<<endl;
	}
	return 0;
}