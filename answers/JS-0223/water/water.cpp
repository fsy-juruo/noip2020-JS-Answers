// NOIP 2020
// lycLTb
// 每题保证 20min 的有效思考时间
// 题目难度和题目编号成正比,部分分难度和题目难度不成正比
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug puts("QwQ")
inline int read(){
	int f=1,x=0;
	char ch;
	while (ch<'0'||ch>'9') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

const int MAXN=100005;
int n,m;
vector<int> v[MAXN];
int siz[MAXN];

inline int gcd(int x,int y){
	if (x<y) swap(x,y);
	if (y==0) return x;
	return gcd(y,x%y);
}

struct frac{
	int a,b;
	
	void chk(){
		int tmp=gcd(a,b);
		a/=tmp;
		b/=tmp;
	}
	
	void div(int x){
		b*=x;
		chk();
	}
	
	void plus(frac x){
		if (a==0 && b==0){
			a=x.a;b=x.b;
			return;
		}
		a=a*x.b+x.a*b;
		b*=x.b;
		chk();
	}
	
	void print(){
		printf("%lld %lld\n",a,b);
	}
}val[MAXN];

signed main()

{
//	int a=read(),b=read(),c=read(),d=read();
//	frac x,y;
//	x.a=a;x.b=b;y.a=c;y.b=d;
//	x.div(3);
//	x.print();
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for (int i=1;i<=n;i++){
		int d=read();
		for (int j=1;j<=d;j++){
			int tmp=read();
			v[i].push_back(tmp);
			siz[tmp]++;
		}
	}
	
	queue<int> q;
	vector<int> ans;
	for (int i=1;i<=n;i++){
		if (siz[i]==0){
			q.push(i);
			val[i].a=val[i].b=1;
		}
	}
	
	while (!q.empty()){
		int now=q.front();
		q.pop();
		int s=v[now].size();
		if (s==0){
			ans.push_back(now);
			continue;
		}
		val[now].div(s);
		for (int i=0;i<s;i++){
			int u=v[now][i];
			val[u].plus(val[now]);
			siz[u]--;
			if (siz[u]==0) q.push(u);
		}
	}
	
	sort(ans.begin(),ans.end());
	for (int i=0;i<ans.size();i++){
		val[ans[i]].print();
	}
	return 0;
}

