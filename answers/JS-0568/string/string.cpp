#include<bits/stdc++.h>
using namespace std;
char c[(1<<20)+5];
int T,n,f[(1<<20)+5],g[(1<<20)+5],lt[30],cnt;
int len;
long long ans;
bool v[(1<<20)+5];
int Read(){
	int num=0;
	char cc=getchar();
	while(cc<'0'||cc>'9') cc=getchar();
	while(cc>='0'&&cc<='9'){
		num=(num<<1)+(num<<3);
		num+=cc-'0';
		cc=getchar();
	}
	return num;
}
int Check(int p){
	for(int i=1;(i<<1)<=p;i++){
		if(p%i) continue;
		if(v[i]) continue;
		for(int l=1;l<=i;l++){
			if(c[l]!=c[p-i+l]){
				v[i]=1;
				break;
			}
		}
		if(!v[i]) return i;
	}
	return p;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=Read();
	while(T--){
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		memset(lt,0,sizeof(lt));
		memset(v,0,sizeof(v));
		n=0;cnt=0;ans=0;
		scanf("%s",c+1);
		for(int i=1;;i++){
			if(c[i]<'a'||c[i]>'z') break;
			n++;
			lt[c[i]-'a']++;
			if(lt[c[i]-'a']&1) cnt++;
			else cnt--;
			f[i]=cnt; 
		}
		f[0]=n+1;
		memset(lt,0,sizeof(lt));
		cnt=0;
		for(int i=n;i;i--){
			lt[c[i]-'a']++;
			if(lt[c[i]-'a']&1) cnt++;
			else cnt--;
			g[i]=cnt;
		}
		
		
		for(int i=2;i<n;i++){
			int dp1=0;
			len=Check(i);
			int t=i/len;
			for(int j=1;j<=len;j++) if(f[j]<=g[i+1]) dp1++;
			int dp2=0;
			for(int j=len+1;j<=(len<<1);j++) if(f[j]<=g[i+1]) dp2++;
			int d1=(f[len]<=g[i+1]),d2=(f[len<<1]<=g[i+1]);
			for(int j=1;j<=t/2;j++){
				if(t%j) continue;
				if(j&1)
					ans=ans+(j/2+1)*dp1-d1+(j/2)*dp2;
				if(!(j&1))
					ans=ans+(j/2)*dp1+(j/2)*dp2-d2;
			}
			if(t&1)
				ans=ans+(t/2+1)*dp1-d1+(t/2)*dp2;
			if(!(t&1))
				ans=ans+(t/2)*dp1+(t/2)*dp2-d2;
				
			    		//printf("%d %d %d %d %lld\n",i,len,dp1,dp2,ans);
			
		}
		printf("%lld\n",ans);
	}
	
	
	
	return 0;
}
