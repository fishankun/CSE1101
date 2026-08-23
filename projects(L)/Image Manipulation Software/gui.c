#include <stdio.h>
#include <stdlib.h>
#include <iup.h>
#include <iupdraw.h>

#include "image.h"
#include "bmp.h"
#include "operations.h"
#include "gui.h"

Ihandle *create_iup_image(Image *image){
    unsigned char *pixels = malloc(image->width * image->height * 3 * sizeof(unsigned char));

    for(int i = 0; i < image->height * image->width; i++){
        pixels[i * 3] = image->data[i].r;
        pixels[i * 3 + 1] = image->data[i].g;
        pixels[i * 3 + 2] = image->data[i].b;
    }

    Ihandle *iup_image = IupImageRGB(
        image->width,
        image->height,
        pixels
    );

    free(pixels);
    return iup_image;
}

int open_image_cb(Ihandle *ih){
    Ihandle *dialog = IupFileDlg();

    IupSetAttribute(dialog, "DIALOGTYPE", "OPEN");
    IupSetAttribute(dialog, "FILTER", "*.bmp");
    IupSetAttribute(dialog, "TITLE", "Open BMP Image");

    GUI *gui = (GUI *)IupGetAttribute(ih, "GUI");

    IupPopup(dialog, IUP_CURRENT, IUP_CURRENT);

    const char *filename = IupGetAttribute(dialog, "VALUE");

    if(filename != NULL){
        gui->image = load_bmp(filename);
        gui->undo_image = NULL;

        Ihandle *iup_image = create_iup_image(gui->image);

        IupSetHandle("CURRENT_IMAGE", iup_image);

        IupUpdate(gui->canvas);
    }

    return IUP_DEFAULT;
}

int canvas_image_cb(Ihandle *ih){
    GUI *gui = (GUI *)IupGetAttribute(ih, "GUI");

    if(gui->image == NULL)
        return IUP_DEFAULT;

    IupDrawBegin(ih);

    IupDrawImage(
        ih,
        "CURRENT_IMAGE",
        0,
        0,
        gui->image->width,
        gui->image->height
    );

    IupDrawEnd(ih);

    return IUP_DEFAULT;
}

void gui_init(GUI *gui){
    IupOpen(NULL, NULL);

    gui->canvas = IupCanvas(NULL);
    IupSetAttribute(gui->canvas, "RASTERSIZE", "600x500");
    IupSetAttribute(gui->canvas, "GUI", (char *)gui);
    

    Ihandle *open_button = IupButton("Open", NULL);
    IupSetAttribute(open_button, "GUI", (char *)gui);
    IupSetCallback(open_button, "ACTION", (Icallback)open_image_cb);
    
    IupSetCallback(gui->canvas, "ACTION", (Icallback)canvas_image_cb);

    Ihandle *save_button = IupButton("Save", NULL);
    Ihandle *grayscale_button = IupButton("Grayscale", NULL);
    Ihandle *brightness_button = IupButton("Brightness", NULL);
    Ihandle *invert_button = IupButton("Invert", NULL);
    Ihandle *h_flip_button = IupButton("Horizontal Flip", NULL);
    Ihandle *v_flip_button = IupButton("Vertical Flip", NULL);
    Ihandle *rotate_button = IupButton("Rotate", NULL);
    Ihandle *crop_button = IupButton("Crop", NULL);
    Ihandle *blur_button = IupButton("Blur", NULL);
    Ihandle *sharpen_button = IupButton("Sharpen", NULL);
    Ihandle *undo_button = IupButton("Undo", NULL);

    Ihandle *buttons = IupVbox( 
        open_button,
        save_button,
        grayscale_button,
        brightness_button,
        invert_button,
        h_flip_button,
        v_flip_button,
        rotate_button,
        crop_button,
        blur_button,
        sharpen_button,
        undo_button,
        NULL
    );


    Ihandle *layout = IupHbox(
        buttons,
        gui->canvas,
        NULL
    );
    

    Ihandle *dialog = IupDialog(layout);
    IupSetAttribute(dialog, "TITLE", "Image Manipulation Software");
    IupSetAttribute(dialog, "RASTERSIZE", "800x600");
    
    IupShow(dialog);

    IupMainLoop();
    IupClose();
}