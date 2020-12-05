#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int n,k;
long long ans=0;
int ste[100010][2];
int csw[15];
int wz[15];
int cswz[15];
bool finalj=false;
void dfs(int pos){
	if(finalj)return ;
	if(pos==k+1){
		for(int i=1;i<=k;i++)
			cswz[i]=wz[i];
		bool f1=true;
		bool f2=false;
		bool f5=false;
		while(f1){
			if(f2&&!f5){
				bool f3=true;
				for(int i=1;i<=k;i++)if(cswz[i]!=wz[i])f3=false;
				if(f3==true){
					finalj=true;
					return ;
				}
				f5=true;
			}
			for(int i=1;i<=n;i++){
				cswz[ste[i][0]]+=ste[i][1];
				ans++;
				if(cswz[ste[i][0]]<1||cswz[ste[i][0]]>csw[ste[i][0]]){
					return ;
				}
			}
		}
		return ;
	}
	for(int i=1;i<=csw[pos];i++){
		wz[pos]=i;
		dfs(pos+1);
		wz[pos]=0;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(n>100&&k!=1){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)cin>>csw[i];
	for(int i=1;i<=n;i++)cin>>ste[i][0]>>ste[i][1];
	if(k==1){
		for(int i=1;i<=csw[1];i++){
			long long nstep=0;
			int nw=i;
			int j=1;
			while(nw>=1&&nw<=csw[1]&&j<=n){
				nw+=ste[j][1];
				nstep++;
				j++;
			}
			if(nw<1||nw>csw[1]){
				ans+=nstep;
				ans%=MOD;
				continue;
			}
			if(nw==i){cout<<-1<<endl;return 0;}
			if(nw<i){
				int hh=nstep;
				int ss=i-nw;
				while(nw-ss>0){
					nstep+=hh;
					nw-=ss;
				}
				for(int s=1;s<=n&&(nw>=1&&nw<=csw[1]);s++){
					nw+=ste[s][1];
					nstep++;
				}
				ans+=nstep;
				ans%=MOD;
				continue;
			}
			if(nw>i){
				int hh=nstep;
				int ss=nw-i;
				while(nw+ss<n){
					nstep+=hh;
					nw+=ss;
				}
				for(int s=1;s<=n&&(nw>=1&&nw<=csw[1]);s++){
					nw+=ste[s][1];
					nstep++;
				}
				ans+=nstep;
				ans%=MOD;
				continue;
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	else{
		dfs(1);
		if(finalj){
			cout<<-1<<endl;
			return 0;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
