#include <bits/stdc++.h>
using namespace std;
long long n,m;
int f[100005];
int cnt=0;
int b[100005];
long long d[100005];
vector<long long> e[100005];
long long ans[100005][2];
long long read(){
	long long f=1,x=0;
	char ss=getchar();
	while(ss<'0'){
		if(ss='-') f=-1;
		ss=getchar();
	}
	while(ss>='0'){
		x=x*10+ss-'0';
		ss=getchar();
	}
	return f*x;
}
void bfs(int x){
	queue<int> q;
	ans[x][0]=0; ans[x][1]=0;
	for(int i=0;i<e[x].size();++i){
		ans[e[x][i]][0]=1;
		ans[e[x][i]][1]=e[x].size();
		//cout<<ans[e[x][i]][0]<<" "<<ans[e[x][i]][1]<<endl;
		q.push(e[x][i]);	
	}
	while(!q.empty()){
		int t=q.front();
		if(d[t]==0) break;
		//cout<<t<<endl;
		q.pop();
		if(ans[t][0]==0) break;
		for(int i=0;i<e[t].size();++i){
			if(ans[e[t][i]][0]==0&&ans[e[t][i]][1]==0&&ans[t][0]==1){
				//cout<<" "<<1<<endl;
				ans[e[t][i]][0]=1;
				ans[e[t][i]][1]=ans[t][1]*(e[t].size());
				//cout<<ans[e[t][i]][0]<<" "<<ans[e[t][i]][1]<<endl;
				q.push(e[t][i]);
				continue;
			}
			else if(ans[e[t][i]][0]==0&&ans[e[t][i]][1]==0&&ans[t][0]>1){
				//cout<<" "<<2<<endl;
				int temp=ans[e[t][i]][1];
				ans[e[t][i]][0]=ans[t][0];
				ans[e[t][i]][1]=ans[t][1]*(e[t].size());
				temp=ans[e[t][i]][0];
				for(int j=temp;j>=2;--j){
					if(ans[t][0]%j==0&&ans[e[t][i]][1]%j==0){
						ans[e[t][i]][0]/=j;
						ans[e[t][i]][1]/=j;
					}
				}
				//cout<<ans[e[t][i]][0]<<" "<<ans[e[t][i]][1]<<endl;
				q.push(e[t][i]);
			}
			else{
				//cout<<ans[e[t][i]][0]<<" "<<ans[e[t][i]][1]<<endl;
				int temp=ans[e[t][i]][1];
				ans[e[t][i]][1]=ans[e[t][i]][1]*ans[t][1]*(e[t].size());
				ans[e[t][i]][0]=ans[e[t][i]][0]*(ans[t][1]*(e[t].size()))+ans[t][0]*temp;
				temp=ans[e[t][i]][0];
				//cout<<" "<<ans[e[t][i]][0]<<" "<<ans[e[t][i]][1]<<endl;
				for(int j=temp;j>=2;--j){
					if(ans[e[t][i]][0]%j==0&&ans[e[t][i]][1]%j==0){
						//cout<<"fasf"<<j<<endl;
						ans[e[t][i]][0]=ans[e[t][i]][0]/j;
						ans[e[t][i]][1]/=j;
					}
				}
				
				q.push(e[t][i]);
			}
		}
		ans[t][0]=0; ans[t][1]=0;
	}
	
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read(); m=read();
//	cout<<m<<endl;
	if(m==1){
		//cout<<1<<endl;
		for(int i=1;i<=n;++i){
			d[i]=read();
			if(d[i]!=0)
			for(int j=1;j<=d[i];++j){
				long long x=read();
				e[i].push_back(x);
				f[x]=1;
			}
			if(d[i]==0){
				cnt++;
				b[cnt]=i;
				f[i]==2;
			}
		}
		if(cnt==1){
			cout<<1<<" "<<1<<endl;
			return 0;
		}
		for(int i=1;i<=n;++i){
			if(f[i]==0){
//				cout<<i<<endl;
				ans[i][0]=1;
				ans[i][1]=1;
				bfs(i);
				break;
			}
		}
		for(int i=1;i<=cnt;++i){
			printf("%lld %lld\n",ans[b[i]][0],ans[b[i]][1]);
		}
	}

	return 0;
}
