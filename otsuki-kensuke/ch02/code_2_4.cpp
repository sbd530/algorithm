#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//두점 (x1,y1), (x2,y2) 사이 거리를 구하는 함수
double calc_dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1-y2) * (y1 - y2));
}

int main() {
	int N; cin >> N;
	vector<double> x(N), y(N);
	for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];

	double minimum_dist = 100000000.0;

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			double dist_i_j = calc_dist(x[i], y[i], x[j], y[j]);

			if (dist_i_j < minimum_dist) {
				minimum_dist = dist_i_j;
			}
		}
	}

	cout << minimum_dist << endl;
}