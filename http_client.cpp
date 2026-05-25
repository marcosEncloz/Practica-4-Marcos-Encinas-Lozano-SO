#include "http_client.h"
#include <curl/curl.h>
#include <iostream>

using namespace std;

bool sendMatrixToServer(const nlohmann::json& payload, const string& url) {
    CURL* curl = curl_easy_init();
    if (!curl) {
        cerr << "Error inicializando CURL" << endl;
        return false;
    }

    string jsonStr = payload.dump();

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, jsonStr.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, jsonStr.size());

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    CURLcode res = curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        cerr << "Error en POST: " << curl_easy_strerror(res) << endl;
        return false;
    }

    return true;
}
