#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>		//SetConsoleCursorPosition(), GetStdHandle()

int _CommonSense=0;			//일반상식 획득점수
int _Korea=0;				//국사 획득점수
int _World=0;				//세계사 획득점수
//##########[문제 관련 구조체, 함수, 전역변수]##########//
typedef struct quiz_q
{
	char answer[20];//정답
	char told[100]; //문제
	char hint[100]; //힌트
}quiz_q;

quiz_q quiz[10];						//구조체 배열 (10문제)
void init01();							//국사문제 함수 선언
void init02();							//세계사문제 함수 선언
void init03();							//일반상식문제 함수 선언
void one_print(int quiz_count);			//문제번호출력
void two_print(int i);					//문제 출력
void solution_CommonSense();			//문제정답
void solution_Korea();					//문제정답
void solution_World();					//문제정답
int ok[10];								//문제중복검사
int i=0,j = 0;							//for문을 위한 변수
int count=0;
int inpPoint=0;							//사용자 입력받을 점수
int selection = 0;						//메뉴선택 selection변수
int quiz_count = 1;
char answel[10];
//##########[디지털 숫자 표현 전역변수 및 함수]##########//
void number_check(int k,int i);
void digit_print(int dim[], int line);
int line=0;
int zero[20] =
		{1,1,1,1,
		1,0,0,1,
		1,0,0,1,
		1,0,0,1,
		1,1,1,1};
int one[20] =
		{0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0,
		0,0,1,0};
int two[20] =
		{1,1,1,1,
		0,0,0,1,
		1,1,1,1,
		1,0,0,0,
		1,1,1,1};
int three[20] =
		{1,1,1,1,
		0,0,0,1,
		1,1,1,1,
		0,0,0,1,
		1,1,1,1};
int four[20] =
		{1,0,0,1,
		1,0,0,1,
		1,1,1,1,
		0,0,0,1,
		0,0,0,1};
int five[20] =
		{1,1,1,1,
		1,0,0,0,
		1,1,1,1,
		0,0,0,1,
		1,1,1,1};
int six[20] =
		{1,1,1,1,
		1,0,0,0,
		1,1,1,1,
		1,0,0,1,
		1,1,1,1};
int seven[20] =
		{1,1,1,1,
		1,0,0,1,
		1,0,0,1,
		0,0,0,1,
		0,0,0,1};
int eight[20] =
		{1,1,1,1,
		1,0,0,1,
		1,1,1,1,
		1,0,0,1,
		1,1,1,1};
int nine[20] =
		{1,1,1,1,
		1,0,0,1,
		1,1,1,1,
		0,0,0,1,
		0,0,0,1};
