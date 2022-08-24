/* ######################################################################################################
   ##**************************   	 Mero Virtual Saathi       ************************************##
   ##							                                               ##
   ##				         PURBANCHAL UNIVERSITY                                         ##
   ##												       ##		  					   ##
   ## Submitted to:- Kantipur City College                      Prepared by:- John Subba, Rishi Khadka ##
   ###################################################################################################### */





#include<iostream>
#include<windows.h>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<array>
#include<conio.h>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


typedef struct speech_value{
	int number_mark;
	char user_speech_copy[100];
}Speech;
	
typedef struct Word_Analyzer{
	int Greeting;
	int Question;
	int Task;
	int Statement;
}Word_value;

typedef struct country_details{
	char country_name[20];
	char country_capital[20];
	char total_area[20];
	char currency[20];
	char dominant_language[20];
	char literacy_rate[10];
}country;

void coord_xy(short x, short y){
 		COORD pos ={x,y};
 		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Intro_page(){
	int i=0;
	for(i=4;i<11;i++){
		coord_xy(48,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(44+i,4);printf("%c",178);usleep(100);
		coord_xy(54,(i+4)/2);printf("%c%c",178,178);usleep(1000);
		coord_xy(82,(i+4)/2);printf("%c%c",178,178);usleep(1000);
		coord_xy(50+i,4);printf("%c",178);usleep(100);
		coord_xy(60,i);printf("%c%c",178,178);usleep(1000);
		
		coord_xy(65,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(62+i,4);printf("%c",178);usleep(100);
		coord_xy(62+i,7);printf("%c",178);usleep(1000);
		coord_xy(62+i,10);printf("%c",178);usleep(100);
		
		coord_xy(75,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(72+i,4);printf("%c",178);usleep(100);
		coord_xy(72+i,7);printf("%c",178);usleep(1000);
	//	coord_xy(62+i,10);printf("%c",178);usleep(100);
		
		coord_xy(73+i,5+(i/2));printf("%c%c",178,178);usleep(1000);
	//	coord_xy(81-i,i);printf("%c%c",178,178);usleep(100);
	//	coord_xy(91-i,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(87,i);printf("%c%c",178,178);usleep(1000);
		coord_xy(85+i,4);printf("%c",178);usleep(100);
		coord_xy(95,i);printf("%c%c",178,178);usleep(1000);
		//coord_xy(75+i,7);printf("%c",178);usleep(1000);
		coord_xy(85+i,10);printf("%c",178);usleep(100);
		
	}
//	coord_xy(27,13);printf("| | | | || | \\    ____   ____       _      __  __ ");usleep(100000);
//	coord_xy(27,14);printf("| | | | || |  ]]   / _ \\   / ___| |  _ \\     / \\    |  \\/  |");usleep(100000);
//	coord_xy(27,15);printf("| |_| | || |__))| | | | | |  _  | |_) |   / _ \\   | |\\/| |");usleep(100000);
//	coord_xy(27,16);printf("\     / || --- <  | |_| | | |_| | |  _ <   / ___ \\  | |  | |");usleep(100000);
//	coord_xy(27,17);printf(" \__ /  || |_| \\_\\  \\___/   \\____| |_| \\_\\ /_/   \\_\\ |_|  |_|");usleep(100000);
	
coord_xy(27,13);printf(" __   __   ___     ___   _____   _   _    ___     _         ___    ___     ___    _____   _  _     ___  ");usleep(100000);
coord_xy(27,14);printf(" \\ \\ / /  |_ _|   | _ \\ |_   _| | | | |  /   \\   | |       / __|  /   \\   /   \\  |_   _| | || |   |_ _|      ");usleep(100000);
coord_xy(27,15);printf("  \\ V /    | |    |   /   | |   | |_| |  | - |   | |__     \\__ \\  | - |   | - |    | |   | __ |    | |      ");usleep(100000);
coord_xy(27,16);printf("  _\\_/_   |___|   |_|_\\  _|_|_   \\___/   |_|_|   |____|    |___/  |_|_|   |_|_|   _|_|_  |_||_|   |___|    ");usleep(100000);
//coord_xy(27,17);printf("_| """"|_|""""""|_|""""""|_|""""""|_|""""""|_|""""""|_|""""""| {======|_|""""""|_|""""""|_|""""""|_|""""""|_|""""""|_|""""""| {======| ");usleep(100000);
//coord_xy(27,18);printf("`-0-0-'""`-0-0-'""`-0-0-'""`-0-0-'""`-0-0-'""`-0-0-'""`-0-0-'./o--000'""-0-0-'""-0-0-'""-0-0-'""-0-0-'""-0-0-'""`-0-0-'./o--000'  ");usleep(100000);
	
	coord_xy(35,28);printf("	  _       _   _             _                        ___      _  _   __ ___ ___    "); usleep(100000); 
	coord_xy(35,29);printf("	 |_) | | |_) |_)  /\\  |\\ | /  |_|  /\\  |    | | |\\ |  | \\  / |_ |_) (_   |   | \\_/ ");usleep(100000);
	coord_xy(35,30);printf("	 |   |_| | \\ |_) /--\\ | \\| \\_ | | /--\\ |_   |_| | \\| _|_ \\/  |_ | \\ __) _|_  |  |  ");usleep(100000);
	
	coord_xy(27,23);printf("WELCOME>>>  ");coord_xy(38,23);printf("Press any key to continue...");
	coord_xy(66,23);getchar();
                                                                                   
							                                                    	
}

char saathi_login_prompt(){
    char secret_code[20]="saathi_123", s_code[20],c;
    int y,i=0;

    while (1){
		do{
			coord_xy(60+i,6);
			c=getch();
			if(c==8){
				i--;
				coord_xy(60+i,6);printf(" ");
				continue;
			}
			s_code[i]=c;
			coord_xy(60+i,6);printf("*");
			i++;
			if(c=='\r'){
				coord_xy(60+(i-1),6);printf(" ");
			}
		}while(c!='\r'); 
		coord_xy(60+(i-1),6);             
		s_code[i-1]='\0'; //to let compiler know the end of char stored in p.
		i=0;
        fflush(stdin);
        y=strcmp(s_code, secret_code);
    	if(y==0){
    	return '1';
        }
		else {
        return '7';
        }
       };
       
}

void new_info_to_database(country *c){
	ofstream country_info;
	country_info.open("country_database.bin",ios_base::binary|ios_base::app);
	coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
	cout<<"Country Name: ";cin>>c->country_name;fflush(stdin);
	coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
	cout<<c->country_name<<"'s Capital: ";cin>>c->country_capital;fflush(stdin);
	coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
	cout<<c->country_name<<"'s Area: ";cin>>c->total_area;fflush(stdin);
	coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
	cout<<c->country_name<<"'s Currency: ";cin>>c->currency;fflush(stdin);
	coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
	cout<<c->country_name<<"'s Dominant Language: ";cin>>c->dominant_language;fflush(stdin);
	coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
	cout<<c->country_name<<"'s Literacy Rate: ";cin>>c->literacy_rate;fflush(stdin);
	country_info.write((char *) c,sizeof(country));
	country_info.close();
}

void modify_info_to_database(){
	ifstream country_existing_info;
	ofstream country_new_info;
	string local_country_name, local_temp_1;
	country local_temp;
	int local_flag{0};
	country_existing_info.open("country_database.bin",ios_base::binary|ios_base::in);
	country_new_info.open("country_database_new.bin",ios_base::binary|ios_base::out);
	coord_xy(30,6);cout<<"                                                                      ";
	coord_xy(30,6);
	system("@echo off");
	system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Enter the name of country you want to modify: \"");
	cout<<"Enter the name of country you want to modify: ";cin>>local_country_name;
	transform(local_country_name.begin(), local_country_name.end(), local_country_name.begin(), ::tolower);
	country_existing_info.read((char *) &local_temp,sizeof(country));
	while(!country_existing_info.eof()){
		local_temp_1 = local_temp.country_name; 
		transform(local_temp_1.begin(), local_temp_1.end(), local_temp_1.begin(), ::tolower);
		if(local_country_name == local_temp_1){
			local_flag = 2;
			coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
			cout<<"Enter new details now:";getchar();
			coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
			cout<<"Country Name: ";cin>>local_temp.country_name;fflush(stdin);
			coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
			cout<<local_temp.country_name<<"'s Capital: ";cin>>local_temp.country_capital;fflush(stdin);
			coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
			cout<<local_temp.country_name<<"'s Area: ";cin>>local_temp.total_area;fflush(stdin);
			coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
			cout<<local_temp.country_name<<"'s Currency: ";cin>>local_temp.currency;fflush(stdin);
			coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
			cout<<local_temp.country_name<<"'s Dominant Language: ";cin>>local_temp.dominant_language;fflush(stdin);
			coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
			cout<<local_temp.country_name<<"'s Literacy Rate: ";cin>>local_temp.literacy_rate;fflush(stdin);
			country_new_info.write((char *) &local_temp,sizeof(country));
			fflush(stdin);
			//continue;								
		}
		else
		{
		country_new_info.write((char *) &local_temp, sizeof(country));
		}
		country_existing_info.read((char *) &local_temp,sizeof(country));
	}
	country_existing_info.close();
	country_new_info.close();
	remove("country_database.bin");
	rename("country_database_new.bin","country_database.bin");
	if(local_flag != 2){
		coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
		cout<<"I think this country doesnot exists in our database\n";
	}
	
}

char user_voice[100];	
	
class Boundary_Frame{
	public:
		void coord_xy(short x, short y){
 			COORD pos ={x,y};
 			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		void full_outer_frame(){
			coord_xy(2,0);
			for(int i=0;i<150;i++){
				cout<<(char)220;
			}
			coord_xy(2,1);cout<<(char)219;
			for(int j=2;j<34;j++){
				coord_xy(2,j);
				cout<<(char)219;
			}
			coord_xy(151,1);cout<<(char)219;
			for(int j=2;j<34;j++){
				coord_xy(151,j);
				cout<<(char)219;
			}
			coord_xy(2,34);
			for(int i=0;i<150;i++){
				cout<<(char)223;
			}
		}
		void full_inner_frame(){
			coord_xy(3,1);
			for(int i=0;i<147;i++){
				cout<<(char)178;
			}
			coord_xy(3,1);cout<<(char)178;
			for(int j=1;j<33;j++){
				coord_xy(3,j);
				cout<<(char)178;
			}
			coord_xy(150,1);cout<<(char)178;
			for(int j=1;j<34;j++){
				coord_xy(150,j);
				cout<<(char)178;
			}
			coord_xy(3,33);
			for(int i=0;i<147;i++){
				cout<<(char)178;
			}
			coord_xy(4,35);
		}
		void saathi_communication_frame(){
			coord_xy(67,3);cout<<"|VIRTUAL SAATHI|";
			coord_xy(67,4);cout<<"****************";
			coord_xy(15,2);
			for(int i=0;i<122;i++){
				cout<<(char)178;
			}
			coord_xy(15,2);cout<<(char)178;
			for(int j=2;j<10;j++){
				coord_xy(15,j);
				cout<<(char)178;
			}
			coord_xy(137,2);cout<<(char)178;
			for(int j=2;j<11;j++){
				coord_xy(137,j);
				cout<<(char)178;
			}
			coord_xy(15,10);
			for(int i=0;i<122;i++){
				cout<<(char)178;
			}
			coord_xy(4,35);
		}
		void user_communication_frame(){
			coord_xy(67,21);cout<<"|USER|";
			coord_xy(67,22);cout<<"******";
			coord_xy(15,20);
			for(int i=0;i<122;i++){
				cout<<(char)178;
			}
			coord_xy(15,20);cout<<(char)178;
			for(int j=20;j<32;j++){
				coord_xy(15,j);
				cout<<(char)178;
			}
			coord_xy(137,20);cout<<(char)178;
			for(int j=20;j<33;j++){
				coord_xy(137,j);
				cout<<(char)178;
			}
			coord_xy(15,32);
			for(int i=0;i<122;i++){
				cout<<(char)178;
			}
			coord_xy(4,35);
		}
		
	
		
};

class User_Speech;
class Saathi_Speech:public Boundary_Frame{
	char saathi_voice[100];
	public:
		void speech_start();
		void conversation_start();
		int random_number_generator();
		void conversation_state_updater();
		void conversation_state_finder(Word_value W_temp, string user_voice_str);
		void question_response(string user_voice_str);
		void task_response(string user_voice_str);
		void statement_response(string user_voice_str);
		void greeting_response(string user_voice_str);
		friend User_Speech;
		
};


class User_Speech:public Boundary_Frame{
	Saathi_Speech S1;
	public:
		
		Saathi_Speech Saathi_temp;
		void user_voice_input();
		
};

void User_Speech::user_voice_input(){
			coord_xy(30,25);
			coord_xy(30,25);cout<<"                                                                      ";
			coord_xy(30,25);
			gets(user_voice);
			string user_voice_str{user_voice};
			transform(user_voice_str.begin(), user_voice_str.end(), user_voice_str.begin(), ::tolower);
		//	string correction_string;
		//	Saathi_Speech temp_for_user;
		//	correction_string= " " + user_voice_str;
			//cout<<correction_string<<endl;
			//cout<<user_voice<<endl;
			//strcat(correction_string,user_voice);
		//	string user_voice_str{user_voice};
			user_voice_str += " ";
		//	transform(user_voice_str.begin(), user_voice_str.end(), user_voice_str.begin(), ::tolower);
			Word_value W_temp{0};
			//cout<<user_voice_str<<"5"<<endl;
		//	cout<<W_temp.Question<<" "<<W_temp.Task<<" "<<W_temp.Greeting<<" "<<W_temp.Statement;
			array<string, 10> question{"what ", "where ", "whose ","how ","why ","when ","wher ","whos ","who ","whom "};
			auto iteration1 = find_if(begin(question), end(question),[&](const string& our_string)
                       {return user_voice_str.find(our_string) != string::npos; });
           // cout<<iteration1<<" "<<end(question);
            if (iteration1 != end(question))
				{
    				W_temp.Question += 7;
				//	cout<<"dahel";
				}
			array<string, 5> task{"do ", "make ", "please ","will ","would "};
			auto iteration2 = find_if(begin(task), end(task),[&](const string& our_string)
                       {return user_voice_str.find(our_string) != string::npos; });
            if (iteration2 != end(task))
				{
    				W_temp.Task += 6;
				//	cout<<"ok";
				}
			
			array<string, 19> greeting{"hello ","greetings ","greeting ", "namaste ", "hi ","hey ","morning ","night ","yo ","helo ","afternoon ","evening ","namste ",
			"namashte ","mornin ","nite ","nightt ","evenin ","afternon "};
			auto iteration3 = find_if(begin(greeting), end(greeting),[&](const string& our_string)
                       {return user_voice_str.find(our_string) != string::npos; });
            if (iteration3 != end(greeting))
				{
    				W_temp.Greeting += 4;
					//cout<<"nice";
				}
			if((W_temp.Question&&W_temp.Task&&W_temp.Greeting)==0)
				{
					W_temp.Statement++;
				//	cout<<"cool";	
				}
			
//			if((user_voice_str.find("what")) != string::npos){
//				W_temp.Question++;
//				cout<<"dahel";
//				
//			}
//			else if((user_voice_str.find("(make)|(do)")) != string::npos){
//				W_temp.Task++;
//				cout<<"yes";
//				
//			}
//			else if((user_voice_str.find("hello"||"namaste")) != string::npos){
//				W_temp.Greeting++;
//				
//			}
//			else
//			{
//				W_temp.Statement++;
//				
//			}
		
		//	cout<<W_temp.Question<<" "<<W_temp.Task<<" "<<W_temp.Greeting<<" "<<W_temp.Statement;
			S1.conversation_state_finder(W_temp,user_voice_str);
			
	}
	
void Saathi_Speech::conversation_state_finder(Word_value temp_value,string user_voice_str){
		
		if(temp_value.Question==7){
		//	cout<<temp_value.Statement<<endl;
			//cout<<"this is question\n";
			question_response(user_voice_str);
			
		}
		else if(temp_value.Task==6){
		//	cout<<temp_value.Statement<<endl;
			//cout<<"this is task\n";
			task_response(user_voice_str);
			
		}
		else if(temp_value.Greeting==4){
		//	cout<<temp_value.Statement<<endl;
		//	cout<<"this is greetings\n";
		//	cout<<user_voice_str<<endl;
			greeting_response(user_voice_str);
			
		}
		else if(temp_value.Statement==1){
			
		//	cout<<"this is statement\n";
			statement_response(user_voice_str);
		}
		else{
			return;
		}
		
		
		
	}

void Saathi_Speech::question_response(string user_voice_str){
	array<string, 3> q_task1{"what ","wat ","waht ",};
			auto iteration_task_q1 = find_if(begin(q_task1), end(q_task1),[&](const string& our_task_string)
                       {return user_voice_str.find(our_task_string) != string::npos; });
           
            if (iteration_task_q1 != end(q_task1))
				{
					string local_temp_1,word_finder[10];
					int index{0};
					array<string, 140> task0{"afghanistan ","albania ","algeria ","andorra ","angola ","antigua and barbuda ","argentina ","armenia ",
					"australia ","austria ","azerbaijan ","bahamas ","bahrain ","bangladesh ","barbados ","belarus ","belgium ","belize ","benin ","bhutan ","bolivia ","bosnia and herzegovina ","botswana ",
					"brazil ","brunie ","bulgaria ","burkina faso ","burundi ","cambodia ","cameroon ","canada ","cape verde ","central african republic ","chad ","chile ","china ","colombia ","comoros ","costa rica ","croatia ","cuba ","cyprus ",
					"czech republic ","denmark ","egypt ","ecuador ","estonia ","fiji ","finland ","france ","gabon ","gambia ","germany ","ghana ","greece ","guatemala ","hungary ","haiti ","iceland ","india ","indonesia ","iran ","iraq ","ireland ",
					"israel ","italy ","jamaica ","japan ","jordan ","kuwait ","north korea ","south korea ","kenya ","kazakhstan ","kyrgyzstan ","laos ","latvia ","lebanon ","libya ","luxembourg ","malaysia ","malawi ","madagascar ","maldives ","mali ","malta ",
					"mexico ","moldova ","myanmar ","morocco ","namibia ","nepal ","netherlands ","new zealand ","nigeria ","norway ","oman ","pakistan ","palau ","palestine ","panama ","paraguay ","poland ","peru ","philippines ","portugal ","qatar ","romania ","russia ",
					"senegal ","saudi arabia ","serbia ","singapore ","slovakia ","slovenia ","somalia ","spain ","sri lanka ","south africa ","sudan ","suriname ","sweden ","switzerland ","syria ","thailand ","turkey ","tunisia ","ukraine ","uruguay ","uk ","united kingdom ",
					"usa ","united states of america ","uae ","united arab emirates ","vietnam ","venezuela ","yemen ","zimbabwe ","zambia ",};
					auto sub_iteration_task_0 = find_if(begin(task0), end(task0),[&](const string& our_subtask_string)
                    {if( user_voice_str.find(our_subtask_string) != string::npos){
                       	word_finder[0] = our_subtask_string;
                       	}
						return user_voice_str.find(our_subtask_string) != string::npos;
						});
						
    				array<string, 3> task1{"kapital ","capital ","capitel ",};
					auto sub_iteration_task_1 = find_if(begin(task1), end(task1),[&](const string& our_subtask_string)
                    {if( user_voice_str.find(our_subtask_string) != string::npos){
                       	word_finder[1] = "capital";
                       	}
						return user_voice_str.find(our_subtask_string) != string::npos;
						});
						
					array<string, 4> task2{"currency ","curency ","monetary ","money ",};
					auto sub_iteration_task_2 = find_if(begin(task2), end(task2),[&](const string& our_subtask_string)
                    {if( user_voice_str.find(our_subtask_string) != string::npos){
                       	word_finder[2] = "currency";
                       	}
						return user_voice_str.find(our_subtask_string) != string::npos;
						});
						
					array<string, 3> task3{"literacy ","education ","literate ",};
					auto sub_iteration_task_3 = find_if(begin(task3), end(task3),[&](const string& our_subtask_string)
                    {if( user_voice_str.find(our_subtask_string) != string::npos){
                       	word_finder[3] = "literacy";
                       	}
						return user_voice_str.find(our_subtask_string) != string::npos;
						});
						
					array<string, 4> task4{"area ","big ","landmass ","area covered ",};
					auto sub_iteration_task_4 = find_if(begin(task4), end(task4),[&](const string& our_subtask_string)
                    {if( user_voice_str.find(our_subtask_string) != string::npos){
                       	word_finder[4] = "area";
                       	}
						return user_voice_str.find(our_subtask_string) != string::npos;
						});
						
					array<string, 4> task5{"dominant language ","language ","spoken ","dominant ",};
					auto sub_iteration_task_5 = find_if(begin(task5), end(task5),[&](const string& our_subtask_string)
                    {if( user_voice_str.find(our_subtask_string) != string::npos){
                       	word_finder[5] = "language";
                       	}
						return user_voice_str.find(our_subtask_string) != string::npos;
						});
						
           			//cout<<word_finder[0]<<" "<<word_finder[1]<<" "<<word_finder[2]<<" "<<endl;getchar();
            		if ((sub_iteration_task_1 != end(task1)) || (sub_iteration_task_2 != end(task2)) || (sub_iteration_task_3 != end(task3))
					 || (sub_iteration_task_4 != end(task4)) || (sub_iteration_task_5 != end(task5)) )
					{
						ifstream reader;country s0;
						int local_flag_l1{0};
						reader.open("country_database.bin",ios::binary|ios::in);
						while(!reader.eof()){
						//	cout<<"we are here\n";
							reader.read((char *) &s0, sizeof(country));fflush(stdin);
							local_temp_1 = s0.country_name;
							local_temp_1 += " ";
							transform(local_temp_1.begin(), local_temp_1.end(), local_temp_1.begin(), ::tolower);
							//cout<<local_temp_1<<" "<<word_finder[0]<<endl;getchar();
							if(word_finder[0]==local_temp_1){
							//	cout<<"matched\n";getchar();
								local_flag_l1 = 33;
								break;								
							}
						}
						reader.close();
						if(local_flag_l1 != 33){
							system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" It seems this country doesnot exists in our Database \"");
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"It seems this country doesnot exists in our Database\n"<<endl;
							return;
							
						}
						if(word_finder[1]=="capital"){
							string local_temp1 = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Hey It's capital is: ";
							local_temp1 += s0.country_capital;
							local_temp1 += "\"";
							const char* command1 = local_temp1.c_str();
							system("@echo off");
							//cout<<temp1<<endl;getchar();
							system(command1);
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"Hey It's capital is: "<<s0.country_capital<<endl;
							
						}
						if(word_finder[2]=="currency"){
							string local_temp1 = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \" This country uses: ";
							local_temp1 += s0.currency;
							local_temp1 += "\"";
							const char* command1 = local_temp1.c_str();
							system("@echo off");
							//cout<<temp1<<endl;getchar();
							system(command1);
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"This country uses: "<<s0.currency<<endl;
							
						}
						
						if(word_finder[3]=="literacy"){
							string local_temp1 = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \" It's literacy rate is: ";
							local_temp1 += s0.literacy_rate;
							local_temp1 += "\"";
							const char* command1 = local_temp1.c_str();
							system("@echo off");
							//cout<<temp1<<endl;getchar();
							system(command1);
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"It's literacy rate is: "<<s0.literacy_rate<<endl;
							
						}
						
						if(word_finder[4]=="area"){
							string local_temp1 = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \" It covers a total area of: ";
							local_temp1 += s0.total_area;
							local_temp1 += "\"";
							const char* command1 = local_temp1.c_str();
							system("@echo off");
							//cout<<temp1<<endl;getchar();
							system(command1);
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"It covers a total area of: "<<s0.total_area<<endl;
							
						}
						
						if(word_finder[5]=="language"){
							string local_temp1 = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Majority here speak's: ";
							local_temp1 += s0.dominant_language;
							local_temp1 += "\"";
							const char* command1 = local_temp1.c_str();
							system("@echo off");
							//cout<<temp1<<endl;getchar();
							system(command1);
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"Majority here speak's: "<<s0.dominant_language<<endl;
							
						}
//						system("@echo off");
//						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Hey I have displayed the results for you: \"");
//						coord_xy(30,6);cout<<"                                                                      ";
//						coord_xy(30,6);
//						cout<<"Sure, Saathi"<<endl;
						//no_value_flag[0]++;
    				//	system("start swriter || start word");
				
					}
				}
	
	
	
}

void Saathi_Speech::task_response(string user_voice_str){
			array<string, 9> task{"open ","make ","play ","search ","searc ","searh ","display ","start ","run ",};
			auto iteration_task = find_if(begin(task), end(task),[&](const string& our_task_string)
                       {return user_voice_str.find(our_task_string) != string::npos; });
           
            if (iteration_task != end(task))
				{
					int no_value_flag[40]{0};
    				array<string, 4> task1{"word ", "msword ","mirosoftword ","libreoffice "};
					auto sub_iteration_task_1 = find_if(begin(task1), end(task1),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_1 != end(task1))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Sure saathee \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"Sure, Saathi"<<endl;
						no_value_flag[0]++;
    					system("start swriter || start word");
				
					}
				
					array<string, 3> task2{"calc ", "calculator ","calcultor "};
					auto sub_iteration_task_2 = find_if(begin(task2), end(task2),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_2 != end(task2))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Ok Saathee \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"Ok, Saathi"<<endl;
						no_value_flag[1]++;
    					system("start calc");
				
					}
					array<string, 3> task3{"youtube ", "ytube ","tube "};
					auto sub_iteration_task_3 = find_if(begin(task3), end(task3),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_3 != end(task3))
					{	
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" No Problem, Saathee \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"No Problem, Saathi"<<endl;
						no_value_flag[2]++;
    					system("start www.youtube.com");
				
					}
					array<string, 8> task4{"browser ", "google.com ","google ","edge ","web ","chrome ","mozilla ","firefox "};
					auto sub_iteration_task_4 = find_if(begin(task4), end(task4),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_4 != end(task4))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Ok cha Saathee \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"Ok cha, Saathi"<<endl;
						no_value_flag[3]++;
    					system("start www.google.com");
				
					}
					array<string, 6> task5{"music ", "song ","songs ","mp3 ","audio ","musi "};
					auto sub_iteration_task_5 = find_if(begin(task5), end(task5),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_5 != end(task5))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" On It, Saathee \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"On it, Saathi"<<endl;
						no_value_flag[4]++;
						system("cd .. && cd .. && start music && cd music && start vlc \"Bipul Chettri - Syndicate (Single).mp3\"");
						system("start wmplayer");
    	
					}
					array<string, 5> task6{"share ", "stock ","shares ","stocks ","meroshare ",};
					auto sub_iteration_task_6 = find_if(begin(task6), end(task6),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_6 != end(task6))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Opening It, Saathee \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"Opening it, Saathi"<<endl;
						no_value_flag[5]++;
						system("@echo off");
						system("start https://www.sharesansar.com/today-share-price && start https://nepsealpha.com/ && start https://mrnepse.com/ && start https://meroshare.cdsc.com.np/#/login");
    	
					}
					
					array<string, 4> task7{"notepad ", "notepd ","notpad ","notes ",};
					auto sub_iteration_task_7 = find_if(begin(task7), end(task7),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_7 != end(task7))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" note pad is here, \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"Notepad is here\n"<<endl;
						no_value_flag[6]++;
						system("@echo off");
						system("start notepad");
    	
					}
					
					array<string, 4> task8{"camera ", "cam ","camra ","cameras ",};
					auto sub_iteration_task_8 = find_if(begin(task8), end(task8),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_8 != end(task8))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" camera is opened, be sure to take good selfie \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"Camera is opened, be sure to take good selfie\n"<<endl;
						no_value_flag[7]++;
						system("@echo off");
						system("start microsoft.windows.camera:");
    	
					}
					
					array<string, 6> task9{"voice ", "recorder ","sound ","recorder ","voicerecorder ","soundrecorder ",};
					auto sub_iteration_task_9 = find_if(begin(task9), end(task9),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (sub_iteration_task_9 != end(task9))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Voice recorder started, have a check on your beautiful voice \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"Voice recorder started, have a check on your beautiful voice \n"<<endl;
						no_value_flag[8]++;
						system("@echo off");
						system("explorer.exe shell:appsFolder\\Microsoft.WindowsSoundRecorder_8wekyb3d8bbwe!App");
    	
					}
					
					
					if((no_value_flag[0] + no_value_flag[1] + no_value_flag[2] + no_value_flag[3] + no_value_flag[4] + no_value_flag[5] + no_value_flag[6]
					+no_value_flag[7] + no_value_flag[8])==0){
						char command[100]; 
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						strcpy(command,"espeak -a 150 -p 85 -s 130 -ven-us+f5 \" ");
						strcat(command,"Maybe you could find it in the Internet! Good luck");
						strcat(command," \"");
	
						system("@echo off");
						sleep(1);
						cout<<"Maybe you could find it in the Internet! Good luck";
						system(command);
						system("start www.google.com");	
					}
				}
				
			array<string, 4> n1_task{"close ", "stop ","kill ","exit ",};
					auto iteration_task_n1 = find_if(begin(n1_task), end(n1_task),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (iteration_task_n1 != end(n1_task))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" See your later \"");
						coord_xy(30,6);cout<<"                                                                      ";
						coord_xy(30,6);
						cout<<"See your later \n"<<endl;
						system("@echo off");
						sleep(1);
						coord_xy(4,35);
						exit(0);
						
    	
					}
					
			array<string, 4> n2_task{"create new gk ", "add ","new ","gk ",};
					auto iteration_task_n2 = find_if(begin(n2_task), end(n2_task),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (iteration_task_n2 != end(n2_task))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Tell me our secret code: \"");
						coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
						cout<<"Tell me our secret code: "<<endl;
						char check;
						check = saathi_login_prompt();
						if(check=='1'){
							system("@echo off");
							system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Ok enter your details below:\n \"");
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"Ok enter your details below: \n"<<endl;
							system("@echo off");
							country C1;
							new_info_to_database(&C1);
							sleep(1);
							system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" I think we are all set\n \"");
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"I think we are all set \n"<<endl;
							coord_xy(4,35);
							return;}
						else{
							system("@echo off");
							system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" I'm Sorry, I cant't let you tamper the database \"");
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"I'm Sorry, I cant't let you tamper the database"<<endl;
							return;
						}
						
					}
			array<string, 4> n3_task{"update ", "change ","static gk ","modify ",};
					auto iteration_task_n3 = find_if(begin(n3_task), end(n3_task),[&](const string& our_subtask_string)
                       {return user_voice_str.find(our_subtask_string) != string::npos; });
           
            		if (iteration_task_n3 != end(n3_task))
					{
						system("@echo off");
						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \"Ok, Tell me our secret code: \"");
						coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
						cout<<"Ok, Tell me our secret code: "<<endl;
						char check;
						check = saathi_login_prompt();
						if(check=='1'){
							system("@echo off");
							system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Ok go modify it. \"");
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"Ok go modify it \n"<<endl;
							system("@echo off");
							modify_info_to_database();
							sleep(1);
							system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" I think it's updated for good! \"");
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"I think it's updated for good!"<<endl;
							coord_xy(4,35);
							return;}
						else{
							system("@echo off");
							system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" I'm Sorry, I cant't let you modify the database \"");
							coord_xy(30,6);cout<<"                                                                      ";
							coord_xy(30,6);
							cout<<"I'm Sorry, I cant't let you modify the database"<<endl;
							return;
						}
