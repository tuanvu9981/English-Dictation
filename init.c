#include "init.h"
#include <string.h>

void general_gtk_init(){
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder,"glade_file/eng2.glade",NULL);
  gtk_builder_connect_signals(builder,NULL);

  //intro_window;
  intro_window = GTK_WIDGET(gtk_builder_get_object(builder,"intro_window"));

  //right_annouce_window & //wrong_annouce_window
  right_announce = GTK_WIDGET(gtk_builder_get_object(builder,"right_announce"));
  wrong_announce = GTK_WIDGET(gtk_builder_get_object(builder,"wrong_announce"));

  //working window
  working_wdn = GTK_WIDGET(gtk_builder_get_object(builder,"working_wdn"));
  entry_word = GTK_ENTRY(gtk_builder_get_object(builder,"entry_word"));
  show_viet_word = GTK_LABEL(gtk_builder_get_object(builder,"show_viet_word"));

  //lack word window;
  lack_word_wdn = GTK_WIDGET(gtk_builder_get_object(builder,"lack_word_wdn"));
}

void strcat_strcpy(char *first, char *tail, const char *color){
  strcpy(first,"<span foreground='");
  strcat(first,color);
  strcat(first,"' weight='bold' font='14.5'> ");
  strcat(first,tail);
  strcat(first," </span>");
}
