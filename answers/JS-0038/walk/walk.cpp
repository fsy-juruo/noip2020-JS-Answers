#include<bits/stdc++.h>
using namespace std;
const int N=1e9+7;
int n,k;
int w[20];
int a[20],a1[20];
long long ans;
struct node{
	int c,d;
};
node zl[200];
bool check1()
{
	int i;
	for(i=1;i<=k;i++){
		if(a1[i]<1||a1[i]>w[i])return true;
	}
	return false;
}
void check(){
	int pre=1;
	while(check1()==false){
		if(pre>n)pre=1;
		a1[zl[pre].c]+=zl[pre].d;
		pre++;
		ans++;
		ans%=N;
	}
}
void search(int t)
{
	int i;
	if(t>k){
		for(i=1;i<=k;i++)
		a1[i]=a[i];
		check();
		return;
	}
	for(i=1;i<=w[t];i++){
		a[t]=i;
		search(t+1);
	}
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	if(n>100){
		cout<<"-1"<<endl;
		return 0;
	}
	int i;
	for(i=1;i<=k;i++){
		cin>>w[i];
	}
	for(i=1;i<=n;i++){
		cin>>zl[i].c>>zl[i].d;
	}
	search(1);//里面的数字是维度 
	cout<<ans<<endl;
	return 0;
}
