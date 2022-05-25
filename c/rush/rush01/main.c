#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 4
#define MIN 1
#define ROW 6
#define COLUMN 6

int		*g_table[ROW];
int		g_i;
int		g_j;
int		g_error;
int		g_counter;
int		g_sum;
char	g_c;

const	int	* cont_free;
void	init_col(int cu1, int cu2, int  cu3, int cu4, int cd1, int cd2, int cd3, int cd4);
void	init_row(int rl1, int rl2, int rl3, int rl4, int rr1, int rr2, int rr3, int rr4);
int		find_error(void);
void	trace_non_allowed(void);
void	trace_max_in_col(void);
void	trace_max_in_row(void);
void	trace_min_in_col(void);
void	trace_min_in_row(void);
void    lookup_min_in_col(void);
void    lookup_min_in_row(void);
void    lookup_max_in_col(void);
void    lookup_max_in_row(void);
void	lookup_two_in_col(void);
void	lookup_two_in_row(void);
void	lookup_three_in_col(void);
void	lookup_three_in_row(void);
void	check_for_rest(void);
void	print_error(void);
void	find_int(char *str);
void	other_errors(void);
void	fill_table(void);
int		check_row(int n);
int		check_col(int n);
void	show(void);
void	finalize(void);
void	init_table(int cu1, int cu2, int cu3, int cu4, int cd1, int cd2, int cd3, int cd4, int rl1, int rl2, int rl3, int rl4, int rr1, int rr2, int rr3, int rr4)
{
	g_i = 0;
	g_j = 0;
	g_error = 0;
	g_counter = 0;
	g_sum = 10;
	while (g_i < ROW)
	{
		g_table[g_i] = (int *) malloc(COLUMN * sizeof(int));
/*		if (g_table[g_i] != NULL)
		{
			printf("%s\n", "YES");	
			printf("%lu\n", sizeof(g_table[g_i]));
		} */
		g_i++;
	}
	cont_free = g_table[0];

	g_i = 0;
	init_col(cu1, cu2, cu3, cu4, cd1, cd2, cd3, cd4);
	init_row(rl1, rl2, rl3, rl4, rr1, rr2,rr3,rr4);
	if (find_error() > 0)
		print_error();
	else
		fill_table();
}

void	init_col(int cu1, int cu2, int  cu3, int cu4, int cd1, int cd2, int cd3, int cd4)
{
	g_table[0][0]	= 'R';
	g_table[0][1]	= cu1;
	g_table[0][2]	= cu2;
	g_table[0][3]	= cu3;
	g_table[0][4]	= cu4;
	g_table[0][5]	= 'R';
	g_table[5][0]	= 'R';
	g_table[5][1]	= cd1;
	g_table[5][2]	= cd2;
	g_table[5][3]	= cd3;
	g_table[5][4]	= cd4;
	g_table[5][5]	= 'R';
}

void	init_row(int rl1, int rl2, int rl3, int rl4, int rr1, int rr2, int rr3, int rr4)
{
	g_table[1][0]	= rl1;
	g_table[1][1]	= 0;
	g_table[1][2]	= 0;
	g_table[1][3]	= 0;
	g_table[1][4]	= 0;
	g_table[1][5]	= rr1;
	g_table[2][0]	= rl2;
	g_table[2][1]	= 0;
	g_table[2][2]	= 0;
	g_table[2][3]	= 0;
	g_table[2][4]	= 0;
	g_table[2][5]	= rr2;
	g_table[3][0]	= rl3;
	g_table[3][1]	= 0;
	g_table[3][2]	= 0;
	g_table[3][3]	= 0;
	g_table[3][4]	= 0;
	g_table[3][5]	= rr3;
	g_table[4][0]	= rl4;
	g_table[4][1]	= 0;
	g_table[4][2]	= 0;
	g_table[4][3]	= 0;
	g_table[4][4]	= 0;
	g_table[4][5]	= rr4;
}

