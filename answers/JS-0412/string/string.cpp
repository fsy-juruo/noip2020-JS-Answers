#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ms memset
#define linf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int N=1100000;
const ll p=1e9+7;
char s[N];
ull hash[N],q[N];
void init(){
	hash[0]=s[0]-'a'+1;
	int len=strlen(s);
	q[0]=1;
	for(int i=1;i<=len;i++) q[i]=q[i-1]*p;
	for(int i=1;i<len;i++){
		hash[i]=hash[i-1]*p+s[i]-'a'+1;
	}
}
ull h(int l,int r){
	return hash[r]-hash[l-1]*q[r-l+1];
}
int cnt[N],ch[30],leng[N],f[N][26];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%s",s);int len=strlen(s);
		//getnxt();
		init();ans=0;
		//cout<<hash[2]<<" "<<h(3,5)<<endl;
		for(int i=0;i<=len;i++){
			int j;
			//cout<<i<<" "<<hash[i]<<":";
			for(j=i+1;j+i<=len;j+=i+1){
				//cout<<j<<" "<<h(j,j+i)<<"  ";
				if(h(j,j+i)!=hash[i]){
					leng[i+1]=j-1;
					j=0;
					//cout<<1<<endl;
					break;
				}
			}
			//cout<<j<<endl;
			if(j+i>len) leng[i+1]=len;
			//cout<<leng[i]<<" ";
		}
		//for(int i=1;i<=len;i++)	cout<<leng[i]<<" ";
		//cout<<endl;
		ms(ch,-1,sizeof(ch));
		cnt[0]=1;ch[s[0]-'a']=1;
		for(int i=0;i<len;i++)
			for(int j=0;j<26;j++)
				f[i][j]=0;
		f[0][1]=1;
		//cout<<cnt[0]<<" ";
		for(int i=1;i<len;i++){
			ch[s[i]-'a']*=-1;
			cnt[i]=cnt[i-1]+ch[s[i]-'a'];
			f[i][cnt[i]]++;
			//cout<<cnt[i]<<" ";
		}
		//cout<<endl;
		for(int j=1;j<26;j++) f[0][j]+=f[0][j-1];
		for(int i=1;i<len;i++) f[i][0]+=f[i-1][0];
		for(int i=1;i<len;i++)
			for(int j=1;j<26;j++)
				f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
		/*for(int i=0;i<len;i++){
			for(int j=0;j<3;j++)
				cout<<f[i][j]<<" ";
			cout<<endl;
		}*/	
		int c=0;
		ms(ch,-1,sizeof(ch));
		for(int i=len-1;i>1;i--){
			ch[s[i]-'a']*=-1;c+=ch[s[i]-'a'];
			for(int j=1;j<i;j++){
				if(leng[j+1]>=i-1 && i%(j+1)==0){
					ans+=f[j-1][c];
				}
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