//						system("@echo off");
//						system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Ok go modify it \"");
//						coord_xy(30,6);cout<<"                                                                      ";
//						coord_xy(30,6);
//						cout<<"Ok go modify it \n"<<endl;
//						modify_info_to_database();
//						//sleep(1);
//						coord_xy(4,35);
//						return;
						
    	
					}
//			array<string, 7> task{"open","make","play","search","searc","searh","display"};
//			auto iteration_task = find_if(begin(task), end(task),[&](const string& our_task_string)
//                       {return user_voice_str.find(our_task_string) != string::npos; });
//           
//            if (iteration_task != end(task))
				
	
}

void Saathi_Speech::statement_response(string user_voice_str){
	int sensible_value{0},non_sensible_value{0};
	array<string, 6> words_set_1{"eat ", "drink ","taste ","had ","drank ","ate ",};
		auto word_iteration_task_1 = find_if(begin(words_set_1), end(words_set_1),[&](const string& word_subtask_string)
            {return user_voice_str.find(word_subtask_string) != string::npos; });
           
        if (word_iteration_task_1 != end(words_set_1))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				srand((unsigned)time(NULL));
				string response,temp_for_espeak;
				int local_random_value{0};
				string ask_phrase[5]={"Was, it good\n","Ok, How did it taste\n","Was it tasty?\n","Did you enjoy it?\n","You want more of it? Haha\n"};
				local_random_value = [](){return rand()%5;}();
				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
       			temp_for_espeak += ask_phrase[local_random_value];
       			temp_for_espeak += "\"";
       			const char* command_1 = temp_for_espeak.c_str();
       			system("@echo off");
				system(command_1);
				coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
				cout<<ask_phrase[local_random_value]<<endl;
				coord_xy(30,25);cout<<"                                                                      ";
				coord_xy(30,25);cin>>response;
				transform(response.begin(), response.end(), response.begin(), ::tolower);
				response += " ";
				array<string, 7> temp_words_set_1{"yeah ", "yes ","good ","best ","tasty ","sweet ","lovely ",};
				auto word_iteration_task_1 = find_if(begin(temp_words_set_1), end(temp_words_set_1),[&](const string& word_subtask_string)
            	{return response.find(word_subtask_string) != string::npos; });
       			if (word_iteration_task_1 != end(temp_words_set_1)){
       				string good_response[5]={"Ok, great you are happy\n","Nice\n","Enjoy your stuff\n","That's the spirit, my friend\n","Cheers! Haha\n"};
       				local_random_value=[](){return rand()%5;}();
       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
       				temp_for_espeak += good_response[local_random_value];
       				temp_for_espeak += "\"";
       				const char* command_1 = temp_for_espeak.c_str();
       				system("@echo off");
					system(command_1);
					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
					cout<<good_response[local_random_value]<<endl;
					return;
			  	 }
			  	 
			  	array<string, 7> temp_words_set_2{"naah ", "no ","not ","horrible ","bad ","disastrous ","nah",};
				auto word_iteration_task_2 = find_if(begin(temp_words_set_2), end(temp_words_set_2),[&](const string& word_subtask_string)
            	{return response.find(word_subtask_string) != string::npos; });
            	if (word_iteration_task_2 != end(temp_words_set_2)){
       				string bad_response[5]={"Awww, that was bad luck\n","Nevermind, you will have next time\n","It's Ok\n","Dont worry my friend\n","Yeah sometimes it happens! Haha\n"};
       			//	srand((unsigned)time(NULL));
       				local_random_value=[](){return rand()%5;}();
       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
       				temp_for_espeak += bad_response[local_random_value];
       				temp_for_espeak += "\"";
       				const char* command_1 = temp_for_espeak.c_str();
       				system("@echo off");
					system(command_1);
					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
					cout<<bad_response[local_random_value]<<endl;
					return;
			  	 }
				
			}
			
		array<string, 3> words_set_2{"travel ", "travelling ","flying ",};
		auto word_iteration_task_2 = find_if(begin(words_set_2), end(words_set_2),[&](const string& word_subtask_string)
            {return user_voice_str.find(word_subtask_string) != string::npos; });
           
        if (word_iteration_task_2 != end(words_set_2))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				srand((unsigned)time(NULL));
				string response,temp_for_espeak;
				int local_random_value{0};
				string ask_phrase[5]={"Have a Safe journey\n","Ok, Have fun\n","See you soon\n","Ok, have a great time\n","You always loved it, Haha\n"};
				local_random_value = [](){return rand()%5;}();
				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
       			temp_for_espeak += ask_phrase[local_random_value];
       			temp_for_espeak += "\"";
       			const char* command_1 = temp_for_espeak.c_str();
       			system("@echo off");
				system(command_1);
				coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
				cout<<ask_phrase[local_random_value]<<endl;
				coord_xy(30,25);cout<<"                                                                      ";
