#include<graphics.h>
#include<iostream>
#include<cmath>
#include<windows.h>
#include<stdio.h>
using namespace std;
void seven_segment(int n=0,int i =0)
{
	n *= 50;
	setcolor(RED);							
	if(i == 1|| i == 4)						
		setcolor(BLACK);				    
	else 	setcolor(RED);					
	line(240 + n,150,270 +n,150);   //   0  
	if(i == 1|| i == 2 || i ==3|| i ==7)
		setcolor(BLACK);
	else 	setcolor(RED);
	line(240 + n,153,240 +n,183);	// 1
	if(i == 1|| i == 3 || i == 4|| i == 5|| i == 7|| i == 9)
		setcolor(BLACK);
	else 	setcolor(RED);
	line(240+ n,186,240+ n,216);	//2
	if(i == 1|| i == 4|| i == 7)
		setcolor(BLACK);
	else 	setcolor(RED);
	line(240+ n,219,270+ n,219);    //3
	if(i == 2)
		setcolor(BLACK);
	else 	setcolor(RED);
	line(270+ n,186,270+ n,216);  //4
	if(i == 5|| i == 6)
		setcolor(BLACK);
	else 	setcolor(RED);
	line(270+ n,153,270+ n,183);	//5

	if(i == 1|| i == 7|| i == 0)
		setcolor(BLACK);
	else 	setcolor(RED);
	line(240+ n,184,270+ n,184);	//6
}
void clock(int hr1 = 0,int min1 = 0,int sec1 =0)
{
//	char arr[50];
//	int s=0;
	initwindow(1100,700);
	int x,y,hr,min,sec,msec;;
	setcolor(GREEN);
	settextstyle(7,0,3);
	outtextxy(333,70," -----CLOCK----- ");
	setcolor(BLUE);					//given 4 line is for box of watch
	line(200,100,810,100);
	line(200,100,200,266);
	line(200,266,810,266);
	line(810,100,810,266);
	setcolor(RED);
	settextstyle(3,0,3);
	outtextxy(200,360,"stop");
	setcolor(BLUE);
	line(170,330,270,330);
	line(170,420,170,330);
	line(170,420,270,420);
	line(270,420,270,330);
	setcolor(RED);
	outtextxy(452,360,"wait/start");
	setcolor(BLUE);
	line(450,330,550,330);
	line(450,420,450,330);
	line(450,420,550,420);
	line(550,420,550,330);
	setcolor(RED);
	outtextxy(760,360,"save");
	setcolor(BLUE);
	line(730,330,830,330);
	line(730,420,730,330);
	line(730,420,830,420);
	line(830,420,830,330);

	reset:
		{
			setcolor(BLACK);
			settextstyle(3,0,3);
			outtextxy(197,360,"reset");
			setcolor(RED);
			settextstyle(3,0,3);
			outtextxy(200,360,"stop");
			for(hr=hr1;hr<100;hr++)
			{
				seven_segment(0,hr/10);
				seven_segment(1,hr%10);
				for(min=min1;min<60;min++)
				{
					seven_segment(3,min/10);
					seven_segment(4,min%10);
					for(sec=sec1;sec<60;sec++)
					{
						Beep(200000000,100);
						seven_segment(6,sec/10);
						seven_segment(7,sec%10);
						for(msec = 0;msec<51;msec++)
						{
							setcolor(BLACK);
							seven_segment(9,(msec*2)/10);
							seven_segment(10,(msec*2)%10);
							getmouseclick(WM_LBUTTONDOWN,x,y);
							if(x>170 && x < 270 && y > 330 && y< 420)
							{
								Beep(3000000,700);
								goto stop;
							}
							if(x>450 && x <550 && y > 330 && y< 420)
							{
								get: goto check;
								Beep(2987654,700);
								restart:
									{
										setcolor(BLACK);
										settextstyle(3,0,3);
										outtextxy(197,360,"reset");
										setcolor(RED);
										settextstyle(3,0,3);
										outtextxy(200,360,"stop");
									}
								}
							if(x>730 && x < 830 && y > 330 && y< 420)
							{
								Beep(21000000,100);
//								sprintf(arr,"you save: %d hr %d min %d sec %d msec",hr,min,sec,msec);
//								outtextxy(200,450 + s,arr);	
//								s += 30;							
								cout<<"you save: "<<hr<<" hr "<<min<<" min "<<sec<<" sec "<<msec<<" msec "<<endl;
							}
							delay(1);
						}
						sec1=0;
					}
					min1 =0;
				}
				hr1=0;
			}
		}
	check:
		{
			setcolor(BLACK);
			settextstyle(3,0,3);
			outtextxy(200,360,"stop");
			setcolor(RED);
			settextstyle(3,0,3);
			outtextxy(197,360,"reset");
			delay(1);
			getmouseclick(WM_LBUTTONDOWN,x,y);
			if(x>450 && x <550 && y > 330 && y< 420)
			{
				goto restart;
			}
			else if(x>170 && x < 270 && y > 330 && y< 420)
			{
				Beep(3000000,700);
				goto reset;
			}
			else if(x>730 && x < 830 && y > 330 && y< 420)
			{
				Beep(21000000,100);
				cout<<"you save: "<<hr<<" hr "<<min<<" min "<<sec<<" sec "<<msec<<" msec "<<endl;
				goto get;
			}
			else{
				goto get;
			}
		}
	stop:
	{
		cout<<"you stop at "<<hr<<" hr "<<min<<" min "<<sec<<" sec "<<msec<<" msec "<<endl;
	}
	closegraph();
}
void timer(int hr1, int min1, int sec1)
{
    initwindow(1100,700);
	int x,y,hr,min,sec,msec;
	setcolor(GREEN);
	settextstyle(6,0,3);
	outtextxy(400,70," -----TIMER----- ");
	setcolor(BLUE);					//given 4 line is for box of watch
	line(200,100,810,100);
	line(200,100,200,266);
	line(200,266,810,266);
	line(810,100,810,266);
    for(hr=0;hr<100;hr++)
			{
				seven_segment(0,hr/10);
				seven_segment(1,hr%10);
				for(min=0;min<60;min++)
				{
					seven_segment(3,min/10);
					seven_segment(4,min%10);
					for(sec=0;sec<60;sec++)
					{
						Beep(200000000,100);
						seven_segment(6,sec/10);
						seven_segment(7,sec%10);
						for(msec = 0;msec<51;msec++)
						{
							setcolor(BLACK);
							seven_segment(9,(msec*2)/10);
							seven_segment(10,(msec*2)%10);
							if(hr==hr1&& min==min1 && sec==sec1)
                            {
                                Beep(3000000,7000);
                                cout<<"time over "<<hr<<":"<<min<<":"<<sec<<":"<<msec<<endl;
                                goto close;
                            }
                            delay(1);
						}
					}
				}
			}
    close: closegraph();
}
int main()
{
	int i=1,hr,min,sec;
	while(i)
	{
		system("CLS");
		cout<<" enter 1 for normal stop-watch \n enter 2 for start sopt-watch from your time \n enter 3 for timer \n enter 0 for exit\n";
		cin>>i;
		if(i==1)
		{
			clock();
		}
		else if(i == 2)
		{
			cout<<"enter your time as HH:MM:SS <- this format with space : ";
			cin>>hr>>min>>sec;
			if( hr>99 || min >59 || sec >59)
			{
				cout<<"plz enter valid info( hr <100 , min <60 , sec<60 )"<<endl;
			}
			else{
				clock(hr,min,sec);
			}
		}
		else if(i==3)
        {
            cout<<"enter your time as HH:MM:SS <- this format with space : "<<endl;
			cin>>hr>>min>>sec;
			if( hr>99 || min >59 || sec >59)
			{
				cout<<"plz enter valid info( hr <100 , min <60 , sec<60 )";
			}
			else{
				timer(hr,min,sec);	
			}
        }
		else if( i == 0)
		{
			cout<<"Thank you for using stop-watch"<<endl;
		}
		else
		{
			cout<<"enter valid input";
		}
		system("pause");
	}
	return 0;
}
