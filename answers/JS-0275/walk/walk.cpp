#include<bits/stdc++.h>
using namespace std;
int w[100],step[10000][2],m[100],s=0,mm[100],mw=-1;
int n,k;
void walk(){
//	for(int j=1;j<=k;j++){
//		cout<<m[j]<<' ';
//	}cout<<endl;
//	cout<<m[1]<<' '<<m[2]<<endl;
	for(int i=1;i<=k;i++){
		mm[i]=m[i];
	}
	int tt=0;
	while(1){
		if(tt>=mw){
			cout<<-1<<endl;
			exit(0);
		}
		tt++;
		for(int i=1;i<=n;i++){
			mm[step[i][0]]+=step[i][1];
			s++;
			if(mm[step[i][0]]<1||mm[step[i][0]]>w[step[i][0]]){
			//	cout<<s<<endl;
				return;
			}
			
		}
	}
	
}
void dfs(int dep){
	if(dep>k){
//			for(int j=1;j<=k;j++){
//		cout<<m[j]<<' ';
//	}cout<<endl;
		walk();
		return;
	}
	for(int i=1;i<=w[dep];i++){
		
		m[dep]=i;
		//cout<<dep<<' '<<m[dep]<<' '<<i<<' '<<m[1]<<endl;
		dfs(dep+1);
	}
	return;
}
int main(){
freopen("walk.in","r",stdin);
freopen("walk.out","w",stdout);
	
	cin>>n>>k;
	if(n>=1e5){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>w[i];
		mw=max(mw,w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>step[i][0]>>step[i][1];
	}
	dfs(1);
	cout<<s<<endl;
return 0;
}

