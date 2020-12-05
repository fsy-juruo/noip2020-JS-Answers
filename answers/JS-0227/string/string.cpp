#include<bits/stdc++.h>
using namespace std;
long long t;
char s[1050000];
unsigned long long mod[3]={131,13331,3373};
unsigned long long ha[1050000][3];
unsigned long long ji[1050000];
unsigned long long mi(unsigned long long x,unsigned long long y){
	unsigned long long i=1,j=x;
	while(y){
		if(y&1)i*=j;
		j*=j;
		y>>=1;
	}
	return i;
}
bool chk(unsigned long long len,unsigned long long mul){
	for(unsigned long long ii=0;ii<3;ii++){
		unsigned long long m=mul;
		unsigned long long cheng=mi(mod[ii],len);
		unsigned long long tmp1=ha[len][ii];
		unsigned long long ch[30];
		ch[0]=1;
		ch[1]=mi(mod[ii],len);
		for(unsigned long long i=2;i<=25;i++)
			ch[i]=ch[i-1]*ch[i-1];
		unsigned long long chh[30];
		chh[1]=ha[len][ii];
		for(unsigned long long i=2;i<=25;i++)
			chh[i]=chh[i-1]*(ch[i-1]+1);
		unsigned long long ans=0;
		unsigned long long kk=2;
		while(m){
			if(m&1)ans=ans*ch[kk-1]+chh[kk-1];
			m>>=1;
			kk++;
		}
		if(ans!=ha[len*mul][ii])return false;
	}
	return true;
}
unsigned long long cnt(unsigned long long x){
	unsigned long long ans=0;
	while(x){
		if(x&1)ans++;
		x>>=1;
	}
	return ans;
}
unsigned long long countt[1050000];
unsigned long long bit[1050000];
void ins(int pos){
	for(int i=pos;i<=1049999;i+=(i&-i))
		bit[i]++;
}
int ser(int pos){
	int retr=0;
	for(int i=pos;i;i-=(i&-i))
		retr+=bit[i];
	return retr;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(unsigned long long i=1;i<=t;i++){
		scanf("%s",s+1);
		unsigned long long len=strlen(s+1);
		memset(ha,0,sizeof(ha));
		memset(ji,0,sizeof(ji));
		memset(countt,0,sizeof(countt));
		memset(bit,0,sizeof(bit));
		for(unsigned long long j=0;j<3;j++)
			for(unsigned long long k=1;k<=len;k++)
				ha[k][j]=ha[k-1][j]*mod[j]+(unsigned long long)s[k];
		for(unsigned long long j=1;j<=len;j++)
			ji[j]=ji[j-1]^(1<<(s[j]-'a')),countt[j]=cnt(ji[j]);
		unsigned long long ans=0;
		unsigned long long ml[len+1];
		ins(2);
		for(unsigned long long j=2;j<len;j++){
			unsigned long long l=0,r=(len-1)/j;
			while(l<r){
				unsigned long long m=(l+r+1)/2;
				if(chk(j,m))l=m;
				else r=m-1;
			}
			ml[j]=l;
			unsigned long long mx=cnt(ji[j*l]^ji[len]);
			long long ll=ser(mx+1);
			unsigned long long mx2=cnt((ji[j*l]^ji[len])^ji[j]);
			long long lll=ser(mx2+1);
			ans+=l/2*lll+(l-l/2)*ll;
			ins(countt[j]+1);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
