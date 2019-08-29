#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include  <opencv2/imgproc/imgproc.hpp>
#include "funciones.h"
#include "funciones.cpp"


using namespace std;
using namespace cv;


int main(int argc, char **argv){

  if(argc>=7){

  int x=0,y=0;
  string ruta_imagen,ruta_salida,resolucion;

  ruta_imagen = recibir_entrada(argv,argc); //Se contienen las 3 rutas correspondientes
  ruta_salida = recibir_salida(argv,argc);
  resolucion = recibir_resolucion(argv,argc);

  Resolucion_cambiar(resolucion,x,y);

  Mat src = imread(ruta_imagen, CV_LOAD_IMAGE_UNCHANGED);
  imshow("Imagen Original", src); //Muestra la imagen original, con sus pixeles originales

  Mat dst;
  resize(src,dst,Size(x,y), 0, 0, INTER_LINEAR); //x,y es la resolucion de la imagen en pixeles
  imshow("Salida", dst);
  imwrite(ruta_salida, dst); //Devuelve la imagen escalada con la resolucion elegida

  waitKey(0);

  return 0;
  }

  else{
    cout<<"No se ingresaron los argumentos necesarios"<<endl;
    return 1;
  }
}
