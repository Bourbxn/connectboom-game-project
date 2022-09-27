#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//define function
void menu_main();
void menu_pvc();
void menu_pvp();
void menu_exit();

//render
void render_menu(){
	printf("  ______                                     ______\n");
	printf(" / _____)                            _      (____  \\ \n");
	printf("| /      ___  ____  ____   ____ ____| |_     ____)  ) ___   ___  ____ \n");
	printf("| |     / _ \\|  _ \\|  _ \\ / _  ) ___)  _)   |  __  ( / _ \\ / _ \\|    \\ \n");
	printf("| \\____| |_| | | | | | | ( (/ ( (___| |__   | |__)  ) |_| | |_| | | | |\n");
	printf(" \\______)___/|_| |_|_| |_|\\____)____)\\___)  |______/ \\___/ \\___/|_|_|_| \n");
	printf("========================================================================\n");
	printf("Select Menu\n");
	printf("[1] Player vs Computer\n");
	printf("[2] Player vs Player\n");
	printf("[3] Exit\n");
	printf("Choose: ");
}

void render_board(char board[6][6]){
	int chr = 65;
  printf("    1   2   3   4   5   6   \n");
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6 && j==0;k++){
				if(k==0){
					printf("  |");
				} 
				printf("---|");
				if(k==5) printf("\n");
			}
			if(j==0){
				printf("%c |",chr++);
			}
			printf(" %c |",board[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<6;i++){
		if(i==0) printf("  |");
		printf("---|");
		if(i==5) printf("\n");
	}
	for(int i=0;i<27;i++){
		printf("=");
		if(i==26) printf("\n");
	}
}

void render_result(char board[6][6],char pl[1000]){
  render_board(board);
  printf("!!! The Winner is %s !!!\n\n",pl);
  printf("Select Menu\n");
	printf("[1] Restart\n");
	printf("[2] Menu\n");
	printf("Choose: ");
}

void render_draw(char board[6][6]){
	render_board(board);
	printf("!!! The Match is draw !!!\n\n");
  printf("Select Menu\n");
	printf("[1] Restart\n");
	printf("[2] Menu\n");
	printf("Choose: ");
}

//engine
int is_bingo(char board[6][6]){
  //check col
	int isBingo = 0;
  for(int i=0;i<6 && !isBingo;i++){
    for(int j=5;j>=3;j--){
      if(board[j][i]==board[j-1][i] &&
          board[j-1][i]==board[j-2][i] &&
          board[j-2][i]==board[j-3][i] &&
          board[j][i]!=' ' && board[j-1][i]!= ' ' &&
          board[j-2][i]!=' ' && board[j-3][i] != ' ')
        isBingo = 1;
    }
  }	
  //check row
  for(int i=5;i>=0 && !isBingo;i--){
    for(int j=0;j<3;j++){
      if(board[i][j]==board[i][j+1] &&
          board[i][j+1]==board[i][j+2] &&
          board[i][j+2]==board[i][j+3] &&
          board[i][j]!=' ' && board[i][j+1]!= ' ' &&
          board[i][j+2]!=' ' && board[i][j+3] != ' ')
        isBingo = 1;
    }
  }
  //check left to right diagonal
  for(int i=5;i>=3 && !isBingo;i--){
    for(int j=0;j<3;j++){
      if(board[i][j]==board[i-1][j+1] &&
          board[i-1][j+1]==board[i-2][j+2] &&
          board[i-2][j+2]==board[i-3][j+3] &&
          board[i][j]!=' ' && board[i-1][j+1]!= ' ' &&
          board[i-2][j+2]!=' ' && board[i-3][j+3] != ' ')
        isBingo = 1;
    }
  }
  //check right to left diagonal
  for(int i=5;i>=3 && !isBingo;i--){
    for(int j=3;j<=5;j++){
      if(board[i][j]==board[i-1][j-1] &&
          board[i-1][j-1]==board[i-2][j-2] &&
          board[i-2][j-2]==board[i-3][j-3] &&
          board[i][j]!=' ' && board[i-1][j-1]!= ' ' &&
          board[i-2][j-2]!=' ' && board[i-3][j-3] != ' ')
        isBingo = 1;
    }
  }
 return isBingo;
}

