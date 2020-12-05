#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+500;
int n,m,num[maxn];
int head[maxn],Next[maxn*2],ver[maxn*2],tot;
int f_zi[maxn],f_mu[maxn],deg[maxn];
vector<int> vec;
void add(int u,int v){
	tot++;
	ver[tot]=v;
	Next[tot]=head[u];
	head[u]=tot;
}
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
void yuefen(int &x,int &y){
	int now_gcd=gcd(x,y);
	x=x/now_gcd;
	y=y/now_gcd;
}
int read(){
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+ch-'0';
		ch=getchar();
	}
	return res*f;
}
void toposort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!deg[i]) q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
//		cout<<x<<endl;
		q.pop();
//		cout<<x<<" "<<num[x]<<endl;
		if(num[x]) f_mu[x]=f_mu[x]*num[x];
		for(int i=head[x];i;i=Next[i]){
			int y=ver[i];
			if(!f_zi[y]){
				f_zi[y]=f_zi[x];
				f_mu[y]=f_mu[x];
			}
			else{
//				f_mu[y]=f_mu[y]*f_mu[x];
				f_zi[y]=f_zi[x]*f_mu[y]+f_zi[y]*f_mu[x];
				f_mu[y]=f_mu[y]*f_mu[x];
			}
//			cout<<f_zi[x]<<" "<<f_mu[x]<<endl;
//			f[y]+=f[x]/num[x];
//			cout<<y<<" "<<f[y]<<endl;
			yuefen(f_zi[y],f_mu[y]);
			deg[y]--;
			if(!deg[y]) q.push(y);
		}
	}
}
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
//		f_mu[i]=1;
		cin>>num[i];
		if(num[i]==0) vec.push_back(i);
		for(int j=1;j<=num[i];j++){
			int a;
			cin>>a;
			add(i,a);
			deg[a]++;
		}
	}
	for(int i=1;i<=m;i++){
		f_zi[i]=1;
		f_mu[i]=1;
	}
	toposort();
	for(int i=0;i<vec.size();i++){
		int now=vec[i];
//		cout<<now<<endl;
		yuefen(f_zi[now],f_mu[now]);
		cout<<f_zi[now]<<" "<<f_mu[now]<<endl;
//		cout<<f[now]<<endl;	
	}
	return 0;
}
/*

5 1
3 2 3 5 
2 4 5
2 5 4
0
0


10 1
5 2 3 4 5 6
2 7 8
2 8 10
2 9 7
1 9
3 7 8 9
1 10
0
1 10
0


*/
