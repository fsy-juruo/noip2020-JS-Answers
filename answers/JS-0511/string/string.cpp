#include<bits/stdc++.h>
using namespace std;
int n;string s;
int C[2000000][26];
int A[2000000][26];
int AA[2000000],CC[2000000];
long long way=0;
bool same(int sa,int sb,int S)
{
	if(sb-sa!=S)return 0;
	for(int i=0;i<S;i++)
	{
		if(s[sa+i]!=s[sb+i])return 0;
	}
	return 1;
}
bool same2(int sa,int ec,int S)
{
	if(S!=s.size()-ec)return 0;
	for(int i=0;i<S;i++)
	{
		if(s[s.size()-1-i]!=s[sa+i])return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;way=0;
		memset(A,0,sizeof(A));
		memset(C,0,sizeof(C));
		memset(AA,0,sizeof(AA));
		memset(CC,0,sizeof(CC));
		for(int j=0;j<s.size();j++)
		{
			int pj=s.size()-j-1;
			for(int k=0;k<26;k++)C[pj][k]=C[pj+1][k];
			A[j][s[j]-'a']++;C[pj][s[pj]-'a']++;
			for(int k=0;k<26;k++)A[j+1][k]=A[j][k];
			for(int k=0;k<26;k++)
			{
				if(A[j][k]%2)AA[j]++;
				if(C[pj][k]%2)CC[pj]++;
			}
		}//cout<<"O";
		for(int a=0;a<s.size()-2;a++)
		{
			for(int b=a+1;b<s.size()-1;b++)
			{
				int j,c=b+1;
				for(j=b+1;j<s.size();j++)
				{
					if((j)%(b+1)==0)c+=b+1;
					if(s[j]!=s[(j)%(b+1)])break;
					
				}
				if(c!=b+1)c-=b+1;
				for(int k=b+1;k<=c;k++)
				{
					
					if(AA[a]<=CC[k]&&(!same(0,a+1,b-a)||!same2(0,k,a+1)||!same2(a+1,k,b-a))){
						//cout<<c<<':';for(int o=0;o<s.size();o++)
						//{
						//	cout<<s[o];if(o==a||o==b)cout<<' ';
						//}cout<<endl;
						way++;
					}
				}
			}
		}
		cout<<way<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
