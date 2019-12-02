#include "funciones.h"

int main()
{

    unsigned int w;
    unsigned int h;
    auto image = decode("../in.png", w, h);

    //printConsole("../in.png", image, w, h);


    //Rfilter("../red.png", image, w, h);
    //Gfilter("../green.png", image, w, h);
    //Bfilter("../blue.png", image, w, h);


    //Rotate45("../rotate.png", image, w, h);



    //ParallelRFilter("../red.png", image, w, h);
    //ParallelGFilter("../green.png", image, w, h);
    ParallelBFilter("../blue.png", image, w, h);
}
