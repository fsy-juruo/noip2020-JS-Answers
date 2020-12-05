#include<bits/stdc++.h>
using namespace std;
int t,fo[1100003],bo[1100003];
char s[1100003];
bool fod[29],bod[29];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int l=strlen(s);
		if(l<3){
			printf("0\n");
			continue;
		}
		memset(fod,0,sizeof(fod));
		memset(bod,0,sizeof(bod));
		for(int i=1;i<l;++i){
			int a=s[i-1]-'a',b=s[l-i]-'a';
			fod[a]=!fod[a],bod[b]=!bod[b];
			if(fod[a]) fo[i]=fo[i-1]+1;
			else fo[i]=fo[i-1]-1;
			if(bod[b]) bo[i]=bo[i-1]+1;
			else bo[i]=bo[i-1]-1;
		}
		int ans=0;
		for(int k=2;k<l;++k){
			for(int i=0;i<k-1;++i)
				if(fo[i+1]<=bo[l-k]) ans++;
			for(int i=k;i<l-1;++i){
				if(s[i]!=s[i-k]) break;
				if((i+1)%k==0)
					for(int j=i-k+1;j<i;++j)
						if(fo[j+k-i]<=bo[l-i-1]) ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
