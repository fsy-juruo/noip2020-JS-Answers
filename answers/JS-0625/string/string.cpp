#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1<<20+5;
int read(){
	int p=0,q=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')q=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		p=p*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
char c[N],t[N],tt[N];
int ans=0,num1[200],num2[200];
int Size=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=read();
	while(T--){
		ans=0;
		Size=0;
		char ch;
		while(ch=getchar()){
			if(int(ch)==10)break;
			c[++Size]=ch;
		}
		for(int i=1;i<=Size;++i){
			for(int j=1;j<=Size;++j){
				for(int k=1;k<=Size;++k){
					memset(num1,0,sizeof(num1));
					memset(num2,0,sizeof(num2));
					if((Size-k)%(i+j)!=0||i+j+k!=Size)continue;
					for(int s=1;s<=i;++s)num1[int(c[s])]++;
					for(int s=Size-k+1;s<=Size;++s)num2[int(c[s])]++;
					int ji1=0,ji2=0;
					for(int s=1;s<=199;++s)if(num1[s]%2==1)++ji1;
					for(int s=1;s<=199;++s)if(num2[s]%2==1)++ji2;
					if(ji1>ji2)continue;
					int f=1;
					for(int s=i+j+1;s<=Size-k;++s){
						if(c[s%(i+j)]!=c[s]){
							f=0;
							break;
						}
					}
					if(f){
						++ans;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


