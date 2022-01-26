char	**make_square(int size /* to be define */)
{
	char	**board;
	int		index;

	board = (char **)malloc(sizeof(char **) * size);
	index = 0;
	if (board)
	{
		while (index++ < size)
		{
			board[index] = ft_strnew(size);
			if (board[index] == NULL)
				free(board);
			ft_memset(board[index], '.', size);
		}
	}
	return (board);
}	
