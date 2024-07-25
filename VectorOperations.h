#pragma once
#include <vector>
#include <numeric>
#include <cmath>

std::vector<double> operator-(std::vector<double> v1, std::vector<double> v2);
std::vector<double> operator+(std::vector<double> v1, std::vector<double> v2);
std::vector<double> operator/(std::vector<double> v1, std::vector<double> v2);
std::vector<double> operator*(std::vector<double> v1, double a);
