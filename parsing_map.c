/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:41:30 by shifterpro        #+#    #+#             */
/*   Updated: 2024/03/05 16:45:53 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

// Vérifie si la map est bien entourée de murs '1'
// D'abbord toute la première colonne, puis la dernière
// Appel wall_utils pour vérifier la première et dernière ligne
int	ft_wall(t_parse *parse)
{
	int	i;

	i = 0;
	while (i < parse->nb_line)
	{
		if (parse->map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < parse->nb_line)
	{
		if (parse->map[i][parse->sizeline - 1] != '1')
			return (1);
		i++;
	}
	if (ft_wall_utils(parse->map[0]) == 1)
		return (1);
	if (ft_wall_utils(parse->map[parse->nb_line - 1]) == 1)
		return (1);
	return (0);
}

// Si ft_start renvoie 1, alors on est sur le point de départ du perso,
// on copie '0' à la place
// Si c'est un espace on copie '1' à la place, sinon on copie str[j]
// On remplit le reste de la ligne par des '1'
int	ft_copy_map(char *str, t_parse *parse)
{
	static int	i = 0;
	int			j;

	j = 0;
	parse->map[i] = NULL;
	if (!(parse->map[i] = malloc(sizeof(char) * parse->size_line + 1)))
		return (0);
	while (str[j])
	{
		if (ft_start(str[j], parse, i, j) == 1)
			parse->map[i][j] = '0';
		else if (str[j] == ' ')
			parse->map[i][j] = '1';
		else
			parse->map[i][j] = str[j];
		j++;
	}
	while (j <= (parse->size_line - 1))
	{
		parse->map[i][j] = '1';
		j++;
	}
	parse->map[i][j] = '\0';
	i++;
	return (0);
}

// Vérifie qu'il y a un '1' ou un '0', qu'on est dans la map
// Vérifie qu'il n'y a que des caractères autorisés, sinon
// insidemap pour savoir si on est dans la map, si oui
// wrongcharmap = 2 et on return 0 et on peut mettre dans ta partie des gestions
// d'erreur que ça veut dire qu'il y a un caractère non valide dans la map
int	ft_is_map(char *str, t_parse *parse)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1 || ft_charinstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1'
				&& str[i] != '2' && str[i] != 'N' && str[i] != 'S'
				&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
				&& str[i] != '\t')
			{
				if (parse->insidemap == 1)
					parse->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

// Vérifie si la ligne str est une ligne valide de la map
// Met à jour les valeurs de nb_line et sizeline
void	ft_map(char *str, t_parse *parse)
{
	int		i;
	static int	snb_line = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, parse) == 1)
	{
		if (parse->f == -1 || parse->c == -1 || parse->no == NULL
			|| parse->so == NULL || parse->we == NULL
			|| parse->ea == NULL || parse->sp == NULL)
			return (); //error
		if ((i = ft_strlen(str)) > ssizeline)
			ssizeline = i;
		snb_line = snb_line + 1;
	}
	parse->nb_line = snb_line;
	parse->sizeline = ssizeline;
}
