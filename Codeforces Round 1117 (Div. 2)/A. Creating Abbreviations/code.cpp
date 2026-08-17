#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        bool present[26] = {};
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            present[s[0]-'a']=1;
        }
        bool f= 1;
        for(int i=0;i<m;i++){
            string s;
            cin >> s;
            for(char c : s){
                if(!present[c-'A']){
                    f=0;
                }
            }
        }
        if(f) cout << "YES"<< endl;
        else cout << "NO"<< endl;
    }
 
    return 0;
}