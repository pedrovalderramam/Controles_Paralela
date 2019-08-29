#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

using namespace std;
using namespace cv;

string entrada, salida, resolucion;

void Resolucion_cambiar(string resolucion, int &x, int &y) {

  if(resolucion=="2K" || resolucion=="2k"){

    x= 2048;
    y= 1080;
  }

  else if(resolucion=="4K" || resolucion=="4k"){

    x = 4096;
    y = 2160;
  }

  else if(resolucion=="8K" || resolucion=="8k"){

    x = 7680;
    y = 4320;
  }

}


char* recibir_entrada(char** matriz, int largo) {
        char* imagen_entrada = NULL;
        int i = 0, k = 0;

        if (largo > 0) {
                for (i = 0; i < largo; i++) {
                        if (strcmp("-f", matriz[i]) == 0) {
                                k = i + 1;
                                imagen_entrada = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));
                                snprintf(imagen_entrada, strlen(matriz[k]) + 1, "%s", matriz[k]);
                                break;
                        }
                }
        }

        return imagen_entrada; //Retornar el directorio donde se encuentra la imagen ej: Pedro/imagen.png
}

char* recibir_salida(char** matriz, int largo) {
        char* imagen_salida = NULL;
        int i = 0, k = 0;

        if (largo > 0) {
                for (i = 0; i < largo; i++) {
                        if (strcmp("-o", matriz[i]) == 0) {
                                k = i + 1;
                                imagen_salida = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));

                                snprintf(imagen_salida, strlen(matriz[k]) + 1, "%s", matriz[k]);
                                break;
                        }
                }
        }

        return imagen_salida; //Retornar el directorio donde se almacenara la imagen ej: Pedro/imagen.png
}

char* recibir_resolucion(char** matriz, int largo) {
        char* resolucion = NULL;
        int i = 0, k = 0;

        if (largo > 0) {
                for (i = 0; i < largo; i++) {
                        if (strcmp("-e", matriz[i]) == 0) {
                                k = i + 1;
                                resolucion = (char *) calloc(strlen(matriz[k]) + 1, sizeof (char));
                                snprintf(resolucion, strlen(matriz[k]) + 1, "%s", matriz[k]);
                                break;
                        }
                }
        }

        return resolucion; //Retornar el directorio donde se almacenara la imagen ej: Pedro/imagen.png
}
