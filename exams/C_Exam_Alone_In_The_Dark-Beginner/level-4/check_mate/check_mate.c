
// Test from King
#include <unistd.h>

void get_king(char **map, int *krow, int *kcol)
{
	int x = 0;
	int y = 0;

	while(map[x])
	{
		while(map[x][y])
		{
			if (map[x][y] == 'K')
			{
				*krow = x;
				*kcol = y;
				return;
			}
			y++;
		}
		x++;
		y = 0;
	}
	*krow = -1;
	*kcol = -1;
}

int check_ortho(char **map, int krow, int kcol)
{
	int row = krow;
	int col = kcol;

	while(row > 0)
	{
		row--;
		if (map[row][col] == 'Q' || map[row][col] == 'R')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'B')
			break;
	}
	while(col > 0)
	{
		col--;
		if (map[row][col] == 'Q' || map[row][col] == 'R')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'B')
			break;
	}
	row = krow;
	col = kcol;
	while (map[row + 1][col])
	{
		row++;
		if (map[row][col] == 'Q' || map[row][col] == 'R')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'B')
			break;
	}
	while (map[row][col + 1])
	{
		col++;
		if (map[row][col] == 'Q' || map[row][col] == 'R')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'B')
			break;
	}
	return (0);
}

int	check_diagonal(char **map, int krow, int kcol)
{
	int row = krow;
	int col = kcol;

	while(row > 0 && col > 0 )
	{
		row--;
		col--;
		if (map[row][col] == 'B' || map[row][col] == 'Q')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
			break;
	}
	row = krow;
	col = kcol;
	while (map[row + 1][col + 1])
	{
		row++;
		col++;
		if (map[row][col] == 'B' || map[row][col] == 'Q')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
		{
			if (row == krow + 1)
				return (1);
			else
				break;
		}
	}
	row = krow;
	col = kcol;
	while (map[row + 1][col - 1] && col > 0)
	{
		row++;
		col--;
		if (map[row][col] == 'B' || map[row][col] == 'Q')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
		{
			if (row == krow + 1)
				return(1);
			else
				break;
		}
	}
	row = krow;
	col = kcol;
	while (map[row - 1][col + 1] && row > 0)
	{
		row--;
		col++;
		if (map[row][col] == 'B' || map[row][col] == 'Q')
			return (1);
		else if (map[row][col] == 'P' || map[row][col] == 'R')
			break;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int krow = 0;
	int kcol = 0;
	char **map;
	if (argc > 1)
	{
		// Parse input into 2D char array
		map = &argv[1];
		// Find pos of king
		get_king(map, &krow, &kcol);
		// Check horizontal & vertical (Orthogonal)
		if(check_ortho(map, krow, kcol))
			write(1, "Success", 7);
		// Check diagonal
		else if(check_diagonal(map, krow, kcol))
			write(1, "Success", 7);
		else
			write(1, "Fail", 4);
	}
	write(1, "\n", 1);
	return 0;
}
