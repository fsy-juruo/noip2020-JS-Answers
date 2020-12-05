#include<bits/stdc++.h>
using namespace std;
void read(int &sum){
	sum=0;char ch=getchar();int p=1;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')p=-1;
	for(; isdigit(ch);ch=getchar())sum=sum*10+ch-48;
	sum*=p;
}
void write(int sum){
	if(sum<0){
		putchar('-');
		sum=0-sum;
	}
	if(sum>9){
		write(sum/10);
		sum%=10;
	}
	putchar(sum+48);
}
void writek(int sum){
	write(sum);
	putchar(' ');
}
void writeln(int sum){
	write(sum);
	putchar('\n');
}
map<vector<vector<int> >,bool>ma;
deque<vector<vector<int> > >q;
deque<int>px,py,p,pxx,pyy;
vector<vector<int> >v,w;
vector<int>emp;
int n,m;
bool check(){
	int i,j;
	for(i=0;i<n;i++){
		if(w[i].size()!=m){
			return false;
		}
		int x=w[i][0];
		for(j=1;j<m;j++){
			if(w[i][j]!=x){
				return false;
			}
		}
	}
	return true;
}
void work(){
	int i=px.size()-1;
//	cout<<i<<endl;
	while(p[i]!=-1){
		pxx.push_back(px[i]);
		pyy.push_back(py[i]);
//		cout<<i<<' '<<px[i]<<' '<<py[i]<<endl;
		i=p[i];
	}
	writeln(pxx.size());
	for(i=pxx.size()-1;i>=0;i--){
		writek(pxx[i]);
		writeln(pyy[i]);
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	int i,j,x,tot;
	for(i=1;i<=n;i++){
		v.push_back(emp);
		for(j=1;j<=m;j++){
			read(x);
			v[i-1].push_back(x);
		}
	}
	v.push_back(emp);
//	cout<<v.size()<<endl;
	ma[v]=1;
	q.push_back(v);
	px.push_back(0);
	py.push_back(0);
	p.push_back(-1);
	v.clear();
	tot=-1;
//	dis.push_back(0);
	while(!q.empty()){
		v=q.front();
//int 		dist=dis.front();
//		dis.pop_front();
//		cout<<dist<<endl;
//		cout<<v.size()<<endl;
//		for(i=0;i<=n;i++){
//			
//			for(j=1;j<=v[i].size();j++){
////				cout<<i<<' '<<j<<endl;
//				cout<<v[i][j-1]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<"FUCK"<<endl;
		tot++;
//		cout<<px[tot]<<' '<<py[tot]<<' '<<p[tot]<<endl<<endl;;
		q.pop_front();
		for(i=0;i<=n;i++){
			if(v[i].size()==0){
				continue;
			}
//			cout<<"FUCK"<<endl;
			for(j=0;j<=n;j++){
//				cout<<i<<' '<<j<<endl;
				if(v[j].size()==m){
					continue;
				}
//				cout<<i<<' '<<j<<endl;
//				cout<<"FUCL"<<endl;
				w=v;
				int x=w[i].back();
				w[i].pop_back();
				w[j].push_back(x);
				if(ma.find(w)==ma.end()){
					ma[w]=1;
					q.push_back(w);
					px.push_back(i+1);
					py.push_back(j+1);
					p.push_back(tot);
//					dis.push_back(dist+1);
					if(check()){
						work();
						return 0;
					}
				}
//				cout<<"FUCK"<<endl;
			}
		}
	}
	return 0;
}

