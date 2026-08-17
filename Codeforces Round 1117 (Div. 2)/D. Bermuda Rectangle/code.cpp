#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
vector<int> divs;
vector<int> pref;
int s;
 
int getSum(int x){
    if(x <= 0) return 0;
    int pos = upper_bound(divs.begin(), divs.end(), x) - divs.begin();
    int b=0,l = 0;
    if(pos > 0){
        b = pref[pos-1];
        l = divs[pos-1];
    }
    if(pos == (int)divs.size()){
        return b+(x-l);
    }
    return b+(x-l)*(s/divs[pos]);
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> s >> q;
        divs.clear();
        for(int i=1;i*i<=s;i++){
            if(s%i==0){
                divs.push_back(i);
                if(i*i!=s){
                    divs.push_back(s/i);
                }
            }
        }
        sort(divs.begin(), divs.end());
        int sz = divs.size();
        pref.assign(sz, 0);
        int last = 0;
        int sum = 0;
        for(int i=0;i<sz;i++){
            int d = divs[i];
            sum += (d - last) * (s / d);
            pref[i] = sum;
            last = d;
        }
        while(q--){
            int x,y;
            cin >>x>>y;
            int limit = s/y;
            int pos = upper_bound(divs.begin(),divs.end(),limit)-divs.begin()-1;
            int p = divs[pos];
            p = min(p,x);
            int ans = p*y+getSum(x)-getSum(p);
            cout << ans<< endl;
        }
    }
 
    return 0;
}