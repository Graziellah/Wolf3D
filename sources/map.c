/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 06:00:27 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/16 19:00:22 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		init_pos(t_env *e)
{
	e->posx = 4.5;
	e->posy = 8.5;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->time = 0;
	e->oldtime = 0;
	e->exit = 1;
	e->map_lenght = 15;
	e->map_hight = 15;
	e->movespeed = 0;
	e->rotspeed = 0;
	e->light = 0;
	e->terminer = 1;
}

t_env			ft_init_env(SDL_Window *fenetre)
{
	t_env	e;

	if (fenetre == NULL)
		SDL_Quit();
	e.renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC);
	if (e.renderer == 0)
		SDL_Quit();
	e.texture = SDL_CreateTexture(e.renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	SDL_SetRenderDrawColor(e.renderer, 0, 0, 0, 255);
	if (e.texture == NULL)
		SDL_Quit();
	SDL_RenderClear(e.renderer);
	init_pos(&e);
	e.pixel = malloc(sizeof(unsigned int) * WIDTH * HEIGHT);
	ft_bzero(e.pixel, WIDTH * HEIGHT * sizeof(Uint32));
	return (e);
}
