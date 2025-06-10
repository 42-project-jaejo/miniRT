/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaejo <jaejo@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:47:08 by jaejo             #+#    #+#             */
/*   Updated: 2025/06/09 21:39:59 by jaejo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define FALSE 0
# define TRUE 1
# define VEC 2
# define RGB 3
# define O_VEC 4
# define SP 5
# define PL 6
# define CY 7
# define C 8
# define L 9
# define LIGHT_POINT 10
# define EPSILON 1e-6 // 0.000001
# define LUMEN 3
# define KEY_ESC 65307
# define ONE 49
# define TWO 50
# define THREE 51
# define FOUR 52
# define KEY_UP 117
# define KEY_DOWN 100
# define KEY_LEFT 65363
# define KEY_RIGHT 65361
# define KEY_BACK 65362
# define KEY_GO 65364
# define X 120
# define Y 121
# define Z 122

# define M_PI 3.14159265358979323846

# include "./ft_printf/ft_printf.h"

typedef int				t_bool;
typedef int				t_object_type;
typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_vec_point3;
typedef struct s_vec3	t_color3;

typedef struct s_mlx
{
	int					bpp;
	int					endian;
	int					width;
	void				*mlx;
	void				*win;
	void				*img;
	void				*img_addr;
}						t_mlx;

struct					s_vec3
{
	double				x;
	double				y;
	double				z;
};

typedef struct s_ray
{
	t_vec_point3		orig;
	t_vec3				dir;
}						t_ray;

typedef struct s_camera
{
	t_vec_point3		orig;
	double				viewport_h;
	double				viewport_w;
	t_vec3				horizontal;
	t_vec3				vertical;
	t_vec3				cam_dir;
	t_vec3				vec_up;
	double				fov;
	double				focal_len;
	t_vec_point3		left_bottom;
}						t_camera;

typedef struct s_canvas
{
	int					width;
	int					height;
	double				aspect_ratio;
}						t_canvas;

typedef struct s_sphere
{
	t_vec_point3		center;
	double				radius;
	double				radius2;
}						t_sphere;

typedef struct s_plane
{
	t_vec_point3		point;
	t_vec3				normal;
	t_color3			color;
}						t_plane;

typedef struct s_cylinder
{
	t_vec_point3		center;
	t_vec3				normal;
	double				height;
	double				radius;
	double				radius2;
}						t_cylinder;

typedef struct s_hit_record
{
	t_vec_point3		p;
	t_vec3				normal;
	double				tmin;
	double				tmax;
	double				t;
	t_bool				front_face;
	t_color3			albedo;
}						t_hit_record;

typedef struct s_object
{
	t_object_type		type;
	void				*element;
	t_color3			albedo;
	void				*next;
}						t_object;

typedef struct s_light
{
	t_vec_point3		origin;
	t_color3			light_color;
	double				bright_ratio;
}						t_light;

typedef struct s_scene
{
	void				*now;
	char				*rotate_dir;
	char				*object_name;
	t_canvas			canvas;
	t_camera			camera;
	t_object			*world;
	t_object			*light;
	t_color3			ambient;
	t_ray				ray;
	t_hit_record		rec;
	t_mlx				mlx_data;
}						t_scene;

#endif