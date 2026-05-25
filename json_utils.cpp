#include "json_utils.h"
#include <fstream>
#include <iostream>

using namespace std;

nlohmann::json readJSON(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo JSON");
    }

    nlohmann::json j;
    file >> j;
    return j;
}

bool validateMatrix(const Matrix16& m) {
    if (m.size() != 16) return false;
    for (const auto& row : m) {
        if (row.size() != 16) return false;
    }
    return true;
}
