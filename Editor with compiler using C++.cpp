#include<gtkmm/main.h>
#include<stdlib.h>
#include<string.h>
#include<gtkmm/button.h>
#include<gtkmm/window.h>
#include<iostream>
#include<gtkmm/checkbutton.h>
#include<gtkmm.h>
#include<gtkmm/box.h>
#include<gtkmm/separator.h>
#include<gtkmm/radiobutton.h>
#include<stdio.h>
#include<string>
#include<gtk/gtk.h>
#include<gtkmm/dialog.h>
using namespace std;
string name="Use buffer";

char name_file[50];
int a=0;

class another:public Gtk::Window
{
public:
	another();
	virtual ~another();
	

protected:
	void check_edit();
	void check_vis();
	void close_but();


/*Child Widgets*/

Gtk::Box m_HBox; 	//Horizontal Boxes
Gtk::Box m_VBox1; 	//Vertical Boxes

Gtk::Entry m_Entry;	// gtk entry

Gtk::Button but; 	//gtk button class object

Gtk::CheckButton m_Checkbutton_edit,m_Checkbutton_vis;
};





another::another(): m_VBox1(Gtk::ORIENTATION_VERTICAL),but("Submit"),m_Checkbutton_edit("Editable"),m_Checkbutton_vis("Visible")
{
	set_size_request(200,100);
	set_title("Gtk Entry");

	// For sze and title

	add(m_VBox1); //adding vertical box to window

	m_Entry.set_max_length(50);
	m_Entry.set_placeholder_text("password");
	m_Entry.select_region(0,m_Entry.get_text_length());
	
	m_VBox1.pack_start(m_Entry);

	m_VBox1.add(m_HBox);

	m_HBox.pack_start(m_Checkbutton_edit,Gtk::PACK_SHRINK);
	m_HBox.pack_start(m_Checkbutton_vis,Gtk::PACK_SHRINK);

	m_Checkbutton_edit.signal_toggled().connect(sigc::mem_fun(*this,&another::check_edit));
	m_Checkbutton_edit.set_active(true);

	m_Checkbutton_vis.signal_toggled().connect(sigc::mem_fun(*this,&another::check_vis));
	m_Checkbutton_vis.set_active(true);

	but.signal_clicked().connect(sigc::mem_fun(*this,&another::close_but));

	m_VBox1.pack_start(but);

	but.set_can_default();
	but.grab_default();
	m_Entry.set_activates_default();

	show_all_children();
}



 
another::~another()
{
cout<<"Destructor True called"<<endl;
}


void another::check_edit()
{
m_Entry.set_editable(m_Checkbutton_edit.get_active());
}




void another::check_vis()
{
m_Entry.set_visibility(m_Checkbutton_vis.get_active());
}





void another::close_but()
{

hide();

Glib::ustring s="Satvik";
if(s!=m_Entry.get_text())
{
cout<<"Incorrect Password"<<endl;
a=1;
exit(0);
}
else
cout<<"Access Granted"<<endl;
}









class _Window : public Gtk::Window
{
public:
_Window();
virtual ~_Window();
void myentry();
protected:
virtual void fill_buffers();

virtual void on_button_quit();
virtual void on_button_buffer1();
virtual void on_button_buffer2();
virtual void on_button_buffer3();
virtual void add_buff();

Gtk::VBox m_VBox;
Gtk::ScrolledWindow m_ScrolledWindow;
Gtk::TextView m_TextView;

Glib::RefPtr<Gtk::TextBuffer>m_refTextBuffer1[20];

Gtk::HButtonBox m_ButtonBox,bb2;
Gtk::Button m_Button_Quit,m_Button_Buffer1,m_Button_Buffer2,m_Button_Save,Compile,Run;

Gtk::VButtonBox m_ButtonBox1;
	Gtk::Button m_Button_File,m_Button_Folder;




virtual void on_menu_file_new_generic();
virtual void on_menu_file_quit();
virtual void on_menu_others();
virtual void on_menu_copy();
virtual void on_menu_choices_one();
virtual void on_menu_choices_two();
	virtual void on_button_file_clicked();
	virtual void on_button_folder_clicked();
	//virtual void on_buffer_new();
	virtual void compile_clicked();
	virtual void run_clicked();
//Child widgets



Glib::RefPtr<Gtk::UIManager> m_refUIManager;
Glib::RefPtr<Gtk::ActionGroup>m_refActionGroup;
Glib::RefPtr<Gtk::RadioAction> m_refChoiceOne, m_refChoiceTwo;

Gdk::Color m_Color;
};

