#include<gtk/gtk.h>

#include<string.h>

static void response(GtkWidget *,gpointer);



int main(int argc,char* argv[])
{
	FILE *f;
	gtk_init(&argc,&argv);
	GtkWidget *window,*menu_bar,*menu_item,*file_menu,*help_menu,*vbox,*button;
	GtkWindow *parent;
	
	
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete_event",G_CALLBACK(gtk_main_quit),NULL);

	menu_bar=gtk_menu_bar_new();
	
	file_menu=gtk_menu_new();
	help_menu=gtk_menu_new();

	menu_item=gtk_menu_item_new_with_label("File");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),file_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

	menu_item=gtk_menu_item_new_with_label("Help");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_item),help_menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),menu_item);

	menu_item=gtk_menu_item_new_with_label("New Window");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_item);
	g_signal_connect(menu_item,"activate",G_CALLBACK(main),NULL);

	menu_item=gtk_menu_item_new_with_label("Exit");
	gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),menu_item);
	g_signal_connect(menu_item,"activate",G_CALLBACK(gtk_main_quit),NULL);

	menu_item=gtk_menu_item_new_with_label("About");
	gtk_menu_shell_append(GTK_MENU_SHELL(help_menu),menu_item);
	g_signal_connect(menu_item,"activate",G_CALLBACK(response),NULL);
	
	
	GtkWidget *view;
	GtkTextBuffer *buffer;
	GtkTextIter start, end;
	GtkTextIter iter;

vbox=gtk_vbox_new(0,0);
	button=gtk_button_new_with_label("hello");
	gtk_box_pack_start(GTK_BOX(vbox),menu_bar,0,0,0);
	gtk_box_pack_start(GTK_BOX(vbox),button,0,0,0);
	






	view=gtk_text_view_new();
	gtk_box_pack_start(GTK_BOX(vbox),view,TRUE,TRUE,0);
	buffer=gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	
GtkWidget *dialog;
GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_SAVE;
gint res;

dialog = gtk_file_chooser_dialog_new ("Open File",
                                      GTK_WINDOW(window),
                                       GTK_FILE_CHOOSER_ACTION_OPEN,
                                      GTK_STOCK_OK,
                                      GTK_RESPONSE_OK,
                                      GTK_STOCK_CANCEL,
                                      GTK_RESPONSE_CANCEL,
                                      NULL);
gtk_widget_show_all(dialog);

res=gtk_dialog_run(GTK_DIALOG(dialog));


if (res == GTK_RESPONSE_OK)
  {
    char *filename;
	FILE *f;
	

    g_print("%s\n,",gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog)));
f=fopen("filename","r+");
  }
else
g_print("You pressed the cancel");




	


	gtk_container_add(GTK_CONTAINER(window),vbox);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;

	
}

static void response(GtkWidget * menu_item,gpointer data)
{

	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)),"New")==0)
{
	g_print("New was just pressed ");
}
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)),"Exit")==0)
{
	g_print("Exit was just pressed ");
}
	if(strcmp(gtk_menu_item_get_label(GTK_MENU_ITEM(menu_item)),"About")==0)
{
	g_print("About was just presses ");
}
}

