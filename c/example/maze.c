#include <stdio.h>

char map[][10] = {
		"#####",
		"#E#S#",
		"# # #",
		"#####",
};
int s_i = 1;
int s_j = 3;

int travel(int i, int j) {
	if (map[i][j] == '#' || map[i][j] == 'O') {
		return 0;
	}
	if (map[i][j] == 'E') {
		return 1;
	}
	map[i][j] = 'O';
	int rs = 0;
	rs += travel(i+1, j);
	rs += travel(i-1, j);
	rs += travel(i, j+1);
	rs += travel(i, j-1);
	return rs;
}

int main(void) {
	int rs;
	rs = travel(s_i, s_j);
	printf("%d\n", rs);
	return 0;
}
