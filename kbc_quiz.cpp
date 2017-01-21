#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include<time.h>
#include<string.h>
using namespace std;

char nick[50];

int life=4;
int fifty=1,phone_a_friend=1,expert_advice=1,audience_poll=1;

void phonefriend();
void fiftyfifty(char);
void auidencepoll(char);
void expert(char);
void getinfo();
void lifeline(char );
void balance(int,int);
	
int main()
{
	cout<<"\n________________WELCOME TO KBC___________________________\n";
	getinfo();
	cout<<"\nLET'S START THE GAME\n";
	ifstream in;
	in.open("kbc.txt",fstream::binary);
	char a[50];
	while(!in.eof())
	{
			char ch,ch1,ph,ch2,ch3,ch4;
			unsigned int sval;
			time_t t;
			sval=(unsigned)time(&t);
			srand(sval);
			for(int i=1;i<15;i++)
			{
				int num=rand() % 3;
				in.seekg(6*(50*num),ios::cur);
				for(int j=0;j<5;j++)
				{
					
					in.getline(a,50);
					puts(a);
				}
				in>>ph;
				cout<<"Enter L for lifeline: "<<endl;	
				cout<<"\nEnter option: ";
				cin>>ch;
				while(ch=='L' )
				{
						if(life==0)
						{
							cout<<"No lifeline available\n";
							cout<<"Do you want to continue?Press N to exit safely with current balance";
							cin>>ch1;
							if(ch1=='N')
								balance(i,-1);
							else
							{
						    	cin>>ch2;
								break;												
							}										
   						 }
						 lifeline(ph);
						 cout<<"\nWant to use Lifeline again press y or n";     cin>>ch3;
						 if(ch=='y')
						         continue;
						 else
						 {
						        cout<<"\nEnter Your Answer:";
						        cin>>ch4;       break;
						 }     					
					
				}		
				if(ch==ph || ch2==ph || ch4==ph)
					balance(i,1);
				else
				{
					balance(i,0);	        return 0;
			        }				
				//in.seekg(49,ios::cur);
				in.seekg(6*(50*(2-num)),ios::cur);	
			
			}
	
	}	
	return 0;
}

void getinfo()
{
	cout<<"\nEnter Your Nick Name:";
	cin>>nick;
}
void phonefriend()
{
	int opt;
	phone_a_friend=0;	
	cout<<"\nAvailable Phone Numbers to call Friend are";
	cout<<"1) 8888855555\n"<<"2) 9503386612\n"<<"3) 8237669414\n"<<"4) 7350617969\n";
	cin>>opt;
	cout<<"\nCalling Your Friend..........";
	switch(opt)
	{
		case 1:
			cout<<"It's Probably answer is A";
			break; 	 
		case 2:
			cout<<"It's Probably answer is B";
			break; 	 
		case 3:
			cout<<"It's Probably answer is C";
			break; 	 
		case 4:
			cout<<"It's Probably answer is D";
			break; 	 
	}
}
void fiftyfifty(char ch)
{
	
	fifty=0;
	int n=ch-97;
	switch(n)
	{
		case 0:
			cout<<"\nIt's Probabale answer is "<<ch<<" or "<<char(ch+1);
			break;
		case 1:
			cout<<"\nIt's Probabale answer is "<<ch<<" or "<<char(ch+1);
			break;
		case 2:
			cout<<"\nIt's Probabale answer is "<<ch<<" or "<<char(ch-2);
			break;
	}
}
void auidencepoll(char ch)
{
	
	audience_poll=0;
	int n;
	n=rand()%10+1;
	cout<<"The Auidence suggestions"<<endl;
	switch(ch)
	{
		case 'a':
			cout<<"A: "<<n*10<<" B: "<<(10-n)/6.0*10<<" C: "<<(10-n)/3.0*10<<" D: "<<(10-n)/2.0*10; break;	
		case 'b':
			cout<<"A: "<<(10-n)/6.0*10<<" B: "<<n*10<<" C: "<<(10-n)/2.0*10<<" D: "<<(10-n)/3.0*10; break;	

		case 'c':
			cout<<"A: "<<(10-n)/2.0*10<<" B: "<<(10-n)/6.0*10<<" C: "<<n*10<<" D: "<<(10-n)/3.0*10; break;	

		case 'd':
			cout<<"A: "<<(10-n)/2.0*10<<" B: "<<(10-n)/6.0*10<<" C: "<<(10-n)/3.0*10<<" D: "<<n*10; break;	

	}
}
void expert(char ch)

{

	int opt;
	expert_advice=0;

	while(1)

	{
	
		cout<<"\nHi, You have chosen expert advice lifeline.\nChoose one expert:\n1.Mr.Nikhil Pathak(IIM Ahemedabad)\n2.Vighnesh Aiyer(Ph.D.MIT)\n3.Sankalp Yerawar(Harvard University)\n4.Dr.Rahul Bagad(Ph.D.Oxford University)\nOption: ";
	
		cin>>opt;
	
		if(opt>4||opt<1)
	
		{
		
			cout<<"\nPlease enter a valid option:\n";
		
				continue;
	
		}

		switch(opt)
	
		{
		
			case 1:
			
				cout<<"\nHello,I am not sure but I think answer "<< ch<< " is correct.\n";
			
				return;
		
			case 2:
			
				cout<<"\nHi,this one is tricky I think answer "<< ch<< " is correct.\n";
			
				return;
		
			case 3:
			
				cout<<"\nHello,I am  sure that answer "<< ch<< " is correct.\n";
			
				return;
		
			case 4:
			
				cout<<"\nHello,I am definitely sure that answer "<< ch<< " is correct.\n";
			
				return;
	
		}
		
	} 


}
	
			

void lifeline(char ch)
{
	int ch1;
	cout<<"You have "<<life<<" lifeline availaible\n";
	life-=1;
	cout<<"\n1.Fifty Fifty: "<<fifty<<"\n2.Auidence Poll: "<<audience_poll<<"\n3.Expert Advice: "<<expert_advice<<"\n4.Phone a friend: "<<phone_a_friend;
	cin>>ch1;
	while(1)
	{
		switch(ch1)
		{
		case 1:
			if(fifty==0)
			{
				cout<<"Lifeline already used"<<endl;
				break;	
			}
			fiftyfifty(ch);
			return;
		case 2:
			if(audience_poll==0)
			{
				cout<<"Lifeline already used"<<endl;
				break;	
			}
			auidencepoll(ch);
			return;
		case 3:
			if(expert_advice==0)
			{
				cout<<"Lifeline already used"<<endl;
				break;
			}
	
			expert(ch);
			return;
		case 4:
			if(phone_a_friend==0)
			{
				cout<<"Lifeline already used"<<endl;
				break;
			}
			phonefriend();
			return;			
		}
	}
	
}			

void balance(int qno,int flg)
{
	long int money[]={1000,2000,5000,10000,20000,50000,100000,200000,5000000,1000000,2000000,3000000,5000000,7500000,10000000};
	if(flg==0)
	{
		cout<<"You have entered wrong answer.\n";
		if(qno>12)
			cout<<"Amount Received: "<<money[12];
		else
		{
			if(qno>9)
				cout<<"Amount Received "<<money[9];
			else
			{
				if(qno>6)
					cout<<"Amount Received "<<money[6];
				else
					cout<<"Amount Received 0";
			}
		}
	}
	else
	{
		if(flg==-1)
		{
			cout<<"You have QUIT and ";
			cout<<"Amount Received: "<<money[qno-1];
			return ;
		}
		else
			cout<<"Current Amount: "<<money[qno];
	}
}
