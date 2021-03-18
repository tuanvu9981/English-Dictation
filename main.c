#include <stdio.h>
#include "init.h"
#include "gtk/gtk.h"
#include "interface.h"
#include "main.h"

int main(int argc, char* argv[]){
  int rc = sqlite3_open("my_english.db", &db);
  if(rc != SQLITE_OK){
    fprintf(stderr,"Cannot open database: %s\n",sqlite3_errmsg(db));
    sqlite3_close(db);
  }

  //bring int rc = open... to open dtbase 1st
  //when it was written after gtk_main() (FINAL POSITION), run wrong, return 0 everything
  gtk_init(&argc,&argv);
  general_gtk_init();
  interface_begin();
  gtk_main();

}
