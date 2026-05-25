#include <iostream>
#include "json_utils.h"
#include "interpolation.h"
#include "http_client.h"

using namespace std;

int main() {
    try {
        auto jsonData = readJSON("tactile_captures_50.json");

        for (int i = 0; i < 50; i++) {

            Matrix16 m = jsonData["captures"][i]["matrix"].get<Matrix16>();

            if (!validateMatrix(m)) {
                cout << "Error: matriz inválida en captura " << i << endl;
                continue;
            }

            Matrix128 out = interpolateBilinear(m);

            nlohmann::json payload;
            payload["capture_id"] = i;
            payload["width"] = 128;
            payload["height"] = 128;
            payload["data"] = out;

            cout << "Enviando captura " << i << "..." << endl;

            bool ok = sendMatrixToServer(payload, "http://127.0.0.1:5000/upload");

            if (ok)
                cout << "OK" << endl;
            else
                cout << "ERROR" << endl;
        }

    } catch (const exception& e) {
        cout << "Excepción: " << e.what() << endl;
        return 1;
    }

    return 0;
}

