#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
int T;
std::string s;
int n;
int r;
int h[27]={0};
int fnum[1005]={0};
int bnum[1005]={0};
int ans;
int cnt=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	for(int zz=1;zz<=T;++zz){
		memset(h,0,sizeof(h));
		std::cin>>s;
		n=s.size();
		fnum[0]=1;
		h[int(s[0]-'a')]=1;
		for(int i=1;i<n;++i){
			if(h[int(s[i]-'a')]==0) fnum[i]=fnum[i-1]+1;
			else fnum[i]=fnum[i-1]-1;
			h[int(s[i]-'a')]^=1;
		}
		memset(h,0,sizeof(h));
		bnum[n-1]=1;
		h[int(s[n-1]-'a')]=1;
		for(int i=n-2;i>=0;--i){
			if(h[int(s[i]-'a')]==0) bnum[i]=bnum[i+1]+1;
			else bnum[i]=bnum[i+1]-1;
			h[int(s[i]-'a')]^=1;
		}
		ans=0;
		for(int i=0;i<n-2;++i){
			for(int j=i+1;j<n-1;++j){
				cnt=0;
				for(int k=j+1;k<n;++k){
					if(s[k%(j+1)]!=s[k]){
						cnt=1;
						r=k;
						break;
					}
				}
				if(cnt==0) r=n-1;
				for(int k=j+1;k<=r;k+=(j+1)){
					if(fnum[i]<=bnum[k]){
						ans++;
					}
				}
			}
		}
		std::cout<<ans<<std::endl;
	}
}
