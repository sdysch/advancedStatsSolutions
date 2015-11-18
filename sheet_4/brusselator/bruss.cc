#include <iostream>
#include <cmath>
#include <fstream>

const double b = 1.8;

double dx(const double x, const double y) {
	return 1. - (b + 1.) * x + pow(x, 2.) * y;
}

double dy(const double x, const double y) {
	return b * x - y * pow(x, 2.);
}

int main() {
	const double h = 0.01; // step size
	double x, y; 
	double xt, yt = 1;// x and y temporary variables
	const double tf = 75;
	
	std::ofstream myfilex;
	myfilex.open("out_x.dat");
	std::ofstream myfiley;
	myfiley.open("out_y.dat");
	std::ofstream myfilecombined;
	myfilecombined.open("out_all.dat");
	
	for (double t = 0; t < tf; t += h) {
		x = xt + h * dx(xt, yt);
		y = yt + h * dy(xt, yt);
		myfilex << t << " " << x << std::endl;
		myfiley << t << " " << y << std::endl;
		myfilecombined << y << " " << x << std::endl;
		xt = x;
		yt = y;
//		std::cout << t << std::endl;
	}
	myfilex.close();
	myfiley.close();
	return 0;
}
