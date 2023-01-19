#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int map[5][5];

void endJudgment();

void initialize()
{
  for (int y = 0; y < 5; y++)
  {
    for (int x = 0; x < 5; x++)
    {
      map[y][x] = -1;
    }
  }
  printf("\033[H\033[2J"); // 画面をクリア
}

void setBomb(){
  srand((unsigned int)time(NULL));

  map[rand() % 5][rand() % 5] = -2;
  map[rand() % 5][rand() % 5] = -2;
  map[rand() % 5][rand() % 5] = -2;
}

void printAns(int x_size, int y_size)
{
  printf("  x 1 2 3 4 5\n");
  printf("y - - - - - - -\n");
  for (int y = 0; y < y_size; y++)
  {
    printf("%d |", y + 1);
    for (int x = 0; x < x_size; x++)
    {
      if (map[y][x] >= 0)
      {
        printf(" %d", map[y][x]);
      }
      else
      {
        printf("%d", map[y][x]);
      }
    }
    printf(" |\n");
    printf("  - - - - - - -\n");
  }
  printf("\n");
}

void printMap(int x_size, int y_size)
{
  printf("\033[H  x 1 2 3 4 5\ny - - - - - - -\n");
  for (int y = 0; y < y_size; y++)
  {
    printf("%d |", y + 1);
    for (int x = 0; x < x_size; x++)
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
    printf(" |\n  - - - - - - -\n");
  }
  printf("\n");
}

void user_task()
{
  int condition = 1;
  while (condition)
  {
    printMap(5, 5);
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
      int cnt = 0;
      if (map[y - 1][x] == -2 && y - 1 >= 0)
        cnt++;
      if (map[y + 1][x] == -2 && y + 1 < 5)
        cnt++;
      if (map[y][x - 1] == -2 && x - 1 >= 0)
        cnt++;
      if (map[y][x + 1] == -2 && x + 1 < 5)
        cnt++;
      if (map[y - 1][x - 1] == -2 && y - 1 >= 0 && x - 1 >= 0)
        cnt++;
      if (map[y + 1][x + 1] == -2 && y + 1 < 5 && x + 1 < 5)
        cnt++;
      if (map[y + 1][x - 1] == -2 && y + 1 < 5 && x - 1 >= 0)
        cnt++;
      if (map[y - 1][x + 1] == -2 && y - 1 >= 0 && x + 1 < 5)
        cnt++;

      map[y][x] = cnt;
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

int main(){
  initialize();
  setBomb();
  user_task();
}
