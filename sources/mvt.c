/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:43:24 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/10 15:42:18 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	mvt_up_down(t_env *e, t_map *map, SDL_Event eve)
{
	if (eve.key.keysym.sym == SDLK_UP || eve.key.keysym.sym == SDLK_w)
	{
		if (!map->tab[(int)(e->posx + e->dirx * e->movespeed)][(int)e->posy] ||
				map->tab[(int)(e->posx + e->dirx * e->movespeed)][(int)e->posy]
				== 8)
			e->posx += e->dirx * e->movespeed;
		if (!map->tab[(int)e->posx][(int)(e->posy + e->diry * e->movespeed)] ||
				map->tab[(int)e->posx][(int)(e->posy + e->diry * e->movespeed)]
				== 8)
			e->posy += e->diry * e->movespeed;
	}
	if (eve.key.keysym.sym == SDLK_DOWN || eve.key.keysym.sym == SDLK_e)
	{
		if (!map->tab[(int)(e->posx - e->dirx * e->movespeed)][(int)e->posy])
			e->posx -= e->dirx * e->movespeed;
		if (!map->tab[(int)e->posx][(int)(e->posy - e->diry * e->movespeed)])
			e->posy -= e->diry * e->movespeed;
	}
}

void	mvt_rotate(t_env *e, SDL_Event eve)
{
	double	oldirx;
	double	oldplanex;

	oldirx = e->dirx;
	oldplanex = e->planex;
	if (eve.key.keysym.sym == SDLK_RIGHT || eve.key.keysym.sym == SDLK_f)
	{
		e->dirx = e->dirx * cos(-e->rotspeed) - e->diry * sin(-e->rotspeed);
		e->diry = oldirx * sin(-e->rotspeed) + e->diry * cos(-e->rotspeed);
		e->planex = e->planex * cos(-e->rotspeed)
			- e->planey * sin(-e->rotspeed);
		e->planey = oldplanex * sin(-e->rotspeed)
			+ e->planey * cos(-e->rotspeed);
	}
	if (eve.key.keysym.sym == SDLK_LEFT || eve.key.keysym.sym == SDLK_a)
	{
		e->dirx = e->dirx * cos(e->rotspeed) - e->diry * sin(e->rotspeed);
		e->diry = oldirx * sin(e->rotspeed) + e->diry * cos(e->rotspeed);
		e->planex = e->planex * cos(e->rotspeed) - e->planey * sin(e->rotspeed);
		e->planey = oldplanex * sin(e->rotspeed) + e->planey * cos(e->rotspeed);
	}
}
