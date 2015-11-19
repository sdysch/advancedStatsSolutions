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
	const double omega = 1000;
	const double b = 1.8;
	double nx = 1.;
	double ny = 1.;// initial conditions from before
	const double tf = 600;
	double t = 0;
	std::ofstream myfile;
	myfile.open("out.dat");

	while (t < tf) {
		const double w1 = omega;
		const double w2 = nx;
		const double w3 = b * nx;
		const double w4 = pow(nx, 2.) * ny / pow(omega, 2.);
		if (nx > 0) {
			const double lambda = w1 + w2 + w3;
			t += get_random_expo(lambda);
			const double r = get_random();
			if (r < w1 / lambda) {
				++nx;
			}
			else if (w1 / lambda < r <= w1 / lambda + w2 / lambda) {
				--nx;
			}
			else if (w1 / lambda + w2 / lambda < r <= w1 / lambda + w2 / lambda + w3 / lambda) {
				--nx;
				++ny;
			}
		}
		else if (nx > 1 && ny > 0) {
		const double lambda = w1 + w2 + w3;
			t += get_random_expo(lambda);
			const double r = get_random();
			if (r < w1 / lambda) {
				++nx;
			}
			else if (w1 / lambda < r <= w1 / lambda + w2 / lambda) {
				--nx;
			}
			else if (w1 / lambda + w2 / lambda < r <= w1 / lambda + w2 / lambda + w3 / lambda) {
				--nx;
				++ny;
			}
			else if (w1 / lambda + w2 / lambda + w3 / lambda < r <= w1 / lambda + w2 / lambda + w3 / lambda + w4 / lambda) {
				++nx;
				--ny;
			}
		}
		else {// nx = ny = 0
			const double lambda = w1;
			t += get_random_expo(lambda);
			++nx;
		}
		myfile << ny / omega << " " << t << std::endl;
		std::cout << t << std::endl;
	}
	myfile.close();
	return 0;
}
