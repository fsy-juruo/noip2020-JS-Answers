#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[60][500],hd[60],q[8200][10][86],cnt;

bool check(){
	for(int i=1;i<=n;i++)if(hd[i]!=m)return 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]!=mp[i][1])return 0;
		}
	}
	return 1;
}
bool chong(){
	for(int o=0;o<=cnt;o++){
		int flg=1;
		for(int j=1;j<=n+1;j++){
		if(hd[j]!=q[o][j][0]){
			flg=0;
			break;
			}
		}
		if(flg==0)continue;
		for(int i=1;i<=n+1;i++){
			for(int j=1;j<=hd[i];j++){
				if(mp[i][j]!=q[o][i][j]){
					flg=0;break;
				}
			}
			if(flg==0)break;
		}
		if(flg==0)continue;
		else return 1;
	}
	return 0;
}
int ans;
void dfs(int stp){
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=hd[i];j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	if(check()){
		ans=min(ans,stp);
		return;
	}
	if(stp>ans)return ;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			if(hd[i]<1||hd[j]>=m)continue;
			mp[j][++hd[j]]=mp[i][hd[i]--];
			mp[i][hd[i]+1]=0;
			if(!chong())
			dfs(stp+1);
			cnt++;
			for(int k=1;k<=n+1;++k){
				q[cnt][k][0]=hd[k];
				for(int l=1;l<=hd[k];l++){
					q[cnt][k][l]=mp[k][l];
				}
			}
			mp[i][++hd[i]]=mp[j][hd[j]--];
			mp[j][hd[j]+1]=0;
		}
	}
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][++hd[i]];
			q[0][i][j]=mp[i][j];
		}
	}
	if(check()){
		cout<<0<<endl;
		return 0;
	}
	ans=820000;
//	dfs(1);
cout<<ans<<endl;
	return 0;
}
