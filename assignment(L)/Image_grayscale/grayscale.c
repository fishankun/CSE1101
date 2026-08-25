#include "image.h"
#include <stdio.h>

void grayscale(Image *image){
    for(int i = 0; i < image->width * image->height; i++){
        int gray = 0.299 * image->data[i].r + 0.587 * image->data[i].g + 0.114 * image->data[i].b;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}