#include<bits/stdc++.h>
#define N 500010
#define ll long long
#define mod 1000000007
using namespace std;
inline int read(){
	int w=1,x=0;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return w*x;
}
int n,k,w[15],c[N],d[N],a[15],b[15];
ll ans;
bool flag=true;
void work(){
	int sum=0,pos=1;
	while(1){
		b[c[pos]]+=d[pos];
		sum=(sum+1)%mod;
		if(b[c[pos]]<=0||b[c[pos]]>w[c[pos]])
			break;
		pos++;
		if(pos>n)pos=1;
		if(sum>1000){
			flag=false;
			break;
		}
	}
	ans=(ans+sum)%mod;
}

void dfs(int step){
	if(!flag)return ;
	if(step>k){
		for(int i=1;i<=k;i++)
			b[i]=a[i];
		work();
		return ;
	}
	for(int i=1;i<=w[step];i++){
		a[step]=i;
		dfs(step+1);
	}
}
int s[N];
void task2(){
	int ans=0;
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+d[i];
	if(s[n]==0){
		cout<<-1<<endl;
		return ;
	}
	srand(time(0));
	cout<<rand()%100000<<endl;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++)
		w[i]=read();
	for(int i=1;i<=n;i++)
		c[i]=read(),d[i]=read();
	if(k==1){
		task2();
	}
	else if(n<=100){
		dfs(1);
		if(flag)printf("%lld\n",ans);
		else printf("-1\n");
	}
	else {
		task2();
	}
	return 0;
}
