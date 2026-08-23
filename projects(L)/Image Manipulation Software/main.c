// #include <iup.h>
// #include <stddef.h>
#include <stdio.h>
#include <string.h>
// #include <stdlib.h>

#include "image.h"
#include "bmp.h"
#include "operations.h"
#include "gui.h"

int main(){

    GUI gui = {0};

    gui_init(&gui);

    // Image *image = load_bmp("test2.bmp");
    // int input;
    // Image *undo_image = copy_image(image);

    // printf("grayscale 1.\nbrightness adjustment 2\ninversion 3\n");
    // printf("H flip 4\nV flip 5\nRotate 6\nCrop 7\nBlur 8\nSharpen 9\n");
    // scanf("%d", &input);

    // if(input == 1) grayscale(image);
    // else if(input == 2) brightness(image);
    // else if(input == 3) inversion(image);
    // else if(input == 4) h_flip(image);
    // else if(input == 5) v_flip(image);
    // else if(input == 6){
    //     Image *rotated = rotate(image);

    //     free_image(image);
    //     image = rotated;
    // }

    // else if(input == 7){
    //     int x, y, width, height;
    //     printf("X Y width height\n");
    //     scanf("%d%d%d%d", &x, &y, &width, &height);
    //     Image *cropped = crop(image, x, y, width, height);

    //     free_image(image);
    //     image = cropped;
    // }

    // else if(input == 8){
    //     Image *blurred = blur(image);

    //     free_image(image);
    //     image = blurred;
    // }

    // else if(input == 9){
    //     Image *sharpened = sharpen(image);

    //     free_image(image);
    //     image = sharpened;
    // }

    // char o_file[100];
    // scanf(" %s", o_file);
    // if(save_bmp(image, o_file)) printf("Saved.\n");
    // else printf("Failed.\n");

    // undo(&image, &undo_image);

    // save_bmp(image, "undo.bmp");

    // free_image(image);
    return 0;
}