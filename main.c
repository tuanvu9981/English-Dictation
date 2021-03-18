#include <stdio.h>
#include "init.h"
#include "gtk/gtk.h"
#include "interface.h"
#include "main.h"

int main(int argc, char* argv[]){
  gtk_init(&argc,&argv);
  general_gtk_init();
  interface_begin();
  gtk_main();
}
