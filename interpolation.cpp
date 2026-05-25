#include "interpolation.h"
#include <algorithm>

using namespace std;

Matrix128 interpolateBilinear(const Matrix16& input) {
    Matrix128 output(128, vector<float>(128));

    float scale = 128.0f / 16.0f; // = 8.0

    for (int y = 0; y < 128; y++) {
        for (int x = 0; x < 128; x++) {

            float gx = x / scale;
            float gy = y / scale;

            int x0 = (int)gx;
            int y0 = (int)gy;

            int x1 = min(x0 + 1, 15);
            int y1 = min(y0 + 1, 15);

            float dx = gx - x0;
            float dy = gy - y0;

            float v00 = input[y0][x0];
            float v01 = input[y0][x1];
            float v10 = input[y1][x0];
            float v11 = input[y1][x1];

            float top = v00 * (1 - dx) + v01 * dx;
            float bottom = v10 * (1 - dx) + v11 * dx;

            output[y][x] = top * (1 - dy) + bottom * dy;
        }
    }

    return output;
}
