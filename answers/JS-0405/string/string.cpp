#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int num=0,zf=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')zf=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return zf*num;
}
int T;
string s;
int l;
unsigned long long ans;
int aa[2][1100];
int fg[1232];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while(T--){
		ans=0;
		cin>>s;l=s.size();
		bool ok=1;
		for(int i=1;i<l;i++)if(s[i]!=s[0]){ok=0;break;}
		if(ok==1){
			for(int j=3;j<=l;j++){
				for(int i=1;i<=sqrt(j-1);i++){
					if((j-1)%i==0){
						if((l-j+1)%2==1){
							ans+=(((j-1)/i)-1);
							if(i*i!=j-1&&i!=1)ans+=(i-1);
						}
						else{
							ans+=(((j-1)/i)-1)/2;
							if(i*i!=j-1&&i!=1)ans+=(i-1)/2;
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
		else{
			for(int i='a';i<='z';i++)fg[i]=0;
			for(int i=0;i<l;i++){
				fg[s[i]]++;
				if(fg[s[i]]%2==0){
					aa[0][i]=aa[0][i-1]-1;
				}
				else{
					aa[0][i]=aa[0][i-1]+1;
				}
			}
			for(int i='a';i<='z';i++)fg[i]=0;
			for(int i=l-1;i>=0;i--){
				fg[s[i]]++;
				if(fg[s[i]]%2==0){
					aa[1][i]=aa[1][i+1]-1;
				}
				else{
					aa[1][i]=aa[1][i+1]+1;
				}
			}
			for(int i='a';i<='z';i++)fg[i]=0;
			for(int j=3;j<=l;j++){
				for(int k=1;k<j-1;k++)
				if((j-1)%k==0){
					int l=1,r=(j-1)/k;
					bool can=1;
					for(int i=l;i<=r;i++){
						for(int g=1;g<k;g++){
							if(s[i-1]!=s[i+g*r-1])can=0;
							if(can==0)break;
						}
						if(can==0)break;
					}
					if(can==0)break;
					for(int u=l;u<r;u++)if(aa[0][u-1]<=aa[1][j-1])ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
