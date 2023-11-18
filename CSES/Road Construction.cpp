#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

/*

*/

vi par, sz;

int root (int x){
	if (par[x] == x) return x;
	else return par[x] = root(par[x]);
}

int Union (int a, int b){
	a = root(a);
	b = root(b);
	par[b] = a;
	if (a != b) sz[a] = sz[a] + sz[b];
	return sz[a];
}

signed main (){

	int n, m;
	std::cin >> n >> m;

	par.resize(n + 1);
	for (int i = 1; i <= n; i++) par[i] = i;

	sz.resize(n + 1, 1);

	std::vector<vi> roads (m);

	for (int i = 0; i < m; i++){
		roads[i].resize(2);
		for (int j = 0; j < 2; j++) std::cin >> roads[i][j];
	}

	int components = n, biggest = 1;
	for (auto& road: roads){
		if (root(road[0]) != root(road[1])){
			components--;
		}
		biggest = std::max(biggest, Union(road[0], road[1]));
		std::cout << components << ' ' << biggest << '\n';
	}

	return 0;

}