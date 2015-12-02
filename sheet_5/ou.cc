// simulation of long term dynamics of Ornstein - Uhlenbeck process
// Simplification: x' = -x + eta(t)
// eta(t) is Gaussian white noise with <eta(t)> = 0 and <eta(t) * eta(T)> = delta (t-T)
// In long run, exact solution gives <x> = 0 and <x^2> = 0.5

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <random>
#include <cmath>
#include <vector>

double gauss() {
	std::random_device rd;
    std::mt19937 e2(rd());
    std::normal_distribution<double> dist(0., 1.);
	return dist(rd);
}

double mean(const std::vector<double> &vec) {// too inefficient for a running average
	int n = 0;
	double count = 0;
	for (auto it = vec.begin(); it != vec.end(); ++it) {
		count += *it;
		++n;
	}
	return (double) count / n;
}

int main() {
	std::ofstream file, file2;
	file.open("plots/out.dat");
	file2.open("plots/out2.dat");
	const double dt = 0.01;
	const double tf = 1000;
	double t = 0.;
	double x = 0;// initial conditions
	//std::vector <double> results_x;
	//std::vector <double> results_xSq;

	double avg_x = 0;
	double avg_xSq = 0;
	int count = 0;

	while (t < tf) {
		++count;
		if (count % 50 == 0) {
			file << t << " " << avg_x << std::endl;
			file2 << t << " " << avg_xSq << std::endl;
		}
		x = x - dt * x + sqrt(dt) * gauss();
		t += dt;
		avg_x =  (double) (avg_x * count + x) / (count + 1);// calculate running averages of x and xSq
		avg_xSq = (double) (avg_xSq * count + x * x) / (count + 1);
	}
	std::cout << "done!" << std::endl;
	file.close();
	file2.close();
	return 0;
}
