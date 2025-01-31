#include "../../include/cub3d.h"
#include "parsing.h"
#include "../error/error.h"

static void	check_left(t_data *data, t_map *map, int checkpoint)
{
	int	i;

	i = checkpoint;
	while (i >= 0 && map[i].stop != 1 && map[checkpoint].y == map[i].y)
	{
		if (map[i].z == WALL)
			return ;
		else if (map[i].z == EMPTY)
			error(data, "MAP OPEN ON LEFT!");
		i--;
	}
	error(data, "MAP OPEN ON THE LEFT !");
}

static void	check_right(t_data *data, t_map *map, int checkpoint)
{
	int	i;

	i = checkpoint;
	while (i >= 0 && map[i].stop != 1 && map[checkpoint].y == map[i].y)
	{
		if (map[i].z == WALL)
			return ;
		else if (map[i].z == EMPTY)
			error(data, "MAP OPEN ON THE RIGHT!");
		i++;
	}
	error(data, "MAP OPEN ONT THE RIGHT !");
}

static void	check_top(t_data *data, t_map *map, int checkpoint)
{
	int	i;

	i = checkpoint;
	while (i >= 0)
	{
		if (map[i].z == WALL && map[i].x == map[checkpoint].x)
			return ;
		else if (map[i].z == EMPTY && map[i].x == map[checkpoint].x)
			error(data, "MAP OPEN ON THE TOP!");
		i--;
	}
	error(data, "MAP OPEN ON THE TOP !");
}

static void	check_bottom(t_data *data, t_map *map, int checkpoint)
{
	int	i;

	i = checkpoint;
	while (i >= 0 && map[i].stop != 1)
	{
		if (map[i].z == WALL && map[i].x == map[checkpoint].x
			&& map[i].stop != 1)
			return ;
		else if (map[i].z == EMPTY && map[i].x == map[checkpoint].x)
			error(data, "MAP OPEN ON THE BOTTOM!");
		i++;
	}
	error(data, "MAP OPEN ON THE BOTTOM !");
}

void	p_check_map(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (!map[i].stop)
	{
		if (map[i].z == FLOOR || map[i].z == WEST
			|| map[i].z == NORTH || map[i].z == SOUTH || map[i].z == EAST)
		{
			check_left(data, map, i);
			check_right(data, map, i);
			check_top(data, map, i);
			check_bottom(data, map, i);
		}
		i++;
	}
}
