#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>		//SetConsoleCursorPosition(), GetStdHandle()

int _CommonSense=0;			//橾奩鼻衝 �僱碻□�
int _Korea=0;				//措餌 �僱碻□�
int _World=0;				//撮啗餌 �僱碻□�
//##########[僥薯 婦溼 掘褻羹, л熱, 瞪羲滲熱]##########//
typedef struct quiz_q
{
	char answer[20];//薑港
	char told[100]; //僥薯
	char hint[100]; //�爩�
}quiz_q;

quiz_q quiz[10];						//掘褻羹 寡翮 (10僥薯)
void init01();							//措餌僥薯 л熱 摹樹
void init02();							//撮啗餌僥薯 л熱 摹樹
void init03();							//橾奩鼻衝僥薯 л熱 摹樹
void one_print(int quiz_count);			//僥薯廓��轎溘
void two_print(int i);					//僥薯 轎溘
void solution_CommonSense();			//僥薯薑港
void solution_Korea();					//僥薯薑港
void solution_World();					//僥薯薑港
int ok[10];								//僥薯醞犒匐餌
int i=0,j = 0;							//for僥擊 嬪и 滲熱
int count=0;
int inpPoint=0;							//餌辨濠 殮溘嫡擊 薄熱
int selection = 0;						//詭景摹鷗 selection滲熱
int quiz_count = 1;
char answel[10];
//##########[蛤雖瓚 璋濠 ル⑷ 瞪羲滲熱 塽 л熱]##########//
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
//##########[蝸煜 啪歜 瞪羲滲熱 塽 л熱]##########//
void display_rule();									//辦難 萵 渡繩 啪衛っ
void reel_series(int r[][3]);							//萵僥濠 摩朝 л熱
void display_reel(char rc[][3],int r[][3],int index);	//萵啪歜 僥濠 摩朝 л熱
int game_control(char reel[][3],int reel_num[][3]);		//萵啪歜 �爩� 雖晝 嶸/鼠 啗骯 л熱
int return_hint(int r[],int *case_n);					//萵啪歜 �爩� 雖晝 嶸/鼠 啗骯 л熱
int slot_machine();										//蝸煜該褐 Display
//##########[夔樂 璽 儀鼻 Define 撲薑]##########//
#define col GetStdHandle(STD_OUTPUT_HANDLE)				//夔樂璽曖 с菟薑爾 嫡晦 
#define WHITE SetConsoleTextAttribute( col,0x000f);		//�羃�
#define SKY SetConsoleTextAttribute( col, 0x000b);		//ж棺儀
#define YEL SetConsoleTextAttribute( col, 0x000e);		//喻塢儀
#define HIG SetConsoleTextAttribute( col, 0x000d);		//⑽惜
//##########[寞щ酈 ASCII高 Define 撲薑]##########//
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN  80
//##########[だ橾殮轎溘 婦溼 掘褻羹]##########//
typedef struct 
{
	char id[12];
	char pass[14];
	char name[12];
	int ranking;
	int score;
	int getScore_CommonSense;							//橾奩鼻衝 �僱碻□�
	int getScore_Korea;									//措餌 �僱碻□�
	int getScore_World;									//撮啗餌 �僱碻□�
} person;
//##########[寞щ酈 ASCII高 Define 撲薑]##########//
void front_menu();
//##########[蟾晦�� л熱]##########//
void Init_people();										//だ橾殮轎溘擊 嬪и 蟾晦�倆埮�
void ranking();											//楨韁掘⑷л熱
void gotoxy(int x, int y);
//##########[�蛾蠵� 渠и л熱]##########//
void search_people(void);								//�蛾灠侄�
void new_people(void);									//�蛾灠㊣�
void Login();											//煎斜檣
void delete_data(void);									//�蛾艭餑�
//##########[だ橾 薄熱 盪濰 л熱]##########//
void save_score(); 
//##########[婦葬濠 婦溼 л熱]##########//
void master_login(void);								//婦葬濠賅萄 - 煎斜檣
void master_menu(void);									//婦葬濠賅萄 - 詭景爾晦
void master_all_print(void);							//婦葬濠賅萄 - 賅萇餌辨濠爾晦
void main_print(void);									//詭檣�飛� Щ萼お
//##########[詭景摹鷗 檜翕 婦溼 л熱]##########//
void move_01(); 
void move_02();
void main_p();
void main_p2();
//##########[晦顫 瞪羲 滲熱]##########//
char *file = "person.txt";								//だ橾殮轎溘й *だ橾貲*
person* d;												//だ橾殮轎溘衛 翕瞳й渡
int total_block;										//餌辨濠陛 賃貲檣雖 啗骯�� 盪濰
person* login_person;									//煎斜檣 餌辨濠 雖薑
void front_menu()			
{
	int select;
	while(1)
	{
		Init_people();					//餌塋菟曖 薑爾蒂 詭賅濰縑憮 碳楝螞棻
		system("cls");
		main_print();
		gotoxy(49,23);					//詭檣詭景 醴憮謝ル熱薑
		scanf("%d",&select);
		fflush(stdin);
		switch(select)
		{
		case 1:							// *�蛾灠㊣� 
			system("cls");
			new_people();  
			break;
		case 2:							// *煎斜檣
			system("cls");
			Login();
			break;
		case 3:							// *匐儀 
			system("cls");
			search_people();
			break;
		case 4:							// *楨韁		
			system("cls");  
			ranking();
			break;
		case 5:							// *婦葬濠 賅萄
			system("cls");  
			master_login();				//婦葬濠ID : 歜蝓и  婦葬濠PASS : 6411 
			system("cls");
			break;
		case 6:							// *謙猿
			printf("\n\n\n");
			exit(1);		
		default :						 // *1 ~ 6廓曖 廓�ㄟ� 嬴棋 棻艇廓�ㄟ� 揚溜棻賊
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
	printf("                Ⅳ   Welcome To My Quiz Program   Ⅳ            \n");
	printf("    =============================================================== \n");
	WHITE;
	printf("\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t早  1. �蛾灠㊣�                             早\n");
	printf("\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t早  2. 煎斜檣                               早\n");
	printf("\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t早  3. 薑爾 匐儀                            早\n");
	printf("\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t早  4. 楨韁                                 早\n");
	printf("\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t早  5. 婦葬濠 賅萄                          早\n");
	printf("\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t早  6. 謙猿                                 早\n");
	printf("\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\t                            旨收收收收收收收旬       \n");
	printf("\t                            早Number : [ ]  早       \n");
	printf("\t                            曲收收收收收收收旭       \n"); 	
}
//##########[�蛾� л熱]##########//
void Init_people()
{
	FILE *fpr;
	fpr = fopen(file,"rb");
	if(fpr == NULL){
		printf("File Open縑 螃盟嫦儅!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr) / sizeof(person); // �蛾衋� 熱
	fseek(fpr,0L,SEEK_SET);
	d = (person *)malloc(sizeof(person) * total_block);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
}
//##########[�蛾� 瓊晦 л熱]##########//
void search_people()
{
	int i, check = 0;
	char name[12];						//檜葷殮溘寡翮
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               Ⅳ      ID search      Ⅳ                   \n");
	printf("\t===========================================================\n\n");
	WHITE;
	printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t   早         Name : ____________           (12濠 檜頂)早\n");
	printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	gotoxy(30,7);
	gets(name);							// *檜葷 殮溘
	puts("");
	// ******* 檜葷 匐儀 ******* //
	for(i=0;i<total_block;i++)
		if(strcmp(name,d[i].name) == 0)
		{
			puts("");
			check = 1;					 // *餌辨濠 檜葷檜 txtだ橾縑 氈棻賊
			
			printf("\t\t旨收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("\t\t早楨韁 : %-3d蛔                                早\n",d[i].ranking);
			printf("\t\t曲收收收收收收收收收收收收收收收收收收收收收收旭\n");
			printf("\t\t旨收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("\t\t早檜葷 : %-7s                              早\n",d[i].name); 
			printf("\t\t曲收收收收收收收收收收收收收收收收收收收收收收旭\n");
			printf("\t\t旨收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("\t\t早�僱碻□�  :  %-3d薄                          早\n",d[i].score);
			printf("\t\t曲收收收收收收收收收收收收收收收收收收收收收收旭\n");
			printf("\t\t旨收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("\t\t早措餌:%-3d薄 早撮啗餌:%-3d薄早橾奩鼻衝:%-3d薄   早\n",d[i].getScore_Korea,d[i].getScore_World,d[i].getScore_CommonSense);
			printf("\t\t曲收收收收收收收收收收收收收收收收收收收收收收旭\n");
			HIG;
			printf("\t\t\t   Press Enter Key !!\n");
			getch();
			break;
		}
		if(check == 0)					//餌辨濠 檜葷檜 txtだ橾縑 橈棻賊
		{
			HIG;
			printf("\t\n\t\t\t   Non-existent users !! \n");
            getch();
		}
}		
//##########[�蛾� 陛殮 л熱]##########//
void new_people(void)	
{
	int i,j, check = 0;
	char c;					// 綠塵廓�ㄧ� *煎 鎰晦嬪ж罹 и旋濠噶 僥濠蒂 殮溘嫡晦嬪и 滲熱
	FILE *fpa;
	person aa;
	FILE *fpr;
	fpa = fopen(file,"ab"); // *txt 裔菴縑 賦邀
	if(fpa == NULL)
	{
		printf("File Open縑 螃盟 嫦儅!");
		exit(1);
	}
	do{
		check = 0;							 // *嬴檜蛤 醞犒匐餌( :1檜賊 醞犒 :0檜賊 餌辨陛棟 ) 
		system("cls");
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               Ⅳ      Admission      Ⅳ                   \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t   早          I D : ____________           (12濠 檜頂)早\n");
		printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		gotoxy(30,7);
		gets(aa.id);						// *嬴檜蛤 殮溘
		fpr = fopen(file,"rb"); 
		if(fpr == NULL)
		{
			printf("File Open縑 螃盟嫦儅!");
			exit(1);
		}
		puts("");
		for(i=0;i<total_block;i++){
			if(strcmp(aa.id,d[i].id) == 0)  // *殮溘и id陛 txt縑 盪濰脹 id諦 僅偽棻賊
			{ 
				HIG;
				printf("\t\t\t Duplicate ID exists !!\n");
				check = 1;					// *醞犒腑棻堅 1煎 羹觼
				getch();					// *嬴鼠酈釭 殮溘嫡擠
				break;
			}
		}
	}while(check == 1);						// *醞犒腎賊 鼠и瑞Щ
	printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t   早     Password : ____________           (14濠 檜頂)早\n");
	printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	// **** 綠塵廓�� *煎 鎰橫輿晦 **** //
	i = 0;
	while(i<=13)
	{
		gotoxy(30,10);						// *綠塵廓�� 殮溘 謝ル
		for(j=0;j<13;j++){					// *13濠葬 _煎 轎溘п邀
			putchar('_');
		}
		gotoxy(30,10);
		for(j=0;j<i;j++){					//i朝 殮溘и 偎熱檜晦 陽僥縑 
			putchar('*');					//殮溘и 偎熱虜躑 *煎 鎰橫邀
		}
		c = getch();						// *僥濠 и偃 殮溘嫡擠(援葷婁翕衛縑 滲熱c縑 盪濰)
		if(c == '\r'){						// *Enter 殮溘衛 
			aa.pass[i] = '\0';				// *葆雖虞 僥濠朝 NULL盪濰
			break;
		}else if(c == '\b'){				// *Back Space 殮溘衛
			if(i > 0){						// *i高檜 0爾棻 醴撿雖虜 籀擠濠葬縑憮 菴煎 塵溥釭雖 彊擠
				i--;							// *Back Space 晦棟 褒ч擊 嬪п i蒂 и蘊 菴煎 塵橫邀
			}
		}else{								// *Enter or BackSpace陛 嬴棲賊 
			aa.pass[i++] = c;				// *ぬ蝶錶萄 殮溘
		}
	}
	puts("");
	puts("");
	printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t   早         Name : ____________            (6濠 檜頂)早\n");
	printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	gotoxy(30,13);
	gets(aa.name);							// *檜葷 殮溘 
	aa.score = 00;
	aa.ranking=01;
	aa.getScore_CommonSense=0;				//橾奩鼻衝 薄熱 蟾晦��
	aa.getScore_Korea=0;					//措餌 薄熱 蟾晦��
	aa.getScore_World=0;					//撮啗餌 薄熱 蟾晦��
	HIG;
    puts("");
	puts("");
    printf("\t\t\t   旨收收收收收收收收收旬\n");
	printf("\t\t\t   早  save completed! 早\n"); 
	printf("\t\t\t   曲收收收收收收收收收旭\n"); 
	getch();
	fseek(fpa,0L,SEEK_END);
	fwrite(&aa,sizeof(person),1,fpa); 
	fclose(fpa);
}
//##########[�蛾� 煎斜檣 л熱]##########//
void Login()
{
	long i,j,k;
	int check= 0;						// *嬴檜蛤諦 綠塵廓�ㄟ� 蜃懊朝雖 羹觼
	int count = 0;						// *嬴檜蛤諦 綠塵廓�ㄟ� 3廓檜鼻 ぎ溜朝雖 羹觼
	char id[12];
	char pass[14];
	char c;								// *綠塵廓�ㄧ� *煎 鎰橫輿晦嬪и 滲熱 char滲熱
	while(check == 0){					// *嬴檜蛤諦 綠廓檜 蜃雖彊戲賊 鼠и瑞Щ
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               Ⅳ     L o g - i n       Ⅳ                 \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t   早          I D : ____________           (12濠 檜頂)早\n");
		printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		gotoxy(30,7);					// *嬴檜蛤 殮溘 謝ル
		gets(id);						// *嬴檜蛤 殮溘嫡擠
		puts("");
		for(i=0;i<total_block;i++){
			if(strcmp(id,d[i].id) == 0) // *id陛 txt縑 盪濰脹 id諦 橾纂и棻賊
				break;				    // *break蒂 勘橫 i蒂 斜渠煎 盪濰п菸
		}
		WHITE;
		printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t   早     Password : ____________           (14濠 檜頂)早\n");
		printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		k = 0;
		while(k<=13)					// *綠塵廓�ㄣ� 譆渠 14濠葬梱雖 
		{
			gotoxy(30,10);				// *綠塵廓�� 殮溘 謝ル
			for(j=0;j<13;j++){			// *13濠葬 _煎 轎溘п邀
				putchar('_');
			}
			gotoxy(30,10);
			for(j=0;j<k;j++){			// *k朝 殮溘и 偎熱檜晦 陽僥縑 
				putchar('*');			// *殮溘и 偎熱虜躑 *煎 鎰橫邀
			}
			c = getch();				// *僥濠 и偃 殮溘嫡擠(援葷婁翕衛縑 滲熱c縑 盪濰)
			if(c == '\r'){				// *Enter 殮溘衛 
				pass[k] = '\0';			// *葆雖虞 僥濠朝 NULL盪濰
				break;
			}else if(c == '\b'){		// *Back Space 殮溘衛
				if(k > 0){				// *k高檜 0爾棻 醴撿雖虜 籀擠濠葬縑憮 菴煎 塵溥釭雖 彊擠
					k--;					// *Back Space 晦棟 褒ч擊 嬪п k蒂 и蘊 菴煎 塵橫邀
				}
			}else{						// *Enter or BackSpace陛 嬴棲賊 
				pass[k++] = c;			// *ぬ蝶錶萄 殮溘
			}
		}
		puts("");
		puts("");
		if(strcmp(pass,d[i].pass) == 0){ // *綠塵廓�ㄟ� 橾纂и棻賊
			check = 1;					 // *橾纂л :1擊 check縑 盪濰
			HIG;
			printf("\n\t\t\tConnection and Press Enter Key \n"); 
			login_person = &d[i];		 //Change
			getch();
			system("cls");
			move_01(); 
			break;
		}else{							 // *綠塵廓�ㄟ� 橾纂ж雖 彊戲賊 棻衛 瑞Щ
			HIG;
			printf("\n\t\t   ID does not exist or Password error !! \n");
			count++;
			getch();
		}
		if(count == 3) {				 // *綠塵廓�� 3廓梱雖 殮溘陛棟* //
			HIG;
			printf("\n\t\t\tPassword three times the error !! \n");
			getch();
			break;
		}
		system("cls");
	}
}
//##########[薄熱 盪濰 л熱]##########//
void save_score()
{
	//## 詭賅濰縑 だ橾擊 盪濰ж晦 嬪и 滲熱菟 ##
	int i; 
	FILE *fpr;
	person aa;	//
	// ** 偽擎 檜葷擊 瓊嬴 薄熱蒂 殮溘л ** //
	for(i=0;i<total_block;i++)
	{
		if(strcmp(login_person->id , d[i].id) == 0) // *檜葷檜 橾纂ж賊
		{
			d[i].getScore_Korea+=_Korea;			//措餌 �僱� 薄熱 渠殮
			d[i].getScore_World=_World;				//撮啗餌 �僱� 薄熱 渠殮
			d[i].getScore_CommonSense=_CommonSense; //橾奩鼻衝 �僱� 薄熱 渠殮
			d[i].score += inpPoint;
			break;
		}
	}
	//戮離掘ж晦//
	for(i=0 ; i<total_block; i++)
		{
			for(j=0 ; j<total_block; j++)
			{
				if (d[i].score < d[j].score)
					d[i].ranking++;
			}
		}
	fflush(stdin);
	// 熱薑�� 詭賅濰縑 棻衛 盪濰 // 
	fpr = fopen(file,"wb");
	fseek(fpr,0L,SEEK_SET);
	fwrite(d,sizeof(person), total_block, fpr);
	fclose(fpr);	
}
//##########[婦葬濠 л熱]##########//
//##########[婦葬濠-餉薯]##########//
void delete_data(void)
{
	long i , total_block;
	int check = 0;
	char name[12];
	FILE *fpr;
	fpr = fopen(file,"rb");									 // *だ橾 檗擠
	if(fpr == NULL){
		printf("File Open縑 螃盟嫦儅!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr)/sizeof(person);				// *txt縑 盪濰脹 �蛾虃�
	fseek(fpr,0L,SEEK_SET);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
	// ** 餌辨濠 薑爾 轎溘 ** //	
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               Ⅳ    All user information    Ⅳ            \n");
	printf("\t===========================================================\n\n");
	puts("");
	WHITE;
	printf("\t 旨收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t 早%-2s 早%-8s     早%-13s早\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue;  // *婦葬濠 貍堅 轎溘
		printf("\t 早%-2d      早%-8s     早%-13d早\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t 曲收收收收收收收收收收收收收收收收收收收旭\n");
	// ** 餉薯й 檜葷殮溘ж堅 雖遺 ** //
	HIG;
	printf("\n\t    Enter the name of the user to delete and Press Enter\n");
	printf("\t\t[            ]\b\b\b\b\b\b\b\b\b\b\b\b\b");
	gets(name);												// *檜葷殮溘
	for(i=0;i<total_block;i++){
		if(strcmp(name,d[i].name) == 0)						// *檜葷檜 橾纂ж賊
		{
			check = 1;										// *橾纂л :1擊 check縑 盪濰
			d[i] = d[total_block - 1];						// *葆雖虞 等檜攪蒂 雖遴等檜攪縑 厥橫邀
			total_block--;									// *�蛾虃� и貲 還歜
		}													//(txt縑 盪濰й陽 葆雖虞 等檜攪朝 雖錶颶) 
	}
	if(check == 0) 
		HIG;
	printf("No matching data\n"); 
	// ** 等檜攪 餉薯 諫猿 ** //
	// 餉薯 �� 詭賅濰縑 棻衛 盪濰 // 
	fpr = fopen(file,"wb");
	fseek(fpr,0L,SEEK_SET);
	fwrite(d,sizeof(person), total_block, fpr);				// *葆雖虞 �蛾衋� 薯諼и 匙 txt縑 盪濰
	fclose(fpr);
	// ** 餉薯�� 等檜攪 轎溘 ** // 
	system("cls");
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t         Ⅳ   After deleting the list of users    Ⅳ       \n");
	printf("\t===========================================================\n\n");
	WHITE;
	printf("\t 旨收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t 早%-2s 早%-8s     早%-13s早\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue;  // *婦葬濠 貍堅 轎溘
		printf("\t 早%-2d      早%-8s     早%-13d早\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t 曲收收收收收收收收收收收收收收收收收收收旭\n");
	HIG;
	printf("\n\t\t\tPress any key to return to the menu\n");
	getch();
}	
//##########[婦葬濠 煎斜檣 л熱]##########//
// * 婦葬濠 ID : 歜蝓и 婦葬濠 Pass : 6411 * //
void master_login(void)
{
	long i,j,k;
	int check= 0;						// *嬴檜蛤諦 綠廓檜 橾纂ж朝雖 羹觼 
	int count  = 0;						// *3廓檜鼻 ぎ溜朝雖 羹觼
	char id[12];
	char pass[14];
	char c;
	while(check == 0)
	{									// *嬴檜蛤諦 綠塵廓�ㄟ� 橾纂ж雖 彊戲賊 鼠и瑞Щ
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               Ⅳ    Administrator Mode     Ⅳ             \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t   早 Administrator ID : ____________       (12濠 檜頂)早\n");
		printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		gotoxy(34,7);					// *嬴檜蛤 殮溘 謝ル
		gets(id);						// *嬴檜蛤 殮溘
		puts("");
		for(i=0;i<total_block;i++)
		{
			if(strcmp(id,"歜蝓и") == 0)// *婦葬濠嬴檜蛤 (歜蝓и)婁 橾纂ж賊
				break;                  // * for僥 誇蹺堅 i高 盪濰
		}
		WHITE;
		printf("\t   旨收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t   早Administrator Password : ____________  (14濠 檜頂)早\n");
		printf("\t   曲收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		// **** 綠塵廓�� *煎 鎰橫輿晦 **** //
		k = 0;
		while(k<=13)					// *綠塵廓�ㄣ� 譆渠 14濠葬梱雖 
		{
			gotoxy(39,10);				// *綠塵廓�� 殮溘 謝ル
			for(j=0;j<13;j++)
			{
				putchar('_');			// *13濠葬 _煎 轎溘п邀
			}
			gotoxy(39,10);
			for(j=0;j<k;j++)			// *k朝 殮溘и 偎熱檜晦 陽僥縑 
			{
				putchar('*');			// *殮溘и 偎熱虜躑 *煎 鎰橫邀
			}
			c = getch();				// *僥濠 и偃 殮溘嫡擠(援葷婁翕衛縑 滲熱c縑 盪濰)
			if(c == '\r')
			{							// *Enter 殮溘衛 
				pass[k] = '\0';			// *葆雖虞 僥濠朝 NULL盪濰
				break;
			}
			else if(c == '\b')
			{							// *Back Space 殮溘衛
				if(k > 0)
				{						// *k高檜 0爾棻 醴撿雖虜 籀擠濠葬縑憮 菴煎 塵溥釭雖 彊擠
					k--;					// *Back Space 晦棟 褒ч擊 嬪п k蒂 и蘊 菴煎 塵橫邀
				}
			}
			else
			{							// *Enter or BackSpace陛 嬴棲賊 
				pass[k++] = c;			// *ぬ蝶錶萄 殮溘
			}
		}
		puts("");
		puts("");
		if(!strcmp(pass,"6411")){		// *婦葬濠綠廓(6411)婁 橾纂ж賊
			check = 1;					// *while僥 釭馬
			HIG;
            printf("\n\t\t 歜蝓и 椒 Connection .. Press Enter Key \n"); 
			getch();
			system("cls");
			master_menu();				// *婦葬濠 詭景 嗥遺
			break;
		}else{
			HIG;
			printf("\n\t\t   ID does not exist or Password error !! \n");	
			getch();
		}
		if(count == 3) {				// *綠塵廓�� 螃盟 3廓梱雖 陛棟 *//
			HIG;
			printf("\n\t\t\tPassword three times the error !! \n");
			getch();
			break;
		}
		system("cls");
	}
}
//##########[婦葬濠 賅萄 詭景]##########//
void master_menu()
{
	int select = 0;
	while(select != 3)
	{
		system("cls");
		YEL;
		printf("\n");
		printf("\t===========================================================\n");
		printf("\t               Ⅳ     Administrator Mode     Ⅳ            \n");
		printf("\t===========================================================\n\n");
		WHITE;
		printf("\t\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t\t早  1. View all users                       早\n");
		printf("\t\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("\t\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t\t早  2. Delete User Information              早\n");
		printf("\t\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("\t\t旨收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("\t\t早  3. Exit Admin Mode                      早\n");
		printf("\t\t曲收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("\t\t                                              \n"); 
		printf("\t\t                            旨收收收收收收收旬\n");
		printf("\t\t                            早Number : [ ]  早\n");
		printf("\t\t                            曲收收收收收收收旭\n"); 
		gotoxy(57,17);
		scanf("%d",&select); // *餌辨濠煎睡攪 廓��殮溘嫡擠
		fflush(stdin);
		
		switch(select)
		{
		case 1:				// *賅萇�蛾讔內蛹萵�
			system("cls");
			master_all_print();
			break;
		case 2:				// *�蛾礸母旼� 餉薯 
			system("cls");
			delete_data(); 
			break; 
		case 3:				// *謙猿
			system("cls");
			HIG;
			printf("\n\n\n\t\t\tExit Admin Mode... \n");
			Sleep(1500);	//1.5蟾��
		default :			// *1 ~ 3曖 廓�ㄟ� 嬴棲塭賊 �飛� clear
			system("cls");
		}
	}
}
//##########[婦葬濠 賅萄- 賅萇 餌辨濠 爾晦]##########//
void master_all_print() 
{
	long i, total_block;
	FILE *fpr;
	person d[50];								// *txt縑憮 碳楝螢 �蛾�(譆渠 50貲)寡翮
	fpr = fopen(file,"rb");						// *だ橾 檗擠
	if(fpr == NULL){
		printf("File Open縑 螃盟嫦儅!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr) / sizeof(person);	// *txt盪濰脹 �蛾� 熱
	fseek(fpr,0L,SEEK_SET);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               Ⅳ    All user information    Ⅳ            \n");
	printf("\t===========================================================\n\n");
	puts("");
	WHITE;
	printf("\t 旨收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t 早%-2s 早%-8s     早%-13s早\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue;  
		printf("\t 早%-2d      早%-8s     早%-13d早\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t 曲收收收收收收收收收收收收收收收收收收收旭\n");
	
	HIG;
	printf("\n\t\t\tPress any key to return to the menu\n");
	getch();
}
//##########[楨韁 л熱]##########//
void ranking()
{
	long i, total_block;
	FILE *fpr;
	person d[50];					// *txt縑憮 碳楝螢 �蛾�(譆渠 50貲)寡翮
	fpr = fopen(file,"rb");			// *だ橾 檗擠
	if(fpr == NULL){
		printf("File Open縑 螃盟嫦儅!");
		exit(1);
	}
	fseek(fpr,0L,SEEK_END);
	total_block = ftell(fpr) / sizeof(person); // *txt盪濰脹 �蛾� 熱
	fseek(fpr,0L,SEEK_SET);
	fread(d,sizeof(person),total_block,fpr);
	fclose(fpr);
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t               Ⅳ    Ranking information    Ⅳ            \n");
	printf("\t===========================================================\n\n");
	puts("");
	WHITE;
	printf("\t 旨收收收收收收收收收收收收收收收收收收收旬\n");
	printf("\t 早%-2s 早%-8s     早%-13s早\n","Ranking","NickName","Score");
	for(i=0;i<total_block;i++)
	{
		if(!strcmp(d[i].name , "Administrator")) continue; 
		printf("\t 早%-2d      早%-8s     早%-13d早\n",d[i].ranking,d[i].name,d[i].score);
	}
	printf("\t 曲收收收收收收收收收收收收收收收收收收收旭\n");
	HIG;
	printf("\n\t\t\tPress any key to return to the menu\n");
	getch();
}
//###############   僥薯ヴ檜煎 遺霜檜朝剪  ###############//
//###############   僥薯ヴ晦/蕨蝗/鼻嬪詭景  ###############//
void move_01() 
{
	int PosMeX=35, PosMeY=20;
	char c;
	int move = 0;		 //遺霜歜 蘋遴おл熱
	main_p();
	gotoxy(PosMeX,PosMeY);
	printf("* User *");
	while(1)			//鼠и 奩犒
	{
		if(_kbhit())	//酈陛 殮溘雖 馬衛ж堅 酈陛 殮溘腎賊 嬴楚 僥濰擊 褒ч, 欽雖 酈陛 殮溘腎朝雖 馬衛и棻.
		{
			c=getch(); //僥濠 ж釭蒂 殮溘嫡朝 л熱, 僥濠 ж釭蒂 殮溘嫡擊 陽梱雖 鼠и渠晦ж朝 л熱檜雖虜
					   //_kihit() л熱煎 酈陛 殮溘腆 陽虜 奩擬п憮 渠晦 衛除檜 橈棻
			if(c=='a') PosMeX--;
			else if(c=='d') PosMeX++;
			else if(c=='w') PosMeY--;
			else if(c=='s') PosMeY++;
			system("cls");
			main_p();
			SKY;
			gotoxy(PosMeX,PosMeY);
			if(move % 2 == 0)	printf("戌∞忖");
			else printf("忙∞戎");
			move++;
			//[鼻嬪詭景] 殮濰//
			if(( PosMeX == 55 || PosMeX == 56 || PosMeX == 57 || PosMeX == 58 || PosMeX == 59 ) && PosMeY == 15 )
			{
				WHITE;
				gotoxy(10,20);
				printf("===========================================================\n");
				printf("\t                     Ⅳ Wait a minute Ⅳ                 \n");
				gotoxy(10,22);
				printf("===========================================================\n\n\n");
				Sleep(1500); 
				system("cls");
				break;
			}
			//[僥薯ヴ晦] 殮濰// 
			if( ( PosMeX == 13 || PosMeX == 14 || PosMeX == 15 || PosMeX == 16 || PosMeX == 17 ) && PosMeY == 15 )
			{
				WHITE;
				gotoxy(10,20);
				printf("===========================================================\n");
				printf("\t                     Ⅳ Wait a minute Ⅳ                 \n");
				gotoxy(10,22);
				printf("===========================================================\n\n\n");
				Sleep(1500); 
				gotoxy(30,20);
				printf("                             ");
				system("cls");
				gotoxy(0,0);
				//措餌 撮啗餌 鼻衝 摹鷗 �飛橉虞�//
				move_02();
				break;
			}
			//[蕨蝗] 殮濰
			if( ( PosMeX == 35 || PosMeX == 36 || PosMeX == 37 || PosMeX == 38 || PosMeX == 39 ) && PosMeY == 15 )
			{
				int PosMeX=35, PosMeY=20;
				char c;
				int move = 0; 
				WHITE;
				gotoxy(10,20);
				printf("===========================================================\n");
				printf("\t                     Ⅳ Wait a minute Ⅳ                 \n");
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
						if(move % 2 == 0)	printf("戌∞忖");
						else printf("忙∞戎");
						move++;		
						//橾奩鼻衝
						if(( PosMeX == 55 || PosMeX == 56 || PosMeX == 57 || PosMeX == 58 || PosMeX == 59 ) && PosMeY == 15 )
						{
							system("cls");
							solution_CommonSense();
							_getch();
							break;
						}
						//措餌
						if( ( PosMeX == 13 || PosMeX == 14 || PosMeX == 15 || PosMeX == 16 || PosMeX == 17 ) && PosMeY == 15 )
						{
							system("cls");
							solution_Korea();
							_getch();
							break;
						}
						//撮啗餌
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
//###############   措餌/撮啗餌/橾奩鼻衝  ###############//
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
			if(move % 2 == 0)	printf("戌∞忖");
			else printf("忙∞戎");
			move++;
			//橾奩鼻衝
			if(( PosMeX == 55 || PosMeX == 56 || PosMeX == 57 || PosMeX == 58 || PosMeX == 59 ) && PosMeY == 15 )
			{
				init03();
				while(1)
				{
					srand(time(NULL));		
					while(1)					//僥薯 醞犒匐餌
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
						printf("�爩� : %s \n",quiz[i].hint);
					}
					printf("薑港  >> ");
					scanf("%s",answel);
					if(!strcmp(quiz[i].answer,answel))
					{
						inpPoint+=10;			//薑港橾 衛 薄熱 и 僥薯渡 10薄噶 援瞳
						printf("薑港殮棲棻. 棻擠僥薯 檜翕 [Enter] \n");
					}
					else
					{
						printf("ぎ溜蝗棲棻. 棻擠僥薯 檜翕 [Enter] \n");
					}
					quiz_count++;
					getch();		
					system("cls");
					if(quiz_count==11)
					{
						YEL;
						printf("\n");
						printf("=========================\n");
						printf("Ⅳ      �僱� 薄熱      Ⅳ\n");
						printf("=========================\n\n");
						_CommonSense=inpPoint;//橾奩鼻衝 �僱碻□� 滲熱 橾奩鼻衝�僱碻□鶹� 渠殮
											  //婁跡滌 薄熱 掘碟ж晦 嬪л.
						save_score();		  //薄熱 詭賅濰縑 殮溘 �� 盪濰
						//蛤雖瓚剩幗煎 璋濠ル⑷//
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
			//措餌
			if( ( PosMeX == 13 || PosMeX == 14 || PosMeX == 15 || PosMeX == 16 || PosMeX == 17 ) && PosMeY == 15 )
			{
				init01();
				while(1)
				{
					srand(time(NULL));		
					while(1)					//僥薯 醞犒匐餌
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
						printf("�爩� : %s \n",quiz[i].hint);
					}
					printf("薑港  >> ");
					scanf("%s",answel);
					if(!strcmp(quiz[i].answer,answel))
					{
						inpPoint+=10;	
						printf("薑港殮棲棻. 棻擠僥薯 檜翕 [Enter] \n");
					}
					else
					{
						printf("ぎ溜蝗棲棻. 棻擠僥薯 檜翕 [Enter] \n");
					}
					quiz_count++;
					getch();		
					system("cls");
					if(quiz_count==11)
					{
						YEL;
						printf("\n");
						printf("=========================\n");
						printf("Ⅳ      �僱� 薄熱      Ⅳ\n");
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
			//撮啗餌
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
						printf("�爩� : %s \n",quiz[i].hint);	
					}
					printf("薑港  >> ");
					scanf("%s",answel);
					if(!strcmp(quiz[i].answer,answel))
					{
						inpPoint+=10;	
						printf("薑港殮棲棻. 棻擠僥薯 檜翕 [Enter] \n");
					}
					else
					{
						printf("ぎ溜蝗棲棻. 棻擠僥薯 檜翕 [Enter] \n");
					}
					quiz_count++;
					getch();		
					system("cls");
					if(quiz_count==11)
					{
						YEL;
						printf("\n");
						printf("=========================\n");
						printf("Ⅳ      �僱� 薄熱      Ⅳ\n");
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
	printf("\t                       Ⅳ   MENU   Ⅳ                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("\t﹥﹥﹥﹥﹥﹥﹥﹥﹥   ﹥﹥﹥﹥﹥﹥﹥﹥﹥   ﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥  <僥薯ヴ晦>  ﹥   ﹥    <蕨蝗>    ﹥   ﹥  <鼻嬪詭景>  ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥﹥﹥早  早﹥﹥﹥   ﹥﹥﹥早  早﹥﹥﹥   ﹥﹥﹥早  早﹥﹥﹥\n");
	//gotoxy(15,15); //僥薯ヴ晦 殮掘 謝ル高 
	//gotoxy(36,15); //蕨蝗 殮掘 謝ル高
	//gotoxy(58,15); //鼻嬪詭景 殮掘 謝ル高 
}
void main_p2()
{
	gotoxy(0,0);
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       Ⅳ   MENU   Ⅳ                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("\t﹥﹥﹥﹥﹥﹥﹥﹥﹥   ﹥﹥﹥﹥﹥﹥﹥﹥﹥   ﹥﹥﹥﹥﹥﹥﹥﹥﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥  <措    餌>  ﹥   ﹥   <撮啗餌>   ﹥   ﹥  <橾奩鼻衝>  ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥              ﹥   ﹥              ﹥   ﹥              ﹥\n");
	printf("\t﹥﹥﹥早  早﹥﹥﹥   ﹥﹥﹥早  早﹥﹥﹥   ﹥﹥﹥早  早﹥﹥﹥\n");
	//gotoxy(15,15); //措餌 殮掘 謝ル高 
	//gotoxy(58,15); //撮啗餌 殮掘 謝ル高 
	//gotoxy(36,15); //凱撫蝶 殮掘 謝ル高
}
//##########[措餌 僥薯]##########//
void init01()
{
	strcpy(quiz[0].answer,"檜牖褐"); 
	strcpy(quiz[0].told,"100錳縑 億啖霞 嬪檣曖 檜葷擎 鼠歙殮棲梱?");		
	strcpy(quiz[0].hint,"剪磁摹");
	strcpy(quiz[1].answer,"黴啗檜��");
	strcpy(quiz[1].told,"1000錳掏縑 億啖霞 嬪檣曖 檜葷擎 鼠歙殮棲梱?");
	strcpy(quiz[1].hint,"褻摹撩葬з曖 晦蟾蒂 撮遴 摹綠, 釭嬴馬婁 僭楝陴曖 曖嘐");
	strcpy(quiz[2].answer,"徽堊檜檜");
	strcpy(quiz[2].told,"5000錳掏縑 億啖霞 嬪檣曖 檜葷擎 鼠歙殮棲梱?");
	strcpy(quiz[2].hint,"褕餌歜渡曖 嬴菟");
	strcpy(quiz[3].answer,"撮謙渠諾");	
	strcpy(quiz[3].told,"10000錳掏縑 億啖霞 嬪檣曖 檜葷擎 鼠歙殮棲梱?");
	strcpy(quiz[3].hint,"�さ恔分�");
	strcpy(quiz[4].answer,"褐餌歜渡");	
	strcpy(quiz[4].told,"50000錳掏縑 億啖霞 嬪檣曖 檜葷擎 鼠歙殮棲梱?");
	strcpy(quiz[4].hint,"⑷賅曄籀");
	strcpy(quiz[5].answer,"歜霞謁塢");	
	strcpy(quiz[5].told,"[辨橫]1592~1598喇, 舒 離滔縑 勘藥 辦葬釭塭蒂 藹殮и 橾獄婁曖 諄遺 :");
	strcpy(quiz[5].hint,"и骯渠繪");	
	strcpy(quiz[6].answer,"擊嘐餌滲");	
	strcpy(quiz[6].told,"[辨橫]貲撩�笮譫� 衛пж堅 橾獄撮溘 鬼�飛� �嘔犯� 薑滲 :");
	strcpy(quiz[6].hint,"橾獄 濠偌曖 唳犒掙 藹殮 餌勒");
	strcpy(quiz[7].answer,"惜犒");
	strcpy(quiz[7].told,"8錯15橾擎 '﹤﹤瞰'檜棻. 綴蘊擎 鼠歙殮棲梱?");
	strcpy(quiz[7].hint,"嶸婦牖, 寥彰 梯掘, 紫骯 寰璽��");
	strcpy(quiz[8].answer,"濰爾堅");
	strcpy(quiz[8].told,"п瞳菟曖 檣褐衙衙蒂 斬瞰, 諫瞪 模鰻и 褐塭曖 鼠濰 :");
	strcpy(quiz[8].hint,"夥棻曖 諾");
	strcpy(quiz[9].answer,"啗寥");	
	strcpy(quiz[9].told,"釭渡翱м捱(5虜)擊 5繭曖 捱餌煎 啻 離滔 蝓葬蒂 虜萇 濰捱曖 檜葷 :");
	strcpy(quiz[9].hint,"寥薯 蜓晦曖 濰捱");
}
//##########[撮啗餌 僥薯]##########//
void init02()	
{
	strcpy(quiz[0].answer,"4"); 	
	strcpy(quiz[0].told,"薯 1離 撮啗渠瞪擎 ﹤喇翕寰 雖樓腎歷棻. 綴蘊擎 鼠歙殮棲梱?");		
	strcpy(quiz[0].hint,"1918喇 11錯 11橾 絮橾曖 о犒戲煎 部陴.");
	strcpy(quiz[1].answer,"薯2離撮啗渠瞪");
	strcpy(quiz[1].told,"[辨橫]雖旎梱雖曖 檣盟 羲餌縑憮 陛濰 贖 檣貲婁 營骯 Яп蒂 竟擎 瞪爵 :");
	strcpy(quiz[1].hint,"翱м措 餌檜縑 弊橫霞 撮啗 敘賅曖 瞪爵");
	strcpy(quiz[2].answer,"お煎檜跡葆");
	strcpy(quiz[2].told,"[辨橫]﹤﹤﹤﹤﹤朝 斜葬蝶陛 お煎檜蒂 鼠傘お萵 陽 唸薑瞳檣 羲й擊 ж艘棻.");
	strcpy(quiz[2].hint,"Trojan Horse");
	strcpy(quiz[3].answer,"�鷝眺�");	
	strcpy(quiz[3].told,"﹤﹤﹤朝 薯2離撮啗渠瞪擊 橾戲儷雖虜 ぬ儀檜 瞿橫雖濠 濠髦ж艘棻. ");
	strcpy(quiz[3].hint,"絮橾曖 薑纂陛檜貊 絮營濠煎 碳萼棻.");
	strcpy(quiz[4].answer,"霞輿虜");	
	strcpy(quiz[4].told,"[辨橫]橾獄曖 ﹤﹤﹤晦蝗擊 啗晦煎 嘐措檜 2離渠瞪縑 嗨橫菟啪 腎歷棻.");
	strcpy(quiz[4].hint,"Ё睡ж啪 釭湍 霞輿蒂 虜菟橫 頂朝 掉 陽僥縑 稱擎 檜葷");
	strcpy(quiz[5].answer,"濤棻腦觼");	
	strcpy(quiz[5].told,"﹤﹤﹤﹤: 艙措曖 寥喇瞪爵 �覺熂� Щ嫌蝶蒂 嬪晦縑憮 掘и 艙錠瞳檣 模喪.");
	strcpy(quiz[5].hint,"葆喪煎 路溥 19撮 粒棻遴 釭檜縑 �倆� 渡л.");	
	strcpy(quiz[6].answer,"陪癒");	
	strcpy(quiz[6].told,"﹤﹤ 褻擒擎 醞措檜 諼措婁 裕擎 譆蟾曖 斬渠瞳檣 褻擒檜貊 碳ゎ蛔褻擒檜棻.");
	strcpy(quiz[6].hint,"嬴ら瞪爵");
	strcpy(quiz[7].answer,"骯機⑶貲");
	strcpy(quiz[7].told,"﹤﹤﹤﹤:18撮晦 醞膨 艙措縑憮 衛濛脹 晦獎⑶褐婁 餌�腹什碻� 掘褻曖 滲⑶.");
	strcpy(quiz[7].hint,"奢機��");
	strcpy(quiz[8].answer,"漆腦餌嶸");
	strcpy(quiz[8].told,"﹤﹤﹤﹤褻擒:薯1離 撮啗渠瞪 �� 瞪爵縑 蝓葬и 翱м措婁 ぬ瞪措 絮橾曖 鬼�俯馮�.");
	strcpy(quiz[8].hint,"檜 褻擒戲煎 絮橾擎 п諼衝團雖朝 賅舒 鼻褒, 嶸毀 頂 艙饜蒂 檠歷棻.");
	strcpy(quiz[9].answer,"賊賸睡");	
	strcpy(quiz[9].told,"旎瞪 塽 營僭擊 瑰ьи 餌塋菟縑啪 賸蒂 賊п遽棻朝 嗆曖 隸憮.");
	strcpy(quiz[9].hint,"15撮晦 蜓晦,渠榆 嫦ч戲煎 瑞攪曖 綠っ擊 碳楝橾戲酈堅 謙掖 偃⑶曖 褒葆葬陛 脾.");
}
//##########[橾奩鼻衝 僥薯]##########//
void init03()
{
	strcpy(quiz[0].answer,"葆塭紫"); 	
	strcpy(quiz[0].told,"渠и團措縑憮 陛濰 陴薹縑 氈朝 撰擎?");		
	strcpy(quiz[0].hint,"繭翱晦喃僭 薯423��");
	strcpy(quiz[1].answer,"KTX");
	strcpy(quiz[1].told,"辦葬釭塭縑憮 陛濰 緒艇 晦離檣 堅樓繹曖 奢衝 貲蘆擎?");
	strcpy(quiz[1].hint,"[Korea Train eXpress]");
	strcpy(quiz[2].answer,"堝");
	strcpy(quiz[2].told,"�褙� 撩陛衛堅 敝雛擊 陽 ""埤纂陛 嬴Щ棻""塭堅 и棻.\n罹晦憮 ""埤纂""塢 跺曖 橫替 睡嬪蒂 陛葬酈朝 蜓檣陛?");
	strcpy(quiz[2].hint,"賅萇 繫蹺翕僭婁 渠睡碟曖 鼠繫蹺翕僭縑 氈橫憮 褐唳啗曖 醞蹺陛 腎朝 晦婦");
	strcpy(quiz[3].answer,"衙嘐");	
	strcpy(quiz[3].told,"推漪檜朝 橫替 堆醱曖 擁弊溯檣陛? ");
	strcpy(quiz[3].hint,"か熱и 嫦擠晦蒂 陛雖堅 堪擎 模葬煎 選橫 澀 憲溥霞 堆醱檜棻.");
	strcpy(quiz[4].answer,"寥埤陪蜂");	
	strcpy(quiz[4].told,"[餌濠撩橫]避橫憮 寥埤檜 腎橫紫 斜 桶擎 擎��蒂 濱擊 熱陛 橈棻朝 蜓.");
	strcpy(quiz[4].hint,"詘俛桍媓");
	strcpy(quiz[5].answer,"寥喇п煎");	
	strcpy(quiz[5].told,"[餌濠撩橫]睡睡陛 �頁蠗炾� 檣儅擊 л眷 棕擠.");
	strcpy(quiz[5].hint,"詄珒�皮�");	
	strcpy(quiz[6].answer,"寥瞰碳掉");	
	strcpy(quiz[6].told,"[餌濠撩橫]寥 廓 痕罹紫 掉ж雖 彊朝棻朝 嗆. 號擎 堅陪擊 斛犒л.");
	strcpy(quiz[6].hint,"詄儮嫄疪");
	strcpy(quiz[7].answer,"碳措餌");
	strcpy(quiz[7].told,"戮陛鱉婁 棻爾鱉檜 氈朝 瞰. 檜夠擎 橫蛤檣陛?");
	strcpy(quiz[7].hint,"唳輿");
	strcpy(quiz[8].answer,"霞翔偃");
	strcpy(quiz[8].told,"и措 か骯 偃 ヶ謙.");
	strcpy(quiz[8].hint,"繭翱晦喃僭 53��");
	strcpy(quiz[9].answer,"敝");	
	strcpy(quiz[9].told,"辦葬跺縑憮 羹螞檜 陛濰 雪擎 夠擎 橫蛤檣陛?");
	strcpy(quiz[9].hint,"羶陝 塽 ゎ⑽馬陝擊 氬渡ж朝 晦婦");
}
//##########[僥о滌 僥薯]##########//
void solution_Korea()
{
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       Ⅳ   措 餌   Ⅳ                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("  (1)100錳縑 億啖霞 嬪檣曖 檜葷 : 檜牖褐\n");
	printf("  (2)1000錳掏縑 億啖霞 嬪檣曖 檜葷 : 黴啗檜�淚n");
	printf("  (3)5000錳掏縑 億啖霞 嬪檣曖 檜葷 : 徽堊檜檜\n");
	printf("  (4)10000錳掏縑 億啖霞 嬪檣曖 檜葷 : 撮謙渠諾\n");
	printf("  (5)10000錳掏縑 億啖霞 嬪檣曖 檜葷 : 褐餌歜渡\n");
	printf("  (6)1592~1598喇, 舒 離滔縑 勘藥 辦葬釭塭蒂 藹殮и 橾獄婁曖 諄遺 : 歜霞謁塢\n");
	printf("  (7)貲撩�笮譫� 衛пж堅 橾獄撮溘 鬼�飛� �嘔犯� 薑滲 : 擊嘐餌滲\n");
	printf("  (8)8錯15橾擎 '﹤﹤瞰' : 惜犒瞰\n");
	printf("  (9)п瞳菟曖 檣褐衙衙蒂 斬瞰, 諫瞪 模鰻и 褐塭曖 鼠濰 : 濰爾堅\n");
	printf("  (10)釭渡翱м捱(5虜)擊 5繭曖 捱餌煎 啻 離滔 蝓葬蒂 虜萇 濰捱曖 檜葷 : 啗寥\n");
	printf("\n");
}
void solution_World()
{
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       Ⅳ 撮 啗 餌  Ⅳ                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("  (1)薯 1離 撮啗渠瞪擎 ﹤喇翕寰 雖樓腎歷棻. 綴蘊擎 鼠歙殮棲梱?\n");		
	printf("  (2)[辨橫]雖旎梱雖曖 檣盟 羲餌縑憮 陛濰 贖 檣貲婁 營骯 Яп蒂 竟擎 瞪爵 :\n");
	printf("  (3)[辨橫]﹤﹤﹤﹤﹤朝 斜葬蝶陛 お煎檜蒂 鼠傘お萵 陽 唸薑瞳檣 羲й擊 ж艘棻.\n");
	printf("  (4)﹤﹤﹤朝 薯2離撮啗渠瞪擊 橾戲儷雖虜 ぬ儀檜 瞿橫雖濠 濠髦ж艘棻. \n");
	printf("  (5)[辨橫]橾獄曖 ﹤﹤﹤晦蝗擊 啗晦煎 嘐措檜 2離渠瞪縑 嗨橫菟啪 腎歷棻.\n");
	printf("  (6)﹤﹤﹤﹤: 艙措曖 寥喇瞪爵 �覺熂� Щ嫌蝶蒂 嬪晦縑憮 掘и 艙錠瞳檣 模喪.\n");
	printf("  (7)﹤﹤ 褻擒擎 醞措檜 諼措婁 裕擎 譆蟾曖 斬渠瞳檣 褻擒檜貊 碳ゎ蛔褻擒檜棻.\n");
	printf("  (8)﹤﹤﹤﹤:18撮晦 醞膨 艙措縑憮 衛濛脹 晦獎⑶褐婁 餌�腹什碻� 掘褻曖 滲⑶.\n");
	printf("  (9)﹤﹤﹤﹤褻擒:\n\t薯1離 撮啗渠瞪 �� 瞪爵縑 蝓葬и 翱м措婁 ぬ瞪措 絮橾曖 鬼�俯馮�.\n");
	printf("  (10)旎瞪 塽 營僭擊 瑰ьи 餌塋菟縑啪 賸蒂 賊п遽棻朝 嗆曖 隸憮.\n");
	printf("\n");
}
void solution_CommonSense()
{
	YEL;
	printf("\n");
	printf("\t===========================================================\n");
	printf("\t                       Ⅳ  橾奩鼻衝  Ⅳ                      \n");
	printf("\t===========================================================\n\n\n");
	WHITE;
	printf("  (1)渠и團措縑憮 陛濰 陴薹縑 氈朝 撰擎?\n");		
	printf("  (2)辦葬釭塭縑憮 陛濰 緒艇 晦離檣 堅樓繹曖 奢衝 貲蘆擎?\n");
	printf("  (3)�褙� 撩陛衛堅 敝雛擊 陽 ""埤纂陛 嬴Щ棻""塭堅 и棻.\n\t罹晦憮 ""埤纂""塢 跺曖 橫替 睡嬪蒂 陛葬酈朝 蜓檣陛?\n");
	printf("  (4)推漪檜朝 橫替 堆醱曖 擁弊溯檣陛? \n");
	printf("  (5)[餌濠撩橫]避橫憮 寥埤檜 腎橫紫 斜 桶擎 擎��蒂 濱擊 熱陛 橈棻朝 蜓.\n");
	printf("  (6)[餌濠撩橫]睡睡陛 �頁蠗炾� 檣儅擊 л眷 棕擠.\n");
	printf("  (7)[餌濠撩橫]寥 廓 痕罹紫 掉ж雖 彊朝棻朝 嗆. 號擎 堅陪擊 斛犒л.\n");
	printf("  (8)戮陛鱉婁 棻爾鱉檜 氈朝 瞰. 檜夠擎 橫蛤檣陛?\n");
	printf("  (9)и措 か骯 偃 ヶ謙.\n");
	printf("  (10)辦葬跺縑憮 羹螞檜 陛濰 雪擎 夠擎 橫蛤檣陛?\n");
}
//##########[蝸煜 該褐]##########//
int slot_machine()
{
	char reel[6][3]={"≠","Ⅳ","﹣","Ⅵ","Ⅷ","∞"};
	int i,reel_num[3][3];
	srand((unsigned)time(NULL));
	printf("  蝸煜該褐 啪歜\n\n");
	gotoxy(1,17);
	printf("=========================\n");
	printf("\t<<Enter>> \n");
	printf("=========================\n\n");
	display_rule();
	gotoxy(3,5);
	printf("萵1 萵2 萵3");
	gotoxy(1,8);
	printf("旨收收收收收旬");
	gotoxy(1,10);
	printf("曲收收收收收旭");
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
	printf("旨收收收收收收收收收收旬\n");
	gotoxy(30,2);
	printf("早Case 1~9 : Hint 雖晝早  ");
	gotoxy(30,3);
	printf("早  萵1   萵2   萵3   早\n");
	gotoxy(30,4);
	printf("早--------------------早\n");
	gotoxy(30,5);
	printf("早 1: ≠   ≠   ≠    早\n");
	gotoxy(30,6);
	printf("早 2: Ⅳ   Ⅳ   Ⅳ    早\n");
	gotoxy(30,7);
	printf("早 3: ﹣   ﹣   ﹣    早\n");
	gotoxy(30,8);
	printf("早 4: ≠   ≠   晦顫  早\n");
	gotoxy(30,9);
	printf("早 5: Ⅳ   Ⅳ   晦顫  早\n");
	gotoxy(30,10);
	printf("早 6: ﹣   ﹣   晦顫  早\n");
	gotoxy(30,11);
	printf("早 7: Ⅵ   Ⅵ   晦顫  早\n");
	gotoxy(30,12);
	printf("早 8: Ⅷ   Ⅷ   晦顫  早\n");
	gotoxy(30,13);
	printf("早 9: ∞   ∞   晦顫  早\n");
	gotoxy(30,14);
	printf("曲收收收收收收收收收收旭\n");
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
		printf("旨收收收收收收旬\n");
		printf("早 〡〡統〡〡 早\n");
		printf("曲收收收收收收旭\n");	
	}
	else
	{
		gotoxy(1,20);
		printf("旨收收收收收收旬\n");
		printf("早 〡〡統〡〡 早\n");
		printf("曲收收收收收收旭\n");
	}
	if(case_num)
	{
		gotoxy(1,20);
		printf("旨收收收收收收旬\n");
		printf("早〡�爩挨鰡煍疆苒n");
		printf("曲收收收收收收旭\n");
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
//##########[僥薯廓�� 轎溘]##########//
void one_print(int quiz_count)
{
		printf("\n");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早僥薯 %2d廓							      早\n",quiz_count);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
}
//##########[僥薯 轎溘]##########//
void two_print(int i)
{
		printf("\n");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("  %s\n",quiz[i].told);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n\n");
}
//##########[蛤雖瓚 璋濠]##########//
void digit_print(int dim[],int line)
{
	int i;
	WHITE;
	for(i=line*4;i<=line*4+3;i++)
		if(dim[i]==1)
			printf("﹥");
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
