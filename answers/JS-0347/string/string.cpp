#include<bits/stdc++.h>
#define ll long long 

using namespace std;
string s;
ll len;
int Q;
int dp[100000];
//void check(int a,int b){
//	if((len-b)%2==0){
		
//	} 
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i=0;
	cin>>Q;
while(Q--)	
{
cin>>s;
	ll len=s.length();
//	for(int i=1;i<=len-1;i++){
	//	for(int j=i+1;j<=len-1;j++){
	//	if(check(i,j)) ans++;	
	//	}
//}
dp[1]=1;
dp[2]=1;
dp[3]=1;
dp[4]=2;
dp[5]=dp[4]*2+dp[3]*2;
dp[6]=dp[5]*2+dp[4]*2+dp[3]*dp[3];
for(int i=6;i<=len;i++){
	for(int j=1;j<len;j++){
		dp[i]+=dp[i-j]*dp[j];
	}
}
cout<<dp[len];}
	return 0;
}

