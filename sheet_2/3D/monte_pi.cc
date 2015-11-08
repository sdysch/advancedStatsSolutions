#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include <iomanip>

double gen_rand() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0., 1.);
	return dis(gen);
}

bool in_sphere(const double x, const double y, const double z) {
	if (pow(x, 2.) + pow(y, 2.) + pow(z, 2.) <= 1) return true;
	else return false;
}

int main() {
	const double pi = 3.141592654;
	std::ofstream myfile1, myfile2;
	myfile1.open("out_normal.dat");
	myfile2.open("out_div_pi.dat");
	int number_generated = 0;
	int number_in_sphere = 0;
	const int iterations = 500000;

	for (int i = 0; i < iterations; ++i) {
		const double xt = gen_rand();
		const double yt = gen_rand();
		const double zt = gen_rand();
		++number_generated;
		if (in_sphere(xt, yt, zt)) ++number_in_sphere;
		if (i % 1000 == 0) myfile1 << i + 1 << " " << std::setprecision(9) << 0.75 * 8 * (double) number_in_sphere / number_generated << std::endl;
		if (i % 1000 == 0) myfile2 << i + 1 << " " << std::setprecision(9) << 1. / pi * 0.75 * 8 * (double) number_in_sphere / number_generated << std::endl;
	}
	return 0;
}
