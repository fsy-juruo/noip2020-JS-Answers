#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int mcol;
	int mnum;//mian color.num
	int col[402];
	int num;
};
node a[52];
bool www(node XX,node YY){
	//if(XX.mnum>YY.mnum) return XX.mcol>YY.mcol;
	return XX.mnum>YY.mnum;
}
vector <pair<int,int> > ste;


int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		//cin>>a[i].col[1];
		bool pdd=true;
		//a[i].mcol=a[i].col[1];
		for(int j=1;j<=m;++j){
			cin>>a[i].col[j];
		}
		a[i].mcol=a[i].col[1];
		for(int j=1;j<=m;++j){
			if(a[i].col[j] != a[i].mcol) break;
			++a[i].mnum;
		}
		a[i].num=m;
	}
	sort(a+1,a+n+1,www);
	
//	for(int i=1;i<=n;++i){
//		cout<<a[i].mcol<<' '<<a[i].mnum<<endl;
//	}
	
	if(n == 2){
		for(int i=a[1].num;i>a[1].mnum;--i){
			ste.push_back(make_pair(1,3));
			a[3].col[a[1].num-i+1] = a[i].col[i];
			a[1].col[i]=0;
			a[1].num--;
			a[3].num++;
		}
		for(int i=a[2].num;i>a[2].mnum;--i){
			if(a[2].col[i] == a[1].mcol){
				ste.push_back(make_pair(2,1));
			}
			else{
				ste.push_back(make_pair(2,3));
				a[3].col[a[2].num-i+1] = a[i].col[i];
				a[2].col[i]=0;
				a[2].num--;
				a[3].num++;
			}
		}
		for(int i=a[3].num;i>=1;--i){
			if(a[3].col[i] == a[1].mcol){
				ste.push_back(make_pair(3,1));
			}
			else{
				ste.push_back(make_pair(3,2));
				
			}
		}
		
		cout<<ste.size()<<endl;
		for(int i=0;i<ste.size();++i){
			cout<<ste[i].first<<' '<<ste[i].second<<endl;
		}
	}
	else{
		for(int i=a[1].num;i>a[1].mnum;--i){
			ste.push_back(make_pair(1,3));
			a[3].col[a[1].num-i+1] = a[i].col[i];
			a[1].col[i]=0;
			a[1].num--;
			a[3].num++;
		}
		for(int i=a[2].num;i>a[2].mnum;--i){
			if(a[2].col[i] == a[1].mcol){
				ste.push_back(make_pair(2,1));
			}
			else{
				ste.push_back(make_pair(2,3));
				a[3].col[a[2].num-i+1] = a[i].col[i];
				a[2].col[i]=0;
				a[2].num--;
				a[3].num++;
			}
		}
		for(int i=a[3].num;i>=1;--i){
			if(a[3].col[i] == a[1].mcol){
				ste.push_back(make_pair(3,1));
			}
			else{
				ste.push_back(make_pair(3,2));
				
			}
		}
		
		cout<<ste.size()<<endl;
		for(int i=0;i<ste.size();++i){
			cout<<ste[i].first<<' '<<ste[i].second<<endl;
		}
	}
	return 0;
}

