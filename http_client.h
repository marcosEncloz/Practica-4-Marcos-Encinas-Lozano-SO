#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>
#include <nlohmann/json.hpp>

using namespace std;

bool sendMatrixToServer(const nlohmann::json& payload, const string& url);

#endif
