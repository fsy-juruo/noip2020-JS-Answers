#include<bits/stdc++.h>
typedef long long lint;
#define inf (1<<60)
#define mod 100000007
using namespace std;
string s;
int h[1005];
int ca[1005][26];
int co[1005];
int calc(int l,int r){
	int tmp;
	if(l-1==-1)tmp=0;
	else tmp=h[l-1];
	for(int i=l;i<=r;i++){
		tmp*=26;tmp%=mod;
	}
	return h[r]-tmp;
}
int calcodd(int l,int r){//[]
	int cnt[26];
	for(int i=0;i<=25;i++){
		cnt[i]=ca[r][i]-ca[l-1][i];
	}
	int ans=0;
	for(int i=0;i<=25;i++){
		if(cnt[i]%2==1)ans++;
	}
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		memset(h,0,sizeof(h));
		memset(ca,0,sizeof(ca));
		cin>>s;
		int ans=0;
		if(s.length()<=1000){
			int len=s.length();
			h[0]=s[0]-97;
			for(int i=0;i<len;i++){
				h[i]=h[i-1]*26+(s[i]-97);h[i]%=mod;
			}
			ca[0][s[0]-97]=1;
			for(int i=1;i<len;i++){
				for(int j=0;j<=25;j++){
					ca[i][j]=ca[i-1][j];
				}
				ca[i][s[i]-97]++;
			}
			for(int l=1;l<len;l++){
				int i=0,j=l-1;
				int v=calc(i,j);
				int Codd=calcodd(j+1,len-1);
				//cout<<"L="<<l<<endl;
				for(int k=0;k<l-1;k++){
					int Aodd=calcodd(0,k);
					//cout<<"Aodd="<<Aodd<<" "<<"Codd="<<Codd<<endl;
					if(Aodd<=Codd){
						//printf("UPD:[0,%d]^1,Al=%d\n",l-1,k);
						ans++;
					}
				}
				for(i=l,j=l+l-1;j<len-1;i+=l,j+=l){//n2
					int th=i/l+1;
					int v1=calc(i,j);
					if(v==v1){
						int Codd=calcodd(j+1,len-1);
						for(int k=0;k<l-1;k++){
							int Aodd=calcodd(0,k);
							if(Aodd<=Codd){
								//printf("UPD:[0,%d]^%d,Al=%d\n",l-1,th,k);
								ans++;
							}
						}
					}
					else break;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
