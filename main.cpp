#include "funciones.h"

int main()
{

    unsigned int w;
    unsigned int h;
    auto image = decode("../in.png", w, h);


    //Bfilter("../blue.png", image, w, h);

    //Rfilter("../red.png", image, w, h);
    Gfilter("../green.png", image, w, h);


}
