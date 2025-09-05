#include<bits/stdc++.h>
using namespace std;

struct Point{
	long long x,y; 
};


int n; 
vector<Point> v;

bool check(int d){
	vector<Point> a = v;
	sort(a.begin(),a.end(), [](auto &p1,auto &p2){
		return p1.x < p2.x;
	}); 
	
	int n = a.size(); 
	int j = 0;
	multiset<long long> active;
	for(int i = 0;i < n;i++){
		while(j < i && a[j].x <= a[i].x - d){
			active.insert(a[j].y); 
			j++; 
		}
		if(!active.empty()){
			long long minY = *active.begin(); 
			long long maxY = *active.rbegin(); 
			if(minY <= a[i].y - d || maxY >= a[i].y + d){
				return true; 
			}
		}
	}
	return false;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	v.resize(n);
	for(int i = 0;i < n;i++) cin >> v[i].x >> v[i].y; 
	int l = 0, r = 1e9, ans = -1; 
	while(l <= r){
		int m = (l + r)/2;
		if(check(m)){
			ans = m;
			l = m + 1; 
		}
		else r = m - 1;
	}
	cout << ans << "\n"; 
	
}