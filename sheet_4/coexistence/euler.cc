#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

double df(const double n) {
	return 2. * pow(n, 3.) + n - 3 * pow(n, 2.);
}

int main(int argc, char* argv[]) {
	double t = 0;
	const double tf = 400;
	const double h = 0.01;
	double n = atof(argv[1]);
	//std::cout << n << std::endl;
	std::string ext = "out.dat";
	std::string filename = argv[1] + ext;
	filename = "output_data/" + filename;
	std::ofstream myfile;
	myfile.open(filename.c_str());

	while (t < tf) {
		n = n + h * df(n);
		t += h;
		myfile << t << " " << n << std::endl;
	}
	myfile.close();
	return 0;
}
