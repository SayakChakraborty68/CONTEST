#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> p(n+1);
        vector<int> d(n+1);
        p[1]=0;
        d[1]=0;
        for(int i=2;i<=n;i++){
            cin >> p[i];
            d[i] = d[p[i]]+1;
        }
        int m;
        cin >> m;
        vector<int> a(m);
        for(int i=0;i<m;i++){
            cin >> a[i];
        }
        int mn = a[0];
        for(int i=1;i<m;i++){
            if(d[a[i]]<d[mn]){
                mn = a[i];
            }
        }
        cout << m-1;
        for(int i=0;i<m;i++){
            if(a[i] != mn){
                cout << " " << a[i];
            }
        }
        cout << endl;
    }
 
    return 0;
}