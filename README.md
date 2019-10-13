# FDF
The basics of graphic programming

To execute the project copy next 4 lines in your shell:

git clone https://github.com/nikGrape/FDF.git<br>
cd FDF<br>
make<br>
./fdf test_maps/42.fdf<br>

The&nbsp&nbspFDF project is oboult to create 3D model from a text map.<br>

Example of map:
<pre>
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
</pre>
Here the numbers are *z* cordinates and plase of a number is *x* and *y* cordinates,<br>
for examle the first 10 has [2:2:10] cordinates.<br><br>
<p>Here is the picture wich the fdf draw ftom the map.<br>
You can move, zoom and rotate it</p>
<img src="https://github.com/nikGrape/FDF/blob/master/Screen%20Shot%202019-10-05%20at%202.38.08%20PM.png" height="50%" width="50%">

<pre>
**	------------------------------------------- How to do -------------------------------------------
**	1. read file
**		- get height(how many lines) of text
**		- get width(how many numbers in line)
**		- allocate memory for **int by using width and height (look your ft_strsplit() )
**		- read file and write number into **int matrix
**				by using ft_strsplit() and atoi()
**	--------------
**	2. drawing line function (google Bresenham algorithm)
**		- find by how much we need to increase x and by how much we need to increase y
**			by using float. Example:
**				x = 2; x1 = 4;
**				y = 2; y1 = 6;
**				steps for x: 2
**				steps for y: 4
**				that means that y should grow 2 times faster than x
**				ewery loop step: y += 1 and x += 0.5
**				after 4 steps x and y will be equal with x1, y1
**
**					real x:y		x:y     pixels				
**			start:		2.0 : 2.0		2:2        .
**			step1:		2.5 : 3.0		2:3        .
**			step2:		3.0 : 4.0		3:4         .
**			step3:		3.5 : 5.0		3:5         .
**			step4:		4.0 : 6.0		4:6          .
**
**				that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
**	--------------
**	3. function which draws lines beetwen every dot
**		- examle:
**				0->		0->		0->		0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		10->            10->            0
**				|		|		|		|
**				
**				0->		0->		0->		0
**			'->' and '|'are lines between dots 
**			every dot has two lines (right and down):	0->
**                                                                      |
**	----------------
**	4. adding 3D
**		- change coordinates by using isometric formulas:
**			x` = (x - y) * cos(angle)
**			y` = (x + y) * sin(angle) - z
**		- x` and y` are coordintes in 3D format (default angle 0.8)
**	----------------
**	5. adding donuses (move, rotation, zoom)
**		- when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
**			call the func. deal_key.
**		- In the deal key func. you have to change some parametrs, clear the window with
**			mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
**	----------------
**	6. error handling
**		- check if argc == 2
**		- check if file exists: if ((fd = open(file_name, O_RDONLY) > 0))
**	----------------
**	7. fix leaks
**		- type leaks a.out or leaks fdf in your shell
</pre><br>
<pre>
**  ------------------------------- resourses --------------------------------
**	--------------- 3D ------------------------------------------
**		x` = (x - y) * cos(angle);
**		y` = (x + y) * sin(angle) - z;
**	-------------------------------------------------------------
** 	------- mlx_function ----------------------------------------
**		void *mlx_ptr;
**		void *win_prt;
**
**		mlx_ptr = mlx_init();
**		win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
**
**		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
**
**		mlx_key_hook(win_ptr, deal_key, NULL);
**		mlx_loop(mlx_ptr);
**	--------------------------------------------------------------
**	------- deal_key prototype -----------------------------------
**		int		deal_key(int key, void *data);
**	--------------------------------------------------------------
**	colors:
**		white = 0xffffff
**		red = 0xe80c0c
**	----------------------------
**	frameworks:
**		-framework OpenGL -framework AppKit
</pre>
