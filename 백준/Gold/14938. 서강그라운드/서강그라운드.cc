#include <bits/stdc++.h>
#define POS first
#define DIST second
using namespace std;

struct Region {
	bool isVisited;
	vector<pair<int, int>> posDist;
	int itemVal;
};

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		if (a.DIST == b.DIST) return a.POS > b.POS;
		return a.DIST > b.DIST;
	}
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, r, a, b, l, curPos, curDist;
	cin >> n >> m >> r;
	vector<int> sum(n, 0);
	vector<Region> regions(n);
	for (auto& r : regions) cin >> r.itemVal;
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		regions[a - 1].posDist.emplace_back(make_pair(b - 1, l));
		regions[b - 1].posDist.emplace_back(make_pair(a - 1, l));
	}
	for (int i = 0; i < n; i++) {
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
		for (auto& r : regions) r.isVisited = false;
		pq.push(make_pair(i, 0));
		while (!pq.empty()) {
			curPos = pq.top().POS;
			curDist = pq.top().DIST;
			pq.pop();
			if (regions[curPos].isVisited) continue;
			regions[curPos].isVisited = true;
			sum[i] += regions[curPos].itemVal;
			for (auto& pii : regions[curPos].posDist) {
				if (!regions[pii.POS].isVisited && (pii.DIST + curDist <= m)) {
					pq.push(make_pair(pii.POS, pii.DIST + curDist));
				}
			}
		}
	}
	cout << *max_element(sum.begin(), sum.end());
}