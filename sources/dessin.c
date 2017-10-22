/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:17:14 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/16 17:34:36 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

Uint32		color(Uint8 r, Uint8 g, Uint8 b)
{
	return ((((r << 8) + g) << 8) + b);
}

void		drawskyfloor(t_env *e, int x)
{
	int			i;

	i = 0;
	while (i < HEIGHT / 2)
	{
		if (e->light == 1)
			e->pixel[i * WIDTH + x] = color((2 * i / (HEIGHT / 2)), 128, 255);
		else
			e->pixel[i * WIDTH + x] = color((250 * i / (HEIGHT / 2)), 86, 100);
		i++;
	}
	while (i < HEIGHT)
	{
		if (e->light == 1)
			e->pixel[i * WIDTH + x] = 0x003A9D23;
		else
			e->pixel[i * WIDTH + x] = (0x003A9D23 >> 1) & 8355711;
		i++;
	}
}

void		texture2(t_draw *d, t_wall *w, t_map *map)
{
	d->textnum = 0;
	d->textnum = map->tab[w->mapx][w->mapy] - 1;
	if (w->mvtvertouhorz == 0)
		d->wallx = w->rayposy + w->longueurmur * w->raydiry;
	else
		d->wallx = w->rayposx + w->longueurmur * w->raydirx;
	d->wallx -= (int)d->wallx;
	d->texx = (int)(d->wallx * (double)TEXH);
	if (w->mvtvertouhorz == 0 && w->raydirx > 0)
		d->texx = TEXH - d->texx - 1;
	if (w->mvtvertouhorz == 1 && w->raydiry < 0)
		d->texx = TEXH - d->texx - 1;
	d->y = w->drawstart;
}

t_text		tex_img(void)
{
	t_text		walltex;

	walltex.surface[0] = SDL_LoadBMP("img/wall_mario.bmp");
	walltex.surface[1] = SDL_LoadBMP("img/stone.bmp");
	walltex.surface[2] = SDL_LoadBMP("img/stone_flower.bmp");
	return (walltex);
}

Uint32		get_pixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	else if (bpp == 2)
		return (*(Uint16*)p);
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	else if (bpp == 4)
		return (*(Uint32*)p);
	else
		return (0);
}
