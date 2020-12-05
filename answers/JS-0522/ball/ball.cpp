#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define fn "ball"
int n,m,D[52],sydd,H[52],jb[52];
LL ans=0;

stack<int> akk[52];

inline int read(){
	int xs=0,ys=1;char ss=getchar();
	while(ss<'0'||ss>'9'){if(ss=='-')ys=-1;ss=getchar();}
	while(ss>='0'&&ss<='9'){xs=xs*10+ss-'0';ss=getchar();}
	return xs*ys;
}

queue<pair<int,int> > qq;

void yd(int zhz){
	while(akk[zhz].size()>D[zhz]){
		akk[n+1].push(akk[zhz].top());
	//	cout<<zhz<<" "<<n+1<<endl;
		qq.push(make_pair(zhz,n+1));
		++ans;
		akk[zhz].pop();
	}
	for(int i=1;i<=n;++i){
		if(i^zhz){
			while(akk[i].top()==zhz){
				akk[i].pop();
				akk[zhz].push(zhz);
				++D[zhz];
			//	cout<<i<<" "<<zhz<<endl;
				qq.push(make_pair(i,zhz));
				++ans;
			}
			while(akk[i].size()<m){
				if(akk[n+1].top()==i) ++D[i];
				akk[i].push(akk[n+1].top());
				akk[n+1].pop();
				qq.push(make_pair(n+1,i));
			//	cout<<n+1<<" "<<i<<endl;
				++ans;
			}
		}
//		cout<<D[zhz]<<endl;
	}
	while(akk[n+1].size()){
	//	cout<<n+1<<" "<<zhz<<endl;
		qq.push(make_pair(n+1,zhz));
		++ans;
		if(akk[n+1].top()==zhz) ++D[zhz];
		akk[zhz].push(akk[n+1].top());
		akk[n+1].pop();//cout<<D[zhz]<<endl;
	}
}

int main(){
	freopen(fn".in","r",stdin);
	freopen(fn".out","w",stdout);
	n=read(),m=read();
	sydd=n*m;
	for(int i=1;i<=n;++i) {
		int aa=0;
		for(int j=1;j<=m;++j) {
			int tmp=read();
			if(tmp==i&&aa==j-1)++aa;
			akk[i].push(tmp);
		}
		D[i]=aa;
		H[i]=m;
		sydd-=aa;
	}
//	for(int i=1;i<=n;++i) cout<<D[i]<<endl;
	while(sydd){
		int matrix=0,maxx=0;
	//	cout<<" "<<D[1]<<" "<<D[2]<<endl;
		memset(jb,0,sizeof(jb));
		for(int i=1;i<=n;++i) {
			if(D[i]<m) ++jb[akk[i].top()];
		}
		for(int i=1;i<=n;++i) if(jb[i]>matrix)matrix=jb[i],maxx=i;
	//	cout<<maxx<<endl;
		yd(maxx);
		bool aaa=true;
		for(int i=1;i<=n;++i){
			if(D[i]<m)aaa=false;
		}
		if(aaa) break;
	}
	cout<<ans<<endl;
	while(qq.size()){
		cout<<qq.front().first<<" "<<qq.front().second<<endl;
		qq.pop();
	}
	return 0;
}

