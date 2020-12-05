#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()

typedef long long ll;

string s;
int cnt;
int a[26];

int calc(string ss)
{
	memset(a,0,sizeof(a));
	for(int i=0;i<ss.size();i++)a[(int)(ss[i]-'a')]^=1;
	
	int cc=0;
	for(int i=0;i<26;i++)cc+=a[i];
	
	return cc;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;cin>>t;while(t--)
	{
		cnt=0;
		
		cin>>s;int len=s.size();
			for(int lena=1;lena<=len-2;lena++)
			{
				string sa=s.substr(0,lena);
				if(sa.size()==0)continue;
				int calca=calc(sa);
				
				for(int lenb=1;lenb+lena-1<len-1;lenb++)
				{
					string sb=s.substr(lena,lenb);
					if(sb.size()==0)continue;
					int calcb=calc(sb);
					
					for(int i=1;i*(lena+lenb)<=s.size();i++)
					{
						string sc=s.substr((i*(lena+lenb)));
						if(sc.size()==0)continue;
						string ret="";
						for(int j=0;j<i;j++){ret+=sa;ret+=sb;}
						if(ret+sc!=s)continue;
						if(calc(sc)>=calca)cnt++;
					}
				}
			}
		cout<<cnt<<endl;
	}
	return 0;
}

/*
3
nnrnnr
zzzaab
mmlmmlo


5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
