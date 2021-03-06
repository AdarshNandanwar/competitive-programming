// Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

// Input Format
// First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
// The first line of each test case contains two integers N and M.

// Constraints
// 1 <= T<= 1000
// 1 <= N,M <= 100000

// Output Format
// Print answer for every test case in a new line modulo 10^9+7.

// Sample Input
// 2
// 2 3
// 4 4
// Sample Output
// 1
// 2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main() {

	ll t;
	cin>>t;
	while(t--){
		ll n, m;
		cin>>n>>m;
		vector<ll> dp(n+1, 1);
		for(ll i = 2; i<=n; i++){
			dp[i] = dp[i-1];
			if(i-m>=0) dp[i] = (dp[i]+dp[i-m])%MOD;
		}
		cout<<dp[n]<<endl;
	}

	return 0;
}