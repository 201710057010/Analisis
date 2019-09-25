#pragma once

double raicesMultiples(double (*func)(double), double (*dFunc)(double), double (*d2Func)(double), double x0, int nIter, double tol, bool error);
