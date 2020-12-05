#include<cstdio>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
const int mod=1e9+7;
LL n,k,zb[1007],w[1007],c[1007],d[1007],s[1007],qzh[1007][1007];
LL ans;
bool check(){
	for (int i=1;i<=k;i++) if (s[i]+qzh[n][i]!=s[i]) return false;
	return true;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++) cin>>w[i],s[i]=1;
	for (int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
		for (int j=1;j<=n;j++) qzh[i][c[j]]=qzh[i-1][c[j]];
		qzh[i][c[i]]+=d[i];
	}
	while (true){
		int tot=1,temp=0;
		while (true){
			if (s[c[tot]]+qzh[tot][c[tot]]+temp*qzh[n][c[tot]]<1||s[c[tot]]+qzh[tot][c[tot]]+temp*qzh[n][c[tot]]>w[c[tot]]){
				ans=(ans+temp*n+tot)%mod;
				break;
			} 
			if (tot==n&&check()){
				cout<<-1<<endl;
				return 0;
			}
			if (tot==n) tot=0,temp++;
			tot++;
		}
		s[1]++;
		int tmp=1;
		bool tof=true;
		while (s[tmp]>w[tmp]){
			s[tmp]=1;
			tmp++;
			if (tmp>k){
				tof=false;
				break;
			}
			s[tmp]++;
		}
		if (!tof) break;
	}
	cout<<ans%mod<<endl;
	return 0;
}
/*
3 2
3 3
1 1
2 -1
1 1
*/
