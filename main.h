#ifndef MAIN
#define MAIN
#include <iostream>
#include <gtk/gtk.h>
#include "WindowApp.h"
int errorCheck();
void admin(GtkWidget*, WindowApp*);
void callback();
void application(GtkWidget*, WindowApp*);
int main(int,char**);
#endif
