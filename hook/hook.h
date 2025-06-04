/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 20:13:33 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/04 22:36:01 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "../types.h"
# include "../free/free.h"
# include "../vec/vec_utils.h"
# include "../print/print.h"
# include "../minilibx-linux/mlx.h"

int	x_hook(t_scene *data);
int	key_hook(int keycode, t_scene *data);

#endif