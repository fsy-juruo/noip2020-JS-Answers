// wish to get a better mark

#include<bits/stdc++.h>
#define re register int
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

using namespace std;

inline int rd(){
	int fl=1,x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}

inline void wr(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10),putchar('0'+(x%10));
	else putchar(x+'0');
}

// ---------- IO ---------- //

const int N=(1<<20)+20;
int T,n,cntA[30],cntC[30],A[N],C[N],sum[30],ss[30],hash[N]={0};
ll ans;
char s[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=rd();
	while(T--){
		ans=0;
		scanf("%s",s+1);n=strlen(s+1);
		for(re i=0;i<30;i++) sum[i]=cntA[i]=cntC[i]=0;
		for(re i=1;i<=n;i++){
			hash[i]=hash[i-1]+(s[i]-'a'+1)*(s[i-1]-'a'+1)*137+s[i]*157;
			if(cntA[s[i]-'a']&1) A[i]=A[i-1]-1;
			else A[i]=A[i-1]+1;
			cntA[s[i]-'a']++;
		}
		for(re i=n;i>0;i--){
			if(cntC[s[i]-'a']&1) C[i]=C[i+1]-1;
			else C[i]=C[i+1]+1;
			cntC[s[i]-'a']++;
		}
		/*for(re j=n;j>0;j--){
			for(re i=1;i<j;i++){
				if(A[i]>C[j]) continue;
				for(re k=i+1;k<j;k++){
					if((j-1)%k) continue;
					if(check(k,j-1)) ans++;//,cout<<i<<' '<<k<<' '<<j<<endl;
				}
			}
		}*/
		for(re k=2;k<n;k++){
			int nw=k+1;sum[A[k-1]]++;ss[0]=sum[0];
			for(re i=1;i<30;i++) ss[i]=ss[i-1]+sum[i];
			for(re j=k+1;j<=n;j+=k){
				if(hash[j-1]-hash[j-k-1]-(s[j-k]-'a'+1)*(s[j-k-1]-'a'+1)*137+(s[j-k]-'a'+1)*(s[0]-'a'+1)*137!=hash[k]) break;
		//		for(;nw<j;nw++){
		//			if(nw%k==0&&s[nw]!=s[k]) break;
		//			if(nw%k&&s[nw]!=s[nw%k]) break;
		//		}
		//		if(nw!=j) break;
				ans+=1ll*ss[C[j]];
			}
		}
		wr(ans);puts("");
	}
	return 0;
}

// ---------- Main ---------- //

