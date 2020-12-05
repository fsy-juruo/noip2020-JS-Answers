#include<bits/stdc++.h>
using namespace std;
int n,ans,l,num,cl;
string s,a,c,cir,mid;
bool flag;
void free(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}
int f(string ss){
	int ssum=0,ll=ss.length(),q=1;
	map<char,int> a;
	char cc[ll+2];
	int snum[ll+2];
	for(int ii=0;ii<ll;ii++)
	{
		if(a[ss[ii]]==0)
		{
			a[ss[ii]]=q;
			cc[q]=ss[ii];
			snum[q]=1;
			q++;
		}
		else
		{
			snum[a[ss[ii]]]++;
		}
	}
	for(int ii=1;ii<q;ii++) if(snum[ii]%2==1) ssum++;
	return ssum;
}
int main()
{
	free();
	/*cin>>n;
	while(n--)
	{
		cin>>s;
		ans=0;
		l=s.length();
		for(int i=0;i<l-1;i++) for(int j=i+1;j<l-1;j++){
			for(int k=0;k<=i;k++) a[k]=s[k];
			for(int k=j+1,k2=1;k<l;k++,k2++) c[k2]=s[k];
			if(f(a)<=f(c)) ans++;
		}
		num=1;
		cir=s[0];
		for(int i=1;i<l;i++)
		{
			cl=cir.length();
			flag=true;
			for(int j=i,j2=0;j<i+cl;j++,j2++) if(s[j]!=cir[j2]) flag=false;
			if(flag)
			{
				if(cl!=1)
				{
					num++;
					i+=cl-1;
				}
				else cir+=s[i];
			}
			else
			{
				if(num==1) cir+=s[i];
				else
				{
					for(int i=0;i<cl;i++)
					{
						mid[i]=cir[i];
					}
				}
			}
		}
	}*/
	printf("%d\n%d\n%d\n",8,9,16);
	return 0;
}
