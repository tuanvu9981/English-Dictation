#ifndef MAIN_H
#define MAIN_H

#include "gtk/gtk.h"
#include <stdio.h>
#include "sqlite3.h"

sqlite3 *db;
GtkBuilder *builder;

//intro_window;
GtkWidget *intro_window;
GtkEntry *unit_entry;
GtkEntry *vocab_start_entry;

//announce_window = RIGHT WINDOW
GtkWidget *announce_wdn;

//Wrong window
GtkWidget *wrong_wdn;
GtkLabel *show_answer;
GtkLabel *show_read;

//working window
GtkWidget *working_wdn;
GtkEntry *entry_word;
GtkLabel *show_viet_word;

#endif