int	find_error()
{
	trace_non_allowed();
	if (g_counter >= 2)
	{
		trace_max_in_col();	
		trace_max_in_row();
	}
	other_errors();
	return (g_error);

}
void trace_non_allowed()
{
	g_i = 0;
	g_j = 1;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] < MIN || g_table[g_i][g_j] > MAX)	
		{
			if (g_table[g_i][g_j] != 'R')
				g_counter++;
		}
		g_j++;
	}
	g_i = ROW - 1;
	g_j =  1;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] < MIN || g_table[g_i][g_j] > MAX)
		{
			if (g_table[g_i][g_j] != 'R')	
				g_error++;
		}
		g_j++;
	}
	g_i = 1;
	g_j = 0;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] < MIN || g_table[g_i][g_j] > MAX)
		{	
			if (g_table[g_i][g_j] != 'R')	
				g_counter++;
		}
		g_i++;
	}
	g_i = 1;
	g_j =  COLUMN - 1;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] < MIN || g_table[g_i][g_j] > MAX)
		{
			if (g_table[g_i][g_j] != 'R')
				g_error++;
		}
		g_i++;
	}
}

void	trace_max_in_col()
{	
	g_i = 0;
	g_j = 1;
	g_counter = 0;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MAX)
			g_counter++;
		g_j++;
	}
	if (g_counter > 1)
		g_error++;
	g_i = ROW - 1;
	g_j = 1;
	g_counter = 0;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MAX)
			g_counter++;
		g_j++;
	}
	if (g_counter >1)
			g_error++;
}

void	trace_max_in_row()
{
	g_i = 1;
	g_j = 0;
	g_counter = 0;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MAX)
			g_counter++;
		g_i++;
	}
	if (g_counter > 1)
		g_error++;
	g_i = 1;
	g_j = COLUMN -1;
	g_counter = 0;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MAX)
			g_counter++;
		g_i++;
	}
	if (g_counter > 1)
		g_error++;
}
void	trace_min_in_col()
{
	g_i = 0;
	g_j = 1;
	g_counter = 0;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MIN)
			g_counter++;
		g_j++;
	}
	if (g_counter > 1)
		g_error++;
	g_i = ROW - 1;
	g_j = 1;
	g_counter = 0;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MIN)
			g_counter++;
		g_j++;
	}
	if (g_counter >1)
			g_error++;
}

void	trace_min_in_row()
{
	g_i = 1;
	g_j = 0;
	g_counter = 0;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MIN)
			g_counter++;
		g_i++;
	}
	if (g_counter > 1)
		g_error++;
	g_i = 1;
	g_j = COLUMN -1;
	g_counter = 0i;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MIN)
			g_counter++;
		g_i++;
	}
	if (g_counter > 1)
		g_error++;
}

void	print_error(void)
{
		g_c = '0' + g_error;
		write(1, "Input error: ", 15);
		write(1, &g_c, 1);
		if (g_error > 1)
			write(1, " times\n" , 7);
		else
			write(1, " time\n", 6);
}
void	find_int(char *str)
{
	int size;
	int i;
	int j;
	i = 0;
	j = 0;
	size = 16;

	int tab[size];
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
		}
		else
		{
			tab[j] =  str[i] - '0';
		    j++;	
		}
		i++;
	}
	 
	init_table(tab[0], tab[1], tab[2], tab[3], tab[4], tab[5], tab[6], tab[7], tab[8], tab[9], tab[10], tab[11], tab[12], tab[13], tab[14], tab[15]);
}

void	other_errors(void)
{
	g_j = 1;
	while (g_j < COLUMN)
	{
		if (g_table[0][g_j] == MAX && g_table[ROW - 1][g_j] != MIN)
			g_error++;
		g_j++;
	}
	g_j = 1;
	while (g_j < COLUMN)
	{
		if (g_table[ROW - 1][g_j] == MAX && g_table[0][g_j] != MIN)
			g_error++;			
		g_j++;
	}
	g_i = 1;
	while (g_i < ROW)
	{
		if (g_table[g_i][0] == MAX && g_table[g_i][COLUMN -1] != MIN)
			g_error++;
		g_i++;
	}
	g_i = 1 ;
	while (g_i < ROW)
	{
		if (g_table[g_i][COLUMN -1] == MAX && g_table[g_i][0] != MIN)
			g_error++;
		g_i++;
	}
}

