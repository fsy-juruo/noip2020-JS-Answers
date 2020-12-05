#include <fstream>
using namespace std;

ifstream cin("ball.in");
ofstream cout("ball.out");
int cor[56][450],cnt[56];
int out[820005][2],ans;
int n,m;
inline void print(int a,int b){
	out[ans][0]=a;
	out[ans][1]=b;
	ans++;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>cor[i][j];
			cnt[i]++;
		} 
	}
	int pick_c=cor[1][cnt[1]];
	print(1,3);
	cnt[1]--;
	for(int i=cnt[2];i>=1;i--){
		if(cor[2][i]==pick_c){
			int y_cnt=cnt[2];
			for(int j=y_cnt;j>i;j--){
				print(2,3);
			}
			print(2,1);
			for(int j=y_cnt;j>i;j--){
				print(3,2);
			}
			print(1,3);
			cnt[2]--;
		}
	}
	for(int i=cnt[1];i>=1;i--){
		if(cor[1][i]==pick_c){
			print(1,3);
		}else{
			print(1,2);
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<ans;i++){
		cout<<out[i][0]<<" "<<out[i][1]<<endl;
	}
	return 0;
}

