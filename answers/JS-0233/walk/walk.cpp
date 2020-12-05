#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<fstream>
#define N 500100
#define K 10
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
vector<int> w;
int n,k,ans;
int c[N],d[N];
map<pair<vector<int>,int>,bool>vis;
bool legal(vector<int>& q){
	for(int i=0;i<q.size();i++)
		if(q[i]>w[i]||q[i]<=0)return false;
	return true;
}
int count(vector<int> q,int p){
	q[c[p]-1]+=d[p];
	if(vis[make_pair(q,p)])return -1;
	vis[make_pair(q,p)]=true;
	if(legal(q)){
		int ret=count(q,(p+1)%n);
		if(ret==-1)return -1;
		else return ret+1;
	}
	else return 1;
}
void cal(int d,vector<int> q){
	if(d==k){
		vis.clear();
		int ret=count(q,0);
		if(ans==-1||ret==-1)ans=-1;
		else ans+=ret;
		return;
	}
	for(int i=1;i<=w[d];i++){
		q.push_back(i);
		cal(d+1,q);
		q.pop_back();
	}
} 
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++)w.push_back(read());
	for(int i=0;i<n;i++)c[i]=read(),d[i]=read();
	ans=0;
	vector<int> q;
	cal(0,q);
	cout<<ans;
	return 0;
}
