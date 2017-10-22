/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:51:44 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/16 18:43:18 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define HEIGHT 480
# define WIDTH 640
# define TEXH 64
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sdl2/SDL.h>

typedef struct				s_map
{
	int		i;
	int		j;
	int		**tab;
}							t_map;

typedef struct				s_draw
{
	int		textnum;
	double	wallx;
	int		texx;
	int		texy;
	int		y;
	int		d;
}							t_draw;

typedef struct				s_env
{
	double					posx;
	double					posy;
	double					dirx;
	double					diry;
	double					planex;
	double					planey;
	double					time;
	double					oldtime;
	double					frametime;
	double					movespeed;
	double					rotspeed;
	int						exit;
	int						**map_e;
	int						map_lenght;
	int						map_hight;
	SDL_Renderer			*renderer;
	SDL_Texture				*texture;
	Uint32					*pixel;
	int						light;
	int						ton;
	int						terminer;
}							t_env;

typedef struct				s_line
{
	int						x;
	int						start;
	int						end;
}							t_line;

typedef struct				s_color
{
	int						r;
	int						g;
	int						b;
	int						a;
}							t_color;

typedef struct				s_text
{
	SDL_Surface *surface[3];
}							t_text;

typedef struct				s_wall
{
	double		camx;
	double		rayposx;
	double		rayposy;
	double		raydirx;
	double		raydiry;
	double		distmurx;
	double		distmury;
	double		dist2murx;
	double		dist2mury;
	double		longueurmur;
	int			mapx;
	int			mapy;
	int			etapex;
	int			etapey;
	int			touche;
	int			mvtvertouhorz;
	int			hauteurmur;
	int			drawstart;
	int			drawend;
}							t_wall;

int							**ft_creatmap(char **tab, t_map *tmp);
int							ft_init_param(t_map *map);
t_env						ft_init_env(SDL_Window *win);
t_line						creat_coord(int x, int y, int z);
int							**creat_map(int ***map);
t_color						sdl_get_color(int i);
void						mvt_up_down(t_env *e, t_map *map, SDL_Event eve);
void						mvt_rotate(t_env *e, SDL_Event evenement);
void						sdl_pixel_put(t_env *e, int x, int y, t_color *col);
t_text						tex_img(void);
void						run(t_env *e, t_map *map);
void						texture(t_wall *w, t_env *e, t_map *map, int x);
Uint32						get_pixel(SDL_Surface *surface, int x, int y);
void						find_wall(t_wall *w, t_map *map);
void						find_start_end(t_wall *w);
void						wall_distance(t_wall *w);
void						init_wall(t_wall *w, t_env *e, int x);
void						drawskyfloor(t_env *e, int x);
Uint32						couleur(Uint8 r, Uint8 g, Uint8 b);
void						texture2(t_draw *d, t_wall *w, t_map *map);
void						errors(int nb);
#endif
