#ifndef MAIN_H
#define MAIN_H

#include "gtk/gtk.h"
#include <stdio.h>

FILE *eng_opn;
FILE *viet_opn;
GtkBuilder *builder;

//intro_window;
GtkWidget *intro_window;

//right_annouce & //wrong_annouce
GtkWidget *right_announce;
GtkWidget *wrong_announce;

//working window
GtkWidget *working_wdn;
GtkEntry *entry_word;
GtkLabel *show_viet_word;

//warning
GtkWidget *lack_word_wdn;
#endif
