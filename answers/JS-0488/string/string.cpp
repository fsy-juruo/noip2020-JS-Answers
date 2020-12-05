#include<bits/stdc++.h>
#define mo1 99999989
#define mo2 99999971
#define mo3 99999959
using namespace std;
int read(){
	int num=0,f=1;char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar(); }
	while(isdigit(c)){num=num*10+c-'0'; c=getchar(); }
	return num*f;
}
int T,ma,len;
string str[6],st;
long long ha1[1048600],ha2[1048600],ha3[1048600];
int rt1=137,rt2=211,rt3=197;
long long a1[1048600],a2[1048600],a3[1048600];
int pr['z'+1][1048600],pre[27][1048600],sss[1048600];
long long ans;
long long zzz1,zzz2,zzz3;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++)
	{
		cin>>str[i];
		int len=str[i].size();
		ma=max(len,ma);
	}
	a1[0]=a2[0]=a3[0]=1;
	for(int i=1;i<=ma+1;i++)
	{
		a1[i]=(a1[i-1]*rt1)%mo1;
		a2[i]=(a2[i-1]*rt2)%mo2;
//		a3[i]=(a3[i-1]*rt3)%mo3;
	}
	for(int o=1;o<=T;o++)
	{
		st=' '+str[o];
		len=st.size();
		ans=0;
//		memset(ha1,0,sizeof(ha1));
//		memset(ha2,0,sizeof(ha2));
//		memset(ha3,0,sizeof(ha3));
		for(int i=1;i<=len;i++)
			for(int j=0;j<=26;j++) pre[j][i]=0;
//		memset(pr,0,sizeof(pr));
//		cout<<len<<endl;
		long long aa1=1,aa2=1,aa3=1;
		for(int i=1;i<len;i++)
		{
			ha1[i]=(ha1[i-1]+st[i]*aa1)%mo1;
			aa1=(aa1*rt1)%mo1;
			ha2[i]=(ha2[i-1]+st[i]*aa2)%mo2;
			aa2=(aa2*rt2)%mo2;
//			ha3[i]=(ha3[i-1]+st[i]*aa3)%mo3;
//			aa3=(aa3*rt3)%mo3;
		}
//		for(int i=1;i<len;i++)
//			cout<<ha1[i]<<" "<<ha2[i]<<" "<<ha3[i]<<endl;
		for(int i=1;i<len;i++) 
		{
			for(char j='a';j<='z';j++)
				if (st[i]==j) pr[j][i]=pr[j][i-1]+1;
				else pr[j][i]=pr[j][i-1];
		}
//		for(int i=1;i<len;i++)
//		{
//			for(char j='a';j<='z';j++)
//				cout<<pr[j][i]<<" ";
//			cout<<endl;
//		}
		for(int i=1;i<len;i++)
		{
			int s=0;
			for(char j='a';j<='z';j++)
				if (pr[j][i]%2==1) s++;
			pre[s][i]++;
		}
		for(int i=len-1;i>=1;i--)
		{
			if ((pr[st[i]][len-1]-pr[st[i]][i-1])%2==1) sss[i]=sss[i+1]+1;
			else sss[i]=sss[i+1]-1; 
		}
		for(int i=1;i<len;i++)
		{
			pre[0][i]+=pre[0][i-1];
			for(int j=1;j<=26;j++)
				pre[j][i]+=pre[j][i-1]+pre[j-1][i]-pre[j-1][i-1];
		}
//		for(int i=1;i<len;i++)
//		{
//			for(int j=0;j<=26;j++)
//				cout<<pre[j][i]<<" ";
//			cout<<endl;
//		}
		for(signed i=2;i<len-1;i++)
		{
			signed z=i;
			zzz1=zzz2=zzz3=1;
			while(1)
			{
//				cout<<z<<endl;
				ans+=pre[sss[z+1]][i-1];
				if (z+i>=len-1) break;
				zzz1+=a1[z];
				zzz1%=mo1;
				zzz2+=a2[z];
				zzz2%=mo2;
//				zzz3+=a3[z];
//				zzz3%=mo3;
				if ((ha1[i]*zzz1%mo1==ha1[(z+i)])&&(ha2[i]*zzz2%mo2==ha2[(z+i)])
		//		&&(ha3[i]*zzz3%mo3==ha3[(z+i)])
				)
					z+=i;
				else break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

1
nnrnnr
*/
