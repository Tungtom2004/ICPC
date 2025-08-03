#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> A[100001];
bool check[100001];

int res = 0;
int dem = 0;

void DFS(int u){
	dem++;
	check[u] = true;
	for(auto v : A[u]){
		if(!check[v]) DFS(v);
	}
}

int main(){
	cin >> n >> m;
	memset(check,false, sizeof(check));
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(!check[i]){
			DFS(i);
			res = max(res, dem);
			dem = 0;
//			memset(check,false, sizeof(check));
		}
	}
	cout << res << endl;
}
