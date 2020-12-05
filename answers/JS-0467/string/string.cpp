#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n,len,ans;
char a[1010];
int nex[1010];
int h[1010][1010];

bool pd(int l,int r){
	if (l!=l-r+1||l!=len-r+1||len-r!=r-l) return 1;
	for (int i=1;i<=l;++i) if (a[i]!=a[l+i]) return 1;
	for (int i=1;i<=l;++i) if (a[l+i]!=a[r+i]) return 1;
	return 0;
}

int deal(int l,int r){
	int x=r/2;
	if (l*2>=r||l+1==r||r&1==1) return 0;
	for (int i=1;i<=x;++i)
		if (a[i]!=a[x+i]) return 0;
	return 1;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while (n--){
		char ch=getchar();
		len=0,ans=0;
		for (;ch<'a'||ch>'z';ch=getchar()){}
		for (;ch>='a'&&ch<='z';ch=getchar()) a[++len]=ch;
		int c[30];
		memset(h,0,sizeof(h));
		for (int i=1;i<=26;++i) c[i]=0;
		for (int i=1;i<=len;++i){
			for (int j=i;j<=len;++j){
				for (int k=1;k<=26;++k) c[k]=0;
				for (int k=i;k<=j;++k)
					c[a[k]-'a'+1]++;
				for (int k=1;k<=26;++k)
					if (c[k]&1==1) h[i][j]++;
			}
		}
		for (int i=1;i<=len;++i)
			for (int j=i+2;j<=len;++j)
				if (h[1][i]<=h[j][len]){
					if (pd(i,j)) 
						ans=ans+1+deal(i,j-1);
				}
		cout<<ans<<endl;
	}
	return 0;
}