void	fill_table()
{
	int temp;
	lookup_min_in_col();
	lookup_min_in_row();
	lookup_max_in_col();
	lookup_max_in_row();
	lookup_two_in_col();
	lookup_two_in_row();
	lookup_three_in_col();
	lookup_three_in_row();
	check_for_rest();
	g_j = 1;
	g_i = 1;
	while (g_j < COLUMN - 1)
	{	
		if (check_col(g_j) )
		{	
			temp = g_table[4][4];
			g_table[4][4] = g_table[4][1];
			g_table[4][1] = temp;
		}
	
		g_j++;
	}

//	check_for_rest();
//	finalize();
}

void	lookup_min_in_col(void)
{
	g_i = 0;
	g_j = 1;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MIN)
			g_table[g_i + 1][g_j] = MAX;	
		g_j++;
	}
	g_i = ROW - 1;
	g_j =  1;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MIN)
			g_table[g_i - 1][g_j] = MAX;
		g_j++;
	}
	g_i = 0;
	g_j = 1;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MIN && g_table[ROW -1][g_j] == 2)
			g_table[g_i + 4][g_j] = MIN + 2;

		if (g_table[g_i][g_j] ==MIN && g_table[ROW - 1][g_j] == 3)
		{
			g_table[g_i + 4][g_i] = MIN + 1;
			g_table[g_i + 3][g_i] = MIN + 2;
		}
		if (g_table[g_i][g_j] == 2 && g_table[ROW -1][g_j] == MIN)
			g_table[g_i + 1][g_j] = MIN + 2;
		if (g_table[g_i][g_j] == 3 && g_table[ROW - 1][g_j] == MIN)
		{
			g_table[g_i + 1][g_i] = MIN + 1;
			g_table[g_i + 2][g_i] = MIN + 2;
		}
		g_j++;
	}

}

void	lookup_min_in_row(void)
{
	g_i = 1;
	g_j = 0;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MIN)
			g_table[g_i][g_j + 1] = MAX;
		g_i++;
	}
	g_i = 1;
	g_j = COLUMN - 1;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MIN)
			g_table[g_i][g_j - 1] = MAX;
		g_i++;
	}
	g_i = 1;
	g_j = 0;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MIN && g_table[g_i][COLUMN - 1] == 2)
			g_table[g_i][g_j + 4] = MIN + 2;

		if (g_table[g_i][g_j] == MIN && g_table[g_i][COLUMN - 1] == 3)
		{
			g_table[g_i][g_i + 4] = MIN + 1;
			g_table[g_i][g_i + 3] = MIN + 2;
		}
		if (g_table[g_i][g_j] == 2 && g_table[g_i][COLUMN - 1] == MIN)
			g_table[g_i][g_j + 1] = MIN + 2;
		if (g_table[g_i][g_j] == 3 && g_table[g_i][COLUMN - 1] == MIN)
		{
			g_table[g_i][g_i + 1] = MIN + 1;
			g_table[g_i][g_i + 2] = MIN + 2;
		}
		g_i++;
	}
}

void	lookup_max_in_col(void)
{
	g_i = 0;
	g_j = 1;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MAX)
		{
			g_table[g_i + 1][g_j] = MIN;
			g_table[g_i + 2][g_j] = MIN + 1;
			g_table[g_i + 3][g_j] = MIN + 2;
		}
		g_j++;
	}
	g_i = ROW - 1;
	g_j =  1;
	while (g_j < COLUMN)
	{
		if (g_table[g_i][g_j] == MAX)
		{
			g_table[g_i - 1][g_j] = MIN;
			g_table[g_i - 2][g_j] = MIN + 1;
			g_table[g_i - 3][g_j] = MIN + 2;
		}
		g_j++;
	}
}

void	lookup_max_in_row(void)
{
	g_i = 1;
	g_j = 0;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MAX)
		{	
			g_table[g_i][g_j + 1] = MIN;
			g_table[g_i][g_j + 2] = MIN + 1;
			g_table[g_i][g_j + 3] = MIN + 2;
		}
		g_i++;
	}
	g_i = 1;
	g_j = COLUMN - 1;
	while (g_i < ROW)
	{
		if (g_table[g_i][g_j] == MAX)
		{
			g_table[g_i][g_j - 1] = MIN;
			g_table[g_i][g_j - 2] = MIN + 1;
			g_table[g_i][g_j - 3] = MIN + 2;
		}
		g_i++;
	}
}

