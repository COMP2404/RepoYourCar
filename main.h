#ifndef MAIN
#define MAIN
#include <iostream>
#include <gtk/gtk.h>
#include "WindowApp.h"
int errorCheck();
void admin(GtkWidget*, WindowApp*);
void callback();
void application(GtkWidget*, WindowApp*);
void getInfo(WindowApp*);
int main(int,char**);
#endif
