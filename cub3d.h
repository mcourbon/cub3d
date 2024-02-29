/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:58:17 by shifterpro        #+#    #+#             */
/*   Updated: 2024/02/29 17:32:29 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

typedef	struct s_parse
{
	int		dx;
	int		dy;
	int		i;
	int		f;
	int		c;
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	char	*sp;
	char	**map;
	int		nb_line;
	int		sizeline;
	int		count;
	int		count2;
	int		tot;
	int		empty_line;
	int		start;
	int		insidemap;
	t_data	texture[5];
	t_data	data;
}	t_parse;