int is_draw(char board[6][6]){
	int isSpace = 0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			if(board[i][j]==' '){
				isSpace = 1;
				break;
			}
		}
	}
	return !isSpace;
}

int comp_select(char board[6][6]){
	int free[6],len=0,drop;
	for(int i=0;i<6;i++){
		if(board[0][i]==' '){
			free[len]=i;
			len++;
		}
	}
	drop = free[rand() % len];
  return drop;
}

//sub menu
void menu_pvp_result(char board[6][6],char pl[1000]){
  system("clear");
  int select;
  render_result(board,pl);
  scanf("%d",&select);
  if(select==1){
    menu_pvp();
  }
  else if(select==2){
    menu_main();
  }
}

void menu_pvc_result(char board[6][6],char pl[1000]){
  system("clear");
  int select;
  render_result(board,pl);
  scanf("%d",&select);
  if(select==1){
    menu_pvc();
  }
  else if(select==2){
    menu_main();
  }
}

void menu_pvp_draw(char board[6][6]){
	system("clear");
  int select;
  render_draw(board);
  scanf("%d",&select);
  if(select==1){
    menu_pvp();
  }
  else if(select==2){
    menu_main();
  }
}

void menu_pvc_draw(char board[6][6]){
	system("clear");
  int select;
  render_draw(board);
  scanf("%d",&select);
  if(select==1){
    menu_pvc();
  }
  else if(select==2){
    menu_main();
  }
}

int menu_pvpc_item_def(char board[6][6],int round,int itemAct,char p1[1000],char p2[1000]){
	system("clear");
	char select[1];
	int useDef=0;
	render_board(board);
	if(round==0) printf("%s, your defending time!\n\n",p2);
	else printf("%s, your defending time!\n\n",p1);
	if(itemAct==1 || itemAct==2) printf("Oppenent got Special Item!\n");
	else if(itemAct==3) printf("Oppenent got Freezing Item!\n");
	printf("Do you want to use defending item(Y/N)?\n");
	printf("Choose: ");
	scanf("%s",select);
	if(select[0]=='Y'){
		useDef=1;
	}
	return useDef;
}

int menu_pvpc_item_1(char board[6][6],int round,char p1[1000],char p2[1000]){
	int select;
	system("clear");
	render_board(board);
	if(round==0) printf("%s, your turn!\n\n",p1);
	else printf("%s, your turn!\n\n",p2);
	printf("!!! Special Item !!!\n");
	printf("Where do you want to remove?\n");
	printf("[1] Left\n[2] Right\n[3] Down\n[4] No\nChoose: ");
	scanf("%d",&select);
	return select;
}

void menu_pvpc_item_2(char board[6][6],int round,char p1[1000],char p2[1000]){
	system("clear");
	render_board(board);
	if(round==0) printf("%s, your turn!\n\n",p1);
	else printf("%s, your turn!\n\n",p2);
	printf("!!! Special Item !!!\n");
	printf("Where do you want to remove(row,column ex. A0)?\n");
	printf("Choose: ");
}

void menu_pvpc_item_4(char board[6][6],int round,char p1[1000],char p2[1000]){
	system("clear");
	render_board(board);
	if(round==0) printf("%s, your turn!\n\n",p1);
	else printf("%s, your turn!\n\n",p2);
	printf("!!! Defending Item !!!\n");
	printf("Do you want to keep it(Y/N)?\n");
	printf("Choose: ");
}

//menu
void menu_main(){
  system("clear");
	int select;
	render_menu();
	scanf("%d",&select);
	if(select==1){
		menu_pvc();
	}
	else if(select==2){
		menu_pvp();
	}
	else if(select==3){
		menu_exit();
	}
	else{
		menu_main();
	}
}

