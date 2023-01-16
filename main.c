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
  int x, y;
  printf("x座標を入力してください: ");
  scanf("%d", &x);
  printf("y座標を入力してください: ");
  scanf("%d", &y);
  if (map[y - 1][x - 1] == -2)
  {
    printf("爆弾があります\n");
  }
  else
  {
    printf("爆弾はありません\n");
  }
}

int main(){
  initialize();
  setBomb();
  printMap(5, 5);
  user_task();
}
