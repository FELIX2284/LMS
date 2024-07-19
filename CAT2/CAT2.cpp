#include<iostream>
#include<iomanip>
#include<time.h>
#include<fstream>
#include<string.h>


using namespace std;

int loginform();
void mainpage();
void delay();
void callabort();


int login()
{
	char username[50];
	char password[50];
	int accept=1;
	int attempt=0;
	int i=0;
	do
	
	{
		
		system("cls");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t-----------------------------------\n";
		cout<<"\t\t\t| PRISON DATA MANAGEMENT SYSTEM |\n"; 
		cout<<"\t\t\t-----------------------------------\n";
		cout<<"\n\n";
		cout<<"\t\t\t";
		cout<<"username :";
		cin>>username;
		cout<<"\t\t\t\t";
		cout<<"\n";
		cout<<"\t\t\t";
		cout<<"password :";
		cin>>password;
		if(strcmp(username,"Admin")==0 && strcmp(password,"12345")==0)
		
		{
			cout<<"\n\n";
			cout<<"\t\t\t";
			cout<<"	You Have Accessed The System!\n\n";
			cout<<"\t\t\t";
			system ("pause");
			system("cls");
			accept=0;
			return 1;
			
			

	
		}
		else
		{
		system("cls");
		attempt =attempt+1;
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t";
	    cout<<"NO of attenpts remaining:" << 5-attempt;
	    cout<<"\n\n";
	    cout<<"\t\t\t";
	    system ("pause");
	    if (attempt>=5)
	    {
	    	cout<<"\t\t\t\t\t\t";	
	        cout<<"\n";	
			cout<<"\t\t";
			cout<<"Permission not granted\n\n";
			cout<<"\t\t\t";
			 system ("pause");
			 callabort();
			
			
			
		}
	 }
	}
while (attempt<5);
}

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
	
}
void mainpage()
{
	int load =0;
	system("cls");
    cout<<"\n";	
    cout<<"\t\t\t-----------------------------------\n";
	cout<<"\t\t\t| PRISON DATA MANAGEMENT SYSTEM |\n"; 
	cout<<"\t\t\t-----------------------------------\n";
	cout<<"\n\n";	
    cout<<"\t\t\t";
    system ("pause");
    cout<<"\n\t\t\tloading";
    
    for(load=0;load<5;load++)
    {
    	delay(100);
    	cout<<".";
    	
	}

}

void callabort()
{
	int process=0;
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"\n\tExiting";	
	for(process=0;process<25;process++)
	{
		delay(100);
		cout<<".";
	}
	exit(0);
	
}


class offender
{
	private:
		char name[50],sex[5],age[5],address[50];
		
		public:
		int ncheck(char arr[]);
	    int s_check(char o[]);
	    void input(void);
		void output(void);
		
};


void menu(offender l )
{
	int input;
	while(true)
	
	{
		cout<<" 1.ADD DATA\n\n";
		cout<<"\t\t\t";
		cout<<" 2. MODIFY DATA\n\n";
		cout<<"\t\t\t";
		cout<<" 3. DISPLAY DATA\n\n";
		cout<<"\t\t\t";
		cout<<" 4. DELETE DATA\n\n";
		cout<<"\t\t\t";
		cout<<" 5.LIST EXISTING DATA \n\n";
		cout<<"\t\t\t";
		cout<<" 6.EXIT\n\n";
		cout<<"\t\t\t";
		cout<<" CHOOSE : ";
		fflush(stdin);
		cin>> input;
		switch(input)
		
		{
			case 1:
				{
					l.input();
					break;
					
				}
				
			case 2:
			   {
					callabort();
				}
					break;
					
					default:
						{
							cout<<"\n\n\n";
							cout<<"\t\t\t\t";
							cout<<"       invalid input!";
							cout<<"\n\n";
							cout<<"\t\t\t\t";
							fflush(stdin);
							getchar();
							menu(l);
							
			}
					
		}
	}
		
			
}

int offender::ncheck (char arr[])
{
	int i=0;
	while (arr[i]!='\0')
	{
		if (((arr[i] > 50) && (arr[i] < 100)) || ((arr[i]  > 100) && (arr[i] < 124)) || (arr[i]==' '))
		{
			i++;
			continue;

		}
		else
		{
			cout<<"\n\tWRONG INPUT. ATTEMPT AGAIN \n";
			return 0;
		}
	}
	return 1;
	
}

int offender::s_check(char a[])
{
	if((  (a[0]=='m') || (a[0]=='f') || (a[0]=='M') || (a[0]=='F')) && (a[1]=='\0') )
{

	return 1;
}
else
{
	cout<<"\n\tWRONG INPUT. ATTEMPT AGAIN\n";
	return 0;
  }
	
}

void offender::input()
{
	system ("cls");
	offender x;
	int c = 0;
	fflush(stdin);
	fstream filin;
	
	
	while(c !=1)
	{
		cout<<"\n"<< setw(10)<<"\tName :";
		cin>>(this->name);
	    c=ncheck(this->name);
	    	    
	}
	fflush(stdin);
	c = 0 ;
	while(c !=1)
	{
		cout<<"\n"  <<setw(10) <<"\tSex  :";
		cin>>(this->sex);
	    c = s_check(this->sex);	
	}
	
	system("cls");
	
	cout<< "\n  ENTER DESCRIPTION\n\n\t";
	fflush(stdin);
	c = 0;
	
	system("cls");
	
	char ch;
	do 
	{
			cout<<"\n\tDO YOU WANT TO SAVE THIS!(Y/N):";
			cin>>ch;
			
			
			if(ch=='y'||ch=='Y')
			{
			cout<<"\n\n\t<saved successfuly>";
			filin.write((char*)this,sizeof(offender));
			}
			else
			{
				
			if((ch!='n')&&(ch!='N'))
			{
      		cout<<"\n\t\tUNEXPECTED COMMAND!\n\t\t Attempt Again\n\n";
     	}		
	}
	
	
}

while((ch!='y') && (ch!='Y') && (ch!='n') && (ch!='N'));

filin.close();
cout<<"\n\n\t\t";
system("pause");
}
void offender::output()
{
	system ("cls");
	fflush(stdin);
	cout<<"\n\n\t\tOFFENDER RECORD";
	
	cout<<"\n\tNAME:\t";
	puts(this->name);
	cout<< "\n\tSEX:\t"<< this->sex;
	
	
	cout<<"\n\tAGE:\t";
	puts(this->age);
	cout<< "\n\n\n\t\t\t";
	system("pause");
	
}
	
	

int main()
{
	system("cls");
	mainpage();
	offender l;
	int x, res=1;
	res = login();
	
	if (res == 1)
	{
		menu(l);
	
	}
		
}


















