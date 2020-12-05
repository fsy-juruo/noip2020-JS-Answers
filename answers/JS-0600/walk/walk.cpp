#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
int f[20],ff[20],c[500005],d[500005],w[20];
bool sol(){
	for (int i=1;i<=n;i++){
		ff[c[i]]+=d[i];
		ans=(ans+1)%1000000007;
		if (ff[c[i]]<1||ff[c[i]]>w[c[i]]) return 1;
	}
	bool flag=1;
	for (int i=1;i<=k;i++){
		if (ff[i]!=f[i]){
	   	   flag=0;
		   break;
	    }
	} 
	if (flag){
		puts("-1");
		return 0;
	}
	else{
		while(1){
			for (int i=1;i<=n;i++){
		        ff[c[i]]+=d[i];
		        ans=(ans+1)%1000000007;
		        if (ff[c[i]]<1||ff[c[i]]>w[c[i]]) return 1;
	        }
		}
	}
}

int main(){
	freopen("r","walk.in",stdin);
	freopen("w","walk.out",stdout);
	
    scanf("%d%d",&n,&k);
    ans=0;
    if (n>100){
    	puts("-1");
    	return 0;
	}
    for (int i=1;i<=k;i++){
    	scanf("%d",&w[i]);
	}
	for (int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
	}
	for (int i=1;i<=k;i++)
	   f[i]=1;
	while (f[k+1]!=1){
		memcpy(ff,f,sizeof(f));
		bool q;
	    q=sol();
		if (q==0) return 0;
		f[1]++;
		for (int i=1;i<=k;i++){
			if (f[i]>w[i]) f[i]=1,f[i+1]++;
			else break;
		}
	}
	printf("%lld\n",ans);

	return 0;
}

