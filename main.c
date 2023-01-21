#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X_SIZE 8
#define Y_SIZE 9

int map[Y_SIZE][X_SIZE];

void endJudgment();
void additionalOpen(int, int);
int countBomb(int, int);

void initialize()
{
  for (int y = 0; y < Y_SIZE; y++)
  {
    for (int x = 0; x < X_SIZE; x++)
    {
      map[y][x] = -1;
    }
  }
  printf("\033[H\033[2J");\
}

void setBomb(){
  srand((unsigned int)time(NULL));

  for(int i = 0; i < X_SIZE; i++){
    map[rand() % Y_SIZE][rand() % X_SIZE] = -2;
  }
}

void printAns()
{
  printf("  x");
  for (int i = 1; i <= X_SIZE; i++)
  {
    printf(" %d", i);
  }
  printf("\ny");
  for (int j = 0; j <= X_SIZE; j++)
  {
    printf(" -");
  }
  for (int y = 0; y < Y_SIZE; y++)
  {
    printf("\n%d |", y + 1);
    for (int x = 0; x < X_SIZE; x++)
    {
      printf(" %d", map[y][x]);
    }
    printf(" |\n ");
    for (int k = 0; k <= X_SIZE; k++)
    {
      printf(" -");
    }
  }
  printf("\n");
}

void printMap()
{
  printf("\033[H  x");
  for(int i = 1; i <= X_SIZE; i++){ printf(" %d", i); }
  printf("\ny");
  for(int j = 0; j <= X_SIZE; j++){ printf(" -"); }
  for(int y = 0; y < Y_SIZE; y++)
  {
    printf("\n%d |", y+1);
    for (int x = 0; x < X_SIZE; x++)
    {
      if (map[y][x] >= 0)
      {
        printf(" %d", map[y][x]);
      }
      else
      {
        printf("  ");
      }
    }
    printf(" |\n ");
    for(int k = 0; k <= X_SIZE; k++){ printf(" -"); }
  }
  printf("\n");
}

void user_task()
{
  int condition = 1;
  while (condition)
  {
    printMap();
    printf("座標を入力してください(x y) :\033[0K");
    int x, y;
    scanf("%d %d", &x, &y);

    x--;
    y--;
    if (map[y][x] == -2)
    {
      printf("爆弾がありました。ゲームオーバーです。\n");
      condition = 0;
    }
    else if (map[y][x] == -1)
    {
      int cnt = countBomb(x, y);
      map[y][x] = cnt;
      if(cnt == 0){ additionalOpen(x, y); }
      printf("爆弾はありませんでした。\n");
    }
    else
    {
      printf("既に開いています。\n");
    }
    endJudgment();
  }
}

void endJudgment(){
  int cnt = 0;
  for (int y = 0; y < 5; y++)
  {
    for (int x = 0; x < 5; x++)
    {
      if (map[y][x] == -1)
      {
        cnt++;
      }
    }
  }
  if (cnt == 0){
    printf("ゲームクリアです。\n");
    exit(0);
  }
}

int countBomb(int x, int y){
  int cnt = 0;
  if (map[y-1][x] == -2 && y-1 >= 0)
    cnt++;
  if (map[y+1][x] == -2 && y+1 < Y_SIZE)
    cnt++;
  if (map[y][x-1] == -2 && x-1 >= 0)
    cnt++;
  if (map[y][x+1] == -2 && x+1 < X_SIZE)
    cnt++;
  if (map[y-1][x-1] == -2 && y-1 >= 0 && x-1 >= 0)
    cnt++;
  if (map[y+1][x+1] == -2 && y+1 < Y_SIZE && x+1 < X_SIZE)
    cnt++;
  if (map[y+1][x-1] == -2 && y+1 < Y_SIZE && x-1 >= 0)
    cnt++;
  if (map[y-1][x+1] == -2 && y-1 >= 0 && x+1 < X_SIZE)
    cnt++;

  return cnt;
}

void additionalOpen(int x, int y){
  int cnt;
  if (map[y-1][x] == -1 && y-1 >= 0){
    cnt = countBomb(x, y-1);
    map[y-1][x] = cnt;
    if(cnt == 0){ additionalOpen(x, y-1); }
  }
  if (map[y+1][x] == -1 && y+1 < Y_SIZE){
    cnt = countBomb(x, y+1);
    map[y+1][x] = cnt;
    if(cnt == 0){ additionalOpen(x, y+1); }
  }
  if (map[y][x-1] == -1 && x-1 >= 0){
    cnt = countBomb(x-1, y);
    map[y][x-1] = cnt;
    if(cnt == 0){ additionalOpen(x-1, y); }
  }
  if (map[y][x+1] == -1 && x+1 < X_SIZE){
    cnt = countBomb(x+1, y);
    map[y][x+1] = cnt;
    if(cnt == 0){ additionalOpen(x+1, y); }
  }
  if (map[y-1][x-1] == -1 && y-1 >= 0 && x-1 >= 0){
    cnt = countBomb(x-1, y-1);
    map[y-1][x-1] = cnt;
    if(cnt == 0){ additionalOpen(x-1, y-1); }
  }
  if (map[y+1][x+1] == -1 && y+1 < Y_SIZE && x+1 < X_SIZE){
    cnt = countBomb(x+1, y+1);
    map[y+1][x+1] = cnt;
    if(cnt == 0){ additionalOpen(x+1, y+1); }
  }
  if (map[y+1][x-1] == -1 && y+1 < Y_SIZE && x-1 >= 0){
    cnt = countBomb(x-1, y+1);
    map[y+1][x-1] = cnt;
    if(cnt == 0){ additionalOpen(x-1, y+1); }
  }
  if (map[y-1][x+1] == -1 && y-1 >= 0 && x+1 < X_SIZE){
    cnt = countBomb(x+1, y-1);
    map[y-1][x+1] = cnt;
    if(cnt == 0){ additionalOpen(x+1, y-1); }
  }
}

int main(){
  initialize();
  setBomb();
  user_task();
}