//				coord_xy(30,25);cin>>response;
//				transform(response.begin(), response.end(), response.begin(), ::tolower);
//				response += " ";
//				array<string, 8> temp_words_set_1{"yeah ", "yes ","good ","best ","tasty ","Ok ","lovely ","yep "};
//				auto word_iteration_task_1 = find_if(begin(temp_words_set_1), end(temp_words_set_1),[&](const string& word_subtask_string)
//            	{return response.find(word_subtask_string) != string::npos; });
//       			if (word_iteration_task_1 != end(temp_words_set_1)){
//       				string good_response[5]={"Ok, great you are happy\n","Nice\n","Enjoy your stuff\n","That's the spirit, my friend\n","Cheers! Haha\n"};
//       				local_random_value=[](){return rand()%5;}();
//       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
//       				temp_for_espeak += good_response[local_random_value];
//       				temp_for_espeak += "\"";
//       				const char* command_1 = temp_for_espeak.c_str();
//       				system("@echo off");
//					system(command_1);
//					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
//					cout<<good_response[local_random_value]<<endl;
//					return;
//			  	 }
			  	 
//			  	array<string, 7> temp_words_set_2{"naah ", "no ","not ","horrible ","bad ","disastrous ","nah",};
//				auto word_iteration_task_2 = find_if(begin(temp_words_set_2), end(temp_words_set_2),[&](const string& word_subtask_string)
//            	{return response.find(word_subtask_string) != string::npos; });
//            	if (word_iteration_task_2 != end(temp_words_set_2)){
//       				string bad_response[5]={"Awww, that was bad luck\n","Nevermind, you will have next time\n","It's Ok\n","Dont worry my friend\n","Yeah sometimes it happens! Haha\n"};
//       				srand((unsigned)time(NULL));
//       				local_random_value=[](){return rand()%5;}();
//       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
//       				temp_for_espeak += bad_response[local_random_value];
//       				temp_for_espeak += "\"";
//       				const char* command_1 = temp_for_espeak.c_str();
//       				system("@echo off");
//					system(command_1);
//					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
//					cout<<bad_response[local_random_value]<<endl;
//					return;
//			  	 }
				
			}
		
		array<string, 9> words_set_3{"play ", "playing ","game ","games ","dancing ","singing ","played ","plays ","danced ",};
		auto word_iteration_task_3 = find_if(begin(words_set_3), end(words_set_3),[&](const string& word_subtask_string)
            {return user_voice_str.find(word_subtask_string) != string::npos; });
           
        if (word_iteration_task_3 != end(words_set_3))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				srand((unsigned)time(NULL));
				string response,temp_for_espeak;
				int local_random_value{0};
				string ask_phrase[5]={"We could play someday together\n","You are a chill person, Haha\n","That's one way to enjoy life\n","Great! now you must be very happy\n","Haha, I wish the same\n"};
				local_random_value = [](){return rand()%5;}();
				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
       			temp_for_espeak += ask_phrase[local_random_value];
       			temp_for_espeak += "\"";
       			const char* command_1 = temp_for_espeak.c_str();
       			system("@echo off");
				system(command_1);
				coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
				cout<<ask_phrase[local_random_value]<<endl;
				coord_xy(30,25);cout<<"                                                                      ";
