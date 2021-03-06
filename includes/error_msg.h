/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:35:58 by mhirabay          #+#    #+#             */
/*   Updated: 2022/01/21 22:00:23 by mhirabay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define INVALID_ARGS_NUM "args must be 2\n"
# define INVALID_FILENAME "filename must be end .ber\n"
# define INVALID_MAP_SIZE "map size too big\n"
# define MAP_SHAPE_ERROR "map must be rectangle\n"
# define TOP_OR_END_ERROR "map's top or end must be wall\n"
# define AREA_WALL_ERROR "map must be surrounded wall\n"
# define AREA_ERROR "map attribute is invalid\n"
# define VALIDATION_ERROR "validation error\n"
# define FILE_NOT_FOUND_ERROR "file is not found\n"
# define INVALID_ATTRIBUTE "map must contain only \"1, 0, P, C, E\"\n"
# define FILE_READ_ERROR "cannot read map file\n"
# define MALLOC_ERROR "malloc error\n"

#endif
