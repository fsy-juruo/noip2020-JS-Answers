#include<bits/stdc++.h>
using namespace std;
long long m,n;
int w[100000][1000];
struct xsd{
	long long p;
	long long q;
	long long d;
}b[100000];
void jf(int fz,int fm,int num);
void ss(int start,int end);
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i].d;
		b[i].p=0;
		b[i].q=1;
		for(long long l=1;l<=b[i].d;l++)
			cin>>w[i][l];
	}
	for(int i=1;i<=m;i++)
		b[i].p=1;
	for(int i=1;i<=m;i++)
		for(int l=1;l<=b[i].d;l++)
			ss(i,w[i][l]);
	for(int i=1;i<=n;i++)
		if(b[i].d==0) cout<<b[i].p<<" "<<b[i].q<<endl;
	return 0;
}
void jf(int fz,int fm,int num){
	int ans1=fz*b[num].q+b[num].p*fm,ans2=fm*b[num].q;
	int o=2;
	while(o<=ans1){
		if(ans1%o==0&&ans2%o==0){
			ans1/=o;
			ans2/=o;
			o--;
		}
		o++;
	}
	b[num].q=ans2;
	b[num].p=ans1;
}
void ss(int start,int end){
	if(b[start].d!=0){
		jf(b[start].p,b[start].q*b[start].d,end);
		for(int j=1;j<=b[end].d;j++)
			ss(end,w[end][j]);
	}
}
