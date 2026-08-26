#include <iup.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int operation(char *num1, char *sign, char *num2){
    int a = atoi(num1);
    int b = atoi(num2);

    if(!strcmp(sign, "+")) return a + b;
    else if(!strcmp(sign, "-")) return a - b;
    else return 0;
}

int operation_callback(Ihandle *self){
    
    Ihandle *text1 = IupGetAttributeHandle(self, "TEXT1");
    Ihandle *text2 = IupGetAttributeHandle(self, "TEXT2");
    Ihandle *result_text = IupGetAttributeHandle(self, "RESULT");

    char *sign = IupGetAttribute(self, "TITLE");
    char *value1 = IupGetAttribute(text1, "VALUE");
    char *value2 = IupGetAttribute(text2, "VALUE");
    char sresult[100];

    // printf("You have entered: %s\n", value1);
    // printf("You have entered: %s\n", value2);

    int result = operation(value1, sign, value2);
    snprintf(sresult, sizeof(sresult), "%d", result);

    IupSetAttribute(result_text, "VALUE", sresult);

    // printf("%s\n", sresult);
    
    return IUP_DEFAULT;
}

int main(){
    IupOpen(NULL, NULL);

    Ihandle *label = IupLabel("Write your numbers, then press the operator");

    Ihandle *label2 = IupLabel("Result: ");
    
    Ihandle *text1 = IupText(NULL);
    Ihandle *text2 = IupText(NULL);

    Ihandle *result_text = IupText(NULL);
    IupSetAttribute(result_text, "READONLY", "YES");

    Ihandle *plus = IupButton("+", NULL);
    IupSetAttributeHandle(plus, "TEXT1", text1);
    IupSetAttributeHandle(plus, "TEXT2", text2);
    IupSetCallback(plus, "ACTION", (Icallback)operation_callback);
    

    Ihandle *minus = IupButton("-", NULL);
    IupSetAttributeHandle(minus, "TEXT1", text1);
    IupSetAttributeHandle(minus, "TEXT2", text2);
    IupSetCallback(minus, "ACTION", (Icallback)operation_callback);

    IupSetAttributeHandle(plus, "RESULT", result_text);
    IupSetAttributeHandle(minus, "RESULT", result_text);

    Ihandle *numbers = IupHbox(text1, text2, NULL);
    Ihandle *operators = IupHbox(plus, minus, NULL);
    Ihandle *result = IupHbox(label2, result_text, NULL);
    Ihandle *vbox = IupVbox(label, numbers, operators, result, NULL);
    Ihandle *dialog = IupDialog(vbox);

    IupSetAttribute(dialog, "TITLE", "The Amazing Calcula_Thor");
    IupSetAttribute(dialog, "SIZE", "170x65");
    IupSetAttribute(dialog, "BGCOLOR", "137 137 137");
    
    IupShow(dialog);
    IupMainLoop();

    IupClose();
    
    return 0;
}