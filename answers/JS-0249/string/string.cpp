#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
ak a[1111111],odd[1111111],suf[1111111],pre[1111111][33],cnt[33],up[111111];
ak play(ak n){
	ak ans=0;
	F(i,2,n-1){
		for(int j=1;j*j<=i;j++){
			if(i%j)continue;ak d1=j,d2=i/j;
			if((n-i)&1){ak len=i/j;ans+=len-1;}
			else{ak len=i/j;ans+=(len-1)>>1;}
			if(d2==i||d2==d1)continue;
			if((n-i)&1){ak len=i/d2;ans+=len-1;}
			else{ak len=i/d2;ans+=(len-1)>>1;}
		}
	}
	return ans;
}
int main(){
	#ifndef lpcak
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	#endif
	int t;ak ans=0;
	ios::sync_with_stdio(0);
	cin>>t;
	F(jiba,1,t){
		string str;cin>>str;ak n=str.size();
		if(n>1000){cout<<play(n)<<"\n";continue;}//Below is for 48 pts
		F(i,1,n)a[i]=str[i-1]-'a'+1;
		F(i,1,26)cnt[i]=0;ans=0;
		F(i,0,n+1)odd[i]=suf[i]=up[i]=0;
		F(i,0,n+1)F(j,0,27)pre[i][j]=0;
		F(i,1,n){
			cnt[a[i]]++;odd[i]=odd[i-1];
			if(cnt[a[i]]&1)odd[i]++;
			else odd[i]--;
		}
		F(i,1,26)cnt[i]=0;F(i,0,n+1)suf[i]=0;
		G(i,n,1){
			cnt[a[i]]++;suf[i]=suf[i+1];
			if(cnt[a[i]]&1)suf[i]++;
			else suf[i]--;
		}
		F(i,1,n){
			F(j,0,26)
				pre[i][j]=pre[i-1][j]+(odd[i]<=j);
			if(i>n/2){up[i]=1;continue;}up[i]=1;
			F(j,i+1,n-1){
				if(j>n-1)break;
				if(a[(j%i)?(j%i):i]!=a[j])break;
				if(j%i==0)up[i]++;
			}
		}
		
		
//		F(i,1,n)cout<<odd[i]<<" "<<suf[i]<<" "<<up[i]<<"\n";
		
		
		F(i,2,n-1)F(j,1,up[i]){
			ak tar=suf[i*j+1];ans+=pre[i-1][tar];
			
			
//			cout<<i<<" "<<j<<" "<<pre[i-1][tar]<<"\n";
			
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*

3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab

1
kkkkkkkkkkkkkkkkkkkk

*/
