/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcoetzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:30:22 by kcoetzee          #+#    #+#             */
/*   Updated: 2017/06/28 14:35:19 by kcoetzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct	s_vertex
{
	int x;
	int y;
	int z;
}				t_vertex;

typedef struct	s_edge
{
	t_vertex	point1;
	t_vertex	point2;
}				t_edge;

t_edge		*create_edge(t_vertex *p1, t_vertex *p2)
{
	t_edge *edge;

	edge = (t_edge*)malloc(sizeof(t_edge));
	edge->point1.x = p1->x;
	edge->point1.y = p1->y;
	edge->point1.z = p1->z;
	edge->point2.x = p2->x;
	edge->point2.y = p2->y;
	edge->point2.z = p2->z;

	return (edge);
 }	

t_vertex	*create_vertex(int _x, int _y, int _z)
{
	t_vertex *vertex;

	vertex = (t_vertex*)malloc(sizeof(t_vertex));
	vertex->x = _x;
	vertex->y = _y;
	vertex->z = _z;

	return (vertex);
}

#include "mlx.h"

void	draw_points(void *mlx, void *win,  t_vertex *points, int num_points)
{
	int i = 0;
	
	while (i < num_points)
	{
		mlx_pixel_put(mlx, win, points[i].x + 200, points[i].y + 200, 0x00FFFFFF);
		i++;	
	}
}

void	draw_line(t_vertex *point1, t_vertex *point2)
{
	
}

int main()
{
	void *mlx;
	void *win;
	int i;

	i = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx");
	// Creating 8 points/ vertices
	t_vertex *point[8];
	point[0] = create_vertex(-100, -100, -100);
	point[1] = create_vertex(-100, -100, 100);
	point[2] = create_vertex(-100, 100, -100);
	point[3] = create_vertex(-100, 100, 100);
	point[4] = create_vertex(100, -100, -100);
	point[5] = create_vertex(100, -100, 100);
	point[6] = create_vertex(100, 100, -100);
	point[7] = create_vertex(100, 100, 100);

	// Draw the points
	// draw_points(mlx, win, (point[0]), 8);
	while (i < 8)
	{
		mlx_pixel_put(mlx, win, point[i]->x + 200, point[i]->y + 200, 0x00FFFFFF);
		i++;	
	}

	// Creating edges for all the points
	t_edge	*edge[12];
	edge[0] = create_edge(point[0], point[1]);
	edge[1] = create_edge(point[1], point[3]);
	edge[2] = create_edge(point[3], point[2]);
	edge[3] = create_edge(point[2], point[0]);
	edge[4] = create_edge(point[4], point[5]);
	edge[5] = create_edge(point[5], point[7]);
	edge[6] = create_edge(point[7], point[6]);
	edge[7] = create_edge(point[6], point[4]);
	edge[8] = create_edge(point[0], point[4]);
	edge[9] = create_edge(point[1], point[5]);
	edge[10] = create_edge(point[2], point[6]);
	edge[11] = create_edge(point[3], point[7]);
	
	i = 0;
	// draw the edges
	while (i < 12)
	{
		
	}
	mlx_loop(mlx);
}