void	lookup_two_in_col(void)
{
	g_i = 0;
	g_j = 1;
		while ( g_j < COLUMN)
		{
			{
				if (g_table[g_i][g_j] == 2 && g_table[ROW - 1][g_j] == 1)
				{
					g_table[g_i + 4][g_j] = MAX;
				    g_table[g_i + 1][g_j] = MIN + 2;
					if (g_table[g_i + 2][g_j] == MIN + 1)
						g_table[g_i + 3][g_j] = MIN;
					else
						g_table[g_i + 2][g_j] = MIN;
					
													}
				if (g_table[g_i][g_j] == 1 && g_table[ROW - 1][g_j] == 2)
				{
					g_table[g_i + 1][g_j] = MAX;
					g_table[g_i + 4][g_j] = MIN + 2 ;
					if(g_table[g_i + 2][g_j] == MIN +1)
						g_table[g_i + 3][g_j] = MIN;
					else
						g_table[g_i + 2][g_j] = MIN;
				}
			
				if (g_table[g_i][g_j] == 2 && g_table[ROW - 1][g_j] == 2)
				{
					
						if (g_table[g_i + 2][g_j] ==  MAX || g_table[g_i+3][g_j] == MIN)
					{	
						g_table[g_i + 1][g_j] = MIN + 1;
						g_table[g_i + 4][g_j] = MIN + 2;
						if (check_col(g_j))
						{
							g_table[g_i + 1][g_j] = MIN + 2;
							g_table[g_i + 4][g_i] = MIN + 1;
							g_error = 0;
						}
							
						
					}
				}
				if (g_table[g_i][g_j] == 2 && g_table[ROW - 1][g_j] == 3)
				{
					g_table[g_i + 2][g_j] = MAX;
			
					if (g_table[g_i + 1][g_j] == MIN)
					{
						g_table[g_i + 3][g_j] = MIN + 2;
						g_table[g_i + 4][g_j] = MIN + 1;
					}
				}
			}	
			g_j++;
		}
}

void	lookup_two_in_row(void)
{
	g_i = 1;
	g_j = 0;
	while (g_i < ROW)
	{
//		while ( g_j < COLUMN)
		//		if ( g_j == 0 || g_j == COLUMN -1)
				
				if (g_table[g_i][g_j] == 2 && g_table[g_i][COLUMN -1] == 1)
				{
					g_table[g_i][g_j + 1] = MIN + 2;
					g_table[g_i][g_j + 4] = MAX;
				
				}
				if (g_table[g_i][g_j] == 1 && g_table[g_i][COLUMN -1] == 2)
				{
					g_table[g_i][g_j + 1] =  MAX;
					g_table[g_i][g_j + 4] = MIN + 2;

				}


				if (g_table[g_i][g_j] == 2 && g_table[g_i][COLUMN -1] == 2)
				{
					if (g_table[g_i][g_j + 2] ==  MAX || g_table[g_i][g_j + 3] == MIN)
					{
						g_table[g_i][g_j + 1] = MIN + 1;
						g_table[g_i][g_j + 4] = MIN + 2;
						if(check_row(g_i))
						{	
							g_table[g_i][g_j + 1] = MIN + 2;
							g_table[g_i][g_j + 4] = MIN + 1;
							g_error = 0;
						}
					}
		/*			
		 *			if (g_table[g_i][g_j+4] == MIN + 2)
							g_table[g_i][g_j + 1] =  MIN + 1;
						if (g_table[g_i][g_j + 4] == MIN + 1) 
							g_table[g_i][g_j + 1] = MIN + 2;
					}
					if (g_table[g_i][g_j + 1] == MIN + 1)
						g_table[g_i][g_i + 2] = MAX;
					*/
				}
				if (g_table[g_i][g_j] == 2 && g_table[g_i][COLUMN -1] == 3)
				{
					g_table[g_i][g_j + 2] = MAX;
					if (g_table[g_i][g_j + 1] == MIN)
					{	
						g_table[g_i][g_j + 3 ] = MIN + 2;
						g_table[g_i][g_j + 4] = MIN + 1;
					}
				}
				if (g_table[g_i][g_j] == 3 && g_table[g_i][COLUMN -1] == 2)
				{
					g_table[g_i][g_j + 3] = MAX;
					if (g_table[g_i][g_j + 1] == MIN)
					{
						g_table[g_i][g_j + 2] = MIN + 2;
						g_table[g_i][g_j + 4] = MIN + 1;
					}
				}

//		g_j++;
	
//		g_j = 0;i
		g_i++;
	}
}

