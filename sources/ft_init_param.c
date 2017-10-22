/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghippoda <ghippoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 19:22:37 by ghippoda          #+#    #+#             */
/*   Updated: 2017/05/10 14:51:21 by ghippoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		quit_all(t_env *e, SDL_Window *fenetre)
{
	system("killall afplay");
	SDL_DestroyTexture(e->texture);
	free(e->pixel);
	SDL_DestroyRenderer(e->renderer);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
}

void		init_wall(t_wall *w, t_env *e, int x)
{
	w->touche = 0;
	w->camx = 2 * x / (double)WIDTH - 1;
	w->rayposx = e->posx;
	w->rayposy = e->posy;
	w->raydirx = e->dirx + e->planex * w->camx;
	w->raydiry = e->diry + e->planey * w->camx;
	w->mapx = (int)w->rayposx;
	w->mapy = (int)w->rayposy;
	w->dist2murx = sqrt(1 + (w->raydiry * w->raydiry) /
			(w->raydirx * w->raydirx));
	w->dist2mury = sqrt(1 + (w->raydirx * w->raydirx) /
			(w->raydiry * w->raydiry));
}

void		run_wolf(t_env *e, t_map *map)
{
	run(e, map);
	e->oldtime = e->time;
	e->time = SDL_GetTicks();
	e->frametime = ((e->time - e->oldtime) / 2100.0);
	ft_putstr("FPS:");
	ft_putnbr((int)(1 / e->frametime));
	ft_putstr("\n");
	SDL_RenderCopy(e->renderer, e->texture, NULL, NULL);
	SDL_RenderPresent(e->renderer);
}

void		catch_event(SDL_Event eve, t_env *e, t_map *map)
{
	if (eve.type == SDL_QUIT)
		e->terminer = 0;
	if (eve.key.keysym.sym == SDLK_ESCAPE)
		e->terminer = 0;
	if (eve.key.keysym.sym == SDLK_RIGHT ||
			eve.key.keysym.sym == SDLK_LEFT ||
			eve.key.keysym.sym == SDLK_a ||
			eve.key.keysym.sym == SDLK_f)
		mvt_rotate(e, eve);
	if (eve.key.keysym.sym == SDLK_UP || eve.key.keysym.sym == SDLK_e ||
			eve.key.keysym.sym == SDLK_w ||
			eve.key.keysym.sym == SDLK_DOWN)
		mvt_up_down(e, map, eve);
}

int			ft_init_param(t_map *map)
{
	t_env			e;
	SDL_Window		*fenetre;
	SDL_Event		eve;
	int				son;

	ft_memset(&e, 0, sizeof(t_env));
	son = 1;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		return (0);
	fenetre = SDL_CreateWindow("WOLF3D", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	e = ft_init_env(fenetre);
	system("afplay /Users/ghippoda/Projets/Wolf/son/super_accapella.mp3&");
	while (e.terminer)
	{
		SDL_UpdateTexture(e.texture, NULL, e.pixel, WIDTH * sizeof(Uint32));
		e.movespeed = e.frametime * 5.0;
		e.rotspeed = e.frametime * 3.0;
		while (SDL_PollEvent(&eve))
			catch_event(eve, &e, map);
		run_wolf(&e, map);
	}
	quit_all(&e, fenetre);
	return (0);
}
