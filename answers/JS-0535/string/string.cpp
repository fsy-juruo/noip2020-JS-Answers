#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;i++)
#define DF(i,a,b) for (int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
//#pragma GCC optimize(2)
using namespace std;
inline int read(){
	int w=1,c=0; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=(1<<20)+11;
#define UL unsigned LL
const UL p=1313131;
UL hs[M],pw[M];
char ch[M];
int t[50];
int tx[50];
UL gv(int l,int r){
	return hs[r]-hs[l-1]*pw[r-l+1];
}
int n,res[M];
void solve(){
	scanf("%s",ch+1); n=strlen(ch+1);
//	cerr<<n<<"\n";
//	cerr<<"fuck\n";
	int num=0;
	pw[0]=1;
	F(i,1,n) pw[i]=pw[i-1]*p;
	DF(i,n,1){
		int o=ch[i]-'a';
		t[o]++;
		if (t[o]&1) num++;
		else num--;
		res[i]=num;
	}
	hs[0]=0;
	F(i,1,n){
		hs[i]=hs[i-1]*p+ch[i];
	}
//	cout<<gv(1,3)<<" "<<gv(4,6)<<" "<<(gv(1,3)==gv(4,6))<<"\n";
	ms(t,0); num=0;
	LL ans=0;
	F(i,1,n-1){
		UL lst=0;
		for (int j=i;j<n;j+=i){
			UL now=gv(j-i+1,j);
			if (j>i){
				if (now^lst) break;
			}	
//			cout<<i<<" "<<j<<" "<<" <= "<<res[j+1]<<" number = "<<tx[res[j+1]]<<"    gg\n";
			ans=ans+tx[res[j+1]];
			lst=now;
		}
		
		int o=ch[i]-'a';
		t[o]++;
		if (t[o]&1) num++;
		else num--;
		F(j,num,30) tx[j]++;
	}
	cout<<ans<<"\n";
	ms(t,0); ms(tx,0);
}
int nxt[M],mip[M];
void solve_kmp(){
	scanf("%s",ch+1); n=strlen(ch+1);
//	cerr<<n<<"\n";
//	cerr<<"fuck\n";
	int j=0,num=0;
	F(i,2,n){
		while (j && ch[j+1]!=ch[i]) j=nxt[j];
		if (ch[j+1]==ch[i]) j++;
		nxt[i]=j;
		mip[i]=(i%(i-j) ? i : i-j);
//		cout<<mip[i]<<"   hh\n";
	}
	DF(i,n,1){
		int o=ch[i]-'a';
		t[o]++;
		if (t[o]&1) num++;
		else num--;
		res[i]=num;
	}
//	hs[0]=0;
//	F(i,1,n){
//		hs[i]=hs[i-1]*p+ch[i];
//	}
//	cout<<gv(1,3)<<" "<<gv(4,6)<<" "<<(gv(1,3)==gv(4,6))<<"\n";
	ms(t,0); num=0;
	LL ans=0;
	F(i,1,n-1){
//		UL lst=0;
		if (i>1){
			int l=1,r=(n-1)/i,tar=1;
			while (l<=r){
				int mid=(l+r>>1);
				if (i%mip[mid*i]==0) l=mid+1,tar=mid;
				else r=mid-1;
			}
//			cerr<<tar<<" "<<tar*i<<" "<<n<<"\n";
			for (int j=i,o=1;o<=tar;j+=i,o++){
//				if (j>n) cout<<j<<" "<<o<<" "<<ans<<"\n";
	//			UL now=gv(j-i+1,j);
	//			if (j>i){
	//				if (now^lst) break;
	//			}	
	//			cout<<i<<" "<<j<<" "<<" <= "<<res[j+1]<<" number = "<<tx[res[j+1]]<<"    gg\n";
				ans=ans+tx[res[j+1]];
	//			lst=now;
			}
		}
		int o=ch[i]-'a';
		t[o]++;
		if (t[o]&1) num++;
		else num--;
		F(j,num,26) tx[j]++;
	}
	cout<<ans<<"\n";
	ms(t,0); ms(tx,0);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=read();
	while (T--) solve_kmp();

	return 0;
}

