#include <string.h>
#include <stdio.h>
#include "gtk/gtk.h"
#include "interface.h"
#include "main.h" //contain variables
#include "init.h"

#define WRONG_WDN 0
#define RIGHT_WDN 1
#define LIMIT 5
int where = 2, count =0, score = 0;
char viet[50], viet_final[200], eng[50];
gchar *word;

void interface_begin(){
  gtk_widget_show(GTK_WIDGET(intro_window));
}

//show first word in Vietnamese.
void on_start_btn_clicked(){
  gtk_widget_hide(GTK_WIDGET(intro_window));
  viet_opn = fopen("viet.txt","r");
  eng_opn = fopen("eng.txt","r");
  if(viet_opn == NULL || eng_opn == NULL) return;
  fscanf(viet_opn,"%[^#]%*c",viet);
  strcat_strcpy(viet_final,viet,"black");
  gtk_label_set_markup(GTK_LABEL(show_viet_word),viet_final);

  gtk_widget_show(GTK_WIDGET(working_wdn));
  strcpy(viet,"");
  strcpy(viet_final,"");
}

//receive answer and compare with result, using "strcmp"
void on_submit_btn_clicked(){
  count++;
  word = (gchar*)gtk_entry_get_text(GTK_ENTRY(entry_word));
  if(strlen(word) <=0) {
      gtk_widget_show(GTK_WIDGET(lack_word_wdn));
  }
  
  fscanf(eng_opn,"%[^\n]%*c",eng);
  if(strcmp(eng,word) == 0){
    gtk_widget_show(GTK_WIDGET(right_announce));
    score++;
    where = 1;
  }
  else{
    gtk_widget_show(GTK_WIDGET(wrong_announce));
    where = 0;
  }
  gtk_entry_set_text(entry_word,"");
  gtk_widget_hide(GTK_WIDGET(working_wdn));
}

//show next Vietnamese word
void on_next_btn_clicked(){
  if(where == WRONG_WDN) gtk_widget_hide(GTK_WIDGET(wrong_announce));
  else if(where == RIGHT_WDN) gtk_widget_hide(GTK_WIDGET(right_announce));

  if(count >= LIMIT) {
    printf("Correct answers: %d/%d, equivalent TO %.3f %%\n",score,LIMIT,((double)score/LIMIT)*100 );
    gtk_main_quit();
  }
  else{
    fscanf(viet_opn,"%[^#]%*c",viet);
    strcat_strcpy(viet_final,viet,"black");
    gtk_label_set_markup(GTK_LABEL(show_viet_word),viet_final);
    gtk_widget_show(GTK_WIDGET(working_wdn));
    strcpy(viet,"");
    strcpy(viet_final,"");
    /*
      word = (gchar*)gtk_entry_get_text(GTK_ENTRY(entry_word));
      if(strlen(word) <=0) {
      gtk_widget_show(GTK_WIDGET(lack_word_wdn));
      }
  
      gtk_widget_hide(GTK_WIDGET(working_wdn));
      fscanf(eng_opn,"%[^\n]%*c",eng);
      if(strcmp(eng,word) == 0){
      gtk_widget_show(GTK_WIDGET(right_announce));
      where = 1;
      gtk_entry_set_text(entry_word,"");
      }
      else{
      gtk_widget_show(GTK_WIDGET(wrong_announce));
      where = 0;
      printf("eng = %s\n",eng);
      gtk_entry_set_text(entry_word,"");
      }
    */ //This make code become stupid. We need to make the "working window" appear, done. Doing like this will make program misunderstand that word is always "", wrong.
  }
}


void turn_off_all(){
  gtk_main_quit();
}

void on_back_btn_clicked(){
  gtk_widget_hide(GTK_WIDGET(lack_word_wdn));
}

//Bosung chuc nang: Tim tu da nhap vao sai dung cay JRB. KHi chung ta nhap sai tu, he thong ghi nho key(number integer) cua no, sau cung tra lai value(string) ra man hinh. まだまだ
