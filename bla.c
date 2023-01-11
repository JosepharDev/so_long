// #include <stdio.h>
// void reco(int **image, int r, int c, int color, int newcolor, int csize, int i)
// {
// 	if(image[r][c] == color)
// 	{
// 		image[r][c] = newcolor;
// 		if(r >= 1)
// 			reco(image, r-1, c, color, newcolor, csize, i);
// 		if(c >= 1)
// 			reco(image, r, c-1, color, newcolor, csize, i);
// 		if(r + 1 < i) 
// 			reco(image, r, c + 1, color, newcolor, csize, i);
// 		if(c+1 < strlen((const char *)image[0]))
// 			reco(image, r, c+1, color, newcolor, csize, i);
// 	}
// }
// int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes){
//     int col = image[sr][sc];
//     int i = 0;
//     while(image[i])
//         i++;
// 	if(col != color)
// 		reco(image, sr, sc, col, color, imageColSize, i);
// 	return (image);
// }

// int main()
// {
// 	int a = 5;
// 	int b = 5;
// 	int image[5][5] = {{0,0,1,1,1}, {0,0,0,0,0}, {0,1,0,0,0},{1,0,0,1,1},{1,0,0,1,1}};
// 	int **img = floodFill(image, 5*5, 5, 1,1, 1, &a, &b);
// }

// void boundary(char **map, int x, int y, char fill_color, char bondary_color)
// {
// 	if(map[y][x] != bondary_color && map[y][x] != fill_color)
// 	{
// 		map[y][x] = fill_color;
// 		boundary(map, x + 1, y, fill_color, bondary_color);
// 		boundary(map, x, y + 1, fill_color, bondary_color);
// 		boundary(map, x - 1, y, fill_color, bondary_color);
// 		boundary(map, x, y - 1, fill_color, bondary_color);

// 	}
// }

// int main()
// {
// 	int a = 5;
// 	int b = 5;
// 	char image[5][5] = {"P0111","00000","01000","10011","00000"};
// 	// int **img = floodFill(image, 5*5, 5, 1,1, 1, &a, &b);
// 	boundary(image, 0, 0,'R', '1');

// }

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10000001",
		"00010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}