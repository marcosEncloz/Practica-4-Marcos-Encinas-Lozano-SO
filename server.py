import matplotlib
matplotlib.use('Agg')

from flask import Flask, request, jsonify
import numpy as np
import matplotlib.pyplot as plt
import os

app = Flask(__name__)

@app.route("/upload", methods=["POST"])
def upload_matrix():
    data = request.get_json()

    capture_id = data["capture_id"]
    matrix = np.array(data["data"])

    os.makedirs("images", exist_ok=True)

    plt.imshow(matrix, cmap="inferno")
    plt.colorbar(label="Presión")
    plt.title(f"Mapa táctil {capture_id}")

    filename = f"images/capture_{capture_id}.png"
    plt.savefig(filename)
    plt.close()

    return jsonify({"status": "ok", "saved": filename})

if __name__ == "__main__":
    app.run(host="127.0.0.1", port=5000)
