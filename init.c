/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:19:20 by shifterpro        #+#    #+#             */
/*   Updated: 2024/02/29 17:31:08 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

void	ft_init_more(t_parse *parse)
{
	parse->start = 'x';
	parse->texture[0].img = NULL;
	parse->texture[1].img = NULL;
	parse->texture[2].img = NULL;
	parse->texture[3].img = NULL;
	parse->texture[4].img = NULL;
}

void	ft_atoi3_check(const char *str, t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] = ',')
			j++;
		i++;
	}
	if (j != 2)
		return (); //error
	if (ft_nb_coma(str) != 2)
		return (); //error
}

int	ft_nb_coma(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	return (j);
}

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
			&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}
