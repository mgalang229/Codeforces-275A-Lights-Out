#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<vector<int>> a(3, vector<int>(3));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	// create 'res' vector with 3 x 3 size and set all values of the cells to 1
	vector<vector<int>> res(3, vector<int>(3, 1));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			// if the current value in 'a' vector is odd, then change the value of current 
			// element in 'res' vector, otherwise do not change its value
			res[i][j] = (a[i][j] & 1 ? !res[i][j] : res[i][j]);
			if (i > 0) {
				// same principle applies on the ('i' - 1) adjacent cell
				res[i - 1][j] = (a[i][j] & 1 ? !res[i - 1][j] : res[i - 1][j]);
			}
			if (i < 2) {
				// same principle applies on the ('i' + 1) adjacent cell
				res[i + 1][j] = (a[i][j] & 1 ? !res[i + 1][j] : res[i + 1][j]);
			}
			if (j > 0) {
				// same principle applies on the ('j' - 1) adjacent cell
				res[i][j - 1] = (a[i][j] & 1 ? !res[i][j - 1] : res[i][j - 1]);
			}
			if (j < 2) {
				// same principle applies on the ('j' + 1) adjacent cell
				res[i][j + 1] = (a[i][j] & 1 ? !res[i][j + 1] : res[i][j + 1]);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << res[i][j];
		}
		cout << '\n';
	}
	return 0;
}
