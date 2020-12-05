#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char in[1100000];
int li,T;
ll ans;
int c[150],a[150],ac,cc;
//inline bool check(){
//	int t1=0,t2=0;
//	for(register int i='a';i<='z';++i){
//		if(a[i]&1){
//			++t1;
//		}
//		if(c[i]&1){
//			++t2;
//		}
//	}
//	return t1<=t2;
//}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%s",in+1);
		li=strlen(in+1);
		ans=ac=cc=0;
		for(register int i='a';i<='z';++i){
			a[i]=c[i]=0;
		}
		for(register int i=1;i<=li;++i){
			++c[in[i]];
			if(c[in[i]]&1){
				++cc;
			}
			else{
				--cc;
			}
		}
		for(register int i=1;i<li;++i){
			++a[in[i]];
			--c[in[i]];
			if(a[in[i]]&1){
				++ac;
			}
			else{
				--ac;
			}
			if(c[in[i]]&1){
				++cc;
			}
			else{
				--cc;
			}
			int tc[150],tcc=cc;
			for(register int k='a';k<='z';++k){
				tc[k]=c[k];
			}
			for(register int j=i+1;j<li;++j){
				--tc[in[j]];
				if(tc[in[j]]&1){
					++tcc;
				}
				else{
					--tcc;
				}
				if(ac>tcc)
				continue;
				++ans;
				if(j+j>=li)
				continue;
				int ttc[150],ttcc=tcc;
				for(register int k='a';k<='z';++k){
					ttc[k]=tc[k];
				}
				for(register int k=j+1;k<li;++k){
					if(in[k-j]!=in[k])
					break;
					--ttc[in[k]];
					if(ttc[in[k]]&1){
						++ttcc;
					}
					else{
						--ttcc;
					}
					if(k%j==0){
						if(ac<=ttcc){
							++ans;
						}
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
