#include<bits/stdc++.h>
using namespace std;
const int N=1<<15+10;
int t;
string s;
int f[N],a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=3;i<=N;i++){
		f[i]=i-2;
		if((i-1)%2==0) f[i]+=f[(i+1)/2];
		a[i]=f[i]+a[i-1];
		if(i<=20) printf("%d %d\n",a[i],f[i]);
	}
	while(t--){
		cin>>s;
		printf("%d\n",a[s.size()]);
	}
	return 0;
}
