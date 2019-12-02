//
// Created by Jeronimo on 2019-12-01.
//

#ifndef PRACTICA_CALIFICADA_4_HARMSEN97_MASTER_FUNCIONES_H
#define PRACTICA_CALIFICADA_4_HARMSEN97_MASTER_FUNCIONES_H



#include <iostream>
#include <vector>
#include <string_view>
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
             image[(i * w * 4 + j + 0)]; // Red component
             image[(i * w * 4 + j + 1)]=0; // Green component
             image[(i * w * 4 + j + 2)]=0; // Blue component
             image[i * w * 4 + j + 3]; // Alpha component
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
            image[(i * w * 4 + j + 2)]; // Blue component
            image[i * w * 4 + j + 3]; // Alpha component
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
            image[(i * w * 4 + j + 1)]; // Green component
            image[(i * w * 4 + j + 2)]=0; // Blue component
            image[i * w * 4 + j + 3]; // Alpha component
        }
    }


    unsigned error = lodepng::encode(filename.data(), image, w, h);
    if (error) {
        std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    }
}












#endif //PRACTICA_CALIFICADA_4_HARMSEN97_MASTER_FUNCIONES_H
