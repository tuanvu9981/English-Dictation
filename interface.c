#include <string.h>
#include <stdio.h>
#include "gtk/gtk.h"
#include "interface.h"
#include "main.h" 
#include "init.h"
#include "sqlite3.h"

#define TRUE_WDN 1
#define FALSE_WDN 0
gchar *word, *lesson, *begin_stt;
char *err_msg, sql[250], eng_dtbs[100], contain[100], reade[100];
char viet_final[200], viet[80], order[10], read_e[150];
char answer[200], kazoe[10],table_name[10];
int count, stt, control;

int callback(void *not_used, int argc, char **argv,char **azColName){
  strcpy(contain,argv[0]);
  return 0; //return error code (must be 0 = SQLITE_OK)
}

void interface_begin(){
  gtk_widget_show(GTK_WIDGET(intro_window));
}

void on_start_btn_clicked(/*BEGIN*/){
  lesson = (gchar*)gtk_entry_get_text(GTK_ENTRY(unit_entry));
  begin_stt = (gchar*)gtk_entry_get_text(GTK_ENTRY(vocab_start_entry));
  if(strlen(lesson) >0 && strlen(begin_stt) >0){
    strcpy(table_name,lesson);
    strcat(sql,"SELECT COUNT(*) FROM ");
    strcat(sql,table_name);
    sqlite3_exec(db,sql,callback,0,&err_msg);
    strcpy(kazoe,contain);
    count = atoi(kazoe);
    gtk_widget_hide(GTK_WIDGET(intro_window));

    strcpy(sql,"SELECT viet FROM ");
    strcat(sql,table_name);
    strcat(sql," WHERE stt = ");
    strcat(sql,begin_stt);
    sqlite3_exec(db,sql,callback,0,&err_msg);
    strcpy(viet,contain);
    strcat_strcpy(viet_final,viet,"black","14.5");
    
    gtk_label_set_markup(GTK_LABEL(show_viet_word),viet_final);
    gtk_widget_show(GTK_WIDGET(working_wdn));
    stt = atoi(begin_stt);
  }
  gtk_entry_set_text(unit_entry,"");
  gtk_entry_set_text(vocab_start_entry,"");
}

void on_submit_btn_clicked(){
  word = (gchar*)gtk_entry_get_text(GTK_ENTRY(entry_word));
  if(strlen(word) > 0){
    strcpy(sql,"SELECT eng FROM ");
    strcat(sql,table_name);
    strcat(sql," WHERE stt = ");
    convert_int_into_str(stt,order);
    strcat(sql,order);
    sqlite3_exec(db,sql,callback,0,&err_msg);
    strcpy(eng_dtbs,contain);
    
    if(strcmp(word,eng_dtbs) == 0){
      control = 1;
      gtk_widget_show(GTK_WIDGET(announce_wdn));
    }
    else{
      control = 0;
      strcpy(sql,"SELECT read FROM ");
      strcat(sql,table_name);
      strcat(sql," WHERE stt = ");//order already has
      strcat(sql,order);
      sqlite3_exec(db,sql,callback,0,&err_msg);
      strcpy(reade,contain);

      strcat_strcpy(answer,eng_dtbs,"orange","20.5");
      strcat_strcpy(read_e,reade,"turquoise","20.0");
      gtk_label_set_markup(GTK_LABEL(show_answer),answer);
      gtk_label_set_markup(GTK_LABEL(show_read),read_e);
      gtk_widget_show(GTK_WIDGET(wrong_wdn));
    }
  }
  gtk_entry_set_text(entry_word,"");
}

void on_next_btn_clicked(/*NEXT*/){
  if(stt >= count) {
    if(control == 1){ 
      gtk_widget_hide(GTK_WIDGET(announce_wdn));
      gtk_widget_hide(GTK_WIDGET(working_wdn));
      gtk_widget_show(GTK_WIDGET(intro_window));
    }
    else if(control == 0){
      gtk_widget_hide(GTK_WIDGET(wrong_wdn));
      gtk_widget_hide(GTK_WIDGET(working_wdn));
      gtk_widget_show(GTK_WIDGET(intro_window));
    }
  }
  else{
    stt++;
    strcpy(sql,"SELECT viet FROM ");
    strcat(sql,table_name);
    strcat(sql," WHERE stt = ");
    convert_int_into_str(stt,order);
    strcat(sql,order);
    sqlite3_exec(db,sql,callback,0,&err_msg);
    strcpy(viet,contain);

    strcat_strcpy(viet_final,viet,"black","14.5");
    if(control == 1) gtk_widget_hide(GTK_WIDGET(announce_wdn));
    else if(control == 0) gtk_widget_hide(GTK_WIDGET(wrong_wdn));
  
    gtk_label_set_markup(GTK_LABEL(show_viet_word),viet_final);
    gtk_widget_show(GTK_WIDGET(working_wdn));
  }
}

void turn_off_all(){
  gtk_main_quit();
}
