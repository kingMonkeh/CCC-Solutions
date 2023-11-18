#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

vi par;

int root (int x){
	if (par[x] == x) return x;
	else return par[x] = root(par[x]);
}

void Union (int a, int b){
	a = root(a);
	b = root(b);
	par[b] = a;
}

signed main (){

	int n, m;
	std::cin >> n >> m;

	par.resize(n + 1);
	for (int i = 1; i <= n; i++) par[i] = i;

	std::vector<vi> roads (m);

	for (int i = 0; i < m; i++){
		roads[i].resize(3);
		for (int j = 0; j < 3; j++) std::cin >> roads[i][j];
	}

	std::sort(roads.begin(), roads.end(), [](vi& a, vi& b){
		return a[2] < b[2];
	});

	int roads_used = 0;
	int ans = 0;
	for (auto& road: roads){
		if (root(road[0]) != root(road[1])){
			roads_used++;
			ans += road[2];
			Union(road[0], road[1]);
		}
		if (roads_used == n - 1){
			std::cout << ans;
			return 0;
		}
	}

	std::cout << "IMPOSSIBLE";

	return 0;

}