/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_management.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 16:17:37 by ihering-       #+#    #+#                */
/*   Updated: 2020/02/24 14:07:55 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	void	error_options_two(int id)
{
	if (id == ERROR_INVALIDCH)
		ft_writeincolours("Error: invalid character\n", "red");
	else if (id == ERROR_PARAM)
		ft_printf("\033[31mError: parameter invalid\033[0m\n");
	else if (id == ERROR_INSTRUCTION)
		ft_writeincolours("Error: wrong instruction name.\n", "red");
}

static	void	error_options(int id)
{
	if (id == ERROR_USAGE)
		ft_writeincolours("Usage: ./asm [filename.s]\n", "blue");
	else if (id == ERROR_EXTENSION)
		ft_writeincolours("Error: wrong file extension.\n", "red");
	else if (id == ERROR_FILE)
		ft_writeincolours("Error: can't read file.\n", "red");
	else if (id == ERROR_NAME)
		ft_writeincolours("Error in champion's name.\n", "red");
	else if (id == ERROR_COMMENT)
		ft_writeincolours("Error in comment.\n", "red");
	else if (id == 14)
		ft_printf("\033[31mError: number of parameter invalid\033[0m\n");
	else
		error_options_two(id);
}

void			error_message(int id, char *line)
{
	if (!line)
		error_options(id);
	else
	{
		error_options(id);
		ft_printf("\033[31m\tStatement:\033[0m %s\n", line);
	}
	exit(1);
}