//				coord_xy(30,25);cin>>response;
//				transform(response.begin(), response.end(), response.begin(), ::tolower);
//				response += " ";
//				array<string, 7> temp_words_set_1{"yeah ", "yes ","good ","best ","tasty ","sweet ","lovely ",};
//				auto word_iteration_task_1 = find_if(begin(temp_words_set_1), end(temp_words_set_1),[&](const string& word_subtask_string)
//            	{return response.find(word_subtask_string) != string::npos; });
//       			if (word_iteration_task_1 != end(temp_words_set_1)){
//       				string good_response[5]={"Ok, great you are happy\n","Nice\n","Enjoy your stuff\n","That's the spirit, my friend\n","Cheers! Haha\n"};
//       				local_random_value=[](){return rand()%5;}();
//       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
//       				temp_for_espeak += good_response[local_random_value];
//       				temp_for_espeak += "\"";
//       				const char* command_1 = temp_for_espeak.c_str();
//       				system("@echo off");
//					system(command_1);
//					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
//					cout<<good_response[local_random_value]<<endl;
//					return;
//			  	 }
//			  	 
//			  	array<string, 7> temp_words_set_2{"naah ", "no ","not ","horrible ","bad ","disastrous ","nah",};
//				auto word_iteration_task_2 = find_if(begin(temp_words_set_2), end(temp_words_set_2),[&](const string& word_subtask_string)
//            	{return response.find(word_subtask_string) != string::npos; });
//            	if (word_iteration_task_2 != end(temp_words_set_2)){
//       				string bad_response[5]={"Awww, that was bad luck\n","Nevermind, you will have next time\n","It's Ok\n","Dont worry my friend\n","Yeah sometimes it happens! Haha\n"};
//       			//	srand((unsigned)time(NULL));
//       				local_random_value=[](){return rand()%5;}();
//       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
//       				temp_for_espeak += bad_response[local_random_value];
//       				temp_for_espeak += "\"";
//       				const char* command_1 = temp_for_espeak.c_str();
//       				system("@echo off");
//					system(command_1);
//					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
//					cout<<bad_response[local_random_value]<<endl;
//					return;
//			  	 }
				
			}
			
		array<string, 6> words_set_4{"jump ", "cried ","run ","happy ","beautiful ","sunny ",};
		auto word_iteration_task_4 = find_if(begin(words_set_4), end(words_set_4),[&](const string& word_subtask_string)
            {return user_voice_str.find(word_subtask_string) != string::npos; });
           
        if (word_iteration_task_4 != end(words_set_4))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				srand((unsigned)time(NULL));
				string response,temp_for_espeak;
				int local_random_value{0};
				string ask_phrase[5]={"Alright,\n","Hmmm...\n","Ahhmmm?\n","Okay\n","I see\n"};
				local_random_value = [](){return rand()%5;}();
				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
       			temp_for_espeak += ask_phrase[local_random_value];
       			temp_for_espeak += "\"";
       			const char* command_1 = temp_for_espeak.c_str();
       			system("@echo off");
				system(command_1);
				coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
				cout<<ask_phrase[local_random_value]<<endl;
				coord_xy(30,25);cout<<"                                                                      ";
