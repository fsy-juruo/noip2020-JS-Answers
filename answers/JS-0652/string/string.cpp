#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000000;
int n;
char a[N+5];
int z[N+1];
void z_init(){
	z[1]=n;
	int zl=0,zr=0;
	for(int i=2;i<=n;i++)
		if(zr<i){
			z[i]=0;
			while(i+z[i]<=n&&a[i+z[i]]==a[1+z[i]])z[i]++;
			if(z[i])zl=i,zr=i+z[i]-1;
		}
		else if(i+z[i-zl+1]<=zr)z[i]=z[i-zl+1];
		else{
			z[i]=zr-i+1;
			while(i+z[i]<=n&&a[i+z[i]]==a[1+z[i]])z[i]++;
			zl=i,zr=i+z[i]-1;
		}
//	cout<<"z=";for(int i=1;i<=n;i++)cout<<z[i]<<" ";puts("");
}
int cnt[26];
int Ff[N+1],fF[N+1];
void mian(){//remember to make it first!!!!!!!!!!!!!!!!!
	//memset everything!!!!!!!!!!!!!!
	memset(Ff,0,sizeof(Ff)),memset(fF,0,sizeof(fF));
	scanf("%s",a+1);
	n=strlen(a+1);
	z_init();
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		cnt[a[i]-'a']++;
		if(cnt[a[i]-'a']&1)Ff[i]=Ff[i-1]+1;
		else Ff[i]=Ff[i-1]-1;
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=n;i;i--){
		cnt[a[i]-'a']++;
		if(cnt[a[i]-'a']&1)fF[i]=fF[i+1]+1;
		else fF[i]=fF[i+1]-1;
	}
	int Now[27]={};
	ll ans=0;
	for(int i=2;i<n;i++){
		for(register int j=Ff[i-1];j<=26;j++)Now[j]++;
		for(register int j=i;j<n&&j<=i+z[i+1];j+=i)ans+=Now[fF[j+1]];
//		cout<<ans<<"!\n";
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
