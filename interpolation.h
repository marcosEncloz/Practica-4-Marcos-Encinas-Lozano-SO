#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>

using namespace std;

using Matrix16 = vector<vector<int>>;
using Matrix128 = vector<vector<float>>;

Matrix128 interpolateBilinear(const Matrix16& input);

#endif
