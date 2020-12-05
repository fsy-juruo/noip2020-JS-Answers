#include<bits/stdc++.h>
using namespace std;
int n,m,len[55],stt[55][410],sta[55][410],nex[55],sum1=0;

int main(){
	
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		nex[i]=i+1;
		for(int j=1;j<=m;j++) cin>>sta[i][j],stt[i][j]=sta[i][j];
		
		len[i]=m;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	len[n+1]=0;
	nex[n]=1;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			cnt++;
			int ne=0,bot=0;
			for(int k=1;k<=m;k++){
				if(sta[j][k]==i){
					ne++;
				}
			}
			for(int k=1;k<=ne;k++){
				//cout<<nex[j]<<' '<<n+1;
				len[n+1]++;
				sta[n+1][len[n+1]]=sta[nex[j]][len[nex[j]]];
				len[nex[j]]--;
				sum1++;
			}
			for(int k=m;k>=1;k--){
				if(sta[j][k]==i) sta[nex[j]][++len[nex[j]]]=sta[j][len[i]--];
				else sta[n+1][++len[n+1]]=sta[j][len[i]--];
			}
			len[j]=0;sum1+=m;
			if(i!=j) for(int k=m;sta[i][k]!=i;k--){
				sta[j][++len[j]]=sta[i][len[i]--];
				sum1++;
			}
			if(i!=1||j!=n) for(int k=m;k>m-ne;k--){
				sta[i][len[i]++]=sta[nex[j]][len[nex[j]]--];
				sum1++;
			}
			for(int k=m;k>0;k--){
				if(k>ne){
					if(len[i]<m) sta[i][++len[i]]=sta[n+1][k];
					else sta[j][++len[j]]=sta[n+1][k];
				}
				else sta[nex[j]][++len[nex[j]]]=sta[n+1][k];
			}
			sum1+=m;
			len[n+1]=0;
		}
	}
	cout<<sum1<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) sta[i][j]=stt[i][j];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			cnt++;
			int ne=0,bot=0;
			for(int k=1;k<=m;k++){
				if(sta[j][k]==i){
					ne++;
				}
			}
			for(int k=1;k<=ne;k++){
				cout<<nex[j]<<' '<<n+1<<endl;
				len[n+1]++;
				sta[n+1][len[n+1]]=sta[nex[j]][len[nex[j]]];
				len[nex[j]]--;
				sum1++;
			}
			for(int k=m;k>=1;k--){
				if(sta[j][k]==i) sta[nex[j]][++len[nex[j]]]=sta[j][len[i]--],cout<<j<<' '<<nex[j]<<endl;
				else sta[n+1][++len[n+1]]=sta[j][len[i]--],cout<<j<<' '<<n+1<<endl;
			}
			len[j]=0;sum1+=m;
			if(i!=j) for(int k=m;sta[i][k]!=i;k--){
				sta[j][++len[j]]=sta[i][len[i]--],cout<<i<<' '<<j<<endl;
				sum1++;
			}
			if(i!=1||j!=n) for(int k=m;k>m-ne;k--){
				sta[i][len[i]++]=sta[nex[j]][len[nex[j]]--];
				cout<<nex[j]<<' '<<i<<endl;
				sum1++;
			}
			for(int k=m;k>0;k--){
				if(k>ne){
					if(len[i]<m) sta[i][++len[i]]=sta[n+1][k],cout<<n+1<<' '<<i<<endl;
					else sta[j][++len[j]]=sta[n+1][k],cout<<n+1<<' '<<j<<endl;
				}
				else sta[nex[j]][++len[nex[j]]]=sta[n+1][k],cout<<n+1<<' '<<nex[j]<<endl;
			}
			sum1+=m;
			len[n+1]=0;
		}
	}
	return 0;
}
