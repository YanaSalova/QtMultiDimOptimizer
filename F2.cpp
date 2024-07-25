#include "F2.h"
#include <vector>
#include <cmath>
#include <string>


int F2::GetFuncDim() const
{
	return 2;
}

std::string F2::GetFunc() const
{
	return "(x + 2y - 7)^2 + (2x + y - 5)^2";
}

double F2::GetFuncValue(std::vector<double> x)
{
	return (x[0] + 2 * x[1] - 7) * (x[0] + 2 * x[1] - 7) + (2 * x[0] + x[1] - 5) * (2 * x[0] + x[1] - 5);
}

std::vector<double> F2::GetFuncGrad(std::vector<double> x) const
{
	std::vector<double> gradient;
	gradient.push_back(-34 + 10 * x[0] + 8 * x[1]);
	gradient.push_back(-38 + 8 * x[0] + 10 * x[1]);
	return gradient;
}

