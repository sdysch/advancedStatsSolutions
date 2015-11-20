#include <iostream>
#include <cmath>
#include <random>
#include <fstream>

double get_random() {// uniform random number between 0 and 1
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0., 1.);
	return dis(gen);
}

double get_random_expo(const double lambda) {// random number from exponential distribution with parameter lambda
	return -1./lambda * log(get_random());
}

int main() {
	const int N = 100;
	const double tf = 5000;
	std::ofstream myfile;
	myfile.open("data/out_0p9.dat");
	int n = 90;
	double t = 0;

	while (t < tf) {
		const double wp = (double) n * pow(N - n, 2.) / pow(N, 3.);
		const double wm = (double) pow(n, 2.) * (N - n) / pow(N, 3.);
		const double lambda = wp + wm;
		t += get_random_expo(lambda);
		const double r = get_random() * lambda;
		if (r < wp) {
			++n;
		}
		else if (r < wp + wm) {
			--n;
		}
		myfile << t << " " << (double) n / N << std::endl;
	}
	myfile.close();
	return 0;
}