void _Window::myentry()
{


Gtk::Box m_HBox; 	//Horizontal Boxes
Gtk::Box m_VBox1(Gtk::ORIENTATION_VERTICAL); 	//Vertical Boxes

Gtk::Entry m_Entry;	// gtk entry

Gtk::Button but("Submit"); 	//gtk button class object

Gtk::CheckButton m_Checkbutton_edit("Editable"),m_Checkbutton_vis("Visible");




}
int main(int argc,char *argv[])
{
Gtk::Main kit(argc,argv);
another A;
Gtk::Main::run(A);

if(a!=1)
{
_Window _window;

Gtk::Main::run(_window);
}
return 0;
}

_Window::_Window()
: m_Button_Quit(Gtk::Stock::QUIT),m_Button_File("Open"),m_Button_Folder("Choose Folder"),m_Button_Save("New Buffer"),Compile("Compile"),Run("Run"),
m_Button_Buffer1("Use buffer 1"),
m_Button_Buffer2(" Use buffer 2")
{
set_title("Text Input");
set_border_width(5);
set_default_size(400,200);

add(m_VBox);

m_Color.set_red(0);


m_ButtonBox1.pack_start(m_Button_Folder);
m_Button_Folder.signal_clicked().connect(sigc::mem_fun(*this,&_Window::on_button_folder_clicked));



m_refActionGroup=Gtk::ActionGroup::create();

//File |New submenu;

m_refActionGroup->add(Gtk::Action::create("FileNewStandard",Gtk::Stock::NEW,"_New","Create a new file"),sigc::mem_fun(*this,&_Window::add_buff));
m_refActionGroup->add(Gtk::Action::create("FileNewFoo",Gtk::Stock::NEW,"_New Foo","Create a new foo"),sigc::mem_fun(*this,&_Window::on_menu_file_new_generic));
m_refActionGroup->add(Gtk::Action::create("FileNewGoo",Gtk::Stock::NEW,"_New Goo","Create a new goo"),sigc::mem_fun(*this,&_Window::on_menu_file_new_generic));

//File menu
m_refActionGroup->add(Gtk::Action::create("FileMenu","File"));
//Submenu
m_refActionGroup->add(Gtk::Action::create("FileNew",Gtk::Stock::NEW));
m_refActionGroup->add(Gtk::Action::create("FileQuit",Gtk::Stock::QUIT),sigc::mem_fun(*this,&_Window::on_menu_file_quit));

//Edit menu

m_refActionGroup->add(Gtk::Action::create("EditMenu","Edit"));
//m_refActionGroup->add(Gtk::Action::create("EditCopy",Gtk::Stock::COPY),sigc::mem_fun(*this,&_Window::on_menu_copy));
//m_refActionGroup->add(Gtk::Action::create("EditPaste",Gtk::Stock::PASTE),sigc::mem_fun(*this,&_Window::on_menu_others));
//m_refActionGroup->add(Gtk::Action::create("EditSomethong","Something"),Gtk::AccelKey("<control><alt>S"),sigc::mem_fun(*this,&_Window::on_menu_others));


//Choices menu
m_refActionGroup->add(Gtk::Action::create("ChoicesMenu","Choices"));
Gtk::RadioAction::Group group_userlevel;
m_refChoiceOne=Gtk::RadioAction::create(group_userlevel,"ChoiceOne","One");
m_refActionGroup->add(m_refChoiceOne,sigc::mem_fun(*this,&_Window::on_menu_choices_one));
m_refChoiceTwo=Gtk::RadioAction::create(group_userlevel,"ChoiceTwo","Two");
m_refActionGroup->add(m_refChoiceTwo,sigc::mem_fun(*this,&_Window::on_menu_choices_two));


//help menu


m_refActionGroup->add(Gtk::Action::create("HelpMenu","Help"));
m_refActionGroup->add(Gtk::Action::create("HelpAbout",Gtk::Stock::HELP),sigc::mem_fun(*this,&_Window::on_menu_others));
m_refUIManager=Gtk::UIManager::create();
m_refUIManager->insert_action_group(m_refActionGroup);

add_accel_group(m_refUIManager->get_accel_group());


//Layout

Glib::ustring ui_info=
"<ui>"
"	<menubar name='MenuBar'>"	
"	<menu action='FileMenu'>"
"	<menu action='FileNew'>"
"	<menuitem action='FileNewStandard'/>"
"	<menuitem action='FileNewFoo'/>"
"	<menuitem action='FileNewGoo'/>"
"	</menu>"
"	<separator/>"
"	<menuitem action='FileQuit'/>"
"	</menu>"
"	<menu action='EditMenu'> "
//"	<menuitem action='EditCopy'/>"
//"	<menuitem action='EditPaste'/>"
//"	<menuitem action='EditSomething'/>"
"	</menu>"
"	<menu action='ChoicesMenu'>"
"	<menuitem action='ChoiceOne'/>"
"	<menuitem action='ChoiceTwo'/>"
"	</menu>"
"	<menu action='HelpMenu'>"
"	<menuitem action='HelpAbout'/>"
"	</menu>"
"	</menubar>"
"	<toolbar name='ToolBar'>"
"	<toolitem action='FileNewStandard'/>"
"	<toolitem action='FileQuit'/>"
"	</toolbar>"
"</ui>";

#ifdef GLIBMM_EXCEPTIONS_ENABLED
try
{

m_refUIManager->add_ui_from_string(ui_info);
}

catch(const Glib::Error &ex)
{
std::cerr<<"Building menus failed: "<<ex.what();
}
#else
std::auto_ptr<Glib::Error> ex;
m_refUIManager->add_ui_from_string(ui_info,ex);
if(ex.get())
{
std::cerr<<"Building menus failed: "<<ex->what();
}
#endif

//Get the menu bar and toolbar widgets and them to container widget
Gtk::Widget * pMenubar=m_refUIManager->get_widget("/MenuBar");
if(pMenubar)
m_VBox.pack_start(*pMenubar,Gtk::PACK_SHRINK);

Gtk::Widget * pToolbar=m_refUIManager->get_widget("/ToolBar");

if(pToolbar)
m_VBox.pack_start(*pToolbar,Gtk::PACK_SHRINK);



m_ScrolledWindow.add(m_TextView);

m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);

