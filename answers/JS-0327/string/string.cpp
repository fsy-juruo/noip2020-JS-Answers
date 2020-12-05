#include<bits/stdc++.h>
using namespace std;
int read(){
	int r=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-') ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) r=r*10+ch-'0',ch=getchar();
	return r*f;
}
int a[1005][1005];
void prework(){
	a[1][0]=1;
	a[1][1]=1;
	for (int i=2;i<=1000;i++){
		a[i][0]=2;
		a[i][1]=1;
		a[i][2]=i;
		for (int j=2;j*j<=i;j++){
			if (i%j==0){
				if (j*j==i) a[i][++a[i][0]]=j;
				else a[i][++a[i][0]]=j,a[i][++a[i][0]]=i/j;
			}
		}
	}
	return ;
}
map<char,int> b,c,d[1005];
int T,f1[10005],ans,t2[10005];
string st;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
prework();
//int maxn=0;
//for (int i=1;i<=1000;i++) maxn=max(maxn,a[i][0]);
//cout<<maxn<<endl;
T=read();
while (T--){
	memset(f1,0,sizeof(f1));
	st="";
	ans=0;
	cin>>st;
	if (st.size()<=1000){
		int s=st.size();
		string st1,st2;
		for (int i=0;i<st.size();i++){
			st1="";st2="";f1[i+1]=st.size()/(i+1);
			for (int j=0;j<=i;j++) st1+=st[j];
			for (int j=i+1,l=1;j+i+1<=s;j+=i+1,l++){
				int f=1;
				for (int k=j;k<=j+i;k++) if (st[k]!=st1[k-j]) {
					f=-1;
					break;
				}
				if (f==-1) {
					f1[i+1]=l;
					break;
				}
			}
		}
		for (char j='a';j<='z';j++) c[j]=0;
		t2[0]=1;c[st[0]]++;
		for (int i=1;i<st.size();i++) {
			c[st[i]]++;
			if (c[st[i]]%2==0) t2[i]=t2[i-1]-1;else t2[i]=t2[i-1]+1;
		}
//		for (int i=0;i<st.size();i++) cout<<t2[i]<<' ';
//		cout<<endl;
		for (char j='a';j<='z';j++) c[j]=0;
//		for (int i=0;i<st.size();i++)
//		for (int j=0;j<st.size();j++) r[i][t2[j]]
		for (int i=2;i<st.size();i++){
			int t=0;
			for (char j='a';j<='z';j++) b[j]=c[j]=0;
			for (int j=i;j<st.size();j++) b[st[j]]++;
//			for (char j='a';j<='z';j++) cout<<b[j]<<' ';
//			cout<<endl;
			for (char j='a';j<='z';j++) if (b[j]%2==1) t++;
//			cout<<"i t:"<<i<<' '<<t<<endl<<endl;
			for (int j=1;j<=a[i][0];j++){
//				cout<<j<<endl<<endl;
				for (char k='a';k<='z';k++) c[k]=0;
				int t1=0;
				if (f1[a[i][j]]<i/a[i][j]) continue;
				for (int k=0;k<min(a[i][j]-1,i-1);k++) {
//					c[st[k]]++;
//					if (c[st[k]]%2==0) t1--;
//					else t1++;
					if (t2[k]<=t) ans++;
//					cout<<"k ans:"<<k<<' '<<t1<<' '<<ans<<endl;
				}
//				cout<<"j a[i][j] ans:"<<j<<' '<<a[i][j]<<' '<<ans<<endl;
			}
//			cout<<i<<' '<<ans<<endl<<endl;
		}
		cout<<ans<<endl;
	}
}
	return 0;
}
/*

3
nnrnnr
zzzaab
mmlmmlo
*/
