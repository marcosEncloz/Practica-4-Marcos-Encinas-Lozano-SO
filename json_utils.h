#ifndef JSON_UTILS_H
#define JSON_UTILS_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;

using Matrix16 = vector<vector<int>>;

nlohmann::json readJSON(const string& filename);
bool validateMatrix(const Matrix16& m);

#endif