m_VBox.pack_start(m_ScrolledWindow);

m_VBox.pack_start(m_ButtonBox,Gtk::PACK_SHRINK);

m_ButtonBox.pack_start(m_Button_Buffer1,Gtk::PACK_SHRINK);
m_ButtonBox.pack_start(m_Button_Buffer2,Gtk::PACK_SHRINK);
m_ButtonBox.pack_start(m_Button_Quit,Gtk::PACK_SHRINK);
m_ButtonBox.set_border_width(5);
m_ButtonBox.set_spacing(5);
m_ButtonBox.set_layout(Gtk::BUTTONBOX_START);

m_ButtonBox.pack_start(m_Button_File,Gtk::PACK_SHRINK);
m_Button_File.signal_clicked().connect(sigc::mem_fun(*this,&_Window::on_button_file_clicked));

m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this,&_Window::on_button_quit));
m_Button_Buffer1.signal_clicked().connect(sigc::mem_fun(*this,&_Window::on_button_buffer1));
m_Button_Buffer2.signal_clicked().connect(sigc::mem_fun(*this,&_Window::on_button_buffer2));

fill_buffers();

on_button_buffer1();
m_VBox.pack_start(m_ButtonBox1,Gtk::PACK_SHRINK);

m_ButtonBox.pack_start(Compile);
Compile.signal_clicked().connect(sigc::mem_fun(*this,&_Window::compile_clicked));

m_ButtonBox.pack_start(Run);
Run.signal_clicked().connect(sigc::mem_fun(*this,&_Window::run_clicked));








show_all_children();
}

void _Window::run_clicked()
{
system("./new");

}

void _Window::compile_clicked()
{
std::cout<<"Compile called"<<endl;
char tring[50]="g++ ";
char tring1[50];
strcpy(tring1,name_file);
char tring2[]=" -o new";
strcat(tring,tring1);
int stat;
stat= system(strcat(tring,tring2));
if(stat==0)
cout<<"Compiled Successfully"<<endl;




Gtk::MessageDialog dialog(*this,"Compilation Status");
if(stat==0)
{
dialog.set_secondary_text("Successful");
}
else
dialog.set_secondary_text("Failed");

dialog.run();


}
void _Window::fill_buffers()
{

m_refTextBuffer1[0]=Gtk::TextBuffer::create();
m_refTextBuffer1[0]->set_text("");
//m_refTextBuffer1[0]->set_color(m_Color);







m_refTextBuffer1[1]=Gtk::TextBuffer::create();
m_refTextBuffer1[1]->set_text("");
}




int countt=2;




void _Window::add_buff()
{
m_refTextBuffer1[countt++]=Gtk::TextBuffer::create();
m_TextView.set_buffer(m_refTextBuffer1[countt-1]);
}



