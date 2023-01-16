#include <stdio.h>

int map[5][5];

void initialize()
{
  for (int y = 0; y < 5; y++)
  {
    for (int x = 0; x < 5; x++)
    {
      map[y][x] = -1;
    }
  }
}

void setBomb(){
  map[0][1] = -2;
  map[2][3] = -2;
  map[5][4] = -2;
}

void printMap(int x_size, int y_size)
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
        printf("  ");
      }
    }
    printf(" |\n");
    printf("  - - - - - - -\n");
  }
  printf("\n");
}

void user_task()
{
  int condition = 1;
  while (condition)
  {
    printf("座標を入力してください(x, y) :");
    int x1, y1;
    scanf("%d %d", &x1, &y1);

    x1--;
    y1--;
    if (map[y1][x1] == -2)
    {
      printf("爆弾がありました。ゲームオーバーです。\n");
      condition = 0;
    }
    else if (map[y1][x1] == -1)
    {
      int cnt = 0;
      if (map[y1 - 1][x1] == -2)
        cnt++;
      if (map[y1 + 1][x1] == -2)
        cnt++;
      if (map[y1][x1 - 1] == -2)
        cnt++;
      if (map[y1][x1 + 1] == -2)
        cnt++;
      if (map[y1 - 1][x1 - 1] == -2)
        cnt++;
      if (map[y1 + 1][x1 + 1] == -2)
        cnt++;
      if (map[y1 + 1][x1 - 1] == -2)
        cnt++;
      if (map[y1 - 1][x1 + 1] == -2)
        cnt++;

      map[y1][x1] = cnt;
      printf("爆弾はありませんでした。\n");
      printMap(5, 5);
    }
    else
    {
      printf("既に開いています。\n");
      printMap(5, 5);
    }
  }
}

int main(){
  initialize();
  setBomb();
  printMap(5, 5);
  user_task();
}
