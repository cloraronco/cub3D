#include "../include/cub3d.h"
#include "init/init.h"
#include "draw/draw.h"
#include "dhook/dhook.h"
#include "parsing/parsing.h"
#include "engine/engine.h"
#include "error/error.h"

void	e_set_texture_struct(t_data *data)
{
	data->engine.img_n.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.north_path, &(data->engine.img_n.width),
			&(data->engine.img_n.height));
	data->engine.img_s.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.south_path, &(data->engine.img_s.width),
			&(data->engine.img_s.height));
	data->engine.img_w.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.west_path, &(data->engine.img_w.width),
			&(data->engine.img_w.height));
	data->engine.img_e.data = mlx_xpm_file_to_image(data->window.mlx_ptr,
			data->parsing.east_path, &(data->engine.img_e.width),
			&(data->engine.img_e.height));
}

static int	ft_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	check_name(t_data *data, char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (!av[i - 5] || av[i - 4] != '.' || av[i - 3] != 'c' || av[i - 2] != 'u'
		|| av[i - 1] != 'b')
	{
		error(data, "Wrong map name");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_track	*track;
	t_map	*map;

	track = NULL;
	map = NULL;
	init_data(&data, track, map);
	if (ac != 2 || check_name(&data, av[1]) != 1)
		error(&data, "tu sais pas utiliser le programme");
	init_parsing(&data);
	init_minimap_engine(&data);
	data.ac = ac;
	data.av = av;
	if (!p_parsing(&data, av[1]))
		return (0);
	init_window(&data);
	init_engine(&data);
	p_set_texture_struct(&data.engine, &data);
	draw(&data);
	mlx_hook(data.window.win_ptr, 17, 0, ft_exit, &data);
	mlx_hook(data.window.win_ptr, 02, 1L << 0, dh_keyhook, &data);
	mlx_hook(data.window.win_ptr, 03, 1L << 1, dh_keyrelease, &data);
	mlx_loop_hook(data.window.mlx_ptr, dh_keyloop, &data);
	mlx_loop(data.window.mlx_ptr);
	return (0);
}
