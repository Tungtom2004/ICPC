#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	map<int,int>mp;
	int k,s; cin >> k >> s;
	int cnt = 0;
	for(int i = 0;i <= k;i++) mp[i] = 1;
	for(int i = 0;i <= k;i++){
		for(int j = 0;j <= k;j++){
			if(mp[s - j - i] == 1) cnt+=1; 
		}
	}
	cout << cnt; 
}