#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct quiz_q
{
	char answer[20];//港
	char told[100];
	char hint[100]; //�爩�
}quiz_q;

quiz_q quiz[10];						//掘褻羹 寡翮 (10僥薯)
void init01();							//措餌僥薯 л熱 摹樹
void init02();							//撮啗餌僥薯 л熱 摹樹
int gawi(int i, int quiz_count);		//陛嬪夥嬪爾 
void one_print(int quiz_count);			//僥薯廓��轎溘
void two_print(int i);					//僥薯 轎溘
void solution();						//僥薯 薑港 
void emoticon();						//檜賅じ夔 轎溘擊 嬪и л熱

static int ok[10];
int i=0,j = 0;							//for僥擊 嬪и 滲熱
char temp02;							//僥薯 棻衛ヴ晦 (y/n)
int temp01=0;							//'詭景 犒敝'蒂 嬪п 0,1 高擊 氬朝 滲熱		

int main(void)
{
	char name[10];			//撩瞳ル ID殮溘
	char num_board[5][12] =   // 薄熱っ
	{
		"Excellent  ", "Good       ", "Nice       ", "Not bad    ", "HaveToStudy"
	};
	int point[5] =    // 薄熱
	 {
		100, 80, 60, 40, 20
	 };
	char inpName[5];  // 餌辨濠 殮溘嫡擊 ID
	int inpPoint=0;    //餌辨濠 殮溘嫡擊 薄熱
	
	int selection = 0;//詭景摹鷗 selection滲熱
	int count = 0,temp,quiz_count = 1;
	char answel[10];


	int temp01=1;
	while(temp01){
	for(j=0;j<10;j++) //寡翮 蟾晦��
	{
		ok[j] = 0;
	}
	printf("\n");
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早  襪鍔 陛嬪*夥嬪*爾 Щ煎斜極                    早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n");

	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早  (1) 措    餌                                  早\n");
	printf("早  (2) 撮 啗 餌                                  早\n");
	printf("早  (3) 薑港�挫�                                  早\n");
	printf("早  (4) 薄熱�粉�                                  早\n");
	printf("早  (5) 謙    猿                                  早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("〡 詭景蒂 摹鷗ж撮蹂 : "); //詭景摹鷗.
	fflush(stdin);
	scanf("%d", &selection);

		switch(selection)
		{
		case 1://措餌
			init01();
			printf("〡 I  D : ");
			scanf("%s", inpName);
			while(1)
			{
				srand(time(NULL));		
				one_print(quiz_count); //轎溘 
				while(1) //僥薯 醞犒匐餌
				{
					i = rand()%10;
					if(ok[i] == 0)
					{
						ok[i] = 1;
						break;
					}
				}
	    
				two_print(i); //轎溘 
				temp = gawi(i,quiz_count); 
				one_print(quiz_count);
				two_print(i);
				
				if(temp==1)
				{
					printf("�爩� : %s \n",quiz[i].hint);	//�爩�
				}

				printf("薑港  >> ");
				scanf("%s",answel);

				if(!strcmp(quiz[i].answer,answel))
				{
					inpPoint+=10;	//薑港橾 衛 薄熱 и 僥薯渡 10薄噶 援瞳
					printf("薑港殮棲棻. 棻擠僥薯 檜翕 [Enter] \n");
				}
				else
				{
					printf("ぎ溜蝗棲棻. 棻擠僥薯 檜翕 [Enter] \n");
				}
				quiz_count++;
				getch();		//幗ぷ詭賅葬 濠葬 奢除 getch() ��轎
				system("cls");
		
				if(quiz_count==10)
				{
					printf("\n\n〡 %s椒曖 �僱� 薄熱朝 %3d薄 殮棲棻.\n", inpName,inpPoint);
					break;
				}
			}
			break;
		case 2://撮啗餌
			init02();
			printf("〡 I  D : ");
			scanf("%s", inpName);
			while(1)
			{
				srand(time(NULL));		
				one_print(quiz_count); //轎溘 
				while(1) //僥薯 醞犒匐餌
				{
					i = rand()%10;
					if(ok[i] == 0){
						ok[i] = 1;
						break;
					}
				}
	    
				two_print(i); //轎溘 
				temp = gawi(i,quiz_count); 
				one_print(quiz_count);
				two_print(i);

				if(temp==1)
				{
					printf("�爩� : %s \n",quiz[i].hint);	//�爩�
				}

				printf("薑港  >> ");
				scanf("%s",answel);
	
				if(!strcmp(quiz[i].answer,answel))
				{
					printf("<薑港> Enter Key蒂 殮溘ж衛賊 棻擠 僥薯煎 剩橫骨棲棻. \n");
				}
				else
				{
					printf("<螃港> Enter Key蒂 殮溘ж衛賊 棻擠 僥薯煎 剩橫骨棲棻. \n");
				}
				quiz_count++;
				getch();
				system("cls");

				if(quiz_count==10)
				{
					printf("\n\n〡 %s椒曖 �僱� 薄熱朝 %3d薄 殮棲棻.\n", inpName,inpPoint);
					break;
				}
			}
			break;
		case 3://薑港�挫�
			solution();//薑港�挫� л熱 ��轎
			break;
		case 4://薄熱�粉�
			
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("  〡 薄 熱 �� 骯\n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			printf("〡 I  D : ");
 			scanf("%s", &name);
 			printf("〡 薄 熱: ");
			scanf("%d", &inpPoint);
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("  〡 菜薄滌 薄熱 �粉糒功n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			for (i=0; i<5; i++)
			{
				printf("State : %-10s 薄 熱 : %3d ~%3d\n\n", num_board[i], point[i],point[i]-20);
			}
			printf("旨收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("  〡 %10s椒曖 薄熱 : %3d薄\n",name,inpPoint);
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
			

			break;
		case 5://謙猿
			return 0; // Щ煎斜極 謙猿.
		default:
			printf("\n\a");						//escape 僥濠 'wa' 唳堅擠
			printf("旨CAUTION!收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("早   棻衛 殮溘ж撮蹂.                             早\n");
			printf("曲收收收收收收收收收收收收收收收收收收收收收收收收旭\n\n");
		}
		printf("詭景煎 給嬴陛衛啊蝗棲梱?(y/n)\n");
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
			printf("〡 襪鍔陛嬪夥嬪爾 Щ煎斜極擊 檜辨п 輿敷憮 馬餌м棲棻.\n");
			return 0;
		}
	}
}

//僥薯廓��
void one_print(int quiz_count)
{
		printf("\n");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早僥薯 %2d廓							      早\n",quiz_count);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
}
//僥薯 轎溘
void two_print(int i)
{
		printf("\n");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("  %s\n",quiz[i].told);
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n\n");
			
}
//措餌 僥薯
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
	strcpy(quiz[4].told,"10000錳掏縑 億啖霞 嬪檣曖 檜葷擎 鼠歙殮棲梱?");
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
//撮啗餌 僥薯
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
//薑港�挫�<措餌*撮啗餌>
void solution()
{
	printf("  〡措  餌\n");
	printf("  (1)100錳縑 億啖霞 嬪檣曖 檜葷 : 檜牖褐\n");
	printf("  [Hint] 剪磁摹\n");
	printf("  (2)1000錳掏縑 億啖霞 嬪檣曖 檜葷 : 黴啗檜�淚n");
	printf("  [Hint]褻摹撩葬з曖 晦蟾蒂 撮遴 摹綠, 釭嬴馬婁 僭楝陴曖 曖嘐\n");
	printf("  (3)5000錳掏縑 億啖霞 嬪檣曖 檜葷 : 徽堊檜檜\n");
	printf("  [Hint]褕餌歜渡曖 嬴菟\n");
	printf("  (4)10000錳掏縑 億啖霞 嬪檣曖 檜葷 : 撮謙渠諾\n");
	printf("  [Hint]�さ恔分穀n");
	printf("  (5)10000錳掏縑 億啖霞 嬪檣曖 檜葷 : 褐餌歜渡\n");
	printf("  [Hint]⑷賅曄籀\n");
	printf("  (6)1592~1598喇, 舒 離滔縑 勘藥 辦葬釭塭蒂 藹殮и 橾獄婁曖 諄遺 : 歜霞謁塢\n");
	printf("  [Hint]и骯渠繪\n");
	printf("  (7)貲撩�笮譫� 衛пж堅 橾獄撮溘 鬼�飛� �嘔犯� 薑滲 : 擊嘐餌滲\n");
	printf("  [Hint]橾獄 濠偌曖 唳犒掙 藹殮 餌勒\n");
	printf("  (8)8錯15橾擎 '﹤﹤瞰' : 惜犒瞰\n");
	printf("  [Hint]嶸婦牖, 寥彰 梯掘, 紫骯 寰璽�αn");
	printf("  (9)п瞳菟曖 檣褐衙衙蒂 斬瞰, 諫瞪 模鰻и 褐塭曖 鼠濰 : 濰爾堅\n");
	printf("  [Hint]夥棻曖 諾\n");
	printf("  (10)釭渡翱м捱(5虜)擊 5繭曖 捱餌煎 啻 離滔 蝓葬蒂 虜萇 濰捱曖 檜葷 : 啗寥\n");
	printf("  [Hint]寥薯 蜓晦曖 濰捱\n");
	printf("\n");
	printf("  〡撮啗餌\n");
	printf("  (1)薯 1離 撮啗渠瞪擎 4喇翕寰 雖樓腎歷棻.\n");
	printf("  [Hint]1918喇 11錯 11橾 絮橾曖 о犒戲煎 部陴.\n");
	printf("  (2)雖旎梱雖曖 檣盟 羲餌縑憮 陛濰 贖 檣貲婁 營骯 Яп蒂 竟擎 瞪爵\n");
	printf("  :薯2離撮啗渠瞪\n");
	printf("  [Hint]翱м措 餌檜縑 弊橫霞 撮啗 敘賅曖 瞪爵\n");
	printf("  (3)お煎檜跡葆朝 斜葬蝶陛 お煎檜蒂 鼠傘お萵 陽 唸薑瞳檣 羲й擊 ж艘棻.\n");
	printf("  [HintTrojan Horse\n");
	printf("  (4)�鷝眺秩� 薯2離撮啗渠瞪擊 橾戲儷雖虜 ぬ儀檜 瞿橫雖濠 濠髦ж艘棻.\n");
	printf("  [Hint]絮橾曖 薑纂陛檜貊 絮營濠煎 碳萼棻.\n");
	printf("  (5)橾獄曖 霞輿虜晦蝗擊 啗晦煎 嘐措檜 2離渠瞪縑 嗨橫菟啪 腎歷棻.\n");
	printf("  [Hint]Ё睡ж啪 釭湍 霞輿蒂 虜菟橫 頂朝 掉 陽僥縑 稱擎 檜葷\n");
	printf("  (6)濤棻腦觼: 艙措曖 寥喇瞪爵 �覺熂� Щ嫌蝶蒂 嬪晦縑憮 掘и 艙錠瞳檣 模喪.\n");
	printf("  [Hint]葆喪煎 路溥 19撮 粒棻遴 釭檜縑 �倆� 渡л.\n");
	printf("  (7)陪癒褻擒擎 醞措檜 諼措婁 裕擎 譆蟾曖 斬渠瞳檣 褻擒檜貊 碳ゎ蛔褻擒檜棻.\n");
	printf("  [Hint]嬴ら瞪爵\n");
	printf("  (8)骯機⑶貲:18撮晦 醞膨 艙措縑憮 衛濛脹 晦獎⑶褐婁 餌�腹什碻� 掘褻曖 滲⑶.\n");
	printf("  [Hint]奢機�苒n");
	printf("  (9)漆腦餌嶸褻擒:\n");
	printf("  薯1離 撮啗渠瞪 �� 瞪爵縑 蝓葬и 翱м措婁 ぬ瞪措 絮橾曖 鬼�俯馮�.\n");
	printf("  [Hint]檜 褻擒戲煎 絮橾擎 п諼衝團雖朝 賅舒 鼻褒, 嶸毀 頂 艙饜蒂 檠歷棻.\n");
	printf("  (10)旎瞪 塽 營僭擊 瑰ьи 餌塋菟縑啪 賸蒂 賊п遽棻朝 嗆曖 隸憮 : 賊賸睡\n");
	printf("  [Hint]\n");
	printf("  15撮晦 蜓晦,渠榆 嫦ч戲煎 瑞攪曖 綠っ擊 碳楝橾戲酈堅 謙掖 偃⑶曖 褒葆葬陛 脾.\n");
}
//陛嬪夥嬪爾
int gawi(int i,int quiz_count) //0綠梯 1檜曹 2颶
{
	char *psr[3] = {"陛嬪","夥嬪","爾"};
	int com, you, count = 0;
	int win = 0,t;
		
	printf("〡 闡У攪諦曖 陛嬪*夥嬪*爾 ( 檜晦賊 �爩� 雖晝 )\n");
	printf("〡 Enter Key蒂 援腦賊 渠唸檜 衛濛腌棲棻.\n");
	getch();	
	system("cls");
		
	
	one_print(quiz_count);
	two_print(i);
	emoticon();						//檜賅じ夔 轎溘	
	srand((unsigned)time(NULL));
	com = rand()%3 + 1;
	printf("     陛嬪(1), 夥嬪(2), 爾(3) 璋濠殮溘 [  ]\b\b\b ");
	scanf("%d",&you);
			
	printf("闡У攪朝 %s, 渡褐擎 %s\n",psr[com-1],psr[you-1]);
	printf("\n");
	printf("唸婁 : ");

	if(com==1){
		if(you==1) { printf("綠啣蝗棲棻. \n"); }
		else if(you == 2) { printf("渡褐檜 檜啣蝗棲棻. \n"); count++;}
		else if(you == 3) { printf("闡У攪陛 檜啣蝗棲棻. \n"); }
	}else if(com == 2){
		if(you==1) { printf("闡У攪陛 檜啣蝗棲棻. \n"); }
		else if(you == 2) { printf("綠啣蝗棲棻.\n"); }
		else if(you == 3) { printf("渡褐檜 檜啣蝗棲棻.\n"); count++;}
	}else{
		if(you == 1) { printf("渡褐檜 檜啣蝗棲棻.\n"); count++;}
		else if(you == 2) { printf("闡У攪陛 檜啣蝗棲棻.\n"); }
		else { printf("綠啣蝗棲棻.\n"); }
	}
	printf("\n");
	printf("〡 Enter Key蒂 殮溘ж褐 ��, 薑港擊 晦殮п輿撮蹂.\n\n");	
	getch();
	system("cls");
	return count;
}
//陛嬪夥嬪爾 檜賅じ夔
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

