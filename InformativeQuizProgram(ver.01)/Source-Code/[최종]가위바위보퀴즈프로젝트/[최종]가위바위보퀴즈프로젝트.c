#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct quiz_q
{
	char answer[20];//답
	char told[100];
	char hint[100]; //힌트
}quiz_q;

quiz_q quiz[10];						//구조체 배열 (10문제)
void init01();							//국사문제 함수 선언
void init02();							//세계사문제 함수 선언
int gawi(int i, int quiz_count);		//가위바위보 
void one_print(int quiz_count);			//문제번호출력
void two_print(int i);					//문제 출력
void solution();						//문제 정답 
void emoticon();						//이모티콘 출력을 위한 함수

static int ok[10];
int i=0,j = 0;							//for문을 위한 변수
char temp02;							//문제 다시풀기 (y/n)
int temp01=0;							//'메뉴 복귀'를 위해 0,1 값을 담는 변수		

int main(void)
{
	char name[10];			//성적표 ID입력
	char num_board[5][12] =   // 점수판
	{
		"Excellent  ", "Good       ", "Nice       ", "Not bad    ", "HaveToStudy"
	};
	int point[5] =    // 점수
	 {
		100, 80, 60, 40, 20
	 };
	char inpName[5];  // 사용자 입력받을 ID
	int inpPoint=0;    //사용자 입력받을 점수
	
	int selection = 0;//메뉴선택 selection변수
	int count = 0,temp,quiz_count = 1;
	char answel[10];


	int temp01=1;
	while(temp01){
	for(j=0;j<10;j++) //배열 초기화
	{
		ok[j] = 0;
	}
	printf("\n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃  퀴즈 가위*바위*보 프로그램                    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃  (1) 국    사                                  ┃\n");
	printf("┃  (2) 세 계 사                                  ┃\n");
	printf("┃  (3) 정답확인                                  ┃\n");
	printf("┃  (4) 점수환산                                  ┃\n");
	printf("┃  (5) 종    료                                  ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("▣ 메뉴를 선택하세요 : "); //메뉴선택.
	fflush(stdin);
	scanf("%d", &selection);

		switch(selection)
		{
		case 1://국사
			init01();
			printf("▣ I  D : ");
			scanf("%s", inpName);
			while(1)
			{
				srand(time(NULL));		
				one_print(quiz_count); //출력 
				while(1) //문제 중복검사
				{
					i = rand()%10;
					if(ok[i] == 0)
					{
						ok[i] = 1;
						break;
					}
				}
	    
				two_print(i); //출력 
				temp = gawi(i,quiz_count); 
				one_print(quiz_count);
				two_print(i);
				
				if(temp==1)
				{
					printf("힌트 : %s \n",quiz[i].hint);	//힌트
				}

				printf("정답  >> ");
				scanf("%s",answel);

				if(!strcmp(quiz[i].answer,answel))
				{
					inpPoint+=10;	//정답일 시 점수 한 문제당 10점씩 누적
					printf("정답입니다. 다음문제 이동 [Enter] \n");
				}
				else
				{
					printf("틀렸습니다. 다음문제 이동 [Enter] \n");
				}
				quiz_count++;
				getch();		//버퍼메모리 자리 공간 getch() 호출
				system("cls");
		
				if(quiz_count==10)
				{
					printf("\n\n▣ %s님의 획득 점수는 %3d점 입니다.\n", inpName,inpPoint);
					break;
				}
			}
			break;
		case 2://세계사
			init02();
			printf("▣ I  D : ");
			scanf("%s", inpName);
			while(1)
			{
				srand(time(NULL));		
				one_print(quiz_count); //출력 
				while(1) //문제 중복검사
				{
					i = rand()%10;
					if(ok[i] == 0){
						ok[i] = 1;
						break;
					}
				}
	    
				two_print(i); //출력 
				temp = gawi(i,quiz_count); 
				one_print(quiz_count);
				two_print(i);

				if(temp==1)
				{
					printf("힌트 : %s \n",quiz[i].hint);	//힌트
				}

				printf("정답  >> ");
				scanf("%s",answel);
	
				if(!strcmp(quiz[i].answer,answel))
				{
					printf("<정답> Enter Key를 입력하시면 다음 문제로 넘어갑니다. \n");
				}
				else
				{
					printf("<오답> Enter Key를 입력하시면 다음 문제로 넘어갑니다. \n");
				}
				quiz_count++;
				getch();
				system("cls");

				if(quiz_count==10)
				{
					printf("\n\n▣ %s님의 획득 점수는 %3d점 입니다.\n", inpName,inpPoint);
					break;
				}
			}
			break;
		case 3://정답확인
			solution();//정답확인 함수 호출
			break;
		case 4://점수환산
			
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("  ▣ 점 수 환 산\n");
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("▣ I  D : ");
 			scanf("%s", &name);
 			printf("▣ 점 수: ");
			scanf("%d", &inpPoint);
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("  ▣ 득점별 점수 환산표\n");
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			for (i=0; i<5; i++)
			{
				printf("State : %-10s 점 수 : %3d ~%3d\n\n", num_board[i], point[i],point[i]-20);
			}
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("  ▣ %10s님의 점수 : %3d점\n",name,inpPoint);
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			

			break;
		case 5://종료
			return 0; // 프로그램 종료.
		default:
			printf("\n\a");						//escape 문자 'wa' 경고음
			printf("┏CAUTION!━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("┃   다시 입력하세요.                             ┃\n");
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		}
		printf("메뉴로 돌아가시겠습니까?(y/n)\n");
		scanf("%s",&temp02);
		if(temp02 == 'y' || temp02 == 'Y')
		{
			temp01 = 1;
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			printf("▣ 퀴즈가위바위보 프로그램을 이용해 주셔서 감사합니다.\n");
			return 0;
		}
	}
}

//문제번호
void one_print(int quiz_count)
{
		printf("\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃문제 %2d번							      ┃\n",quiz_count);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}
//문제 출력
void two_print(int i)
{
		printf("\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("  %s\n",quiz[i].told);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
			
}
//국사 문제
void init01()
{
	
	strcpy(quiz[0].answer,"이순신"); 	
	strcpy(quiz[0].told,"100원에 새겨진 위인의 이름은 무엇입니까?");		
	strcpy(quiz[0].hint,"거북선");

	strcpy(quiz[1].answer,"퇴계이황");
	strcpy(quiz[1].told,"1000원권에 새겨진 위인의 이름은 무엇입니까?");
	strcpy(quiz[1].hint,"조선성리학의 기초를 세운 선비, 나아감과 물러남의 의미");

	strcpy(quiz[2].answer,"율곡이이");
	strcpy(quiz[2].told,"5000원권에 새겨진 위인의 이름은 무엇입니까?");
	strcpy(quiz[2].hint,"심사임당의 아들");

	strcpy(quiz[3].answer,"세종대왕");	
	strcpy(quiz[3].told,"10000원권에 새겨진 위인의 이름은 무엇입니까?");
	strcpy(quiz[3].hint,"훈민정음");

	strcpy(quiz[4].answer,"신사임당");	
	strcpy(quiz[4].told,"10000원권에 새겨진 위인의 이름은 무엇입니까?");
	strcpy(quiz[4].hint,"현모양처");

	strcpy(quiz[5].answer,"임진왜란");	
	strcpy(quiz[5].told,"[용어]1592~1598년, 두 차례에 걸쳐 우리나라를 침입한 일본과의 싸움 :");
	strcpy(quiz[5].hint,"한산대첩");	

	strcpy(quiz[6].answer,"을미사변");	
	strcpy(quiz[6].told,"[용어]명성황후를 시해하고 일본세력 강화를 획책한 정변 :");
	strcpy(quiz[6].hint,"일본 자객의 경복궁 침입 사건");

	strcpy(quiz[7].answer,"광복");
	strcpy(quiz[7].told,"8월15일은 '□□절'이다. 빈칸은 무엇입니까?");
	strcpy(quiz[7].hint,"유관순, 백범 김구, 도산 안창호");

	strcpy(quiz[8].answer,"장보고");
	strcpy(quiz[8].told,"해적들의 인신매매를 근절, 완전 소탕한 신라의 무장 :");
	strcpy(quiz[8].hint,"바다의 왕");

	strcpy(quiz[9].answer,"계백");	
	strcpy(quiz[9].told,"나당연합군(5만)을 5천의 군사로 네 차례 승리를 만든 장군의 이름 :");
	strcpy(quiz[9].hint,"백제 말기의 장군");
}
//세계사 문제
void init02()	
{
	
	strcpy(quiz[0].answer,"4"); 	
	strcpy(quiz[0].told,"제 1차 세계대전은 □년동안 지속되었다. 빈칸은 무엇입니까?");		
	strcpy(quiz[0].hint,"1918년 11월 11일 독일의 항복으로 끝남.");

	strcpy(quiz[1].answer,"제2차세계대전");
	strcpy(quiz[1].told,"[용어]지금까지의 인류 역사에서 가장 큰 인명과 재산 피해를 낳은 전쟁 :");
	strcpy(quiz[1].hint,"연합국 사이에 벌어진 세계 규모의 전쟁");

	strcpy(quiz[2].answer,"트로이목마");
	strcpy(quiz[2].told,"[용어]□□□□□는 그리스가 트로이를 무너트릴 때 결정적인 역할을 하였다.");
	strcpy(quiz[2].hint,"Trojan Horse");

	strcpy(quiz[3].answer,"히틀러");	
	strcpy(quiz[3].told,"□□□는 제2차세계대전을 일으켰지만 패색이 짙어지자 자살하였다. ");
	strcpy(quiz[3].hint,"독일의 정치가이며 독재자로 불린다.");

	strcpy(quiz[4].answer,"진주만");	
	strcpy(quiz[4].told,"[용어]일본의 □□□기습을 계기로 미국이 2차대전에 뛰어들게 되었다.");
	strcpy(quiz[4].hint,"풍부하게 나던 진주를 만들어 내는 굴 때문에 붙은 이름");

	strcpy(quiz[5].answer,"잔다르크");	
	strcpy(quiz[5].told,"□□□□: 영국의 백년전쟁 후기에 프랑스를 위기에서 구한 영웅적인 소녀.");
	strcpy(quiz[5].hint,"마녀로 몰려 19세 꽃다운 나이에 화형 당함.");	

	strcpy(quiz[6].answer,"난징");	
	strcpy(quiz[6].told,"□□ 조약은 중국이 외국과 맺은 최초의 근대적인 조약이며 불평등조약이다.");
	strcpy(quiz[6].hint,"아편전쟁");

	strcpy(quiz[7].answer,"산업혁명");
	strcpy(quiz[7].told,"□□□□:18세기 중엽 영국에서 시작된 기술혁신과 사회·경제 구조의 변혁.");
	strcpy(quiz[7].hint,"공업화");

	strcpy(quiz[8].answer,"베르사유");
	strcpy(quiz[8].told,"□□□□조약:제1차 세계대전 후 전쟁에 승리한 연합국과 패전국 독일의 강화조약.");
	strcpy(quiz[8].hint,"이 조약으로 독일은 해외식민지는 모두 상실, 유럽 내 영토를 잃었다.");

	strcpy(quiz[9].answer,"면죄부");	
	strcpy(quiz[9].told,"금전 및 재물을 봉헌한 사람들에게 죄를 면해준다는 뜻의 증서.");
	strcpy(quiz[9].hint,"15세기 말기,대량 발행으로 루터의 비판을 불러일으키고 종교 개혁의 실마리가 됨.");
}
//정답확인<국사*세계사>
void solution()
{
	printf("  ▣국  사\n");
	printf("  (1)100원에 새겨진 위인의 이름 : 이순신\n");
	printf("  [Hint] 거북선\n");
	printf("  (2)1000원권에 새겨진 위인의 이름 : 퇴계이황\n");
	printf("  [Hint]조선성리학의 기초를 세운 선비, 나아감과 물러남의 의미\n");
	printf("  (3)5000원권에 새겨진 위인의 이름 : 율곡이이\n");
	printf("  [Hint]심사임당의 아들\n");
	printf("  (4)10000원권에 새겨진 위인의 이름 : 세종대왕\n");
	printf("  [Hint]훈민정음\n");
	printf("  (5)10000원권에 새겨진 위인의 이름 : 신사임당\n");
	printf("  [Hint]현모양처\n");
	printf("  (6)1592~1598년, 두 차례에 걸쳐 우리나라를 침입한 일본과의 싸움 : 임진왜란\n");
	printf("  [Hint]한산대첩\n");
	printf("  (7)명성황후를 시해하고 일본세력 강화를 획책한 정변 : 을미사변\n");
	printf("  [Hint]일본 자객의 경복궁 침입 사건\n");
	printf("  (8)8월15일은 '□□절' : 광복절\n");
	printf("  [Hint]유관순, 백범 김구, 도산 안창호\n");
	printf("  (9)해적들의 인신매매를 근절, 완전 소탕한 신라의 무장 : 장보고\n");
	printf("  [Hint]바다의 왕\n");
	printf("  (10)나당연합군(5만)을 5천의 군사로 네 차례 승리를 만든 장군의 이름 : 계백\n");
	printf("  [Hint]백제 말기의 장군\n");
	printf("\n");
	printf("  ▣세계사\n");
	printf("  (1)제 1차 세계대전은 4년동안 지속되었다.\n");
	printf("  [Hint]1918년 11월 11일 독일의 항복으로 끝남.\n");
	printf("  (2)지금까지의 인류 역사에서 가장 큰 인명과 재산 피해를 낳은 전쟁\n");
	printf("  :제2차세계대전\n");
	printf("  [Hint]연합국 사이에 벌어진 세계 규모의 전쟁\n");
	printf("  (3)트로이목마는 그리스가 트로이를 무너트릴 때 결정적인 역할을 하였다.\n");
	printf("  [HintTrojan Horse\n");
	printf("  (4)히틀러는 제2차세계대전을 일으켰지만 패색이 짙어지자 자살하였다.\n");
	printf("  [Hint]독일의 정치가이며 독재자로 불린다.\n");
	printf("  (5)일본의 진주만기습을 계기로 미국이 2차대전에 뛰어들게 되었다.\n");
	printf("  [Hint]풍부하게 나던 진주를 만들어 내는 굴 때문에 붙은 이름\n");
	printf("  (6)잔다르크: 영국의 백년전쟁 후기에 프랑스를 위기에서 구한 영웅적인 소녀.\n");
	printf("  [Hint]마녀로 몰려 19세 꽃다운 나이에 화형 당함.\n");
	printf("  (7)난징조약은 중국이 외국과 맺은 최초의 근대적인 조약이며 불평등조약이다.\n");
	printf("  [Hint]아편전쟁\n");
	printf("  (8)산업혁명:18세기 중엽 영국에서 시작된 기술혁신과 사회·경제 구조의 변혁.\n");
	printf("  [Hint]공업화\n");
	printf("  (9)베르사유조약:\n");
	printf("  제1차 세계대전 후 전쟁에 승리한 연합국과 패전국 독일의 강화조약.\n");
	printf("  [Hint]이 조약으로 독일은 해외식민지는 모두 상실, 유럽 내 영토를 잃었다.\n");
	printf("  (10)금전 및 재물을 봉헌한 사람들에게 죄를 면해준다는 뜻의 증서 : 면죄부\n");
	printf("  [Hint]\n");
	printf("  15세기 말기,대량 발행으로 루터의 비판을 불러일으키고 종교 개혁의 실마리가 됨.\n");
}
//가위바위보
int gawi(int i,int quiz_count) //0비김 1이긴 2짐
{
	char *psr[3] = {"가위","바위","보"};
	int com, you, count = 0;
	int win = 0,t;
		
	printf("▣ 컴퓨터와의 가위*바위*보 ( 이기면 힌트 지급 )\n");
	printf("▣ Enter Key를 누르면 대결이 시작됩니다.\n");
	getch();	
	system("cls");
		
	
	one_print(quiz_count);
	two_print(i);
	emoticon();						//이모티콘 출력	
	srand((unsigned)time(NULL));
	com = rand()%3 + 1;
	printf("     가위(1), 바위(2), 보(3) 숫자입력 [  ]\b\b\b ");
	scanf("%d",&you);
			
	printf("컴퓨터는 %s, 당신은 %s\n",psr[com-1],psr[you-1]);
	printf("\n");
	printf("결과 : ");

	if(com==1){
		if(you==1) { printf("비겼습니다. \n"); }
		else if(you == 2) { printf("당신이 이겼습니다. \n"); count++;}
		else if(you == 3) { printf("컴퓨터가 이겼습니다. \n"); }
	}else if(com == 2){
		if(you==1) { printf("컴퓨터가 이겼습니다. \n"); }
		else if(you == 2) { printf("비겼습니다.\n"); }
		else if(you == 3) { printf("당신이 이겼습니다.\n"); count++;}
	}else{
		if(you == 1) { printf("당신이 이겼습니다.\n"); count++;}
		else if(you == 2) { printf("컴퓨터가 이겼습니다.\n"); }
		else { printf("비겼습니다.\n"); }
	}
	printf("\n");
	printf("▣ Enter Key를 입력하신 후, 정답을 기입해주세요.\n\n");	
	getch();
	system("cls");
	return count;
}
//가위바위보 이모티콘
void emoticon()
{
	printf("      **   **               *  *  *  *      \n");   
	printf("      **   **               *  *  *  *      \n");
	printf("      **   **     ******    **********      \n");
	printf("       ** **     ********   *************   \n");
	printf("      *******    ********   **********      \n");
	printf("      *******    ********    *********      \n");
	printf("       ******     ******     ********       \n");
}