void menu_pvc(){
	system("clear");
	char board[6][6],select[100],sp,cp,plwin[1000];
	int round,isDraw=0,item[4][2],rowDrop;
	int def[] = {0,0},frz = 0;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			board[i][j] = ' ';
		}
	}
	//Random item
	for(int i=0;i<4;i++){
		item[i][0] = rand() % 6;
		item[i][1] = rand() % 6;
	}
	// for(int i=0;i<4;i++){
	// 	printf("(%d %d) ",item[i][0],item[i][1]);
	// }
	render_board(board);
	printf("Do you want to play first(Y/N)?\n");
	scanf("%s",select);
	if(select[0]=='Y'){
		round = 0;
		sp = 'X';
		cp = 'O';
	}
	else{
		round = 1;
		sp = 'O';
		cp = 'X';
	}
	while(1){
		system("clear");
		char pick[1];
		int drop,itemAct=0,useDef=0;
		render_board(board);
		if(round==0){
			if(frz==1){
				printf("!!! Opponent was Frozen !!!\n");
				frz=0;
			}
			printf("Player, your turn!\n\n");
			printf("Where do you want to go(1-6)?\n");
			scanf("%s",pick);
		} 
		//Player drop
		if(round==0) drop = pick[0]-'0'-1;
		else if(round==1) drop = comp_select(board);
		for(int i=5;i>=0;i--){
			if(board[i][drop]==' '){
				if(round==0) board[i][drop]=sp;
				else if(round==1) board[i][drop]=cp;
				rowDrop = i;
				break;
			}
		}

		//check item
		if(item[0][0]==rowDrop && item[0][1]==drop) itemAct = 1;
		else if(item[1][0]==rowDrop && item[1][1]==drop) itemAct = 2;
		else if(item[2][0]==rowDrop && item[2][1]==drop) itemAct = 3;
		else if(item[3][0]==rowDrop && item[3][1]==drop) itemAct = 4;
		if(itemAct>0 && def[!round]){
			if(round==0) useDef = menu_pvpc_item_def(board,round,itemAct,"Player","Computer");
			else if(round==1) useDef = 1;
		}
		if(itemAct==1 && !useDef){
			int select;
			if(round==0) select = menu_pvpc_item_1(board,round,"Player","Computer");
			else if(round==1){
				int randSelect[3],idx=0,select=0;
				if(board[rowDrop][drop-1]!=' ') randSelect[idx++]=1;
				if(board[rowDrop][drop+1]!=' ') randSelect[idx++]=2;
				if(board[rowDrop+1][drop]!=' ') randSelect[idx++]=3;
				if(select!=0) select=randSelect[rand()%idx];
			} 
			if(select==1) board[rowDrop][drop-1]=' ';
			else if(select==2) board[rowDrop][drop+1]=' ';
			else if(select==3) board[rowDrop+1][drop]=' ';	
		}
		if(itemAct==2 && !useDef){
			char rowcol[2];
			int rowNum,colNum;
			if(round==0){
				menu_pvpc_item_2(board,round,"Player","Computer");
				scanf("%s",rowcol);
				rowNum = rowcol[0]-'A';
				colNum = rowcol[1]-'1';
			}
			else if(round==1){
				int ranSet[36][2],idx=0,ran;
				for(int i=0;i<6;i++){
					for(int j=0;j<6;j++){
						if(board[i][j]!=' '){
							ranSet[idx][0]=i;
							ranSet[idx][1]=j;
							idx++;
						}
					}
				}
				ran = rand()%idx;
				rowNum =  ranSet[ran][0];
				colNum =  ranSet[ran][1];
			}
			
			board[rowNum][colNum]=' ';
		}
		if(itemAct==4){
			if(round==0){
				char select[1];
				menu_pvpc_item_4(board,round,"Player","Computer");
				scanf("%s",select);
				if(select[0]=='Y') def[round]=1;	
			}
			else if(round==1){
				def[round]=1;
			}
		}
		

		//check ox flow to space
		for(int i=4;i>=0;i--){
			for(int j=0;j<6;j++){
				if(board[i][j]!=' ' && board[i+1][j]==' '){
					board[i+1][j]=board[i][j];
					board[i][j]=' ';
				}
			}
		}
		//check when bingo
		if(is_bingo(board)){
			if(round==0) strcpy(plwin,"Player");
   		else if(round==1) strcpy(plwin,"Computer");
			break;
		}
		else if(is_draw(board)){
  		isDraw = 1;
  		break;
  	}
  	//check freeze item
    if(itemAct==3 && !useDef){
			if(round==0) frz=1;
			round=!round;
		}
    //check use def item
    if(useDef){
    	def[!round] = 0;
    }
		round=!round;
	}
	if(isDraw){
		menu_pvc_draw(board);
	}
	else{
		menu_pvc_result(board,plwin);
	}
}


