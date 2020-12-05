#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
int ball[55][405];
int cnt[55];
bool Ret = 0;
list<pair<int, int> > movement;
pair<int, int> mb;
inline void Move(int From, int To) {
  int Top = ball[From][cnt[From]];
  cnt[From] -- ;
  cnt[To] ++ ;
  ball[To][cnt[To]] = Top;
  movement.push_back(make_pair(From, To));
  mb = make_pair(From, To);
}
inline bool ok() {
  set<int> sc;
  for(int i = 2; i <= n; i++) {
    if(cnt[i]) sc.insert(cnt[i]);
    if(sc.size() > 1) return 0;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 2; j <= cnt[i]; j++) {
      if(ball[i][j] != ball[i][j-1]) return 0;
    }
  }
  return 1;
}
void dfs(int dep, int maxdeep) {
  if(Ret) return;
  if(dep > maxdeep) return;
  if(ok()) {
    cout << movement.size() << endl;
    for(list<pair<int, int> >::iterator it
         = movement.begin(); it != movement.end();
        it ++ )
      cout << it->first << " " 
           << it->second << endl;
    Ret = 1;
    return;
  }
  pair<int, int> order[55];
  for(int i = 1; i <= n; i++) 
    order[i] = make_pair(cnt[i], i);
  sort(order + 1, order + 1 + n, greater<pair<int, int> >());
  for(int ii = 1; ii <= n; ii++)
    for(int ij = n; ij >= 1; ij--) {
      int i = order[ii].second,
          j = order[ij].second;
      if(i == j || make_pair(j, i) == mb)
        continue;
      if(!cnt[i] || cnt[j] > m - 1) continue;
      Move(i, j);
      dfs(dep + 1, maxdeep);
      if(Ret) return;
      Move(j, i); 
      movement.pop_back();
      movement.pop_back();
    }
}
int main() {
  freopen("ball.in", "r", stdin);
  freopen("ball.out", "w", stdout);
  cin >> n >> m;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> ball[i][j];
  fill(cnt + 1, cnt + 1 + n, m);
  bool f;
  for(int i = 1; i <= n; i++) {
    f = 1;
    for(int j = 2; j <= m; j++)
      if(ball[i][j] != ball[i][j-1]) {
        f = 0; break;
      }
    if(!f) break;
  }
  if(f) { cout << "0\n"; return 0; }
  n ++ ;
  for(int d = 0; d <= 20; d ++ )
    for(int i = 1; i < n; i++) {
      Move(i, n);
      dfs(1, min(1 << d, 820000));
      if(Ret) return 0;
      Move(n, i);
      movement.pop_back();
      movement.pop_back();
    }
  return 0;
}
