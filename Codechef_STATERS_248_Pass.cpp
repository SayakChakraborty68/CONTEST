#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    vector<int> a(5);
	    for(int i=0;i<5;i++) cin >> a[i];
	    int x = 0, y=0;
	    for(int i=0;i<5;i++){
	        if(a[i]>=60) x++;
	        if(a[i] >= 30) y++;
	    }
	    if(x>=2 && y >=4) cout << "Pass" << endl;
	    else cout << "Fail" << endl;
	}

}

