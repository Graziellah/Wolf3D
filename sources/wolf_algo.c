/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 14:12:54 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/16 17:34:52 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wall_distance(t_wall *w)
{
	if (w->raydirx < 0)
	{
		w->etapex = -1;
		w->distmurx = (w->rayposx - w->mapx) * w->dist2murx;
	}
	else
	{
		w->etapex = 1;
		w->distmurx = (w->mapx + 1.0 - w->rayposx) * w->dist2murx;
	}
	if (w->raydiry < 0)
	{
		w->etapey = -1;
		w->distmury = (w->rayposy - w->mapy) * w->dist2mury;
	}
	else
	{
		w->etapey = 1;
		w->distmury = (w->mapy + 1.0 - w->rayposy) * w->dist2mury;
	}
}

void	find_start_end(t_wall *w)
{
	w->drawstart = 0;
	w->drawend = 0;
	if (w->mvtvertouhorz == 0)
		w->longueurmur = (w->mapx - w->rayposx + (1 - w->etapex) / 2) /
			w->raydirx;
	else
		w->longueurmur = (w->mapy - w->rayposy + (1 - w->etapey) / 2) /
			w->raydiry;
	w->hauteurmur = (int)(HEIGHT / w->longueurmur);
	w->drawstart = -w->hauteurmur / 2 + HEIGHT / 2;
	w->drawend = w->hauteurmur / 2 + HEIGHT / 2;
	if (w->drawstart < 0)
		w->drawstart = 0;
	if (w->drawend >= HEIGHT)
		w->drawend = HEIGHT - 1;
}

void	find_wall(t_wall *w, t_map *map)
{
	while (w->touche == 0)
	{
		if (w->distmurx < w->distmury)
		{
			w->distmurx += w->dist2murx;
			w->mapx += w->etapex;
			w->mvtvertouhorz = 0;
		}
		else
		{
			w->distmury += w->dist2mury;
			w->mapy += w->etapey;
			w->mvtvertouhorz = 1;
		}
		if (map->tab[w->mapx][w->mapy] > 0)
			w->touche = 1;
	}
}

void	texture(t_wall *w, t_env *e, t_map *map, int x)
{
	t_draw		d;
	t_text		texture;
	Uint32		color_tex;

	drawskyfloor(e, x);
	texture = tex_img();
	texture2(&d, w, map);
	while (d.y < w->drawend)
	{
		d.d = d.y * 256 - HEIGHT * 128 + w->hauteurmur * 128;
		d.texy = ((d.d * TEXH) / w->hauteurmur) / 256;
		if (map->tab[w->mapx][w->mapy] == 1)
			color_tex = get_pixel(texture.surface[0], d.texx, d.texy);
		if (map->tab[w->mapx][w->mapy] == 2 || map->tab[w->mapx][w->mapy] == 8)
			color_tex = get_pixel(texture.surface[2], d.texx, d.texy);
		if (map->tab[w->mapx][w->mapy] == 3)
			color_tex = get_pixel(texture.surface[1], d.texx, d.texy);
		d.y++;
		if (w->mvtvertouhorz == 1)
			color_tex = (color_tex >> 1) & 8355711;
		e->pixel[d.y * WIDTH + x] = color_tex;
	}
	SDL_FreeSurface(texture.surface[0]);
	SDL_FreeSurface(texture.surface[1]);
	SDL_FreeSurface(texture.surface[2]);
}

void	run(t_env *e, t_map *map)
{
	t_wall		w;
	int			x;

	x = 0;
	ft_bzero(e->pixel, WIDTH * HEIGHT * sizeof(Uint32));
	if (e->posx > map->i / 2)
		e->light = 1;
	else
		e->light = 0;
	while (x < WIDTH)
	{
		init_wall(&w, e, x);
		wall_distance(&w);
		find_wall(&w, map);
		find_start_end(&w);
		texture(&w, e, map, x);
		x++;
	}
}
