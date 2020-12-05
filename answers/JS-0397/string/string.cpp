#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#define N 1048580
using namespace std;
int T,x,sz,ans;
string s;
int a[N],b[N],c[N],vi[30],now[30];
int p(int i,int j){
	if(i>=j) return j-1;
	if(j%i==0) return i-1;
	else return j%i-1;
}
void init(){
	ans=x=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(vi,0,sizeof(vi));
	memset(now,0,sizeof(now));
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		cin>>s;
		sz=s.size();
		for(int i=0;i<sz;i++) if(!vi[s[i]-96]){vi[s[i]-96]=1;x++;}
		for(int i=0;i<sz;i++){
			a[i+1]=a[i];
			if(now[s[i]-96]) a[i+1]--;  else a[i+1]++;
			now[s[i]-96]^=1;
		}
		memset(now,0,sizeof(now));
		for(int i=sz-1;i>=0;i--){
			b[i+1]=b[i+2];
			if(now[s[i]-96]) b[i+1]--;  else b[i+1]++;
			now[s[i]-96]^=1;
		}
		if(x==1){
			for(int i=0;i<sz;i++) c[i]=sz/(i+1);
			for(int i=0;i<sz-1;i++)
		  	  for(int j=0;j<i;j++)
		        for(int k=1;k<=c[i];k++){
		    	if(a[j+1]<=b[(i+1)*k+1]) ans++;
			  }
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<sz;i++)
		  for(int j=0;j<sz;j++){
		    if(s[j]!=s[p(i+1,j+1)]) {c[i]=j/(i+1);break;}
			if(j==sz-1) c[i]=j/i;
		  }
		for(int i=0;i<sz-1;i++)
		  for(int j=0;j<i;j++)
		    for(int k=1;k<=c[i];k++){
		    	if(a[j+1]<=b[(i+1)*k+1]) ans++;
			}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

*/
