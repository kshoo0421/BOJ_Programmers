#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> arr, memo;
int n, m, max_val, all_op[8];

int xp3(const int& x, const int& y)
{
	if (x + 3 >= m) return 0;
	return arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y][x + 3];
}

int yp3(const int& x, const int& y)
{
	if (y + 3 >= n) return 0;
	return arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 3][x];
}

int xp1yp1(const int& x, const int& y)
{
	if (x + 1 >= m || y + 1 >= n) return 0;
	return arr[y][x] + arr[y + 1][x] + arr[y][x + 1] + arr[y + 1][x + 1];
}

int xp2yp1(const int& x, const int& y)
{
	int temp[5];
	if (x + 2 >= m || y + 1 >= n) return 0;
	temp[0] = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 2];
	temp[1] = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x + 1];
	temp[2] = arr[y][x] + arr[y][x + 1] + arr[y][x + 2] + arr[y + 1][x];
	temp[3] = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 1][x + 2];
	temp[4] = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 1][x + 2];
	sort(temp, temp + 5, greater<int>());
	return temp[0];
}

int xp1yp2(const int& x, const int& y)
{
	int temp[5];
	if (x + 1 >= m || y + 2 >= n) return 0;
	temp[0] = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x + 1];
	temp[1] = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x + 1];
	temp[2] = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y][x + 1];
	temp[3] = arr[y][x] + arr[y + 1][x] + arr[y + 1][x + 1] + arr[y + 2][x + 1];
	temp[4] = arr[y][x] + arr[y][x + 1] + arr[y + 1][x + 1] + arr[y + 2][x + 1];
	sort(temp, temp + 5, greater<int>());
	return temp[0];
}

int xm1yp2(const int& x, const int& y)
{
	int temp[3];
	if (x - 1 < 0 || y + 2 >= n) return 0;
	temp[0] = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 2][x - 1];
	temp[1] = arr[y][x] + arr[y + 1][x] + arr[y + 2][x] + arr[y + 1][x - 1];
	temp[2] = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 2][x - 1];
	sort(temp, temp + 3, greater<int>());
	return temp[0];
}

int xm2yp1(const int& x, const int& y)
{
	if (x - 2 < 0 || y + 1 >= n) return 0;
	return arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 1][x - 2];
}

int xpm1yp1(const int& x, const int& y)
{
	int temp[2];
	if (x - 1 < 0 || x + 1 >= m || y + 1 >= n) return 0;
	temp[0] = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y][x + 1];
	temp[1] = arr[y][x] + arr[y + 1][x] + arr[y + 1][x - 1] + arr[y + 1][x + 1];
	sort(temp, temp + 2, greater<int>());
	return temp[0];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	vector<int> temp(m);
	arr.resize(n), memo.resize(n);
	for (int i = 0; i < n; i++) arr[i] = temp, memo[i] = temp;
	for (auto& i : arr) for (int& j : i) cin >> j;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			all_op[0] = xm1yp2(x, y);
			all_op[1] = xm2yp1(x, y);
			all_op[2] = xp1yp1(x, y);
			all_op[3] = xp1yp2(x, y);
			all_op[4] = xp2yp1(x, y);
			all_op[5] = xp3(x, y);
			all_op[6] = xpm1yp1(x, y);
			all_op[7] = yp3(x, y);
			sort(all_op, all_op + 8, greater<int>());
			memo[y][x] = all_op[0];
		}
	}
	max_val = 0;
	for (auto i : memo) for (int j : i) if (max_val < j) max_val = j;
	cout << max_val;
	return 0;
}