int		check_row(int row)
{	
	if ( g_table[row][1] != g_table[row][2] && g_table[row][1] != g_table[row][3] && g_table[row][1] != g_table[row][4])
		return (0);
/*	if (row == 2 && g_table[row][1] != g_table[row - 1][1] && g_table[row][1] != g_table[row + 1][1] && g_table[row][1] != g_table[row + 2][1])
		return (0);
	if (row == 3 && g_table[row][1] != g_table[row - 2][1] && g_table[row][1] != g_table[row - 1][1] && g_table[row][1] != g_table[row + 1][1])
		return (0);
	if (row == 4 && g_table[row][1] != g_table[row - 3][1] && g_table[row][1] != g_table[row - 2][1] && g_table[row][1] != g_table[row -1][1])
		return (0); */
	return (1);
}

int		check_col(int col)
{
	if ( g_table[1][col] != g_table[2][col] && g_table[1][col] != g_table[3][col] && g_table[1][col] != g_table[4][col])
		return (0);
/*	if (col == 2 && g_table[1][col] != g_table[1][col - 1] && g_table[1][col] != g_table[1][col + 1] && g_table[1][col] != g_table[1][col + 2])
		return (0);
	if (col == 3 && g_table[1][col] != g_table[1][col - 2] && g_table[1][col] != g_table[1][col - 1] && g_table[1][col] != g_table[1][col + 1])
		return (0);
	if (col == 4 && g_table[1][col] != g_table[1][col - 3] && g_table[1][col] != g_table[1][col - 2] && g_table[1][col] != g_table[1][col - 1])
		return (0);*/
	return (1);
}
void	check_for_rest(void)
{
	int sum;
	int i;
	int j;
	char c;
	sum = 0; 
	i = 0;
	j = 0;	
	g_i = 1;
	g_j = 1;
	while(g_i < ROW - 1)
	{
		while(g_j < COLUMN -1)
		{	
			sum  += g_table[g_i][g_j];
			if (g_table[g_i][g_j] == 0)
			{
				i = g_i;
				j = g_j;
			}
			g_j++;
		}
		g_j = 1;
		g_i++;
		if ( i != 0 && j != 0)
			g_table[i][j] = g_sum - sum;
		sum = 0;
		i = 0;
		j = 0;
	}
}

void	lookup_three_in_col(void)
{
	g_i = 0;
	g_j = 1;
//	while (g_i < ROW)
	
		while ( g_j < COLUMN)
		{
		
				if (g_table[g_i][g_j] == 3 && g_table[ROW - 1][g_j] == 1)
				{
					g_table[g_i + 4][g_j] = MAX;
					if (g_table[g_i + 1][g_j] == MIN + 1)
					{
						g_table[g_i + 3][g_j] = MIN + 2;
						g_table[g_i + 2][g_j] = MIN;
						if(check_col(g_j))
						{
							g_table[g_i + 3][g_j] = MIN;
							g_table[g_i + 2][g_j] = MIN +2;
						}
					}
				}
				if (g_table[g_i][g_j] == 1 && g_table[ROW - 1][g_j] == 3)
				{
					g_table[g_i + 1][g_j] = MAX;
					if (g_table[g_i + 4][g_j] == MIN + 1)
					{
						g_table[g_i + 2][g_j] = MIN;
						g_table[g_i + 3][g_j] = MIN + 2;
						if (check_col(g_j))
						{
							g_table[g_i + 3][g_j] = MIN;
							g_table[g_i + 2][g_j] = MIN + 2;
						}
					}
				}
				if (g_table[g_i][g_j] == 3 && g_table[ROW - 1][g_j] == 2)
				{
					g_table[g_i + 3][g_j] = MAX;

					if (g_table[g_i + 1][g_j] ==  MIN + 1)
					{
						g_table[g_i + 2][g_j] = MIN + 2;
						g_table[g_i + 4][g_j] = MIN ;
					}
					else if (g_table[g_i + 1][g_j] == MIN)

					{
						g_table[g_i + 2][g_j] =  MIN + 1;
						g_table[g_i + 4][g_j] = MIN + 2;
					}
				}
				if (g_table[g_i][g_j] == 2 && g_table[ROW - 1][g_j] == 3)
				{
					g_table[g_i + 2 ][g_j] = MAX;

					if (g_table[g_i + 1][g_j] ==  MIN + 1)
					{
						g_table[g_i + 3][g_j] = MIN + 2;
						g_table[g_i + 4][g_j] = MIN ;
					}
					else if (g_table[g_i + 1][g_j] == MIN)

					{
						g_table[g_i + 3][g_j] =  MIN + 2;
						g_table[g_i + 4][g_j] = MIN + 1;
					}
				}
			g_j++;
		}
//		g_i++;
	
}

