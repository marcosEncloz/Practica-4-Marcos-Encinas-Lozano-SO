# Practica-4-Marcos-Encinas-Lozano-SO
Practica 4 Marcos Encinas Lozano Sistemas Operativos 2/6/26


#+ REQUISITOS
Linux / WSL

Python 3 (para ejecutar el servidor Flask)

Entorno virtual Python (venv)

g++ (compilador de C++)

Librería libcurl para enviar peticiones HTTP

Permisos de ejecución para scripts .sh

Conexión local mediante HTTP (127.0.0.1:5000)

#+ ARCHIVOS PRINCIPALES

server.py — Servidor en Python que recibe matrices interpoladas y genera imágenes táctiles usando Matplotlib.

main.cpp — Programa en C++ que lee el JSON, interpola las matrices y las envía al servidor mediante HTTP POST.

json_utils.cpp / .h — Lectura y manejo del archivo JSON.

interpolation.cpp / .h — Implementación de la interpolación bilineal 16×16 → 128×128.

http_client.cpp / .h — Envío de datos al servidor usando libcurl.

tactile_captures_50.json — Archivo con las 50 capturas táctiles originales.

images/ — Carpeta generada automáticamente con las imágenes:
capture_0.png, capture_1.png, … capture_49.png.

#+ COMO EJECUTAR LA PRACTICA
1. Activar el entorno virtual (Python):  
Debe hacerse en una terminal independiente.

source venv/bin/activate

python3 server.py

El servidor debería mostrar:
Running on http://127.0.0.1:5000

2. Ejecutar el cliente (C++):  
En otra terminal distinta:

./programa

El cliente enviará automáticamente las 50 capturas al servidor.

3. Ver las imágenes generadas:

ls images/

Deberían aparecer:


capture_0.png
capture_1.png
...
capture_49.png

#+ SALIDA GENERADA
El servidor Python genera automáticamente 50 imágenes táctiles, una por cada captura enviada desde el cliente C++.

Cada imagen incluye:

· Visualización con plt.imshow(matrix, cmap="inferno")  

· Barra de color con plt.colorbar(label="Presión")  

· Título "Mapa táctil X"

Además, la terminal muestra:

· Recepción correcta de cada POST

· Nombre del archivo guardado

· Confirmación del cliente: OK
