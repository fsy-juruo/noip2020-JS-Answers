#include<bits/stdc++.h>
using namespace std;
int MOD=1000000007;
int w[11],c[500010],d[500010],t[11],g[11],tg[11],ttg[11],flag=1,flag2;
int n,k;
long long ans;
bool check(){
	for(int i=1;i<=k;i++){
		if(g[i]!=tg[i]) return false;
	}
	return true;
}
void walk_(){
	while(1){
		for(int i=1;i<=k;i++){
			tg[i]+=t[i];
			//cout<<tg[i]<<" ";
			if(tg[i]<=0||tg[i]>w[i]){
				//cout<<endl;
				for(int j=1;j<=k;j++){
					tg[j]=g[j];
				}
				//cout<<g[1]<<" "<<g[2]<<endl;
				for(int j=1;j<=n;j++){
					//if(flag2==1)cout<<g[c[j]]<<" "<<d[j]<<" ";
					tg[c[j]]=g[c[j]]+d[j];
					//if(flag2==1)cout<<tg[c[j]]<<endl;
					if(tg[c[j]]<=0||tg[c[j]]>w[c[j]]){
						//cout<<endl;
						ans=ans+j;
						//cout<<j<<endl;
						return ;
					}
					else g[c[j]]=tg[c[j]];
				}
			}
		}
		//cout<<endl;
		if(check()==true){
			cout<<-1;
			flag=0;
			return ;
		}
		else{
			for(int i=1;i<=k;i++){
				g[i]=tg[i];
			}
		}
		ans=(ans%MOD+n%MOD)%MOD;
	}
}
void work(int dep){
	//cout<<d[1]<<" ";
	if(dep>k){
		flag=0;
		flag2=0;
		for(int i=1;i<=k;i++){
			tg[i]=g[i];
		}
		if(g[1]==152&&g[2]==167) flag2=1;
		walk_();
		for(int i=1;i<=k;i++){
			g[i]=ttg[i];
		}
		//cout<<ans<<endl;
		//cout<<flag<<endl;
		if(flag==1) exit(0);
		return ;
	}
	for(int i=1;i<=w[dep];i++){
		g[dep]=i;
		ttg[dep]=i;
		work(dep+1);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i]>>d[i];
		t[c[i]]+=d[i];
	}
	//cout<<t[1]<<" "<<t[2]<<" "<<t[3]<<endl<<endl;
	work(1);
	cout<<ans<<endl;
	return 0;
}

