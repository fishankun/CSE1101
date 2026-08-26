// #include <iup.h>
// #include <stddef.h>
#include <stdio.h>
#include <string.h>
// #include <stdlib.h>

#include "image.h"
#include "bmp.h"



// int operation_callback(Ihandle *self){
    
    
//     return IUP_DEFAULT;
// }

// int main(){
//     IupOpen(NULL, NULL);

    
//     IupMainLoop();

//     IupClose();
    
//     return 0;
// }

int main(){
    Image *image = create_image(2, 2);

    image->data[0].r = 255;
    image->data[1].g = 255;
    image->data[2].b = 255;
    image->data[3].r = 255;
    image->data[3].g = 255;
    image->data[3].b = 255;

    if(save_bmp(image, "test.bmp")) printf("Saved.\n");
    else printf("Failed.\n");
    
    free_image(image);
    return 0;
}