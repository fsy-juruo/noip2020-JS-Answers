#include<bits/stdc++.h>
using namespace std;
#define SZ(v) ((int)(v).size())
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
int n;
const int Maxn=2e6+5;
char s[Maxn];
int wa[26],wc[26];
int ans;
int cmd;

bool can_fold(int len,int l,int r) {
	for(int i=l+len; i<=r; i++) {
		if(s[i]!=s[i-len])return false;
	}
	return true;
}
void type_1(){
	for(int i=2;i<=n-1;i++){
		for(int j=1;j*j<=i;j++){
			if(i%j==0) {
				int len=i/j;
				if(len>=2) {
					if((n-i)%2==0){
						ans+=(len-1)/2;
					}else{
						ans+=len-1;
					}
					
				}
				if(j*j!=i) {
					len=j;
					if(len>=2) {
						if((n-i)%2==0){
							ans+=(len-1)/2;
						}else{
							ans+=len-1;
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
}

void solve() {
	scanf("%s",s+1);
//	cout<<"!!!"<<endl;
	ans=0;
	cmd=0;
	memset(wa,0,sizeof(wa));
	memset(wc,0,sizeof(wc));

	n=strlen(s+1);
	if(n<=2) {
		printf("0\n");
		return;
	}
	for(int i=1;i<=n;i++){
		wc[s[i]-'a']++;
	}
	int ccc=0;
	for(int i=0;i<26;i++){
		if(wc[i]>0){
			ccc++;
			cmd=i;
		}
	}
	if(ccc==1){
		type_1();
		return;
	}
//	cout<<"!!!"<<endl;
	for(int i=2; i<=n-1; i++) { //AB[1,i] C[i+1,n]
		memset(wc,0,sizeof(wc));
		for(int j=i+1; j<=n; j++) {
			wc[s[j]-'a']++;
		}
		int c_cnt=0;
		for(int j=0; j<26; j++) {
			if(wc[j]&1)c_cnt++;
		}
		for(int j=1; j*j<=i; j++) {
			if(i%j==0) {
				int len=i/j;
				if(len>=2) {
					if(can_fold(len,1,i)) {
						memset(wa,0,sizeof(wa));
						for(int k=1; k<len; k++) {
							wa[s[k]-'a']++;
							int a_cnt=0;
							for(int l=0; l<26; l++) {
								if(wa[l]&1)a_cnt++;
							}
							if(a_cnt<=c_cnt) {
								ans++;
//								printf("i=%d len=%d k=%d\n",i,len,k);
							}
						}
					}
				}

				if(j*j!=i) {
					len=j;
					if(len>=2) {
						if(can_fold(len,1,i)) {
							memset(wa,0,sizeof(wa));
							for(int k=1; k<len; k++) {
								wa[s[k]-'a']++;
								int a_cnt=0;
								for(int l=0; l<26; l++) {
									if(wa[l]&1)a_cnt++;
								}
								if(a_cnt<=c_cnt) {
									ans++;
//									printf("i=%d len=%d k=%d\n",i,len,k);
								}
							}
						}
					}
				}
			}
		}
	}
//	cout<<"!!!"<<endl;
	printf("%d\n",ans);
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
//		cerr<<endl;
	}
	return 0;
}

