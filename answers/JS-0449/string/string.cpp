#include <bits/stdc++.h>
#define REP(x,l,u) for(int x=(l);x<=(u);x++)
#define REV(x,u,l) for(int x=(u);x>=(l);x--)
using namespace std;

typedef long long LL;
const int MAXN=10000+10;
int T,DP[MAXN],DS[MAXN],tc[MAXN];
string str;

bool judge(string a,string b){
	string aa=a,bb=b;
	int lena=aa.length(),lenb=bb.length();
	if(lenb%lena)return false;
	int Times=lenb/lena,cur=0;
	bool flag=true;
	REP(i,1,Times){
		if(bb.substr(cur,lena)!=aa){
			flag=false;break;
		}
		cur+=lena;
	}
	if(flag)return true;
	else    return false;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int ans=0;
		cin>>str;int len=str.length();
		int tp=0,ts=0;
		memset(tc,false,sizeof(tc));
		REP(i,0,len-1){
			tc[str[i]-'a']++;
			if(tc[str[i]-'a']%2==0)tp--;
			else                   tp++;
			DP[i]=tp;
		}
		memset(tc,false,sizeof(tc));
		REV(i,len-1,0){
			tc[str[i]-'a']++;
			if(tc[str[i]-'a']%2==0)ts--;
			else                   ts++;
			DS[i]=ts;
		}
		REV(idx,len-1,2){
			REP(lenab,2,idx){
				if(judge(str.substr(0,lenab),str.substr(0,idx))){
					string avistr=str.substr(0,lenab);
					REP(k,1,lenab-1){
						string A=avistr.substr(0,k);
						int lent=A.length();
						if(DP[lent-1]<=DS[idx])ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

