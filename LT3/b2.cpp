#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    int n; cin >> n;
    int a[n+1];
    a[0] = 0; 
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
    	a[i] = a[i] ^ a[i-1]; 
	}
	if(n >= 60) cout << 1 << "\n";
	else{
		int ans = INT_MAX;
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				for(int k = j+1;k <= n;k++){
					long long l = a[j] ^ a[i-1];
					long long r = a[k] ^ a[j]; 
					if(l > r){
						ans = min(ans,(k - i) - 1); 
					}
				}
			}
		}
		if(ans != INT_MAX) cout << ans << "\n";
		else cout << -1 << "\n"; 
	}
}
