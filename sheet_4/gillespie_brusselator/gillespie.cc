#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <ctime>


double get_random() {// uniform random number between 0 and 1
	return ((double) rand() / (RAND_MAX));
}

double get_random_expo(const double lambda) {// random number from exponential distribution with parameter lambda
	return -1./lambda * log(get_random());
}
int main() {
	srand (time(NULL));
	const double omega = 1000;
	const double b = 1.8;
	double nx = 100.;
	double ny = 100.;// initial conditions from before
	const double tf = 60;
	double t = 0;
	std::ofstream myfile;
	myfile.open("data/out_x.dat");
	std::ofstream myfile2;
	myfile2.open("data/out_y.dat");
	std::ofstream myfile3;
	myfile3.open("data/out_xy.dat");

	while (t < tf) {
		const double w1 = omega;
		const double w2 = nx;
		const double w3 = b * nx;
		const double w4 = pow(nx, 2.) * ny / pow(omega, 2.);
		const double lambda = w1 + w2 + w3 + w4;
		t += get_random_expo(lambda);
		const double r = get_random() * lambda;
		if (r < w1) {
			++nx;
		}
		else if (r <= w1 + w2) {
			--nx;
		}
		else if (r <= w1 + w2 + w3) {
			--nx;
			++ny;
		}
		else if (r <= w1 + w2 + w3 + w4) {
			++nx;
			--ny;
		}
		myfile << t << " " << nx / omega << std::endl;
		myfile2 << t << " " << ny / omega << std::endl;
		myfile3 << nx / omega << " " << ny / omega << std::endl;
	}
	myfile.close();
	myfile2.close();
	myfile3.close();
	return 0;
}