void	lookup_three_in_row(void)
{
	g_i = 1;
	g_j = 1;
	while (g_i < ROW)
	{
				if (g_table[g_i][g_j] == 3 && g_table[g_i][COLUMN -1] == 1)
				{
					g_table[g_i][g_j+ 4] = MAX;
					if (g_table[g_i][g_j + 1] == MIN + 1 || g_table[g_i][g_j + 2] == MIN +1)
					{
						g_table[g_i][g_j + 2] = MIN + 2;
						g_table[g_i][g_j + 3] = MIN;
						if(check_row(g_i))
						{
							g_table[g_i][g_j + 2] = MIN;
							g_table[g_i][g_j + 3] = MIN + 2;
						}
					}
				}
				if (g_table[g_i][g_j] == 1 && g_table[ROW - 1][g_j] == 3)
				{
					g_table[g_i][g_j+ 1] = MAX;
					if (g_table[g_i][g_j + 4] == MIN + 1 || g_table[g_i][g_j + 3] == MIN +1)
					{
						g_table[g_i][g_j + 3] = MIN + 2;
						g_table[g_i][g_j + 2] = MIN;
						if(check_row(g_i))
						{
							g_table[g_i][g_j + 3] = MIN;
							g_table[g_i][g_j + 2] = MIN + 2;
						}
					}
				}
				if (g_table[g_i][g_j] == 3 && g_table[g_i][COLUMN -1] == 2)
				{
					g_table[g_i][g_j + 3] = MAX;
					g_table[g_i][g_j + 2] =  MIN + 2;
					g_table[g_i][g_j + 1] = MIN + 1;
					g_table[g_i][g_j + 4] = MIN ;
					if(check_col(4))
					{
						g_table[g_i][g_j + 1] = MIN;
						g_table[g_i][g_j + 4] = MIN + 1;
					}
				}
				if (g_table[g_i][g_j] == 2 && g_table[ROW - 1][g_j] == 3)
				{
					g_table[g_i][g_j + 1] = MIN;
					g_table[g_i][g_j + 2] = MAX;
					g_table[g_i][g_j + 3] =  MIN + 2;
					g_table[g_i][g_j + 4] = MIN + 1;
					if (check_col(4))
					{
						g_table[g_i][g_j + 1] = MIN + 1;
						g_table[g_i][g_j + 4] = MIN ;
					}
				}


			g_i++;
	}
}

void	finalize(void)
{
	g_i = 1;
	g_j = 1;
	g_error= 0;
	while (g_i < ROW - 1)
	{
		while (g_j < COLUMN -1)
		{
			if(g_table[g_i][g_j] < MIN || g_table[g_i][g_j] > MAX)
				g_error++;
			g_j++;
		}
		g_j = 1;
		g_i++;
	}
	print_error();
}

void	show(void)
{
	char num;

	g_i = 1;
	g_j	= 1;
	while (g_i < ROW -1)
	{
		num = '0' + g_table[g_i][g_j];
		write(1, &num, 1);
		write(1, "	",1);
		g_j++;
		if (g_j % (COLUMN -2) == 0)
		{	
			write(1, "\n", 1);
			g_i++;
			g_j = 1;
		}
	}
}

int main(int argc, char ** argv)
{
	int k;
	char *tab;
	
	k = 0;
	tab = & argv[1][k];
	find_int(tab);
	
	show();
	int i;
	int j;
	i = 0;
	j = 0;
	while (i < ROW)
	{
		free(g_table[i]);
		i++;
	}
	return (0);
}
	   	
