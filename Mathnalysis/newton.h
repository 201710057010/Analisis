#pragma once

void newton(double (*func)(double), double (*dfunc)(double), double x0, double tol, int niter);