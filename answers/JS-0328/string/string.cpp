#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1050000;
int T;
int len,lim;
int nx[N],t[28],s[2][N];
ll g[30][N],ans;
string str;
char ch;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j,k,tmp;
	scanf("%d",&T);
	while (T--) {
		cin>>str;
		len=str.size();
		k=-1, j=0;
		memset(nx,0,sizeof(nx));
		nx[0]=-1;
		while (j<len) {
			if (k==-1||str[j]==str[k]) {
				k++, j++;
				nx[j]=k;
			}
			else  k=nx[k];
		}
		memset(t,0,sizeof(t));
		s[0][0]=1;
		t[str[0]-'a']=1;
		for (i=1;i<len;i++) {
			ch=str[i];
			if (t[ch-'a']&1)  s[0][i]=s[0][i-1]-1;
			else  s[0][i]=s[0][i-1]+1;
			t[ch-'a']^=1;
		}
		memset(t,0,sizeof(t));
		for (i=len-1;i>=0;i--) {
			ch=str[i];
			if (t[ch-'a']&1)  s[1][i]=s[1][i+1]-1;
			else  s[1][i]=s[1][i+1]+1;
			t[ch-'a']^=1;
		}
		memset(g,0,sizeof(g));
		for (j=0;j<=26;j++) {
			lim=j;
			if (s[0][0]<=lim)  g[j][0]=1ll;
			for (i=1;i<len;i++)
			  if (s[0][i]<=lim)  g[j][i]=g[j][i-1]+1ll;
			  else  g[j][i]=g[j][i-1];
		}
		ans=0;
		for (i=len-1;i>=2;i--) {
			tmp=i;
			lim=s[1][i];
			ans+=g[lim][i-2];
			if (nx[tmp]*2<i)  continue;
			while (tmp>=2&&tmp*2>=i) {
				tmp=nx[tmp];
				while ((tmp>0)&&(i%(i-tmp)!=0))  tmp=nx[tmp];
				if (i%(i-tmp)!=0)  break;
				if (i-tmp<2)  continue;
				if (tmp==0)  continue;
				ans+=g[lim][i-tmp-2];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

