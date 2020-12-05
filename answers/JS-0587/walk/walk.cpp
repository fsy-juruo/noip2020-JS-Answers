#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
struct step{
	int c,d;
}s[1001];
int n,k,w[6],ans,loc[11]={0,1,1,1,1,1,1,1};
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	  scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	  scanf("%d%d",&s[i].c,&s[i].d);
	while(1){
		int now[11],temp[11];
		for(int i=1;i<=k;i++) now[i]=loc[i];
		for(int i=1;i<=k;i++) temp[i]=now[i];
		bool flag=1;
		for(int i=1;i<=n;i++){
			temp[s[i].c]+=s[i].d;
			if(temp[s[i].c]>w[s[i].c]||temp[s[i].c]<1){
				flag=1;
				break;
			}
	    }
		for(int i=1;i<=k;i++) 
		  if(temp[i]!=now[i]) flag=0;
		if(flag==1){
			printf("-1\n");
			return 0;
		}
		while(1){
			int temp[11];
			bool flag=0;
			for(int i=1;i<=n;i++){
			  now[s[i].c]+=s[i].d;
			  ans+=abs(s[i].d);
			  ans%=mod;
			  if(now[s[i].c]>w[s[i].c]||now[s[i].c]<1){
			  	flag=1;
			  	break;
			  }
		    }
		    if(flag) break;
		}
		loc[k]++;
		for(int i=k;i>=1;i--)
		  if(loc[i]>w[i]){
		  	loc[i]%=w[i];
		  	loc[i-1]++;
		  }
		if(loc[0]) break;
	}
	printf("%d",ans%mod);
}
