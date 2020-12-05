#include<bits/stdc++.h>
using namespace std;
int n,k,w[15],c[500100],d[500100],cur[15],tmp[15],cnt;
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>w[i];
    for(int i=1;i<=k;i++) cur[i]=1;
    for(int i=1;i<=n;i++) cin>>c[i]>>d[i];
    while(1){
    	int o=0;
    	for(int i=k;i>=1;i--){
    		if(cur[i]==w[i]){
    			cur[i]=0;
    			continue;
			}
			else{
				cur[i]++;
				o=1;
				break;
			}
		}
		if(!o) break;
		for(int i=1;i<=k;i++) tmp[i]=cur[i];
		int cs=1;
		while(1){
			cnt++;
			tmp[c[cs]]+=d[cs];
			if(tmp[c[cs]]>w[c[cs]]) break;
			cs++;
			if(cs==n+1) cs=1;
		}
	}
	cout<<cnt<<endl;
    return 0;
}
/*
  REMEMBER to init vals
  REMEMBER to check IO
  REMEMBER to compile before submitting
*/
