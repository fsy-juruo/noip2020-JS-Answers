#include<bits/stdc++.h>
using namespace std;

const int maxn=405;
int n,m;
int sti[maxn][maxn],top[maxn];
int res=0;
pair<int,int> opt[820005];

bool check(){
	for(int i=1;i<=n+1;i++)
		if(top[i]==0)  continue;
		else if(top[i]!=m)  return 0;
		else{
			for(int j=2;j<=m;j++)
				if(sti[i][j]!=sti[i][j-1])  return 0;
		}
	return 1;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)  cin>>sti[i][j];
		top[i]=m;
	}
	top[n+1]=0;
	
	if(n==2){
		int cnt1=1,cnt2=1;
		for(int i=top[1]-1;i>=1;i--)
			if(sti[1][i]==sti[1][i+1])  cnt1++;
			else break;
		for(int i=top[2]-1;i>=1;i--)
			if(sti[2][i]==sti[2][i+1])  cnt2++;
			else break;
		
		int froms,tos,nots;
		if(cnt1>=cnt2)  froms=1,tos=3,nots=2;
		else  froms=2,tos=3,nots=1;
		while(!check() && res<=820000){
			//cout<<froms<<' '<<tos<<' '<<endl;
			bool ff=0;
			if(top[froms]>0)  ff=1;
			if(ff){
				while((sti[froms][top[froms]]==sti[froms][top[froms]-1]) && top[tos]<m && top[froms]>0 && res<=820000){
					sti[tos][++top[tos]]=sti[froms][top[froms]--];
					opt[++res]=make_pair(froms,tos);
				}  
				if(top[tos]<m && top[froms]>0 && res<=820000){
					sti[tos][++top[tos]]=sti[froms][top[froms]--];
					opt[++res]=make_pair(froms,tos);
				}
			}
			//cout<<3<<endl;
			if(sti[nots][top[nots]]==sti[froms][top[froms]]){
				int tf=nots,tt=froms,tn=tos;
				froms=tf,tos=tt,nots=tn;
			}
			else{
				int tf,tt,tn=froms;
				if(top[nots]>=top[tos])  tf=nots,tt=tos;
				else tf=tos,tt=nots;
				froms=tf,tos=tt,nots=tn;
			}
			//cout<<res<<endl;
		}
		
		cout<<res<<endl;
		for(int i=1;i<=res;i++)  cout<<opt[i].first<<' '<<opt[i].second<<endl;
	}
	
	return 0;
}
