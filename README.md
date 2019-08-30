# Controles_Paralela
Computación Paralela y Distribuida 2019-2

# Control n°2

Se solicita desarrollar una aplicación en C/C++,que permita redimensionar una imagen PNG a un formato dado:

- La imagen tendrá formato PNG.
- El compilador usado será GCC.
- El programa debe determinar si la imagen tiene orientación vertical o horizontal.

Donde:

- El argumento​-e​,le indica al programa el tamaño de la redimensión,los valores posibles son:
- FHD​ - Formato full hd de 1920×1080px
- 2K​ - Formato de 2048×1080px
- 4K​ - Formato de 4096 × 2160px.

Donde:
- El argumento​-e​,le indica al programa el tamaño de la redimensión,los valores posibles son:
- FHD​ - Formato full hd de 1920×1080px
- 2K​ - Formato de 2048×1080px
- 4K​ - Formato de 4096 × 2160px
- 8K​ - Formato de 7680 × 4320px

- El argumento ​-f​, le indica al programa la ruta hacia el archivo de entrada.
- El argumento ​-o​, le indica al programa la ruta hacia el archivo de salida8K​ - Formato de 7680 × 4320px
- El argumento ​-f​, le indica al programa la ruta hacia el archivo de entrada.
- El argumento ​-o​, le indica al programa la ruta hacia el archivo de salida

# EJECUCIÓN

> Borrar el ejecutable a.out y volver a crearlol

> g++ escala.cpp `pkg-config --cflags --libs opencv` para crear el ejecutable

> ./programa -e 2K -f /ruta/imagen_entrada.png -o /ruta/imagen_salida.png
