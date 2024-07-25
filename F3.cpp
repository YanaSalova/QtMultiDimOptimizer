#include "F3.h"
#include <vector>
#include <cmath>
#include <string>


int F3::GetFuncDim() const
{
	return 2;
}

std::string F3::GetFunc() const
{
	return "0.26(x^2 + y^2) - 0.48xy";
}

double F3::GetFuncValue(std::vector<double> x)
{
	return 0.26*(x[0] * x[0] + x[1] * x[1]) - 0.48 * x[0] * x[1];
}

std::vector<double> F3::GetFuncGrad(std::vector<double> x) const
{
	std::vector<double> gradient;
	gradient.push_back(0.52  *x[0] - 0.48 * x[1]); 
	gradient.push_back(0.52 * x[1] - 0.48 * x[0]);
	return gradient;
}

