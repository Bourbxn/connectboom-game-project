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
  printf("  1   2   3   4   5   6   \n");
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6 && j==0;k++){
				if(k==0) printf("|");
				printf("---|");
				if(k==5) printf("\n");
			}
			if(j==0) printf("|");
			printf(" %c |",board[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<6;i++){
		if(i==0) printf("|");
		printf("---|");
		if(i==5) printf("\n");
	}
	for(int i=0;i<25;i++){
		printf("=");
		if(i==24) printf("\n");
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
	int round;
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			board[i][j] = ' ';
		}
	}
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
		int drop;
		render_board(board);
		if(round==0){
			printf("Player, your turn!\n\n");
			printf("Where do you want to go(1-6)?\n");
			scanf("%s",pick);
			//Player drop
			drop = pick[0]-'0'-1;
			for(int i=5;i>=0;i--){
				if(board[i][drop]==' '){
					board[i][drop]=sp;
					break;
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
			if(is_bingo(board)){
				strcpy(plwin,"Player");
				break;
			}
		}
		else if(round==1){
			//Computer Drop
			drop = comp_select(board);
			for(int i=5;i>=0;i--){
				if(board[i][drop]==' '){
					board[i][drop]=cp;
					break;
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
			if(is_bingo(board)){
				strcpy(plwin,"Computer");
				break;
			}
		}
		round=!round;
	}
	menu_pvc_result(board,plwin);
}


void menu_pvp(){
	system("clear");
	char board[6][6];
	char p1[1000],p2[1000],plwin[1000];
	int round = 0;
	int reXo[11][2];
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			board[i][j] = ' ';
		}
	}
	render_board(board);
	printf("Player1: ");
	scanf("%s",p1);
	printf("Player2: ");
	scanf("%s",p2);
	while(1){
		system("clear");
		char pick[1],oxb;
		int drop;
		render_board(board);
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
				break;
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
      if(round==0) strcpy(plwin,p1);
      else if(round==1) strcpy(plwin,p2);
      break;
    }
		round=!round;
	}
  menu_pvp_result(board,plwin);
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