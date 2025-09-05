#include<bits/stdc++.h>
using namespace std;

double dp[101][101][101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int A,B,C; cin >> A >> B >> C;
	for(int a = 0;a <= 100;a++){
		for(int b = 0;b <= 100;b++){
			for(int c = 0;c <= 100;c++){
				dp[a][b][c] = 0.0; 
			}
		}
	}
	for(int s = 297;s >= 0;s--){
		for(int a = 0;a <= 100;a++){
			for(int b = 0;b <= 100;b++){
				int c = s - a - b;
				if(c < 0 || c > 100) continue;
				if(a >= 100 || b >= 100 || c >= 100){
					dp[a][b][c] = 0.0;
					continue; 
				}
				int sum = a + b + c;
				double res = 1.0;
				if(a > 0) res += (double)a/s * dp[a+1][b][c]; 
				if(b > 0) res += (double)b/s * dp[a][b+1][c]; 
				if(c > 0) res += (double)c/s * dp[a][b][c+1]; 
				dp[a][b][c] = res; 
			}
		}
	}
	cout.setf(std::ios::fixed); cout << setprecision(6) << dp[A][B][C] << "\n";
	
}