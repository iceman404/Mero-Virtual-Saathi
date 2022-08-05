#include<iostream>
#include<windows.h>
#include<fstream>
#include<cstdlib>
#include<time.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<array>

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


class Saathi_Speech:public Boundary_Frame{
	char saathi_voice[100];
	public:
		void speech_start();
		void conversation_start();
		int random_number_generator();
		void conversation_state_updater();
		void conversation_state_finder();
		void question_response();
		void task_response();
		void statement_response();
		void greeting_response();
		
};


class User_Speech:public Boundary_Frame{
	public:
		Saathi_Speech Saathi_temp;
		void user_voice_input();
		friend Saathi_Speech;
		
};

void User_Speech::user_voice_input(){
			coord_xy(30,25);
			gets(user_voice);
			string user_voice_str{user_voice};
			transform(user_voice_str.begin(), user_voice_str.end(), user_voice_str.begin(), ::tolower);
			Word_value W_temp{0};
		//	cout<<user_voice_str;
			//cout<<W_temp.Question<<" "<<W_temp.Task<<" "<<W_temp.Greeting<<" "<<W_temp.Statement;
			array<string, 10> question{"what", "where", "whose","how","why","when","wher","whos","who","whom"};
			auto iteration1 = find_if(begin(question), end(question),[&](const string& our_string)
                       {return user_voice_str.find(our_string) != string::npos; });
           // cout<<iteration1<<" "<<end(question);
            if (iteration1 != end(question))
				{
    				W_temp.Question += 7;
				//	cout<<"dahel";
				}
			array<string, 5> task{"do", "make", "please","will","would"};
			auto iteration2 = find_if(begin(task), end(task),[&](const string& our_string)
                       {return user_voice_str.find(our_string) != string::npos; });
            if (iteration2 != end(task))
				{
    				W_temp.Task += 6;
				//	cout<<"ok";
				}
			
			array<string, 8> greeting{"hello", "namaste", "hi","hey","morning","good","yo","helo"};
			auto iteration3 = find_if(begin(greeting), end(greeting),[&](const string& our_string)
                       {return user_voice_str.find(our_string) != string::npos; });
            if (iteration3 != end(greeting))
				{
    				W_temp.Greeting += 4;
					//cout<<"nice";
				}
			else
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
			//conversation_state_finder(W_temp);
			Saathi_temp.conversation_state_updater();
	}
	
//void Saathi_Speech::conversation_state_finder(Word_value temp_value, string temp_value){
//		if(temp_value.Question==7){
//			
//			
//		}
//		if(temp_value.Task==6){
//			
//			
//		}
//		if(temp_value.Statement==1){
//			
//			
//		}
//		if(temp_value.Greeting==4){
//			
//			
//		}
//		
//		
//		
//	}

void Saathi_Speech::question_response(){
	
	
}

void Saathi_Speech::task_response(){
	
	
}

void Saathi_Speech::statement_response(){
	
	
}

void Saathi_Speech::greeting_response(){
	
	
	
}

void Saathi_Speech::speech_start(){
			conversation_start();
			coord_xy(30,6);cout<<"                                                                      ";
			coord_xy(30,6);
			sleep(1);
			cout<<saathi_voice;
			coord_xy(30,25);cout<<"                                                                      ";
		}

void Saathi_Speech::conversation_start(){
	ifstream info;
	Speech Sp_Saathi;
	info.open("Speech_Initialization.bin",ios::in|ios::binary);
	int Greeting_value = random_number_generator();
	while(!info.eof()){
		info.read((char*)&Sp_Saathi,sizeof(Sp_Saathi));
		if(Greeting_value==Sp_Saathi.number_mark){
			strcpy(saathi_voice,Sp_Saathi.user_speech_copy);
		}
	
	}
	info.close();
	
	
}

void Saathi_Speech::conversation_state_updater(){
	ifstream state_update_read;
	Speech Sp01;int number_marker{0};
	Sp01.number_mark=0;
	state_update_read.open("Speech_Initialization.bin",ios::in|ios::binary);
	if(state_update_read.is_open()){
	while(!state_update_read.eof()){
		state_update_read.read((char*)&Sp01,sizeof(Sp01));
		number_marker=Sp01.number_mark;
		
	}
	}
	state_update_read.close();
	ofstream state_update_write;
	Sp01.number_mark = number_marker;
	state_update_write.open("Speech_Initialization.bin",ios::app|ios::binary);
	Sp01.number_mark++;
//	cout<<user_voice;
	strcpy(Sp01.user_speech_copy,user_voice);
	//cout<<Sp01.number_mark<<" "<<Sp01.user_speech_copy;
	state_update_write.write((char*)&Sp01,sizeof(Sp01));
	state_update_write.close();
	
	
}

int Saathi_Speech::random_number_generator(){
	srand(time(0));
	int random_value{0};
	ifstream state_update_read;
	Speech Sp01;int number_marker{0};
	Sp01.number_mark=0;
	state_update_read.open("Speech_Initialization.bin",ios::in|ios::binary);
	if(state_update_read.is_open()){
	while(!state_update_read.eof()){
		state_update_read.read((char*)&Sp01,sizeof(Sp01));
		number_marker=Sp01.number_mark;
		
	}
	}
	state_update_read.close();
    random_value = rand()%number_marker;
	return random_value;
}


int main() {
	Boundary_Frame F1;
	Saathi_Speech S1;
	User_Speech U1;
	F1.full_outer_frame();
	F1.full_inner_frame();
	F1.saathi_communication_frame();
	F1.user_communication_frame();
	while(1){
	U1.user_voice_input();
	S1.speech_start();
	}
	F1.coord_xy(4,35);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}