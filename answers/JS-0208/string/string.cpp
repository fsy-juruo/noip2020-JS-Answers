#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef unsigned long long ull;
const int INF=2147483647;
typedef vector<int> vi;
typedef priority_queue<int> pi;
typedef priority_queue<int,greater<int>,vi> pir;

inline int read(){
	int x=0;
//	int neg=1;
	char ch=getchar();
	while(!isdigit(ch)){
//		if(ch=='-') neg=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}

int t;
string s;
int A,B,a[30],b[30];
ull ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	while(t--){
		ans=0;
		cin>>s;
		if(s.size()<=100){
			for(int i=1;i<=s.size()-2;i++){
				for(int j=0;j<26;j++) a[j]=0;
				A=0;
				for(int j=0;j<i;j++) a[s[j]-'a']^=1;
				for(int j=0;j<26;j++) A+=a[j];
				for(int j=1;j<=s.size()-1-i;j++){
					for(int k=1;k*(i+j)<s.size();k++){
						bool f=true;
						for(int l=(k-1)*(i+j);l<(k-1)*(i+j)+i;l++)
							if(s[l]!=s[l-(k-1)*(i+j)]){
								f=false;
								break;
							}
						if(!f) break;
						for(int l=(k-1)*(i+j)+i;l<k*(i+j);l++)
							if(s[l]!=s[l-(k-1)*(i+j)]){
								f=false;
								break;
							}
						if(!f) break;
						for(int l=0;l<26;l++) b[l]=0;
						B=0;
						for(int l=k*(i+j);l<s.size();l++) b[s[l]-'a']^=1;
						for(int l=0;l<26;l++) B+=b[l];
						if(A<=B){
							ans++;
	//						printf("%d %d %d		%d %d\n",i,j,k,A,B);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

