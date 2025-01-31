#include "../../include/cub3d.h"
#include "dhook.h"
#include "../draw/draw.h"

void	dh_rotation_left(t_data *data, t_engine *engine)
{
	(void)data;
	engine->player_angle -= 0.05;
	if (engine->player_angle < 0)
		engine->player_angle += 2 * M_PI;
	engine->pdx = cos(engine->player_angle) * 5;
	engine->pdy = sin(engine->player_angle) * 5;
}

void	dh_rotation_right(t_data *data, t_engine *engine)
{
	(void)data;
	engine->player_angle += 0.05;
	if (engine->player_angle > 2 * M_PI)
		engine->player_angle -= 2 * M_PI;
	engine->pdx = cos(engine->player_angle) * 5;
	engine->pdy = sin(engine->player_angle) * 5;
}

void	dh_rotation_minimap_left(t_data *data, t_minimap *minimap)
{
	(void)data;
	minimap->player_angle -= 0.05;
}

void	dh_rotation_minimap_right(t_data *data, t_minimap *minimap)
{
	(void)data;
	minimap->player_angle += 0.05;
}
