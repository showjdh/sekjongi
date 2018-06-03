#include<stdio.h>

int N;
int map[129][129];
int blue, white;

typedef struct point{
	int y;
	int x;
}Point;

int isCuttable(Point leftup, int size){
	int i, j, color;
	Point rightdown;
	rightdown.y = leftup.y + size - 1;
	rightdown.x = leftup.x + size - 1;
	color = map[leftup.y][leftup.x];

	for (i = leftup.y; i <= rightdown.y; i++){
		for (j = leftup.x; j <= rightdown.x; j++){
			if (map[i][j] != color){
				return 0;
			}
		}
	}
	if (color == 1){
		return 1;
	}
	else{
		return -1;
	}
}

void cutPaper(Point leftup, int size){
	int color;
	Point p1, p2, p3, p4;
	color = isCuttable(leftup, size);

	if (color!=0){
		if (color == 1)
			blue++;
		else
			white++;
		return;
	}

	p1.y = leftup.y; p1.x = leftup.x;
	p2.y = leftup.y; p2.x = leftup.x+size/2;
	p3.y = leftup.y+size/2; p3.x = leftup.x;
	p4.y = leftup.y+size/2; p4.x = leftup.x+size/2;

	cutPaper(p1, size / 2);
	cutPaper(p2, size / 2);
	cutPaper(p3, size / 2);
	cutPaper(p4, size / 2);

}


int main(){
	int i, j;
	Point p1, p2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= N; j++){
			scanf("%d", &map[i][j]);
		}
	}
	p1.y = 1; p1.x = 1;

	cutPaper(p1, N);

	printf("%d\n%d\n", white, blue);

	
	return 0;
}