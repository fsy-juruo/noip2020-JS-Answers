#include<bits/stdc++.h>
using namespace std;
int n,k,w[11],c[500001],d[500001],x[11],t;
unsigned long long ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	    scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	    scanf("%d%d",&c[i],&d[i]);
	if(k==1)
	    for(int i=1;i<=w[1];i++){
	    	x[1]=i;
	    	while(!t)
	    		for(int j=1;j<=n;j++){
	    			x[1]+=d[j];
	    			ans++;
	    			if(x[1]<1||x[1]>w[1]){
	    				t=1;
	    		    	break;
					}
				}
	    	t=0;
		}
	if(k==2)
	    for(int i=1;i<=w[1];i++){
	    	x[1]=i;
	    	for(int j=1;j<=w[2];j++){
	    		x[2]=j;
	    		while(!t)
	    			for(int a=1;a<=n;a++){
	    				x[c[a]]+=d[a];
	    				ans++;
	    				if(x[c[a]]<1||x[c[a]]>w[c[a]]){
	    					t=1;
	    			    	break;
						}
					}
				t=0;
				x[1]=i;
			}
		}
	if(k==3)
	    for(int i=1;i<=w[1];i++){
	    	x[1]=i;
	    	for(int j=1;j<=w[2];j++){
	    		x[2]=j;
	    		for(int b=1;b<=w[3];b++){
	    			x[3]=b;
	    			while(!t)
	    				for(int a=1;a<=n;a++){
	    					x[c[a]]+=d[a];
	    					ans++;
	    					if(x[c[a]]<1||x[c[a]]>w[c[a]]){
	    						t=1;
	    			    		break;
							}
						}
					t=0;
					x[1]=i;
					x[2]=j;
				}
			}
		}
	if(k==4)
	    for(int i=1;i<=w[1];i++){
	    	x[1]=i;
	    	for(int j=1;j<=w[2];j++){
	    		x[2]=j;
	    		for(int b=1;b<=w[3];b++){
	    			x[3]=b;
	    			for(int e=1;e<=w[4];e++){
	    				x[4]=e;
	    				while(!t)
	    					for(int a=1;a<=n;a++){
	    						x[c[a]]+=d[a];
	    						ans++;
	    						if(x[c[a]]<1||x[c[a]]>w[c[a]]){
	    							t=1;
	    			    			break;
								}
							}
					    t=0;
						x[1]=i;
						x[2]=j;
						x[3]=b;
					}
				}
			}
		}
	if(k==5)
	    for(int i=1;i<=w[1];i++){
	    	x[1]=i;
	    	for(int j=1;j<=w[2];j++){
	    		x[2]=j;
	    		for(int b=1;b<=w[3];b++){
	    			x[3]=b;
	    			for(int e=1;e<=w[4];e++){
	    				x[4]=e;
	    				for(int f=1;f<=w[5];f++){
	    					x[5]=f;
	    					while(!t)
	    						for(int a=1;a<=n;a++){
	    							x[c[a]]+=d[a];
	    							ans++;
	    							if(x[c[a]]<1||x[c[a]]>w[c[a]]){
	    			    				t=1;
										break;
									}
								}
							t=0;
							x[1]=i;
							x[2]=j;
							x[3]=b;
							x[4]=e;
						}
					}
				}
			}
		}
	if(k>5)
	    ans=-1;
	if(ans<1000000007)
	    printf("%d\n",ans);
	else
	    printf("%d\n",ans%1000000007);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
