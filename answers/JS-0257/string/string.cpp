#include<bits/stdc++.h>
using namespace std;

typedef long long lint;

const lint MAXN=(1<<20+1);
lint nums[MAXN][26], nxt[MAXN], cnt[MAXN];
string s;

lint gcds(lint a, lint b) { return (b==0 ? a : gcds(b, a%b)); }
lint fs(lint a, lint b) { return (b==gcds(a, b) ? a/b : 1); }

lint cnts(lint L, lint R)
{
	lint cnt=0;
	if(L==0) for(lint i=0; i<26; i++)
	{
		if(nums[R][i]&1) cnt++;
	}
	else for(lint i=0; i<26; i++)
	{
		if((nums[R][i]-nums[L-1][i])&1) cnt++;
	}
	return cnt;
}

lint counts(lint L1, lint R1, lint L2, lint R2)
{
	lint i, res=cnts(L2, R2), ans=0;
	for(i=L1; i<R1; i++) if(cnts(L1, i)<=res) ans++;
	return ans;
}

void works()
{
	lint i, k, n=s.length();
	lint j=-1, ans=0;
	for(i=0; i<n; i++) nxt[i]=0, cnt[i]=0;
	for(k=0; k<26; k++) nums[0][k]=0;
	for(i=0; i<n; i++)
	{
		if(i!=0)
		{
			for(k=0; k<26; k++) nums[i][k]=nums[i-1][k];
			nums[i][s[i]-'a']++;
		}
		else nums[i][s[i]-'a']++;
		while(j!=-1 && s[i]!=s[j]) j=nxt[j];
		nxt[i]=j; j++;
	}
	
	cnt[0]=1;
	for(i=1; i<n; i++)
	{
		if(nxt[i]==-1) cnt[i]=1;
		else cnt[i]=fs((i+1), (i-nxt[i]));
	}
	
	for(i=0; i<n-1; i++)
	{
		ans+=counts(0, i, i+1, n-1);
		for(k=2; k<=cnt[i]; k++) if(cnt[i]%k==0) ans+=counts(0, (i+1)/k-1, i+1, n-1);
	}
	cout<<ans<<endl;
}

int main()
{
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int T;
	cin>>T;
	while(T)
	{
		cin>>s;
		works();
		T--;
	}
	return 0;
}
