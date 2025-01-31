#ifndef DHOOK_H
# define DHOOK_H

int		dh_keyhook(int keycode, t_data *data);
int		check_wall(t_data *data, int posx, int posy, int side);
void	dh_rotation(t_data *data);
void	dh_translation(t_data *data);
void	dh_bonus(t_data *data, int keycode);
void	dh_moove_forward(t_data *data, t_engine *engine);
void	dh_moove_backward(t_data *data, t_engine *engine);
void	dh_moove_right(t_data *data, t_engine *engine);
void	dh_moove_left(t_data *data, t_engine *engine);
void	set_xo_and_yo_for_side_walk(t_engine *engine);
void	dh_rotation_minimap_left(t_data *data, t_minimap *minimap);
void	dh_rotation_minimap_right(t_data *data, t_minimap *minimap);
void	dh_rotation_right(t_data *data, t_engine *engine);
void	dh_rotation_left(t_data *data, t_engine *engine);
int		dh_keyrelease(int keycode, t_data *data);
int		dh_keyloop(t_data *data);

#endif
