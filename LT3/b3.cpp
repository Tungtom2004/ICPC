#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	vector<string> v;
	string s; int k; cin >> s >> k; 
	sort(s.begin(),s.end()); 
	do{
		v.push_back(s);
	}while(next_permutation(s.begin(),s.end())); 
	cout << v[k-1];  
	
}