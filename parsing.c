/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:24:36 by shifterpro        #+#    #+#             */
/*   Updated: 2024/03/05 16:52:53 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

// get next line stocké dans str
// check de lignes vides dans le fichier
// empty_line dans gestion d'erreur -> présence de ligne vide
// on check si on est bien dans la map, on copie la map
// on vérifie les murs aussi 
int	ft_parsing_map(char *file, t_parse *parse)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	fd = open(file, O_RDONLY);
	if (!(parse->map = malloc(sizeof(char *) * parse->nb_line)))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, parse);
		if (parse->insidemap == 1 && ft_empty_line(str) == 0
			&& parse->count < parse->nb_line)
			parse->empty_line = 1;
		if ((parse->insidemap = ft_is_map(str, parse)) == 1)
		{
			parse->count++;
			ft_copy_map(str, parse);
		}
		free(str);
	}
	close(fd);
	ft_wall(parse);
	return (0);
}

// Fonction n°2, check que c'est bien un fichier et pas un dossier, lis le fichier et appelle les autres fonctions
void	ft_parsing(char *file, t_parse *parse)
{
	int		fd;
	int		ret;
	char	*str;

	ret = 1;
	str = NULL;
	if ((fd = open(file, O_DIRECTORY)) != -1)
		return (); //error c'est un dossier
	if ((fd = open(file, O_RDONLY)) == -1)
		return (); //error
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, parse);
		ft_color_resolution(&str, parse);
		ft_texture(str, parse);
		ft_map(str, parse);
		free(str);
	}
	close(fd);
	if (parse->sizeline == 0 || parse->nb_line == 0)
		return (); //error pas de map
	ft_parsing_map(file, parse);
}

// Fonction n°1, check s'il y a bien un '.' et l'extension cub
int	ft_cub(char *str, t_parse *parse)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			return (); //error pas de .cub
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, parse);
	else
		return (); //error nom de map pas valide
	return (0);
}