//##########[슬롯 게임 전역변수 및 함수]##########//
void display_rule();									//우측 릴 당첨 게시판
void reel_series(int r[][3]);							//릴문자 섞는 함수
void display_reel(char rc[][3],int r[][3],int index);	//릴게임 문자 섞는 함수
int game_control(char reel[][3],int reel_num[][3]);		//릴게임 힌트 지급 유/무 계산 함수
int return_hint(int r[],int *case_n);					//릴게임 힌트 지급 유/무 계산 함수
int slot_machine();										//슬롯머신 Display
//##########[콘솔 창 색상 Define 설정]##########//
#define col GetStdHandle(STD_OUTPUT_HANDLE)				//콘솔창의 핸들정보 받기 
#define WHITE SetConsoleTextAttribute( col,0x000f);		//흰색
#define SKY SetConsoleTextAttribute( col, 0x000b);		//하늘색
#define YEL SetConsoleTextAttribute( col, 0x000e);		//노란색
#define HIG SetConsoleTextAttribute( col, 0x000d);		//형광
//##########[방향키 ASCII값 Define 설정]##########//
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN  80
//##########[파일입출력 관련 구조체]##########//
typedef struct 
{
	char id[12];
	char pass[14];
	char name[12];
	int ranking;
	int score;
	int getScore_CommonSense;							//일반상식 획득점수
	int getScore_Korea;									//국사 획득점수
	int getScore_World;									//세계사 획득점수
} person;
//##########[방향키 ASCII값 Define 설정]##########//
void front_menu();
//##########[초기화 함수]##########//
void Init_people();										//파일입출력을 위한 초기화함수
void ranking();											//랭킹구현함수
void gotoxy(int x, int y);
//##########[회원에 대한 함수]##########//
void search_people(void);								//회원검색
void new_people(void);									//회원가입
void Login();											//로그인
void delete_data(void);									//회원삭제
//##########[파일 점수 저장 함수]##########//
void save_score(); 
//##########[관리자 관련 함수]##########//
void master_login(void);								//관리자모드 - 로그인
void master_menu(void);									//관리자모드 - 메뉴보기
void master_all_print(void);							//관리자모드 - 모든사용자보기
void main_print(void);									//메인화면 프린트
//##########[메뉴선택 이동 관련 함수]##########//
void move_01(); 
void move_02();
void main_p();
void main_p2();
//##########[기타 전역 변수]##########//
char *file = "person.txt";								//파일입출력할 *파일명*
person* d;												//파일입출력시 동적할당
int total_block;										//사용자가 몇명인지 계산후 저장
person* login_person;									//로그인 사용자 지정
void front_menu()			
{
	int select;
	while(1)
	{
		Init_people();					//사람들의 정보를 메모장에서 불러온다
		system("cls");
		main_print();
		gotoxy(49,23);					//메인메뉴 커서좌표수정
		scanf("%d",&select);
		fflush(stdin);
		switch(select)
		{
		case 1:							// *회원가입 
			system("cls");
			new_people();  
			break;
		case 2:							// *로그인
			system("cls");
			Login();
			break;
		case 3:							// *검색 
			system("cls");
			search_people();
			break;
		case 4:							// *랭킹		
			system("cls");  
			ranking();
			break;
		case 5:							// *관리자 모드
			system("cls");  
			master_login();				//관리자ID : 임승한  관리자PASS : 6411 
			system("cls");
			break;
		case 6:							// *종료
			printf("\n\n\n");
			exit(1);		
		default :						 // *1 ~ 6번의 번호가 아닌 다른번호가 눌렸다면
			printf("Wrong number. Please re-enter\n");
		}
	} 
}
int main(void)
{	
	front_menu();
	return 0;
}
void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void main_print()
{
	YEL;
	printf("    =============================================================== \n");
	printf("                ♠   Welcome To My Quiz Program   ♠            \n");
	printf("    =============================================================== \n");
	WHITE;
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃  1. 회원가입                             ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃  2. 로그인                               ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃  3. 정보 검색                            ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃  4. 랭킹                                 ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃  5. 관리자 모드                          ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t┃  6. 종료                                 ┃\n");
	printf("\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\t                            ┏━━━━━━━┓       \n");
	printf("\t                            ┃Number : [ ]  ┃       \n");
	printf("\t                            ┗━━━━━━━┛       \n"); 	
}
//##########[회원 함수]##########//
void Init_people()
{
	FILE *fpr;
	fpr = fopen(file,"rb");
	if(fpr == NULL){
		printf("File Open에 오류발생!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr) / sizeof(person); // 회원의 수
	fseek(fpr,0L,SEEK_SET);
	d = (person *)malloc(sizeof(person) * total_block);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
}
//##########[회원 찾기 함수]##########//
void search_people()
{
	int i, check = 0;
	char name[12];						//이름입력배열
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               ♠      ID search      ♠                   \n");
	printf("\t===========================================================\n\n");
	WHITE;
	printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t   ┃         Name : ____________           (12자 이내)┃\n");
	printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	gotoxy(30,7);
	gets(name);							// *이름 입력
	puts("");
	// ******* 이름 검색 ******* //
	for(i=0;i<total_block;i++)
		if(strcmp(name,d[i].name) == 0)
		{
			puts("");
			check = 1;					 // *사용자 이름이 txt파일에 있다면
			
			printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("\t\t┃랭킹 : %-3d등                                ┃\n",d[i].ranking);
			printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("\t\t┃이름 : %-7s                              ┃\n",d[i].name); 
			printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("\t\t┃획득점수  :  %-3d점                          ┃\n",d[i].score);
			printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("\t\t┃국사:%-3d점 ┃세계사:%-3d점┃일반상식:%-3d점   ┃\n",d[i].getScore_Korea,d[i].getScore_World,d[i].getScore_CommonSense);
			printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
			HIG;
			printf("\t\t\t   Press Enter Key !!\n");
			getch();
			break;
		}
		if(check == 0)					//사용자 이름이 txt파일에 없다면
		{
			HIG;
			printf("\t\n\t\t\t   Non-existent users !! \n");
            getch();
		}
}		
//##########[회원 가입 함수]##########//
void new_people(void)	
{
	int i,j, check = 0;
	char c;					// 비밀번호를 *로 찍기위하여 한글자씩 문자를 입력받기위한 변수
	FILE *fpa;
	person aa;
	FILE *fpr;
	fpa = fopen(file,"ab"); // *txt 맨뒤에 써줌
	if(fpa == NULL)
	{
		printf("File Open에 오류 발생!");
		exit(1);
	}
	do{
		check = 0;							 // *아이디 중복검사( :1이면 중복 :0이면 사용가능 ) 
		system("cls");
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               ♠      Admission      ♠                   \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t   ┃          I D : ____________           (12자 이내)┃\n");
		printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		gotoxy(30,7);
		gets(aa.id);						// *아이디 입력
		fpr = fopen(file,"rb"); 
		if(fpr == NULL)
		{
			printf("File Open에 오류발생!");
			exit(1);
		}
		puts("");
		for(i=0;i<total_block;i++){
			if(strcmp(aa.id,d[i].id) == 0)  // *입력한 id가 txt에 저장된 id와 똑같다면
			{ 
				HIG;
				printf("\t\t\t Duplicate ID exists !!\n");
				check = 1;					// *중복됐다고 1로 체크
				getch();					// *아무키나 입력받음
				break;
			}
		}
	}while(check == 1);						// *중복되면 무한루프
	printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t   ┃     Password : ____________           (14자 이내)┃\n");
	printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	// **** 비밀번호 *로 찍어주기 **** //
	i = 0;
	while(i<=13)
	{
		gotoxy(30,10);						// *비밀번호 입력 좌표
		for(j=0;j<13;j++){					// *13자리 _로 출력해줌
			putchar('_');
		}
		gotoxy(30,10);
		for(j=0;j<i;j++){					//i는 입력한 갯수이기 때문에 
			putchar('*');					//입력한 갯수만큼 *로 찍어줌
		}
		c = getch();						// *문자 한개 입력받음(누름과동시에 변수c에 저장)
		if(c == '\r'){						// *Enter 입력시 
			aa.pass[i] = '\0';				// *마지막 문자는 NULL저장
			break;
		}else if(c == '\b'){				// *Back Space 입력시
			if(i > 0){						// *i값이 0보다 커야지만 처음자리에서 뒤로 밀려나지 않음
				i--;							// *Back Space 기능 실행을 위해 i를 한칸 뒤로 밀어줌
			}
		}else{								// *Enter or BackSpace가 아니면 
			aa.pass[i++] = c;				// *패스워드 입력
		}
	}
	puts("");
	puts("");
	printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t   ┃         Name : ____________            (6자 이내)┃\n");
	printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	gotoxy(30,13);
	gets(aa.name);							// *이름 입력 
	aa.score = 00;
	aa.ranking=01;
	aa.getScore_CommonSense=0;				//일반상식 점수 초기화
	aa.getScore_Korea=0;					//국사 점수 초기화
	aa.getScore_World=0;					//세계사 점수 초기화
	HIG;
    puts("");
	puts("");
    printf("\t\t\t   ┏━━━━━━━━━┓\n");
	printf("\t\t\t   ┃  save completed! ┃\n"); 
	printf("\t\t\t   ┗━━━━━━━━━┛\n"); 
	getch();
	fseek(fpa,0L,SEEK_END);
	fwrite(&aa,sizeof(person),1,fpa); 
	fclose(fpa);
}
//##########[회원 로그인 함수]##########//
void Login()
{
	long i,j,k;
	int check= 0;						// *아이디와 비밀번호가 맞았는지 체크
	int count = 0;						// *아이디와 비밀번호가 3번이상 틀렸는지 체크
	char id[12];
	char pass[14];
	char c;								// *비밀번호를 *로 찍어주기위한 변수 char변수
	while(check == 0){					// *아이디와 비번이 맞지않으면 무한루프
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               ♠     L o g - i n       ♠                 \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t   ┃          I D : ____________           (12자 이내)┃\n");
		printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		gotoxy(30,7);					// *아이디 입력 좌표
		gets(id);						// *아이디 입력받음
		puts("");
		for(i=0;i<total_block;i++){
			if(strcmp(id,d[i].id) == 0) // *id가 txt에 저장된 id와 일치한다면
				break;				    // *break를 걸어 i를 그대로 저장해둠
		}
		WHITE;
		printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t   ┃     Password : ____________           (14자 이내)┃\n");
		printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		k = 0;
		while(k<=13)					// *비밀번호는 최대 14자리까지 
		{
			gotoxy(30,10);				// *비밀번호 입력 좌표
			for(j=0;j<13;j++){			// *13자리 _로 출력해줌
				putchar('_');
			}
			gotoxy(30,10);
			for(j=0;j<k;j++){			// *k는 입력한 갯수이기 때문에 
				putchar('*');			// *입력한 갯수만큼 *로 찍어줌
			}
			c = getch();				// *문자 한개 입력받음(누름과동시에 변수c에 저장)
			if(c == '\r'){				// *Enter 입력시 
				pass[k] = '\0';			// *마지막 문자는 NULL저장
				break;
			}else if(c == '\b'){		// *Back Space 입력시
				if(k > 0){				// *k값이 0보다 커야지만 처음자리에서 뒤로 밀려나지 않음
					k--;					// *Back Space 기능 실행을 위해 k를 한칸 뒤로 밀어줌
				}
			}else{						// *Enter or BackSpace가 아니면 
				pass[k++] = c;			// *패스워드 입력
			}
		}
		puts("");
		puts("");
		if(strcmp(pass,d[i].pass) == 0){ // *비밀번호가 일치한다면
			check = 1;					 // *일치함 :1을 check에 저장
			HIG;
			printf("\n\t\t\tConnection and Press Enter Key \n"); 
			login_person = &d[i];		 //Change
			getch();
			system("cls");
			move_01(); 
			break;
		}else{							 // *비밀번호가 일치하지 않으면 다시 루프
			HIG;
			printf("\n\t\t   ID does not exist or Password error !! \n");
			count++;
			getch();
		}
		if(count == 3) {				 // *비밀번호 3번까지 입력가능* //
			HIG;
			printf("\n\t\t\tPassword three times the error !! \n");
			getch();
			break;
		}
		system("cls");
	}
}
//##########[점수 저장 함수]##########//
void save_score()
{
	//## 메모장에 파일을 저장하기 위한 변수들 ##
	int i; 
	FILE *fpr;
	person aa;	//
	// ** 같은 이름을 찾아 점수를 입력함 ** //
	for(i=0;i<total_block;i++)
	{
		if(strcmp(login_person->id , d[i].id) == 0) // *이름이 일치하면
		{
			d[i].getScore_Korea+=_Korea;			//국사 획득 점수 대입
			d[i].getScore_World=_World;				//세계사 획득 점수 대입
			d[i].getScore_CommonSense=_CommonSense; //일반상식 획득 점수 대입
			d[i].score += inpPoint;
			break;
		}
	}
	//석차구하기//
	for(i=0 ; i<total_block; i++)
		{
			for(j=0 ; j<total_block; j++)
			{
				if (d[i].score < d[j].score)
					d[i].ranking++;
			}
		}
	fflush(stdin);
	// 수정후 메모장에 다시 저장 // 
	fpr = fopen(file,"wb");
	fseek(fpr,0L,SEEK_SET);
	fwrite(d,sizeof(person), total_block, fpr);
	fclose(fpr);	
}
//##########[관리자 함수]##########//
//##########[관리자-삭제]##########//
void delete_data(void)
{
	long i , total_block;
	int check = 0;
	char name[12];
	FILE *fpr;
	fpr = fopen(file,"rb");									 // *파일 읽음
	if(fpr == NULL){
		printf("File Open에 오류발생!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr)/sizeof(person);				// *txt에 저장된 회원수
	fseek(fpr,0L,SEEK_SET);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
	// ** 사용자 정보 출력 ** //	
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               ♠    All user information    ♠            \n");
	printf("\t===========================================================\n\n");
	puts("");
	WHITE;
	printf("\t ┏━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t ┃%-2s ┃%-8s     ┃%-13s┃\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue;  // *관리자 빼고 출력
		printf("\t ┃%-2d      ┃%-8s     ┃%-13d┃\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t ┗━━━━━━━━━━━━━━━━━━━┛\n");
	// ** 삭제할 이름입력하고 지움 ** //
	HIG;
	printf("\n\t    Enter the name of the user to delete and Press Enter\n");
	printf("\t\t[            ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
	gets(name);												// *이름입력
	for(i=0;i<total_block;i++){
		if(strcmp(name,d[i].name) == 0)						// *이름이 일치하면
		{
			check = 1;										// *일치함 :1을 check에 저장
			d[i] = d[total_block - 1];						// *마지막 데이터를 지운데이터에 넣어줌
			total_block--;									// *회원수 한명 줄임
		}													//(txt에 저장할때 마지막 데이터는 지워짐) 
	}
	if(check == 0) 
		HIG;
	printf("No matching data\n"); 
	// ** 데이터 삭제 완료 ** //
	// 삭제 후 메모장에 다시 저장 // 
	fpr = fopen(file,"wb");
	fseek(fpr,0L,SEEK_SET);
	fwrite(d,sizeof(person), total_block, fpr);				// *마지막 회원을 제외한 것 txt에 저장
	fclose(fpr);
	// ** 삭제후 데이터 출력 ** // 
	system("cls");
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t         ♠   After deleting the list of users    ♠       \n");
	printf("\t===========================================================\n\n");
	WHITE;
	printf("\t ┏━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t ┃%-2s ┃%-8s     ┃%-13s┃\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue;  // *관리자 빼고 출력
		printf("\t ┃%-2d      ┃%-8s     ┃%-13d┃\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t ┗━━━━━━━━━━━━━━━━━━━┛\n");
	HIG;
	printf("\n\t\t\tPress any key to return to the menu\n");
	getch();
}	
//##########[관리자 로그인 함수]##########//
// * 관리자 ID : 임승한 관리자 Pass : 6411 * //
void master_login(void)
{
	long i,j,k;
	int check= 0;						// *아이디와 비번이 일치하는지 체크 
	int count  = 0;						// *3번이상 틀렸는지 체크
	char id[12];
	char pass[14];
	char c;
	while(check == 0)
	{									// *아이디와 비밀번호가 일치하지 않으면 무한루프
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               ♠    Administrator Mode     ♠             \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t   ┃ Administrator ID : ____________       (12자 이내)┃\n");
		printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		gotoxy(34,7);					// *아이디 입력 좌표
		gets(id);						// *아이디 입력
		puts("");
		for(i=0;i<total_block;i++)
		{
			if(strcmp(id,"임승한") == 0)// *관리자아이디 (임승한)과 일치하면
				break;                  // * for문 멈추고 i값 저장
		}
		WHITE;
		printf("\t   ┏━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t   ┃Administrator Password : ____________  (14자 이내)┃\n");
		printf("\t   ┗━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		// **** 비밀번호 *로 찍어주기 **** //
		k = 0;
		while(k<=13)					// *비밀번호는 최대 14자리까지 
		{
			gotoxy(39,10);				// *비밀번호 입력 좌표
			for(j=0;j<13;j++)
			{
				putchar('_');			// *13자리 _로 출력해줌
			}
			gotoxy(39,10);
			for(j=0;j<k;j++)			// *k는 입력한 갯수이기 때문에 
			{
				putchar('*');			// *입력한 갯수만큼 *로 찍어줌
			}
			c = getch();				// *문자 한개 입력받음(누름과동시에 변수c에 저장)
			if(c == '\r')
			{							// *Enter 입력시 
				pass[k] = '\0';			// *마지막 문자는 NULL저장
				break;
			}
			else if(c == '\b')
			{							// *Back Space 입력시
				if(k > 0)
				{						// *k값이 0보다 커야지만 처음자리에서 뒤로 밀려나지 않음
					k--;					// *Back Space 기능 실행을 위해 k를 한칸 뒤로 밀어줌
				}
			}
			else
			{							// *Enter or BackSpace가 아니면 
				pass[k++] = c;			// *패스워드 입력
			}
		}
		puts("");
		puts("");
		if(!strcmp(pass,"6411")){		// *관리자비번(6411)과 일치하면
			check = 1;					// *while문 나감
			HIG;
            printf("\n\t\t 임승한 님 Connection .. Press Enter Key \n"); 
			getch();
			system("cls");
			master_menu();				// *관리자 메뉴 띄움
			break;
		}else{
			HIG;
			printf("\n\t\t   ID does not exist or Password error !! \n");	
			getch();
		}
		if(count == 3) {				// *비밀번호 오류 3번까지 가능 *//
			HIG;
			printf("\n\t\t\tPassword three times the error !! \n");
			getch();
			break;
		}
		system("cls");
	}
}
//##########[관리자 모드 메뉴]##########//
void master_menu()
{
	int select = 0;
	while(select != 3)
	{
		system("cls");
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               ♠     Administrator Mode     ♠            \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃  1. View all users                       ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃  2. Delete User Information              ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\t\t┏━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("\t\t┃  3. Exit Admin Mode                      ┃\n");
		printf("\t\t┗━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\t\t                                              \n"); 
		printf("\t\t                            ┏━━━━━━━┓\n");
		printf("\t\t                            ┃Number : [ ]  ┃\n");
		printf("\t\t                            ┗━━━━━━━┛\n"); 
		gotoxy(57,17);
		scanf("%d",&select); // *사용자로부터 번호입력받음
		fflush(stdin);
		
		switch(select)
		{
		case 1:				// *모든회원정보보기
			system("cls");
			master_all_print();
			break;
		case 2:				// *회원데이터 삭제 
			system("cls");
			delete_data(); 
			break; 
		case 3:				// *종료
			system("cls");
			HIG;
			printf("\n\n\n\t\t\tExit Admin Mode... \n");
			Sleep(1500);	//1.5초후
		default :			// *1 ~ 3의 번호가 아니라면 화면 clear
			system("cls");
		}
	}
}
//##########[관리자 모드- 모든 사용자 보기]##########//
void master_all_print() 
{
	long i, total_block;
	FILE *fpr;
	person d[50];								// *txt에서 불러올 회원(최대 50명)배열
	fpr = fopen(file,"rb");						// *파일 읽음
	if(fpr == NULL){
		printf("File Open에 오류발생!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr) / sizeof(person);	// *txt저장된 회원 수
	fseek(fpr,0L,SEEK_SET);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               ♠    All user information    ♠            \n");
	printf("\t===========================================================\n\n");
	puts("");
	WHITE;
	printf("\t ┏━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t ┃%-2s ┃%-8s     ┃%-13s┃\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue;  
		printf("\t ┃%-2d      ┃%-8s     ┃%-13d┃\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t ┗━━━━━━━━━━━━━━━━━━━┛\n");
	
	HIG;
	printf("\n\t\t\tPress any key to return to the menu\n");
	getch();
}
//##########[랭킹 함수]##########//
void ranking()
{
	long i, total_block;
	FILE *fpr;
	person d[50];					// *txt에서 불러올 회원(최대 50명)배열
	fpr = fopen(file,"rb");			// *파일 읽음
	if(fpr == NULL){
		printf("File Open에 오류발생!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr) / sizeof(person); // *txt저장된 회원 수
	fseek(fpr,0L,SEEK_SET);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               ♠    Ranking information    ♠            \n");
	printf("\t===========================================================\n\n");
	puts("");
	WHITE;
	printf("\t ┏━━━━━━━━━━━━━━━━━━━┓\n");
	printf("\t ┃%-2s ┃%-8s     ┃%-13s┃\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue; 
		printf("\t ┃%-2d      ┃%-8s     ┃%-13d┃\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t ┗━━━━━━━━━━━━━━━━━━━┛\n");
	HIG;
	printf("\n\t\t\tPress any key to return to the menu\n");
	getch();
}
//###############   문제풀이로 움직이는거  ###############//
//###############   문제풀기/예습/상위메뉴  ###############//
void move_01() 
{
	int PosMeX=35, PosMeY=20;
	char c;
	int move = 0;		 //움직임 카운트함수
	main_p();
	gotoxy(PosMeX,PosMeY);
	printf("* User *");
	while(1)			//무한 반복
	{
		if(_kbhit())	//키가 입력지 감시하고 키가 입력되면 아래 문장을 실행, 단지 키가 입력되는지 감시한다.
		{
			c=getch(); //문자 하나를 입력받는 함수, 문자 하나를 입력받을 때까지 무한대기하는 함수이지만
					   //_kihit() 함수로 키가 입력될 때만 반응해서 대기 시간이 없다
			if(c=='a') PosMeX--;
			else if(c=='d') PosMeX++;
			else if(c=='w') PosMeY--;
			else if(c=='s') PosMeY++;
			system("cls");
			main_p();
			SKY;
			gotoxy(PosMeX,PosMeY);
			if(move % 2 == 0)	printf("└○┐");
			else printf("┌○┘");
			move++;
			//[상위메뉴] 입장//
			if(( PosMeX == 55 || PosMeX == 56 || PosMeX == 57 || PosMeX == 58 || PosMeX == 59 ) && PosMeY == 15 )
			{
				WHITE;
				gotoxy(10,20);
				printf("===========================================================\n");
				printf("\t                     ♠ Wait a minute ♠                 \n");
				gotoxy(10,22);
				printf("===========================================================\n\n\n");
				Sleep(1500); 
				system("cls");
				break;
			}
			//[문제풀기] 입장// 
			if( ( PosMeX == 13 || PosMeX == 14 || PosMeX == 15 || PosMeX == 16 || PosMeX == 17 ) && PosMeY == 15 )
			{
				WHITE;
				gotoxy(10,20);
				printf("===========================================================\n");
				printf("\t                     ♠ Wait a minute ♠                 \n");
				gotoxy(10,22);
				printf("===========================================================\n\n\n");
				Sleep(1500); 
				gotoxy(30,20);
				printf("                             ");
				system("cls");
				gotoxy(0,0);
				//국사 세계사 상식 선택 화면으로//
				move_02();
				break;
			}
			//[예습] 입장
			if( ( PosMeX == 35 || PosMeX == 36 || PosMeX == 37 || PosMeX == 38 || PosMeX == 39 ) && PosMeY == 15 )
			{
				int PosMeX=35, PosMeY=20;
				char c;
				int move = 0; 
				WHITE;
				gotoxy(10,20);
				printf("===========================================================\n");
				printf("\t                     ♠ Wait a minute ♠                 \n");
				gotoxy(10,22);
				printf("===========================================================\n\n\n");
				Sleep(1500);
				system("cls");
				main_p2();
				gotoxy(PosMeX,PosMeY);
				printf("* User *");
				while(1) 
				{
					if(_kbhit()) 
					{
						c=getch();
						if(c=='a') PosMeX--;
						else if(c=='d') PosMeX++;
						else if(c=='w') PosMeY--;
						else if(c=='s') PosMeY++;
						system("cls");
						main_p2();
						SKY;
						gotoxy(PosMeX,PosMeY);
						if(move % 2 == 0)	printf("└○┐");
						else printf("┌○┘");
						move++;		
						//일반상식
						if(( PosMeX == 55 || PosMeX == 56 || PosMeX == 57 || PosMeX == 58 || PosMeX == 59 ) && PosMeY == 15 )
						{
							system("cls");
							solution_CommonSense();
							_getch();
							break;
						}
						//국사
						if( ( PosMeX == 13 || PosMeX == 14 || PosMeX == 15 || PosMeX == 16 || PosMeX == 17 ) && PosMeY == 15 )
						{
							system("cls");
							solution_Korea();
							_getch();
							break;
						}
						//세계사
						if( ( PosMeX == 35 || PosMeX == 36 || PosMeX == 37 || PosMeX == 38 || PosMeX == 39 ) && PosMeY == 15 )
						{
							system("cls");
							solution_World();
							_getch();
							break;
						}
					}
				}
				break;
			}
		}
	}
}
//###############   국사/세계사/일반상식  ###############//
void move_02() 
{
	int PosMeX=35, PosMeY=20;
	char c;
	int move = 0; 
	main_p2();
	gotoxy(PosMeX,PosMeY);
	printf("* User *");
	while(1) 
	{
		if(_kbhit()) 
		{
			c=getch(); 
			if(c=='a') PosMeX--;
			else if(c=='d') PosMeX++;
			else if(c=='w') PosMeY--;
			else if(c=='s') PosMeY++;
			system("cls");
			main_p2();
			SKY;
			gotoxy(PosMeX,PosMeY);
			if(move % 2 == 0)	printf("└○┐");
			else printf("┌○┘");
			move++;
			//일반상식
			if(( PosMeX == 55 || PosMeX == 56 || PosMeX == 57 || PosMeX == 58 || PosMeX == 59 ) && PosMeY == 15 )
			{
				init03();
				while(1)
				{
					srand(time(NULL));		
					while(1)					//문제 중복검사
					{
						i = rand()%10;
						if(ok[i] == 0)
						{
							ok[i] = 1;
							break;
						}
					}
					system("cls");
					count = slot_machine();
					getch();
					system("cls");				
					one_print(quiz_count);
					two_print(i);
					if(count==1)
					{
						printf("힌트 : %s \n",quiz[i].hint);
					}
					printf("정답  >> ");
					scanf("%s",answel);
					if(!strcmp(quiz[i].answer,answel))
					{
						inpPoint+=10;			//정답일 시 점수 한 문제당 10점씩 누적
						printf("정답입니다. 다음문제 이동 [Enter] \n");
					}
					else
					{
						printf("틀렸습니다. 다음문제 이동 [Enter] \n");
					}
					quiz_count++;
					getch();		
					system("cls");
					if(quiz_count==11)
					{
						YEL;
						printf("\n");
						printf("=========================\n");
						printf("♠      획득 점수      ♠\n");
						printf("=========================\n\n");
						_CommonSense=inpPoint;//일반상식 획득점수 변수 일반상식획득점수에 대입
											  //과목별 점수 구분하기 위함.
						save_score();		  //점수 메모장에 입력 후 저장
						//디지털넘버로 숫자표현//
						for(line=0;line<=4;line++)
						{
							number_check(inpPoint, line);	
							printf("\n");
						}
						_getch();
						break;
					}
				}
				break;
			}
			//국사
			if( ( PosMeX == 13 || PosMeX == 14 || PosMeX == 15 || PosMeX == 16 || PosMeX == 17 ) && PosMeY == 15 )
			{
				init01();
				while(1)
				{
					srand(time(NULL));		
					while(1)					//문제 중복검사
					{
						i = rand()%10;
						if(ok[i] == 0)
						{
							ok[i] = 1;
							break;
						}
					}
					system("cls");
					count = slot_machine();
					getch();
					system("cls");				
					one_print(quiz_count);
					two_print(i);
					if(count==1)
					{
						printf("힌트 : %s \n",quiz[i].hint);
					}
					printf("정답  >> ");
					scanf("%s",answel);
					if(!strcmp(quiz[i].answer,answel))
					{
						inpPoint+=10;	
						printf("정답입니다. 다음문제 이동 [Enter] \n");
					}
					else
					{
						printf("틀렸습니다. 다음문제 이동 [Enter] \n");
					}
					quiz_count++;
					getch();		
					system("cls");
					if(quiz_count==11)
					{
						YEL;
						printf("\n");
						printf("=========================\n");
						printf("♠      획득 점수      ♠\n");
						printf("=========================\n\n");
						_Korea=inpPoint;
						save_score();	
						for(line=0;line<=4;line++)
						{
							number_check(inpPoint, line);	
							printf("\n");	
						}
						_getch();
						break;
					}
				}
				break;
			}
			//세계사
			if( ( PosMeX == 35 || PosMeX == 36 || PosMeX == 37 || PosMeX == 38 || PosMeX == 39 ) && PosMeY == 15 )
			{
				init02();
				while(1)
				{
					srand(time(NULL));		
					while(1) 
					{
						i = rand()%10;
						if(ok[i] == 0)
						{
							ok[i] = 1;
							break;
						}
					}
					system("cls");
					count = slot_machine();
					getch();
					system("cls");				
					one_print(quiz_count);
					two_print(i);
					if(count==1)
					{
						printf("힌트 : %s \n",quiz[i].hint);	
					}
					printf("정답  >> ");
					scanf("%s",answel);
					if(!strcmp(quiz[i].answer,answel))
					{
						inpPoint+=10;	
						printf("정답입니다. 다음문제 이동 [Enter] \n");
					}
					else
					{
						printf("틀렸습니다. 다음문제 이동 [Enter] \n");
					}
					quiz_count++;
					getch();		
					system("cls");
					if(quiz_count==11)
					{
						YEL;
						printf("\n");
						printf("=========================\n");
						printf("♠      획득 점수      ♠\n");
						printf("=========================\n\n");
						_World=inpPoint;
						save_score();	
						for(line=0;line<=4;line++)
						{
							number_check(inpPoint, line);	
							printf("\n");
						}
						_getch();
						break;
					}
				}
				break;
			}
		}
	}
}
//############### Main01, Main02  ###############//
void main_p()
{
	gotoxy(0,0);
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       ♠   MENU   ♠                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("\t■■■■■■■■■   ■■■■■■■■■   ■■■■■■■■■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■  <문제풀기>  ■   ■    <예습>    ■   ■  <상위메뉴>  ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■■■┃  ┃■■■   ■■■┃  ┃■■■   ■■■┃  ┃■■■\n");
	//gotoxy(15,15); //문제풀기 입구 좌표값 
	//gotoxy(36,15); //예습 입구 좌표값
	//gotoxy(58,15); //상위메뉴 입구 좌표값 
}
void main_p2()
{
	gotoxy(0,0);
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       ♠   MENU   ♠                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("\t■■■■■■■■■   ■■■■■■■■■   ■■■■■■■■■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■  <국    사>  ■   ■   <세계사>   ■   ■  <일반상식>  ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■              ■   ■              ■   ■              ■\n");
	printf("\t■■■┃  ┃■■■   ■■■┃  ┃■■■   ■■■┃  ┃■■■\n");
	//gotoxy(15,15); //국사 입구 좌표값 
	//gotoxy(58,15); //세계사 입구 좌표값 
	//gotoxy(36,15); //넌센스 입구 좌표값
}
//##########[국사 문제]##########//
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
	strcpy(quiz[4].told,"50000원권에 새겨진 위인의 이름은 무엇입니까?");
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
//##########[세계사 문제]##########//
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
//##########[일반상식 문제]##########//
void init03()
{
	strcpy(quiz[0].answer,"마라도"); 	
	strcpy(quiz[0].told,"대한민국에서 가장 남쪽에 있는 섬은?");		
	strcpy(quiz[0].hint,"천연기념물 제423호");
	strcpy(quiz[1].answer,"KTX");
	strcpy(quiz[1].told,"우리나라에서 가장 빠른 기차인 고속철의 공식 명칭은?");
	strcpy(quiz[1].hint,"[Korea Train eXpress]");
	strcpy(quiz[2].answer,"뇌");
	strcpy(quiz[2].told,"흔히 성가시고 귀찮을 때 ""골치가 아프다""라고 한다.\n여기서 ""골치""란 몸의 어느 부위를 가리키는 말인가?");
	strcpy(quiz[2].hint,"모든 척추동물과 대부분의 무척추동물에 있어서 신경계의 중추가 되는 기관");
	strcpy(quiz[3].answer,"매미");	
	strcpy(quiz[3].told,"굼벵이는 어느 곤충의 애벌레인가? ");
	strcpy(quiz[3].hint,"특수한 발음기를 가지고 높은 소리로 울어 잘 알려진 곤충이다.");
	strcpy(quiz[4].answer,"백골난망");	
	strcpy(quiz[4].told,"[사자성어]죽어서 백골이 되어도 그 깊은 은혜를 잊을 수가 없다는 말.");
	strcpy(quiz[4].hint,"白骨難忘");
	strcpy(quiz[5].answer,"백년해로");	
	strcpy(quiz[5].told,"[사자성어]부부가 화락하게 인생을 함께 늙음.");
	strcpy(quiz[5].hint,"百年偕老");	
	strcpy(quiz[6].answer,"백절불굴");	
	strcpy(quiz[6].told,"[사자성어]백 번 꺾여도 굴하지 않는다는 뜻. 많은 고난을 극복함.");
	strcpy(quiz[6].hint,"百折不屈");
	strcpy(quiz[7].answer,"불국사");
	strcpy(quiz[7].told,"석가탑과 다보탑이 있는 절. 이곳은 어디인가?");
	strcpy(quiz[7].hint,"경주");
	strcpy(quiz[8].answer,"진돗개");
	strcpy(quiz[8].told,"한국 특산 개 품종.");
	strcpy(quiz[8].hint,"천연기념물 53호");
	strcpy(quiz[9].answer,"귀");	
	strcpy(quiz[9].told,"우리몸에서 체온이 가장 낮은 곳은 어디인가?");
	strcpy(quiz[9].hint,"청각 및 평형감각을 담당하는 기관");
}
//##########[문항별 문제]##########//
void solution_Korea()
{
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       ♠   국 사   ♠                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("  (1)100원에 새겨진 위인의 이름 : 이순신\n");
	printf("  (2)1000원권에 새겨진 위인의 이름 : 퇴계이황\n");
	printf("  (3)5000원권에 새겨진 위인의 이름 : 율곡이이\n");
	printf("  (4)10000원권에 새겨진 위인의 이름 : 세종대왕\n");
	printf("  (5)10000원권에 새겨진 위인의 이름 : 신사임당\n");
	printf("  (6)1592~1598년, 두 차례에 걸쳐 우리나라를 침입한 일본과의 싸움 : 임진왜란\n");
	printf("  (7)명성황후를 시해하고 일본세력 강화를 획책한 정변 : 을미사변\n");
	printf("  (8)8월15일은 '□□절' : 광복절\n");
	printf("  (9)해적들의 인신매매를 근절, 완전 소탕한 신라의 무장 : 장보고\n");
	printf("  (10)나당연합군(5만)을 5천의 군사로 네 차례 승리를 만든 장군의 이름 : 계백\n");
	printf("\n");
}
void solution_World()
{
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       ♠ 세 계 사  ♠                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("  (1)제 1차 세계대전은 □년동안 지속되었다. 빈칸은 무엇입니까?\n");		
	printf("  (2)[용어]지금까지의 인류 역사에서 가장 큰 인명과 재산 피해를 낳은 전쟁 :\n");
	printf("  (3)[용어]□□□□□는 그리스가 트로이를 무너트릴 때 결정적인 역할을 하였다.\n");
	printf("  (4)□□□는 제2차세계대전을 일으켰지만 패색이 짙어지자 자살하였다. \n");
	printf("  (5)[용어]일본의 □□□기습을 계기로 미국이 2차대전에 뛰어들게 되었다.\n");
	printf("  (6)□□□□: 영국의 백년전쟁 후기에 프랑스를 위기에서 구한 영웅적인 소녀.\n");
	printf("  (7)□□ 조약은 중국이 외국과 맺은 최초의 근대적인 조약이며 불평등조약이다.\n");
	printf("  (8)□□□□:18세기 중엽 영국에서 시작된 기술혁신과 사회·경제 구조의 변혁.\n");
	printf("  (9)□□□□조약:\n\t제1차 세계대전 후 전쟁에 승리한 연합국과 패전국 독일의 강화조약.\n");
	printf("  (10)금전 및 재물을 봉헌한 사람들에게 죄를 면해준다는 뜻의 증서.\n");
	printf("\n");
}
void solution_CommonSense()
{
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       ♠  일반상식  ♠                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("  (1)대한민국에서 가장 남쪽에 있는 섬은?\n");		
	printf("  (2)우리나라에서 가장 빠른 기차인 고속철의 공식 명칭은?\n");
	printf("  (3)흔히 성가시고 귀찮을 때 ""골치가 아프다""라고 한다.\n\t여기서 ""골치""란 몸의 어느 부위를 가리키는 말인가?\n");
	printf("  (4)굼벵이는 어느 곤충의 애벌레인가? \n");
	printf("  (5)[사자성어]죽어서 백골이 되어도 그 깊은 은혜를 잊을 수가 없다는 말.\n");
	printf("  (6)[사자성어]부부가 화락하게 인생을 함께 늙음.\n");
	printf("  (7)[사자성어]백 번 꺾여도 굴하지 않는다는 뜻. 많은 고난을 극복함.\n");
	printf("  (8)석가탑과 다보탑이 있는 절. 이곳은 어디인가?\n");
	printf("  (9)한국 특산 개 품종.\n");
	printf("  (10)우리몸에서 체온이 가장 낮은 곳은 어디인가?\n");
}
//##########[슬롯 머신]##########//
int slot_machine()
{
	char reel[6][3]={"★","♠","◆","♥","♣","○"};
	int i,reel_num[3][3];
	srand((unsigned)time(NULL));
	printf("  슬롯머신 게임\n\n");
	gotoxy(1,17);
	printf("=========================\n");
	printf("\t<<Enter>> \n");
	printf("=========================\n\n");
	display_rule();
	gotoxy(3,5);
	printf("릴1 릴2 릴3");
	gotoxy(1,8);
	printf("┏━━━━━┓");
	gotoxy(1,10);
	printf("┗━━━━━┛");
	gotoxy(1,6);
	for(i=0;i<3;i++)
		reel_num[0][i]=rand()%5;
	reel_series(reel_num);
	game_control(reel,reel_num);
	return count;
}
void display_rule()
{
	gotoxy(30,1);
	printf("┏━━━━━━━━━━┓\n");
	gotoxy(30,2);
	printf("┃Case 1~9 : Hint 지급┃  ");
	gotoxy(30,3);
	printf("┃  릴1   릴2   릴3   ┃\n");
	gotoxy(30,4);
	printf("┃--------------------┃\n");
	gotoxy(30,5);
	printf("┃ 1: ★   ★   ★    ┃\n");
	gotoxy(30,6);
	printf("┃ 2: ♠   ♠   ♠    ┃\n");
	gotoxy(30,7);
	printf("┃ 3: ◆   ◆   ◆    ┃\n");
	gotoxy(30,8);
	printf("┃ 4: ★   ★   기타  ┃\n");
	gotoxy(30,9);
	printf("┃ 5: ♠   ♠   기타  ┃\n");
	gotoxy(30,10);
	printf("┃ 6: ◆   ◆   기타  ┃\n");
	gotoxy(30,11);
	printf("┃ 7: ♥   ♥   기타  ┃\n");
	gotoxy(30,12);
	printf("┃ 8: ♣   ♣   기타  ┃\n");
	gotoxy(30,13);
	printf("┃ 9: ○   ○   기타  ┃\n");
	gotoxy(30,14);
	printf("┗━━━━━━━━━━┛\n");
}
void reel_series(int r[][3])
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			r[j][i]=(r[0][i]+j)%6;
}
void display_reel(char rc[][3],int r[][3],int index)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=index;j<3;j++)
		{
			gotoxy(3+j*4,7+i*2);
			printf("%s",rc[r[i][j]]);
		}
}
int game_control(char reel[][3],int reel_num[][3])
{
	int i,j,case_num=0,thank,num[3];
	double pst;
	clock_t start,end;
	display_reel(reel,reel_num,0);
	for(i=0;i<3;i++)
	{
		start=clock();
		do
		{
			for(j=i;j<3;j++)
				reel_num[0][j]=reel_num[1][j];
			reel_series(reel_num);
			display_reel(reel,reel_num,i);
			end=clock();
			pst=(double)(end-start)/CLK_TCK;
		}while(!kbhit() || (pst<1));
		num[i]=reel_num[1][i];
	}
	getch();
	thank=return_hint(num,&case_num);
	if(thank==0)
	{
		gotoxy(1,20);
		printf("┏━━━━━━┓\n");
		printf("┃ ▣▣꽝▣▣ ┃\n");
		printf("┗━━━━━━┛\n");	
	}
	else
	{
		gotoxy(1,20);
		printf("┏━━━━━━┓\n");
		printf("┃ ▣▣꽝▣▣ ┃\n");
		printf("┗━━━━━━┛\n");
	}
	if(case_num)
	{
		gotoxy(1,20);
		printf("┏━━━━━━┓\n");
		printf("┃▣힌트지급▣┃\n");
		printf("┗━━━━━━┛\n");
		count=1;
	}
	return count;
}
int return_hint(int r[],int *case_num)
{
	int total=0;
	if(r[0]==r[1] && r[1]==r[2] && r[0]==r[2])
	{
		if(r[0]==0)
		{
			total=1;
			*case_num=1;
		}
		else if(r[0]==1)
		{
			total=1;
			*case_num=2;
		}
		else if(r[0]==2)
		{
			total=1;
			*case_num=3;
		}
	}
	else if((r[0]==0 && r[1]==0) || (r[1]==0 && r[2]==0) || (r[0]==0 && r[2]==0))
	{
		total=1;
		*case_num=4;
	}
	else if((r[0]==1 && r[1]==1) || (r[1]==1 && r[2]==1) || (r[0]==1 && r[2]==1))
	{
		total=1;
		*case_num=5;
	}
	else if((r[0]==2 && r[1]==2) || (r[1]==2 && r[2]==2) || (r[0]==2 && r[2]==2))
	{
		total=1;
		*case_num=6;
	}
	else if((r[0]==3 && r[1]==3) || (r[1]==3 && r[2]==3) || (r[0]==3 && r[2]==3))
	{
		total=1;
		*case_num=7;
	}
	else if((r[0]==4 && r[1]==4) || (r[1]==4 && r[2]==4) || (r[0]==4 && r[2]==4))
	{
		total=1;
		*case_num=8;
	}
	else if((r[0]==5 && r[1]==5) || (r[1]==5 && r[2]==5) || (r[0]==5 && r[2]==5))
	{
		total=1;
		*case_num=9;
	}
	return total;
}
//##########[문제번호 출력]##########//
void one_print(int quiz_count)
{
		printf("\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃문제 %2d번							      ┃\n",quiz_count);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
}
//##########[문제 출력]##########//
void two_print(int i)
{
		printf("\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("  %s\n",quiz[i].told);
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
}
//##########[디지털 숫자]##########//
void digit_print(int dim[],int line)
{
	int i;
	WHITE;
	for(i=line*4;i<=line*4+3;i++)
		if(dim[i]==1)
			printf("■");
		else
			printf("  ");
	printf("    ");
}
void number_check(int k,int i)
{
	if(k>=1)
	{
		number_check(k/10,i);
		switch(k%10)
		{
		case 0 :
			digit_print(zero,i);
			break;
		case 1 :
			digit_print(one,i);
			break;
		case 2 :
			digit_print(two,i);
			break;
		case 3 :
			digit_print(three,i);
			break;
		case 4 :
			digit_print(four,i);
			break;
		case 5 :
			digit_print(five,i);
			break;
		case 6 :
			digit_print(six,i);
			break;
		case 7 :
			digit_print(seven,i);
			break;
		case 8 :
			digit_print(eight,i);
			break;
		case 9 :
			digit_print(nine,i);
			break;
		}
	}
}
