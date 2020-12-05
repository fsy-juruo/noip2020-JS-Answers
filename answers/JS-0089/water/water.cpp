#include<bits/stdc++.h>

using namespace std;

struct PP {
	int fz;
	int fm;
} res[1005];

int n, m;
int inTubeID;
vector<int> a[1005];
bool IDs[1005];

deque<int> q;

void init() {
	PP p;
	p.fm = 1;
	for (int i = 1; i <= 20; i++) {
		IDs[i] = true;
		res[i] = p;
	}
}

PP Add(PP a, PP b) {
	int fm = a.fm * b.fm;
	int fz = b.fm * a.fz + a.fm * b.fz;
	int gcd = __gcd(fm, fz);
	PP res;
	res.fm = fm / gcd;
	res.fz = fz / gcd;
	return res;
}


void input() {
	scanf("%d%d", &n, &m);
//	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d", &x);
//		cin >> x;
		for (int j = 0; j < x; j++) {
			scanf("%d", &y);
//			cin >> y;
//			cout << x << ' ' << y << endl;
			IDs[y] = false;
			a[i].push_back(y);
		}
	}
	for (int i = 1; i <= n; i++)
		if (IDs[i] == true) {
			inTubeID = i;
			break;
		}
}

void flow() {
	while (q.size() != 0) {
		int id = q.front();
		q.pop_front();
		PP p;
		p.fz = res[id].fz;
		p.fm = res[id].fm * a[id].size();
		for (int i = 0; i < a[id].size(); i++) {
			res[a[id][i]] = Add(res[a[id][i]], p);
			if (a[id].size() != 0) {
				q.push_back(a[id][i]);
				res[id].fz = 0;
				res[id].fm = 1;
			}
		}
	}

}


int main() {
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout); // wrong output
	init();
	input();
	//cout << n << ' ' << m;
	res[inTubeID].fz = 1;
	q.push_back(inTubeID);
	flow();
	for (int i = 1; i <= n; i++) {
		if (a[i].size() == 0) {
			//cout << res[4].fz << res[4].fm;
//			cout << res[i].fz << endl;
//			int fz = res[i].fz; // wrong value pass to fz
//			cout << fz << endl; // wrong output
//			int fm = res[i].fm;
//			cout << fz << ' ' << fm << endl; // error when output alone 
//			cout << r.fz << endl;
//			printf("%d %d\n", res[i].fz, res[i].fm); // error when output alone 
			cout << res[i].fz << ' ' << res[i].fm << endl; // correct using this
		}
		// the code is run correctly only when using without freopen and using the statement at 98 line
		// its pretty strange that i never meet the situation like this before
		// god bless me 
	}
	return 0;
}