//				coord_xy(30,25);cin>>response;
//				transform(response.begin(), response.end(), response.begin(), ::tolower);
//				response += " ";
//				array<string, 7> temp_words_set_1{"yeah ", "yes ","good ","best ","tasty ","sweet ","lovely ",};
//				auto word_iteration_task_1 = find_if(begin(temp_words_set_1), end(temp_words_set_1),[&](const string& word_subtask_string)
//            	{return response.find(word_subtask_string) != string::npos; });
//       			if (word_iteration_task_1 != end(temp_words_set_1)){
//       				string good_response[5]={"Ok, great you are happy\n","Nice\n","Enjoy your stuff\n","That's the spirit, my friend\n","Cheers! Haha\n"};
//       				local_random_value=[](){return rand()%5;}();
//       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
//       				temp_for_espeak += good_response[local_random_value];
//       				temp_for_espeak += "\"";
//       				const char* command_1 = temp_for_espeak.c_str();
//       				system("@echo off");
//					system(command_1);
//					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
//					cout<<good_response[local_random_value]<<endl;
//					return;
//			  	 }
//			  	 
//			  	array<string, 7> temp_words_set_2{"naah ", "no ","not ","horrible ","bad ","disastrous ","nah",};
//				auto word_iteration_task_2 = find_if(begin(temp_words_set_2), end(temp_words_set_2),[&](const string& word_subtask_string)
//            	{return response.find(word_subtask_string) != string::npos; });
//            	if (word_iteration_task_2 != end(temp_words_set_2)){
//       				string bad_response[5]={"Awww, that was bad luck\n","Nevermind, you will have next time\n","It's Ok\n","Dont worry my friend\n","Yeah sometimes it happens! Haha\n"};
//       			//	srand((unsigned)time(NULL));
//       				local_random_value=[](){return rand()%5;}();
//       				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
//       				temp_for_espeak += bad_response[local_random_value];
//       				temp_for_espeak += "\"";
//       				const char* command_1 = temp_for_espeak.c_str();
//       				system("@echo off");
//					system(command_1);
//					coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
//					cout<<bad_response[local_random_value]<<endl;
//					return;
//			  	 }
				
			}
			
		array<string, 6> words_set_5{"bye ", "goodbye ","bye-bye ","see ya ","see you ","have a good day ",};
		auto word_iteration_task_5 = find_if(begin(words_set_5), end(words_set_5),[&](const string& word_subtask_string)
            {return user_voice_str.find(word_subtask_string) != string::npos; });
           
        if (word_iteration_task_5 != end(words_set_5))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				srand((unsigned)time(NULL));
				string response,temp_for_espeak;
				int local_random_value{0};
				string ask_phrase[5]={"See you soon,\n","Ba byee \n","Bye Bye, Saathee \n","Ok See yaa...\n","Bye....\n"};
				local_random_value = [](){return rand()%5;}();
				temp_for_espeak = "espeak -a 150 -p 85 -s 130 -ven-us+f5 \"";
       			temp_for_espeak += ask_phrase[local_random_value];
       			temp_for_espeak += "\"";
       			const char* command_1 = temp_for_espeak.c_str();
       			system("@echo off");
				system(command_1);
				coord_xy(30,6);cout<<"                                                                      ";coord_xy(30,6);
				cout<<ask_phrase[local_random_value]<<endl;
				coord_xy(30,25);cout<<"                                                                      ";
				coord_xy(4,34);
				exit(0);
				
			}
		
	
}

