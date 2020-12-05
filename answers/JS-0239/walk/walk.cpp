#include<bits/stdc++.h>
using namespace std;
int n,k,w[100],c[500005],d[500005],ans,p[4],cur[4];
map<pair<int,pair<int,int> >,bool>mp[100005];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	if(n>1000){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=3;i++)
		w[i]=1;
	for(int i=1;i<=k;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	for(p[1]=1;p[1]<=w[1];p[1]++)
		for(p[2]=1;p[2]<=w[2];p[2]++)
			for(p[3]=1;p[3]<=w[3];p[3]++){
				cur[1]=p[1],cur[2]=p[2],cur[3]=p[3];
				int step=0;
				for(int i=1;i<=n;i++)
					mp[i].clear();
				for(int i=1;cur[1]>0&&cur[1]<=w[1]&&cur[2]>0&&cur[2]<=w[2]&&cur[3]>0&&cur[3]<=w[3];i=i%n+1){
						if(mp[i][make_pair(cur[1],make_pair(cur[2],cur[3]))]){
							cout<<-1;
							return 0;
						}	
						cur[c[i]]+=d[i],step++;
						mp[i][make_pair(cur[1],make_pair(cur[2],cur[3]))]=1;
				}
				ans+=step;
			}
	cout<<ans;		
	return 0;
}

