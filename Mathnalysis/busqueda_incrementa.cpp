#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double function(double x) {
	return sin(x);
}

void busqueda_incremental(double x0, double delta, int niter) {
	double fx0 = function(x0);
	cout << fixed;
	cout.precision(3);
	if (fx0 == 0) {
		cout << x0 << " is a root" << endl;
	}
	else {
		cout << "|  i  |   x0  |  fx0  |   x1  |  fx1  | fx0 * fx1 |" << endl;
		double x1 = x0 + delta;
		int count = 1;
		double fx1 = function(x1);
		while (fx1 * fx0 > 0 && count < niter) {
			string spaces = "";
			if (count < 10)spaces += " ";
			cout << "| " << count << spaces << "  | " << x0 << " | " << fx0 << " | " << x1 << " | " << fx1 << " |     " << fx0 * fx1 << " |" << endl;
			x0 = x1;
			fx0 = fx1;
			x1 = x0 + delta;
			fx1 = function(x1);
			count += 1;
		}
		cout << "| " << count << "  | " << x0 << " | " << fx0 << " | " << x1 << " | " << fx1 << " |     " << fx0 * fx1 << " |" << endl;
		if (fx1 == 0) {
			cout << x1 << " is a root" << endl;
		}
		else {
			if (fx0 * fx1 < 0) {
				cout << "There is a root between " << x0 << " and " << x1 << endl;
			}
			else {
				cout << "The program fails in " << niter << " iterations" << endl;
			}
		}
	}
}
