//gzz
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,j,k) for (register int i=j;i<=k;++i)
#define dep(i,j,k) for (register int i=j;i>=k;--i)
#define M(a,b) memset(a,b,sizeof(a))
#define FILE "string"
using namespace std;
int T,h,len,ans,y,z;
char a[1005];
bool check(int aa,int bb,int pow){
	if ((len-bb*pow)<=0) return false;
	for (int i=bb+1;i<=bb*pow;i+=bb) 
		rep(j,0,bb-1) 
			if (a[i+j]!=a[j+1]) return false;
	int c1[1005],c2[1005],num1=0,num2=0;M(c1,0);M(c2,0);
	rep(i,1,aa) c1[int(a[i]-'a')]++;rep(i,bb*pow+1,len) c2[int(a[i]-'a')]++;
	rep(i,0,25) num1+=c1[i]%2,num2+=c2[i]%2;
	return num1<=num2;
}
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	cin>>T;
	char ch=getchar();
	while (T--){
		ch=getchar();M(a,0);len=0;ans=0;
		while(ch!=10){
			a[++len]=ch;
			ch=getchar();
		}
		rep(i,1,len)
			rep(j,i+1,len)
				for (int k=1;k<=len && (len-j*k)>0;k++) ans+=check(i,j,k);
		printf("%d\n",ans);
	}
	return 0;
}
