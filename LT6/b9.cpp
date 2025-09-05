#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,k; cin >> n >> k;
	long long a[n+5]; 
	for(int i = 1;i <= n;i++) cin >> a[i]; 
	long long key[n+5];
	key[0] = 0;
	long long s = 0;
	for(int i = 1;i <= n;i++){
		s += a[i]; 
		long long v = (s - i) % k;
		if(v < 0) v += k;
		key[i] = v; 
	}
	map<long long,long long> mp;
	long long ans = 0;
	for(int i = 0;i <= n;i++){
		if(auto it = mp.find(key[i]);it != mp.end()) ans += it->second; 
		mp[key[i]]++; 
		int t = i - (int)(k - 1); 
		if(t >= 0){
			auto it2 = mp.find(key[t]);
			if(it2 != mp.end()){
				if(--(it2->second) == 0) mp.erase(it2); 
			}
		}
	}
	cout << ans; 
}