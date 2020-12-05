#include<bits/stdc++.h>
#define MAX 2000000
using namespace std;
typedef long long ll;
int t,pre[MAX+5][35],len; ll cnt;
string s;
void clean()
{
	for(int i=1; i<=s.length(); i++)
	for(int j=0; j<26; j++)
	pre[i][j]=0;
	cnt=0;
}
bool check(int pos,int pos2)
{
    int cnt1=0,cnt2=0;
	for(int i=0; i<26; i++)
	{
		cnt1+=(pre[pos][i]%2==1);
		cnt2+=((pre[len][i]-pre[pos2][i])%2==1);
    }
	return cnt1<=cnt2;
}
bool check2(int pos,int pos2,int l)
{
	for(int i=1; i<=l; i++)
	if(s[pos+i-1]!=s[pos2+i-1]) return 0;
	return 1;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--)
	{
		clean(); cin>>s; len=s.length();
	    for(int i=1; i<=len; i++)
	    for(int j=0; j<26; j++)
	    {
	    pre[i][j]=pre[i-1][j];
	    if((s[i-1]-'a')==j) pre[i][j]++;
	    }
         for(int l=2; l<=len; l++)
         for(int num=1; num<=len; num++)
         {
        	int flag=0;
        	if(l*num>=len) break;
        	for(int i=1; i<=l*num; i+=l)
        	{
        		if(!check2(0,i-1,l)) { flag=1; break; }
			}
            if(flag) continue;
            for(int i=1; i<l; i++)
            if(check(i,l*num)) cnt++;
		 }
		printf("%lld\n",cnt);
	}
	return 0;
}
