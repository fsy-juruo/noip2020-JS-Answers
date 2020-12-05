//#   # #####  #### #   # ####  #####
// # #    #   #     ##  # #   #   #
//  #     #    ###  # # # ####    #
//  #   # #       # #  ## #       #
//  #    ##   ####  #   # #     #####
#include<bits/stdc++.h>
using namespace std;

void KMP(char *s,int *pi,const int& n){
	pi[0]=0;
	for(int i=1;i<n;i++){
		int& j=pi[i];
		j=pi[i-1];
		while(j>0&&s[i]!=s[j])j=pi[j-1];
		j+=s[i]==s[j];
	}
}

char s[1<<20|50];
int n,pre[1<<20|50],suf[1<<20|50],cha[30],pi[1<<20|50],pp[1<<20|50][30];
long long ans;

void mian(){
	cin>>s+1;
	n=strlen(s+1);
	memset(pre,0,sizeof(pre));
	memset(cha,0,sizeof(cha));
	for(int i=1;i<=n;i++){
		cha[s[i]-'a']^=1;
		for(int k=0;k<26;k++)pre[i]+=cha[k];
		for(int k=0;k<=26;k++)pp[i][k]=pp[i-1][k]+(k>=pre[i]);
	}
	memset(suf,0,sizeof(suf));
	memset(cha,0,sizeof(cha));
	for(int i=n;i>=1;i--){
		cha[s[i]-'a']^=1;
		for(int k=0;k<26;k++)suf[i]+=cha[k];
	}
	KMP(s+1,pi+1,n);
	ans=0;
	for(int i=2;i<n;i++){
		int k;
		if(pi[i]*2>=i)k=i-pi[i];
		else k=i;
		for(int kk=k;kk<=i;kk+=k)if(i%kk==0)ans+=pp[kk-1][suf[i+1]];
	}
	cout<<ans<<'\n';
}

int main(){

	ios_base::sync_with_stdio(0);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	int T;
	cin>>T;
	while(T--)mian();

	return 0;
}
