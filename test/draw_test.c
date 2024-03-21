/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:22:09 by Axel              #+#    #+#             */
/*   Updated: 2024/03/20 17:27:13 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define SCREEN_W 600
#define SCREEN_H 600

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define COLOR(r,g,b) create_trgb(0, r, g, b)

char		*map[4] = {"111111111111", "100000000001", "100000000001",
			"111111111111"};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_test
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
}			t_test;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_test *test, int x, int y, int width, int color)
{
	int	i;
	int	j;

	i = x;
	my_mlx_pixel_put(test->img, 0, 0, color);
	if ((x + width > SCREEN_W || x < 0) && (y + width > SCREEN_H || y < 0))
		return ;
	while (i < x + width)
	{
		j = y;
		while (j < y + width)
		{
			mlx_put_image_to_window(test->mlx, test->mlx_win, test->img->img, i,
				j);
			j++;
		}
		i++;
	}
}

void	render_minimap(t_test *test)
{
	int	i;
	int	j;
	int	offset;
	int	start_pos;

	start_pos = 50;
	offset = 20;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				draw_square(test, start_pos + (j * offset), start_pos + (i
						* offset), 20, RED);
			else if (map[i][j] == '0')
				draw_square(test, start_pos + (j * offset), start_pos + (i
						* offset), 20, COLOR(130, 250, 130));
			j++;
		}
		i++;
	}
}

void	test_map(void)
{
	int i, j;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				printf("1");
			else if (map[i][j] == '0')
				printf("0");
			j++;
		}
		printf("\n");
		i++;
	}
}


int	main(void)
{
	 t_test	test;

	test.img = (t_data *)malloc(sizeof(t_data));
	test.mlx = mlx_init();
	test.mlx_win = mlx_new_window(test.mlx, SCREEN_W, SCREEN_H, "test");
	test.img->img = mlx_new_image(test.mlx, SCREEN_W, SCREEN_H);
	test.img->addr = mlx_get_data_addr(test.img->img,
			&test.img->bits_per_pixel, &test.img->line_length, &test.img->endian);
	draw_square(&test, 50, 50, 50, RED);
	render_minimap(&test);
	test_map();
	mlx_loop(test.mlx);
	free(test.img);
}
