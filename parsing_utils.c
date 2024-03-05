/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:10:35 by shifterpro        #+#    #+#             */
/*   Updated: 2024/03/05 16:29:30 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

// Compte après avoir trouvé un '.'
int	ft_strlen2(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '.')
		i++;
	while (str[i])
	{
		i++;
		j++;
	}
	return (j);
}

// Vérifie que le char c est présent dans la chaîne str
int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// Stocke la valeur des coordonnées de départ du joueur
int	ft_start(char c, t_parse *parse, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		parse->start = c;
		parse->dx = i;
		parse->dy = j;
		return (1);
	}
	return (0);
}

// Vérifie que c'est bien que des '1'
int ft_wall_utils(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// Elle il faudrait l'appeler au début dans le main puis appeler ft_cub
void	ft_init(t_parse *parse)
{
	parse->no = NULL;
	parse->so = NULL;
	parse->ea = NULL;
	parse->we = NULL;
	parse->sp = NULL;
	parse->f = -1;
	parse->c = -1;
	parse->rx = 0;
	parse->ry = 0;
	parse->nb_line = 0;
	parse->sizeline = 0;
	parse->map = NULL;
	parse->dx = 0;
	parse->dy = 0;
	parse->tot = 0;
	parse->count = 0;
	parse->wrongcharmap = 0;
	parse->empty_line = 0;
	ft_init_more(parse);
}
