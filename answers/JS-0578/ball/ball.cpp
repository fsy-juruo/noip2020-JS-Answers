#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T& FF){
	FF=0;T RR=1;char CH=getchar();
	for(;!isdigit(CH);CH=getchar())if(CH=='-')RR=-1;
	for(;isdigit(CH);CH=getchar())FF=(FF<<1)+(FF<<3)+(CH^48);
	FF*=RR;
}
deque<int>q[55];
vector<pair<int,int> >v;
int n,m;
//void work(){
//	for(int i=1;i<=n+1;i++){
//		for(int j=0;j<q[i].size();j++)
//			cout<<q[i][j]<<" ";
//		cout<<endl;
//	}
//}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;read(x);
			q[i].push_front(x);
		}
	}
	for(int i=1;i<n;i++){
//		cout<<i<<endl;
		for(int j=1;j<m;j++){
			v.push_back(make_pair(i,n+1));
			q[n+1].push_front(q[i].front());
//			cout<<q[i].front()<<" "<<q[n+1].front()<<endl;
			q[i].pop_front();
		}
		for(int j=i+1;j<=n;j++){
//			cout<<" "<<j<<endl;
			while(1){
				bool flag=true;
				for(unsigned k=0;k<q[j].size();k++)
					if(q[j][k]==q[i].back()){
						flag=false;
						break;
					}
				if(flag)break;
				/*while(q[j].size()){
					v.push_back(make_pair(j,i));
					q[i].push_front(q[j].front());
					q[j].pop_front();
				}
				v.push_back(make_pair(j,n+1));
				q[n+1].push_front(q[j].front());
				q[j].pop_front();
				while(q[i].front()!=q[i].back()){
					v.push_back(make_pair(i,j));
					q[j].push_front(q[i].front());
					q[i].pop_front();
				}
				v.push_back(make_pair(n+1,i));
				q[i].push_front(q[n+1].front());
				q[n+1].pop_front();*/
				while(q[j].front()!=q[i].back()){
					for(int k=i;k<=n;k++){
						if(q[k].size()<m){
							v.push_back(make_pair(j,k));
							q[k].push_front(q[j].front());
							q[j].pop_front();
							break;
						}
					}
//					if(q[i].size()>m){
//						cout<<i<<" "<<q[i].size()<<endl;
//					}
				}
				v.push_back(make_pair(j,n+1));
				q[n+1].push_front(q[j].front());
				q[j].pop_front();
				while(q[i].front()!=q[i].back()){
					v.push_back(make_pair(i,j));
					q[j].push_front(q[i].front());
					q[i].pop_front();
				}
				v.push_back(make_pair(n+1,i));
				q[i].push_front(q[n+1].front());
				q[n+1].pop_front();
			}
		}
//		if(i==2)work();
//		if(i==2)return 0;
//		int s=0;
		while(q[n+1].size()){
//			cout<<i<<" "<<q[n+1].front()<<endl;
//			cout<<i<<"  ";for(int i=1;i<=n+1;i++)cout<<q[i].size()<<" ";cout<<endl;
//			if(++s>200)return 0;
//			cout<<q[n+1].front()<<endl;
			if(q[n+1].front()==q[i].back()){
				v.push_back(make_pair(n+1,i));
				q[i].push_front(q[n+1].front());
				q[n+1].pop_front();
			}else{
				for(int j=i+1;j<=n;j++)
					if(q[j].size()<m){
						v.push_back(make_pair(n+1,j));
						q[j].push_front(q[n+1].front());
						q[n+1].pop_front();
						break;
					}
			}
		}
	}
	cout<<v.size()<<endl;
	for(unsigned i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
	return 0;
}

