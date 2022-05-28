/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_mapstring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msnow-be <msnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:21:26 by msnow-be          #+#    #+#             */
/*   Updated: 2019/02/06 15:02:54 by msnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_collect_mapstring(char *s1, char *s2)
{
	char	*result;
	char	*temp;

	temp = ft_strjoin(s1, "\n");
	free(s1);
	result = ft_strjoin(temp, s2);
	free(temp);
	return (result);
}