void Saathi_Speech::greeting_response(string user_voice_str){
	array<string, 3> certain_words_set1{"namaste ", "namste ","numaste "};
		auto greetings_iteration_task_1 = find_if(begin(certain_words_set1), end(certain_words_set1),[&](const string& our_subtask_string)
            {return user_voice_str.find(our_subtask_string) != string::npos; });
           
        if (greetings_iteration_task_1 != end(certain_words_set1))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				system("@echo off");
				system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Naa mas teh Saathee \"");
				cout<<"Namaste Saathi";
				return;
			}
	array<string, 3> certain_words_set2{"morning ", "mrning ","mornin "};
		auto greetings_iteration_task_2 = find_if(begin(certain_words_set2), end(certain_words_set2),[&](const string& our_subtask_string)
            {return user_voice_str.find(our_subtask_string) != string::npos; });
           
        if (greetings_iteration_task_2 != end(certain_words_set2))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				system("@echo off");
				system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Good Morning Saathee\"");
				cout<<"Good Morning, Saathi";
				return;
			}
	
	array<string, 3> certain_words_set3{"afternoon ", "aftrnoon ","afternon "};
		auto greetings_iteration_task_3 = find_if(begin(certain_words_set3), end(certain_words_set3),[&](const string& our_subtask_string)
            {return user_voice_str.find(our_subtask_string) != string::npos; });
           
        if (greetings_iteration_task_3 != end(certain_words_set3))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				system("@echo off");
				system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Good Afternoon Saathee\"");
				cout<<"Good Afternoon, Saathi";
				return;
			}
		
	array<string, 4> certain_words_set4{"evening ", "evenin ","evning ","evning "};
		auto greetings_iteration_task_4 = find_if(begin(certain_words_set4), end(certain_words_set4),[&](const string& our_subtask_string)
            {return user_voice_str.find(our_subtask_string) != string::npos; });
           
        if (greetings_iteration_task_4 != end(certain_words_set4))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				system("@echo off");
				system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Good Evening Saathee\"");
				cout<<"Good Evening, Saathi";
				return;
			}
			
	array<string, 4> certain_words_set5{"night ", "nite ","nigh ","niight "};
		auto greetings_iteration_task_5 = find_if(begin(certain_words_set5), end(certain_words_set5),[&](const string& our_subtask_string)
            {return user_voice_str.find(our_subtask_string) != string::npos; });
           
        if (greetings_iteration_task_5 != end(certain_words_set5))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				system("@echo off");
				system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Good Night Saathee, Don't let the bed bugs bite, Haa haa \"");
				cout<<"Good Night Saathi, Don't let the bed bugs bite, Hahaa ";
				return;
			}
	array<string, 5> certain_words_set6{"bye ", "goodbye ","see ya ","see yaa ","bye-bye"};
		auto greetings_iteration_task_6 = find_if(begin(certain_words_set6), end(certain_words_set6),[&](const string& our_subtask_string)
            {return user_voice_str.find(our_subtask_string) != string::npos; });
           
        if (greetings_iteration_task_6 != end(certain_words_set6))
			{	coord_xy(30,6);cout<<"                                                                      ";
				coord_xy(30,6);
				system("@echo off");
				system("espeak -a 150 -p 85 -s 130 -ven-us+f5 \" Good bye my friend,  \"");
				cout<<"Good Bye, my friend\n";
				coord_xy(4,35);
				sleep(1);
				exit(0);
				return;
			}
	speech_start();
	
}

