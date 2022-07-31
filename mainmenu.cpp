#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<unistd.h>
#include<string.h>
#include<windows.h>
using namespace std;
class home{
	public:
	void coord_xy(short x, short y);  //define goto function of xy..
    void intro_page();
    void unive();
    void menu();
    
};
void home::coord_xy(short x,short y)
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
 
void home::intro_page() {
	int i=0;
	for(i=4;i<11;i++){
		coord_xy(23,i);cout<<"%c%c",178,178;usleep(1000);
        coord_xy(22+i,7);cout<<"%",178;usleep(1000);
		coord_xy(31,i);cout<<"%c%c",178,178;usleep(1000);
		
		coord_xy(46-i,i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(40+i,i);cout<<"%c%c",178,178;usleep(100);
		coord_xy(38+i,8);cout<<"%c",178;usleep(1000);
	
		coord_xy(55,i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(52+i,4);cout<<"%c",178;usleep(100);
		coord_xy(61,(i+4)/2);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(59+i,4);cout<<"%c",178;usleep(100);
		coord_xy(67,i);cout<<"%c%c",178,178;usleep(1000);
		
		coord_xy(72,i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(72+i,4);cout<<"%",178;usleep(100);
		coord_xy(79,(i+4)/2);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(71+i,7);cout<<"%c",178;usleep(100);
		coord_xy(71+i,(i+10)/2);cout<<"%c%c",178,178;usleep(1000);
		
	    coord_xy(85,i);cout<<"%c%c",178,178;usleep(1000);
    	coord_xy(82+i,4);cout<<"%",178;usleep(100);
	    coord_xy(82+i,10);cout<<"%",178;usleep(100);
	    coord_xy(91,i);cout<<"%c%c",178,178;usleep(1000);
		
		//anoter
		coord_xy(31-i,10+i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(10+i,10+i);cout<<"%c%c",178,178;usleep(100);
		
		coord_xy(35,10+i);cout<<"%c%",178,178;usleep(1000);
		coord_xy(29+i,14);cout<<"%",190;usleep(1000);
        coord_xy(29+i,20);cout<<"%",190;usleep(1000);
        
       	coord_xy(41,10+i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(41+i,14);cout<<"%",178;usleep(100);
		coord_xy(48,(i+25)/2);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(40+i,17);cout<<"%c",178;usleep(100);
		coord_xy(40+i,(i+30)/2);cout<<"%c%c",178,178;usleep(1000);
		
		coord_xy(57,10+i);cout<<"%c%",178,178;usleep(1000);
		coord_xy(51+i,14);cout<<"%",190;usleep(1000);
		
		coord_xy(63,10+i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(60+i,20);cout<<"%",190;usleep(1000);
		coord_xy(70,10+i);cout<<"%c%c",178,178;usleep(1000);
		
		coord_xy(85-i,10+i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(79+i,10+i);cout<<"%c%c",178,178;usleep(100);
		coord_xy(77+i,18);cout<<"%c",178;usleep(1000);
		
		coord_xy(95,10+i);cout<<"%c%",178,178;usleep(1000);
		coord_xy(91+i,20);cout<<"%",190;usleep(1000);
		
		//another saathi
		coord_xy(20+i,24);cout<<"%c",178;usleep(100);
		coord_xy(21,(i+44)/2);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(20+i,27);cout<<"%c",178;usleep(100);
		coord_xy(28,(i+51)/2);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(17+i,30);cout<<"%c",178;usleep(100);
		
		coord_xy(42-i,20+i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(36+i,20+i);cout<<"%c%c",178,178;usleep(100);
		coord_xy(33+i,28);cout<<"%",178;usleep(1000);
		
		coord_xy(59-i,20+i);cout<<"%c%c",178,178;usleep(1000);
		coord_xy(52+i,20+i);cout<<"%c%c",178,178;usleep(100);
		coord_xy(49+i,28);cout<<"%c",178;usleep(1000);
		
		coord_xy(67,20+i);cout<<"%c%",178,178;usleep(1000);
		coord_xy(61+i,24);cout<<"%",190;usleep(1000);
		
		coord_xy(74,20+i);cout<<"%c%c",178,178;usleep(1000);
        coord_xy(70+i,27);cout<<"%",178;usleep(1000);
		coord_xy(80,20+i);cout<<"%c%c",178,178;usleep(1000);
		
		coord_xy(87,20+i);cout<<"%c%",178,178;usleep(1000);
		coord_xy(81+i,24);cout<<"%",190;usleep(1000);
        coord_xy(81+i,30);cout<<"%",190;usleep(1000);	
	}
	coord_xy(56,43);getchar();
	system("cls");
}
	
	void home::unive(){
	coord_xy(27,13);cout<<" ____    ____     ___     ____   ____       _      __  __ ";usleep(100000);
	coord_xy(27,14);cout<<"|  _ \\  |  _ \\   / _ \\   / ___| |  _ \\     / \\    |  \\/  |";usleep(100000);
	coord_xy(27,15);cout<<"| |_) | | |_) | | | | | | |  _  | |_) |   / _ \\   | |\\/| |";usleep(100000);
	coord_xy(27,16);cout<<"|  __/  |  _ <  | |_| | | |_| | |  _ <   / ___ \\  | |  | |";usleep(100000);
	coord_xy(27,17);cout<<"|_|     |_| \\_\\  \\___/   \\____| |_| \\_\\ /_/   \\_\\ |_|  |_|";usleep(100000);
	
	coord_xy(15,19);cout<<"	  _       _   _             _                        ___      _  _   __ ___ ___    "; usleep(100000); 
	coord_xy(15,20);cout<<"	 |_) | | |_) |_)  /\\  |\\ | /  |_|  /\\  |    | | |\\ |  | \\  / |_ |_) (_   |   | \\_/ ";usleep(100000);
	coord_xy(15,21);cout<<"	 |   |_| | \\ |_) /--\\ | \\| \\_ | | /--\\ |_   |_| | \\| _|_ \\/  |_ | \\ __) _|_  |  |  ";usleep(100000);
	
	coord_xy(17,23);cout<<"WELCOME>>>  ";coord_xy(28,23);cout<<"Press any key to continue...";
	coord_xy(56,23);getchar();		
	}
			                                                    	
int main(){
	home h;
	h.intro_page();
	h.unive();
	system("cls");
	return 0;
}
//daami xa rishi.
