#include <bits/stdc++.h>
using namespace std;

struct node{
	long long p,q;
}b[100010];
long long n,m,f[100010],ans[100010],cnt,x,d;
vector<int>a[100010];
queue<int>q;

long long gcd(long long num1,long long num2){
	if(num2==0)
		return num1;
	return gcd(num2,num1%num2);
}

node fenshujia(long long num1,long long num2,long long sum1,long long sum2){
	x=gcd(num2*sum2,num1*sum2+num2*sum1);
	node anss;
	anss.p=(num1*sum2+num2*sum1)/x;
	anss.q=(num2*sum2)/x;
	return anss;
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		b[i].p=1;
	for(int i=1;i<=n;++i){
		b[i].q=1;
		scanf("%d",&d);
		if(d==0){
			ans[++cnt]=i;
			continue;
		}
		for(int j=1;j<=d;++j){
			scanf("%d",&x);
			f[x]++;
			a[i].push_back(x);
		}
	}
	for(int i=1;i<=n;++i)
		if(f[i]==0)
			q.push(i);
	while(!q.empty()){
		int id=q.front();
		q.pop();
		for(int i=0;i<a[id].size();++i){
			b[a[id][i]]=fenshujia(b[a[id][i]].p,b[a[id][i]].q,b[id].p,b[id].q*a[id].size());
			if(--f[a[id][i]]==0)
				q.push(a[id][i]);
		}
	}
	for(int i=1;i<=cnt;++i){
		x=gcd(b[ans[i]].p,b[ans[i]].q);
		cout<<b[ans[i]].p/x<<' '<<b[ans[i]].q/x<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
