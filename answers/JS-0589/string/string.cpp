#include<bits/stdc++.h>
using namespace std;
#define ll long long
int read(){
	int x=0,f=1; char ch=getchar();
	if(ch=='-'){f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3);
		x+=(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int a[2000005],xa[2000005],n=0,ans;
int hasha[27],hashc[27],fa,fc;
void deal(){
	for(int i=n;i>=3;i--){
		memset(hasha,0,sizeof(hasha));
		hashc[a[i]]++;
		if(hashc[a[i]]%2==0) fc-=2;
		else fc++;
		int j;
		for(j=1;j<=(i-2)/2;j++){
			if(hasha[a[j]]%2==0) fa-=2;
			else fa++;
			xa[j]=a[j];
			if(fa>fc) continue;
			int k,xj=1;
			for(k=j+1;k<=i-2;k++){
				int xk=k;
				if((i-2)%j==0)
					while(a[xk]==xa[xj]){
						xk++;
						xj++;
						if(xj>j){
							ans++;
							break;
						}
					}
			}
			ans++;
		}
		for(;j<(i-2);j++){
			if(hasha[a[j]]%2==0) fa-=2;
			else fa++;
			if(fa>fc) continue;
			ans++;
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//cout<<(long long)pow(2,20)<<endl;
//	cout<<(sizeof(a)+sizeof(xa))/1024/1024;
	int T=read();
	for(int i=1;i<=T;i++){
		char ch=getchar();
		while(ch>='a'&&ch<='z'){
			n++;
			a[n]=(ch-'a');
			ch=getchar();
		}
		ans=0;
		memset(hashc,0,sizeof(hashc));
		fa=0; fc=0;
		deal();
		printf("%d\n",ans);
	}
	return 0;
}
