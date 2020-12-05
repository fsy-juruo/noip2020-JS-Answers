#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n,m;
int vis[100005],t[100005],d[100005];
long long ans[100005][2],u,v,ml;
vector <int > mp[100005];
queue<int > q;
long long gcd(long long x,long long y){
	if(x%y==0) return y;
	else return gcd(y,x%y);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++){
			scanf("%d",&x);
			mp[i].push_back(x);
			t[x]++;
		}
		if(d[i]==0) vis[i]=1;
	}
	for(int i=1;i<=n;i++)
	    if(t[i]==0){
	    	ans[i][0]=ans[i][1]=1;
	        q.push(i);
	    }
	while(!q.empty()){
		int num=q.front();
		q.pop();
		for(int i=0;i<mp[num].size();i++){
			int temp=mp[num][i];
			if(ans[temp][0]==0){
				ans[temp][0]=ans[num][0];
				ans[temp][1]=ans[num][1]*(long long)d[num];
				u=gcd(ans[temp][0],ans[temp][1]);
				ans[temp][0]/=u;
				ans[temp][1]/=u;
			}
			else{
				v=gcd(ans[temp][1],ans[num][1]*(long long)d[num]);
				ml=ans[temp][1]/v*ans[num][1]*(long long)d[num];
				ans[temp][0]=ans[num][0]*ml/(ans[num][1]*(long long)d[num])+ans[temp][0]*ml/(ans[temp][1]);
				ans[temp][1]=ml;
				u=gcd(ans[temp][0],ans[temp][1]);
				ans[temp][0]/=u;
				ans[temp][1]/=u;
/*				if(ans[temp][1]%(ans[num][1]*(long long)d[num])==0){
					ans[temp][0]=ans[temp][0]*(ans[temp][1]%(ans[num][1]*(long long)d[num]));
				}
				else{
					
				    ans[temp][1]=ans[temp][1]*ans[num][1]*(long long)d[num];
				    ans[temp][0]=ans[temp][0]*(long long)d[num];
				    u=gcd(ans[temp][0],ans[temp][1]);
				    ans[temp][1]/=u;
				    ans[temp][0]/=u;
			    }*/
			}
			t[temp]--;
			if(t[temp]==0) q.push(temp);
		}
	}
	for(int i=1;i<=n;i++)
		if(vis[i]==1){
		    cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
		}
	return 0;
}
/*
604661760000000000
9223372036854775807
5 1
3 2 3 5
2 4 5
2 5 4
0
0

*/
