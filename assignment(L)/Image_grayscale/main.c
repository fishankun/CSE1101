#include <stdio.h>
#include <string.h>

#include "image.h"
#include "bmp.h"
#include "grayscale.h"

int main(){
    char name[100];
    printf("Enter the file name: ");
    scanf(" %s", name);
    
    int length = strlen(name);
    char type[4];

    for(int i = length - 3, j = 0; i < length; i++, j++){
        type[j] = name[i];
    }

    type[3] = '\0';

    if(strcmp(type, "bmp") != 0){
        printf("Please enter a bmp file.\n");
        return 0;
    }

    Image *image = load_bmp(name);

    if(!image){
    printf("Failed to load BMP.\n");
    return 0;
}
    printf("Width: %d\tHeight: %d\n", image->width, image->height);

    
    grayscale(image);

    printf("Enter a name: ");
    scanf(" %[^\n]", name);

    int x = save_bmp(image, name);

    if(x) printf("Saved.\n");
    else printf("Failed.\n");

    free_image(image);

    return 0;
}