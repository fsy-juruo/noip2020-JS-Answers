#include<bits/stdc++.h>
#define int long long
using namespace std;
int c[1100007];
int m1[29],m2[29],ji1[1100007],ji2[1100007],l,T,ans;
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return;
}
inline void clear(){
	memset(m1,0,sizeof(m1));
	memset(m2,0,sizeof(m2));
	ans=0;l=0;
	return;
}
inline void init(){
	int cnt=0;char s;
	while(1){
		s=getchar();
		if(s=='\n')break;
		l++;
		c[l]=s-'a';
	}
	for(int i=1;i<=l;i++){
		m1[c[i]]++;
		if(m1[c[i]]&1)cnt++;
		else cnt--;
		ji1[i]=cnt;
	}
	cnt=0;
	for(int i=l;i>=1;i--){
		m2[c[i]]++;
		if(m2[c[i]]&1)cnt++;
		else cnt--;
		ji2[i]=cnt;
	}
	return;
}
inline void work(){
	int len,t,tmp;
	for(int i=2;i<l;i++)
	for(int j=1;j<=i/2;j++)
	if(i%j==0){
		len=i/j;t=0;
		for(int k=len+1;k<=i;k++){
			tmp=k%len;
			if(tmp==0)tmp=len;
			if(c[tmp]!=c[k]){
				t=1;break;
			}
		}
		if(t)continue;
		for(int k=1;k<len;k++)
		if(ji1[k]<=ji2[i+1])ans++;
	}
	return;
}
inline void put(){
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while(T--){
		clear();
		init();	
		work();
		put();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

