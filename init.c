#include "init.h"
#include <string.h>

void general_gtk_init(){
  builder = gtk_builder_new();
  gtk_builder_add_from_file(builder,"glade_file/eng.glade",NULL);
  gtk_builder_connect_signals(builder,NULL);

  //intro_window;
  intro_window = GTK_WIDGET(gtk_builder_get_object(builder,"intro_window"));
  unit_entry = GTK_ENTRY(gtk_builder_get_object(builder,"unit_entry"));
  vocab_start_entry = GTK_ENTRY(gtk_builder_get_object(builder,"vocab_start_entry"));

  //annouce_window = RIGHT WINDOW
  announce_wdn = GTK_WIDGET(gtk_builder_get_object(builder,"announce_wdn"));

  //wrong window
  wrong_wdn = GTK_WIDGET(gtk_builder_get_object(builder,"wrong_wdn"));
  show_answer = GTK_LABEL(gtk_builder_get_object(builder,"show_answer"));
  show_read = GTK_LABEL(gtk_builder_get_object(builder,"show_read"));
  
  //working window
  working_wdn = GTK_WIDGET(gtk_builder_get_object(builder,"working_wdn"));
  entry_word = GTK_ENTRY(gtk_builder_get_object(builder,"entry_word"));
  show_viet_word = GTK_LABEL(gtk_builder_get_object(builder,"show_viet_word"));
}

void strcat_strcpy(char *first, char *tail, const char *color, const char *size){
  strcpy(first,"<span foreground='");
  strcat(first,color);
  strcat(first,"' weight='bold' font='");
  strcat(first,size);
  strcat(first,"'> ");
  strcat(first,tail);
  strcat(first," </span>");
}

void convert_int_into_str(int a, char *final){
  char store[6];  int count = 0; int i,j;
  if(a/10 == 0) {
    final[count++] = a+48;
    final[count] = '\0';
  }
  else{
    while(a>0){
      int quotient = a/10; //THUONG
      int remainder = a - quotient * 10; //SO DU
      store[count++] = remainder + 48;
      a = quotient;
    }
    store[count] = '\0';
    //I LACKED THIS "arr[count] = '\0';"
    //AND THIS PRINTED OUT A BUNCH OF BULLSH*T :)
    for(i=strlen(store)-1,j=0;i>=0;i--,j++) final[j] = store[i];
    final[count] = '\0';
  }
}
