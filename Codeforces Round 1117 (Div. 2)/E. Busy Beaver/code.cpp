#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin >>n>>x;
        vector<int> m(n);
        vector<vector<int>> a(n),b(n);
        vector<vector<tuple<int,int,int>>> seg(n);
        vector<int> ptr(n,0);
        vector<int> progress(n,0);
        for(int i=0;i<n;i++){
            cin >> m[i];
            a[i].resize(m[i]);
            b[i].resize(m[i]);
 
            for(int j=0;j<m[i];j++){
                cin >> a[i][j];
            }
 
            for(int j=0;j<m[i];j++){
                cin >> b[i][j];
            }
            int pref = 0;
            int best = 0;
            int last = 0;
            int mn = (int)4e18;
            for(int j=0;j<m[i];j++){
                mn = min(mn, pref-a[i][j]);
                pref += b[i][j]-a[i][j];
 
                if(pref > best){
                    int req = last-mn;
                    int gain = pref-last;
                    seg[i].push_back({req,gain,j+1});
                    best = pref;
                    last = pref;
                    mn = (int)4e18;
                }
            }
        }
 
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;
 
        for(int i=0;i<n;i++){
            if(!seg[i].empty()){
                auto [req, gain, pos] = seg[i][0];
                pq.push({req,i,0});
            }
        }
        int money = x;
        while(!pq.empty()){
            auto [req, id, pos] = pq.top();
            if(req>money){
                break;
            }
            pq.pop();
            auto [need,gain,floors] = seg[id][pos];
            money+=gain;
            progress[id]=floors;
            ptr[id]++;
            if(ptr[id]<(int)seg[id].size()){
                auto [nreq, ngain, npos] = seg[id][ptr[id]];
                pq.push({nreq, id, ptr[id]});
            }
        }
        int ans = -1;
        int idx = -1;
        for(int i=0;i<n;i++){
            int cur = money;
            int p = progress[i];
            while(p<m[i] && cur >= a[i][p]){
                cur-=a[i][p];
                cur+=b[i][p];
                p++;
            }
            if(p>ans){
                ans=p;
                idx=i+1;
            }
        }
        cout<<ans<<" "<<idx<<endl;
    }
 
    return 0;
}