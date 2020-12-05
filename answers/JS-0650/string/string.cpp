#include<bits/stdc++.h>
using namespace std;
inline int readd(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*w;
}
const int maxn=300005;
int n,m,i,j,k,l,s,d,f,r,h[maxn],a[maxn],b[maxn],h1[maxn][30],h2[maxn],hh[maxn];
long long ans;
string st,st1,st2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=readd();
	while(T--){
		cin>>st;
		n=st.length();
//		cout<<n<<endl;
		for(i=n;i>=1;i--){
			st[i]=st[i-1];
		}
		memset(h,0,sizeof(h));
		memset(h1,0,sizeof(h1));
		memset(h2,0,sizeof(h2));
		l=0;
		for(i=1;i<=n;i++){
			h[st[i]-'a']++;
			if(h[st[i]-'a']&1){
				++l;
			}
			else{
				--l;
			}
			for(j=0;j<=26;j++){
				h1[i][j]=h1[i-1][j];
			}
			h1[i][l]++;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=26;j++){
				h1[i][j]+=h1[i][j-1];
			}
		}
	/*	for(i=1;i<=n;i++){
			cout<<i<<":"<<endl;
			for(j=0;j<=26;j++){
				cout<<h1[i][j]<<" ";
			}
			cout<<endl;
		}*/
		memset(h,0,sizeof(h));
		l=0;
		for(i=n;i>=1;i--){
			h[st[i]-'a']++;
			if(h[st[i]-'a']&1){
				++l;
			}
			else{
				--l;
			}
			h2[i]=l;
		}
/*		for(i=n;i>=1;i--){
			for(j=25;j>=0;j--){
				h2[i][j]+=h2[i][j+1];
			}
		}*/
		st1="";
		st1+=st[1];
		memset(hh,0,sizeof(hh));
		ans=0;
/*		for(i=1;i<=n;i++){
			cout<<h2[i]<<" ";
		}
		cout<<endl;*/
		for(i=2;i<=n-1;i++){
			st1+=st[i];
			if(hh[i]==0){
				l=i;
				hh[i]=1;
				while(true){
					st2="";
					if(l+i>=n){
						break;
					}
					for(j=l+1;j<=l+i;j++){
						if(j>n){
							break;
						}
						st2+=st[j];
					}
					if(st2==st1)hh[i]++;
					else{
						break;
					}
					l+=i;
				}
				l=hh[i];
				f=1;
				for(j=i*2;j<=n/2;j+=i){
					f++;
					if(l>=f){
						hh[j]=l/f;
					}
					else{
						break;
					}
				}
			}
			if(hh[i]==-1){
					ans+=1ll*h1[i-1][h2[i+1]];
			}
			else{
				for(j=1;j<=hh[i];j++){
						ans+=1ll*h1[i-1][h2[i*j+1]];
				}
			}
		}
	/*	for(i=1;i<=n;i++){
			cout<<hh[i]<<" ";
		}
		cout<<endl;*/
		cout<<ans<<endl;
	}
	return 0;
}