void Saathi_Speech::speech_start(){
			conversation_start();
			conversation_state_updater();
			char command[100]; 
			coord_xy(30,6);cout<<"                                                                      ";
			coord_xy(30,6);
			strcpy(command,"espeak -a 150 -p 85 -s 130 -ven-us+f5 \" ");
			strcat(command,saathi_voice);
			strcat(command," \"");
		//	cout<<cmd<<endl;
			system("@echo off");
			sleep(1);
			cout<<saathi_voice;
			system(command);
			coord_xy(30,25);cout<<"                                                                      ";
		}

void Saathi_Speech::conversation_start(){
	ifstream info;
//	cout<<"This is inside conversation\n";
//	cout<<saathi_voice<<endl;
	Speech Sp_Saathi;
	info.open("Greetings_Initialization.bin",ios::in|ios::binary);
	int Greeting_value = random_number_generator();
	if(info.is_open()){
	while(!info.eof()){
		info.read((char*)&Sp_Saathi,sizeof(Sp_Saathi));
		if(Greeting_value==Sp_Saathi.number_mark){
			strcpy(saathi_voice,Sp_Saathi.user_speech_copy);
			}
		}
	}
	else
	//	cout<<"Couldnot open\n";
	info.close();
	
	
}

void Saathi_Speech::conversation_state_updater(){
	//cout<<"Inside state updater\n";getchar();
	ifstream state_update_read;
	Speech Sp01;int number_marker{0};
	Sp01.number_mark=0;
	state_update_read.open("Greetings_Initialization.bin",ios::in|ios::binary);
	if(state_update_read.is_open()){
	while(!state_update_read.eof()){
		state_update_read.read((char*)&Sp01,sizeof(Sp01));
		number_marker=Sp01.number_mark;
		
		}
	}
	state_update_read.close();
	ofstream state_update_write;
	Sp01.number_mark = number_marker;
	state_update_write.open("Greetings_Initialization.bin",ios::app|ios::binary);
	Sp01.number_mark++;
//	cout<<user_voice;
	strcpy(Sp01.user_speech_copy,user_voice);
	//cout<<Sp01.number_mark<<" "<<Sp01.user_speech_copy;
	state_update_write.write((char*)&Sp01,sizeof(Sp01));
	state_update_write.close();
	//cout<<"appended\n";
	getchar();
	
	
}

int Saathi_Speech::random_number_generator(){
	srand(time(0));
	int random_value{0};
	ifstream state_update_read;
	Speech Sp01;int number_marker{0};
	Sp01.number_mark=0;
	state_update_read.open("Greetings_Initialization.bin",ios::in|ios::binary);
	if(state_update_read.is_open()){
	while(!state_update_read.eof()){
		state_update_read.read((char*)&Sp01,sizeof(Sp01));
		number_marker=Sp01.number_mark;
		
		}
	}
	else{
		//cout<<"could not generate random number\n";
		return 0;
	}
	state_update_read.close();
    random_value = rand()%number_marker;
	return random_value;
}


int main(){
	Boundary_Frame F1;
	User_Speech U1;
	F1.full_outer_frame();
	F1.full_inner_frame();
	Intro_page();
	system("cls");
	F1.full_outer_frame();
	F1.full_inner_frame();
	F1.saathi_communication_frame();
	F1.user_communication_frame();
	
	while(1){
	U1.user_voice_input();
	
//	S1.speech_start();
	}
	F1.coord_xy(4,35);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