_Window::~_Window()
{
}




void _Window::on_button_quit()
{
hide();
}





void _Window::on_button_buffer3()
{
m_TextView.set_buffer(m_refTextBuffer1[countt-1]);

}

void _Window::on_button_buffer1()
{
m_TextView.set_buffer(m_refTextBuffer1[0]);
}







void _Window::on_button_buffer2()
{
m_TextView.set_buffer(m_refTextBuffer1[1]);
}




void _Window::on_menu_file_quit()
{
hide();
}




void _Window::on_menu_file_new_generic()
{
cout<<"A file new menu item was selected"<<endl;
}




void _Window::on_menu_others()
{
cout<<"A menu item was selected"<<endl;
}





void _Window::on_menu_choices_one()
{

Glib::ustring message;
if(m_refChoiceOne->get_active())
message="Choice 1 was selected ";
else
message="Choice 1 was deselected";

cout<<message<<endl;
}

void _Window::on_menu_copy()
{

cout<<"Copy pressed"<<endl;


}
void _Window::on_menu_choices_two()
{

Glib::ustring message;
if(m_refChoiceTwo->get_active())
message="Choice 2 was selected ";
else
message="Choice 2 was deselected";

cout<<message<<endl;
}




void _Window::on_button_folder_clicked()
{

Gtk::FileChooserDialog dialog("Please Choose a Folder",Gtk::FILE_CHOOSER_ACTION_SELECT_FOLDER);
dialog.set_transient_for(*this);


dialog.add_button(Gtk::Stock::CANCEL,Gtk::RESPONSE_CANCEL);
dialog.add_button("Select",Gtk::RESPONSE_OK);

int result=dialog.run();


//handle the response


switch(result)
{

case(Gtk::RESPONSE_OK):
{

cout<<"Select clicked"<<endl;
cout<<"Folder clinked: "<<dialog.get_filename()<<endl;
break;
}
case(Gtk::RESPONSE_CANCEL):
{

cout<<"Cancel Clicked"<<endl;
break;
}

default:
cout<<"Something unexpected"<<endl;
}

}