void menu_pvp(){
	system("clear");
	char board[6][6];
	char p1[1000],p2[1000],plwin[1000];
	int round = 0,item[4][2],rowDrop;
	int def[] = {0,0},frz = 0,isDraw;
	//New board
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			board[i][j] = ' ';
		}
	}
	//Random item
	for(int i=0;i<4;i++){
		item[i][0] = rand() % 6;
		item[i][1] = rand() % 6;
	}
	render_board(board);
	// for(int i=0;i<4;i++){
	// 	printf("(%d %d) ",item[i][0],item[i][1]);
	// }
	printf("Player1: ");
	scanf("%s",p1);
	printf("Player2: ");
	scanf("%s",p2);

	while(1){
		system("clear");
		char pick[1],oxb;
		int drop,itemAct=0,useDef=0;
		render_board(board);
		if(frz==1){
			printf("!!! Opponent was Frozen !!!\n");
			frz=0;
		}
		if(round==0) printf("%s, your turn!\n\n",p1);
		else printf("%s, your turn!\n\n",p2);
		printf("Where do you want to go(1-6)?\n");
		scanf("%s",pick);
		//Drop ox
		drop = pick[0]-'0'-1;
		if(round==0) oxb='X';
		else oxb='O';
		for(int i=5;i>=0;i--){
			if(board[i][drop]==' '){
				board[i][drop]=oxb;
				rowDrop = i;
				break;
			}
		}
		//check item
		if(item[0][0]==rowDrop && item[0][1]==drop) itemAct = 1;
		else if(item[1][0]==rowDrop && item[1][1]==drop) itemAct = 2;
		else if(item[2][0]==rowDrop && item[2][1]==drop) itemAct = 3;
		else if(item[3][0]==rowDrop && item[3][1]==drop) itemAct = 4;

		if(itemAct>0 && def[!round]){
			useDef = menu_pvpc_item_def(board,round,itemAct,p1,p2);
		}
		if(itemAct==1 && !useDef){
			int select = menu_pvpc_item_1(board,round,p1,p2);
			if(select==1) board[rowDrop][drop-1]=' ';
			else if(select==2) board[rowDrop][drop+1]=' ';
			else if(select==3) board[rowDrop+1][drop]=' ';
		}
		if(itemAct==2 && !useDef){
			char rowcol[2];
			int rowNum,colNum;
			menu_pvpc_item_2(board,round,p1,p2);
			scanf("%s",rowcol);
			rowNum = rowcol[0]-'A';
			colNum = rowcol[1]-'1';
			board[rowNum][colNum]=' ';
		}
		if(itemAct==4){
			char select[1];
			menu_pvpc_item_4(board,round,p1,p2);
			scanf("%s",select);
			if(select[0]=='Y') def[round]=1;
		}

		//check ox flow to space
		for(int i=4;i>=0;i--){
			for(int j=0;j<6;j++){
				if(board[i][j]!=' ' && board[i+1][j]==' '){
					board[i+1][j]=board[i][j];
					board[i][j]=' ';
				}
			}
		}
		//check when bingo
    if(is_bingo(board)){
    	isDraw = 0;
      if(round==0) strcpy(plwin,p1);
      else if(round==1) strcpy(plwin,p2);
      break;
    }
    else if(is_draw(board)){
    	isDraw = 1;
    	break;
    }

    //check freeze item
    if(itemAct==3 && !useDef){
			frz=1;
			round=!round;
		}
    //check use def item
    if(useDef){
    	def[!round] = 0;
    }
		round=!round;
	}
	if(isDraw){
		menu_pvp_draw(board);
	}
	else{
		menu_pvp_result(board,plwin);
	}
 
}

void menu_exit(){
	system("clear");
	exit(0);
}

//core
void connectboom(){
	menu_main();
}

//main
int main(){
	srand(time(NULL));
	connectboom();
	return 0;
}