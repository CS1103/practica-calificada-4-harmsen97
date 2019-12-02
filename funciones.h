//
// Created by Jeronimo on 2019-12-01.
//

#ifndef PRACTICA_CALIFICADA_4_HARMSEN97_MASTER_FUNCIONES_H
#define PRACTICA_CALIFICADA_4_HARMSEN97_MASTER_FUNCIONES_H



#include <iostream>
#include <vector>
#include <string_view>
#include <cmath>
#include "lodepng.h"
using namespace std;

std::vector<unsigned char> decode(string_view filename, unsigned int& width, unsigned int& height) {

    std::vector<unsigned char> result;
    unsigned error = lodepng::decode(result, width, height, filename.data());
    if (error) {
        std::cerr << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
    return result;
}


void encode(string_view filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
    unsigned error = lodepng::encode(filename.data(), image, width, height);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}


void Rfilter(string_view filename, std::vector<unsigned char>& image, unsigned w, unsigned h) {

    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {

             image[(i * w * 4 + j + 1)]=0; // Green component
             image[(i * w * 4 + j + 2)]=0; // Blue component

        }
    }


    unsigned error = lodepng::encode(filename.data(), image, w, h);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}



void Bfilter(string_view filename, std::vector<unsigned char>& image, unsigned w, unsigned h) {

    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            image[(i * w * 4 + j + 0)]=0; // Red component
            image[(i * w * 4 + j + 1)]=0; // Green component

        }
    }


    unsigned error = lodepng::encode(filename.data(), image, w, h);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}


void Gfilter(string_view filename, std::vector<unsigned char>& image, unsigned w, unsigned h) {

    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            image[(i * w * 4 + j + 0)]=0; // Red component

            image[(i * w * 4 + j + 2)]=0; // Blue component

        }
    }


    unsigned error = lodepng::encode(filename.data(), image, w, h);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

void printConsole(string_view filename, std::vector<unsigned char>& image, unsigned w, unsigned h) {

    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
            int r = image[i * w * 4 + j + 0]; // Red component
            int g = image[i * w * 4 + j + 1]; // Green component
            int b = image[i * w * 4 + j + 2]; // Blue component
            int a = image[i * w * 4 + j + 3]; // Alpha component
            std::cout << r << " ";
            std::cout << g << " ";
            std::cout << b << " ";
            std::cout << a << "|";
        }

        std::cout <<endl;

    }


    unsigned error = lodepng::encode(filename.data(), image, w, h);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

void Rotate45(string_view filename, std::vector<unsigned char> &image, unsigned w, unsigned h) {

    auto aux = image;
    int A = M_PI/4; // 45

    for (size_t i = 0; i < h; i++) {
        for (size_t j = 0; j < w * 4; j += 4) {
             aux[i * w * 4 + j + 0]=image[((sin(A)*j + cos(A)*i)) * w * 4 + (cos(A)*j - sin(A)*i) + 0];
             aux[i * w * 4 + j + 1]=image[((sin(A)*j + cos(A)*i)) * w * 4 + (cos(A)*j - sin(A)*i) + 1];
             aux[i * w * 4 + j + 2]=image[((sin(A)*j + cos(A)*i)) * w * 4 + (cos(A)*j - sin(A)*i) + 2];
             aux[i * w * 4 + j + 3]=image[((sin(A)*j + cos(A)*i)) * w * 4 + (cos(A)*j - sin(A)*i) + 3];
               /*aux[i * w * 4 + j + 0]=image[(j-i) * w * 4 + (i+j) + 0];
               aux[i * w * 4 + j + 1]=image[(j-i) * w * 4 + (i+j) + 1];
               aux[i * w * 4 + j + 2]=image[(j-i) * w * 4 + (i+j) + 2];
               aux[i * w * 4 + j + 3]=image[(j-i) * w * 4 + (i+j) + 3]; */

        }



    }

    unsigned error = lodepng::encode(filename.data(), aux, w, h);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}












#endif //PRACTICA_CALIFICADA_4_HARMSEN97_MASTER_FUNCIONES_H