void _Window::on_button_file_clicked()
{
Gtk::FileChooserDialog dialog("Please Choose a File",Gtk::FILE_CHOOSER_ACTION_OPEN);
dialog.set_transient_for(*this);

dialog.add_button(Gtk::Stock::CANCEL,Gtk::RESPONSE_CANCEL);
dialog.add_button(Gtk::Stock::OPEN,Gtk::RESPONSE_OK);


Glib::RefPtr<Gtk::FileFilter>filter_text=Gtk::FileFilter::create();
filter_text->set_name("Text files");
filter_text->add_mime_type("text/plain");
dialog.add_filter(filter_text);

Glib::RefPtr<Gtk::FileFilter>filter_cpp=Gtk::FileFilter::create();
filter_cpp->set_name("C/C++ files");
filter_cpp->add_mime_type("text/x-c");
filter_cpp->add_mime_type("text/x-c++");
filter_cpp->add_mime_type("text/x-header");
dialog.add_filter(filter_cpp);

Glib::RefPtr<Gtk::FileFilter>filter_any=Gtk::FileFilter::create();
filter_any->set_name("Any files");
filter_any->add_pattern("*");
dialog.add_filter(filter_any);

int result=dialog.run();

switch(result)
{
case(Gtk::RESPONSE_OK):
{

cout<<"Open Clicked"<<endl;
string filename=dialog.get_filename();
const char *fname=filename.c_str();

strcpy(name_file,fname);









Glib::RefPtr<Gtk::TextBuffer::Tag>refTagMatch=Gtk::TextBuffer::Tag::create();
Glib::RefPtr<Gtk::TextBuffer::Tag>refTagMatch1=Gtk::TextBuffer::Tag::create();
Glib::RefPtr<Gtk::TextBuffer::Tag>refTagMatch2=Gtk::TextBuffer::Tag::create();
refTagMatch->property_foreground()="black";
refTagMatch1->property_foreground()="magenta";
refTagMatch2->property_foreground()="darkgreen";
Glib::RefPtr<Gtk::TextBuffer::TagTable>refTagTable=Gtk::TextBuffer::TagTable::create();
refTagTable->add(refTagMatch);
refTagTable->add(refTagMatch1);
refTagTable->add(refTagMatch2);







m_refTextBuffer1[countt++]=Gtk::TextBuffer::create(refTagTable);

FILE *fp;
/*
for(i=0;filename[i]!='\0';i++)
{
str[i]=filename[i];
}
str[i]='\0';*/
//char data[10000];
string s;
fp=fopen(fname,"r+");
char ch;
int l=0;
while(1)
{
	ch=fgetc(fp);
	if(ch==EOF)
	break;
	else
	s[l++]=ch;
}
s[l]='\0';
const char *data=s.c_str();
//string str=m_refTextBuffer1[countt]->get_text();



int len=strlen(data);
m_refTextBuffer1[countt-1]->set_text(data);
fclose(fp);




//m_refTextBuffer1[countt-1]=Gtk::TextBuffer::create(refTagTable);
//m_refTextBuffer1->set_text("Hello World");

Gtk::TextBuffer::iterator iter1,iter2,iter_temp,iter_temp2; 
//m_refTextBuffer1[countt-1]->set_text(data);
int it;
iter_temp=m_refTextBuffer1[countt-1]->get_iter_at_offset(0);
for(int i=0;data[i]!='\0';i++)
{
if((data[i]=='i'&&data[i+1]=='n'&&data[i+2]=='t'))
{
iter_temp=m_refTextBuffer1[countt-1]->get_iter_at_offset(i);
iter_temp2=m_refTextBuffer1[countt-1]->get_iter_at_offset(i+4);
m_refTextBuffer1[countt-1]->apply_tag(refTagMatch2,iter_temp,iter_temp2);
}
else if(data[i]=='#'&&data[i+1]=='i'&&data[i+2]=='n'&&data[i+3]=='c'&&data[i+8]=='<')
{int j;
for( j=i;data[j]!='>';j++);
iter_temp=m_refTextBuffer1[countt-1]->get_iter_at_offset(i);
iter_temp2=m_refTextBuffer1[countt-1]->get_iter_at_offset(j+1);
m_refTextBuffer1[countt-1]->apply_tag(refTagMatch1,iter_temp,iter_temp2);
}
else if((data[i]=='f'&&data[i+1]=='l'&&data[i+4]=='t'))
{
iter_temp=m_refTextBuffer1[countt-1]->get_iter_at_offset(i);
iter_temp2=m_refTextBuffer1[countt-1]->get_iter_at_offset(i+5);
m_refTextBuffer1[countt-1]->apply_tag(refTagMatch2,iter_temp,iter_temp2);
}
else if((data[i]=='c'&&data[i+1]=='h'&&data[i+2]=='a'&&data[i+3]=='r'))
{
iter_temp=m_refTextBuffer1[countt-1]->get_iter_at_offset(i);
iter_temp2=m_refTextBuffer1[countt-1]->get_iter_at_offset(i+4);
m_refTextBuffer1[countt-1]->apply_tag(refTagMatch2,iter_temp,iter_temp2);
}
else if(data[i]=='c'&&data[i+1]=='o'&&data[i+2]=='u'&&data[i+3]=='t')
{
iter_temp=m_refTextBuffer1[countt-1]->get_iter_at_offset(i);
iter_temp2=m_refTextBuffer1[countt-1]->get_iter_at_offset(i+4);
m_refTextBuffer1[countt-1]->apply_tag(refTagMatch2,iter_temp,iter_temp2);
}
else if(data[i]=='c'&&data[i+1]=='i'&&data[i+2]=='n')
{
iter_temp=m_refTextBuffer1[countt-1]->get_iter_at_offset(i);
iter_temp2=m_refTextBuffer1[countt-1]->get_iter_at_offset(i+3);
m_refTextBuffer1[countt-1]->apply_tag(refTagMatch2,iter_temp,iter_temp2);
}
}

iter1=m_refTextBuffer1[countt-1]->get_iter_at_offset(0);
//iter1=m_refTextBuffer1->insert(iter1, "Its time to duel");
//iter2=m_refTextBuffer1->insert(iter2,"Go dark");
iter2=m_refTextBuffer1[countt-1]->get_iter_at_offset(l);
m_refTextBuffer1[countt-1]->apply_tag(refTagMatch,iter1,iter2);


//m_refTextBuffer1[countt-1]->remove_all_tags(iter1,iter2);











m_ButtonBox.pack_start(m_Button_Save,Gtk::PACK_SHRINK);
on_button_buffer3();
m_Button_Save.signal_clicked().connect(sigc::mem_fun(*this,&_Window::on_button_buffer3));
show_all_children();





break;
}
case(Gtk::RESPONSE_CANCEL):
{

cout<<"Cancel Clicked"<<endl;
break;
}
default:
cout<<"Something unexpected clicked"<<endl;
}


}
