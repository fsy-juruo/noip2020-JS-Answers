#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

const int MAX_N=55;
const int MAX_M=410;

stack <int> s[MAX_N];
int N,M;
vector <pair<int,int> > ans;

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int x; scanf("%d",&x); x--;
			s[i].push(x);
		}
	}
	for(int i=0;i<N;i++){
		while(!s[i].empty()){
			int x=s[i].top(); s[i].pop(); 
			if(s[i].empty()){
				s[i].push(x);
				break;
			}
			else{
				ans.pb(mp(i,N));
				s[N].push(x);
			}
		}
		int c=s[i].top();
	//	cout<<c<<endl;
		for(int j=i+1;j<N;j++){
			while(true){
				vector <int> v;
				while(!s[j].empty()){
				//	cout<<"here"<<endl;
					if(s[j].top()==c) break;
					v.pb(s[j].top()); s[j].pop();
				}
			//	cout<<j<<endl;	
			//	for(int k=0;k<v.size();k++) cout<<v[k]+1<<" "; cout<<endl;
				if(s[j].empty()){
					for(int k=v.size()-1;k>=0;k--) s[j].push(v[k]);
					while(s[j].size()+1<M&&(!s[N].empty())){
						if(s[N].top()==c){
							s[i].push(s[N].top());
							ans.pb(mp(N,i));
						}
						else{
							s[j].push(s[N].top());
							ans.pb(mp(N,j));
						}
						s[N].pop();
					}
					while((!s[N].empty())&&(s[N].top()==c)){
						s[i].push(s[N].top()); s[N].pop();
						ans.pb(mp(N,i));
					}
					break;
				}
				else{
					int sumN=0,sumi=0;
					for(int k=0;k<v.size();k++){
						if(s[N].size()+1<M){
							s[N].push(v[k]);
							ans.pb(mp(j,N));
							sumN++;
						}
						else{
							s[i].push(v[k]);
							ans.pb(mp(j,i));
							sumi++;
						}
					}
					s[N].push(s[j].top()); s[j].pop(); ans.pb(mp(j,N));
					while(sumi--){
						s[j].push(s[i].top()); s[i].pop();
						ans.pb(mp(i,j));
					}
					s[i].push(s[N].top()); s[N].pop(); ans.pb(mp(N,i));
					while(sumN--){
						s[j].push(s[N].top()); s[N].pop();
						ans.pb(mp(N,j));
					}
				}
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first+1,ans[i].second+1);
	return 0;
}
