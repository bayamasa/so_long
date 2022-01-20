/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:33:09 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/20 21:18:47 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_valid_extension(const char *filepath, const char *ext)
{
	size_t		ext_len;
	size_t		i;
	size_t		j;

	ext_len = ft_strlen(ext);
	i = 0;
	j = 0;
	if (ft_strlen(filepath) == ext_len)
		return (false);
	while (filepath[i] != '\0')
		i++;
	while (j < ext_len)
	{
		i--;
		j++;
	}
	if (ft_strncmp(filepath + i, ext, ext_len))
		return (false);
	return (true);
}

void	check_args(int argc, char *argv[], char **filepath)
{
	const char	*ext;

	ext = BER_EXTENSION;
	if (argc != 2)
		abort_sl_with_msg(NULL, NULL, INVALID_ARGS_NUM);
	if (!is_valid_extension(argv[1], ext))
		abort_sl_with_msg(NULL, NULL, INVALID_FILENAME);
	*filepath = argv[1];
	return ;
}