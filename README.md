<h1 align="center">
  <img src="https://iili.io/2odPQgn.png" alt="gnl header krub" width="1200" height="auto" style="align: bottom;"> 
</h1>

## Descripción

Este proyecto consiste en desarrollar una función personalizada, `get_next_line(fd)`, que se encarga de leer una línea de texto desde un file descriptor de una forma eficiente. Como `ft_printf()`, también es una parte integral de la librería que estamos creando en 42, diseñada para proporcionar una serie de funciones de utilidad que facilitan el desarrollo de programas en C. Al igual que `ft_printf()` y las demás, está diseñada para ser modular y fácilmente integrable en proyectos de C, utilizándola como herramienta (función) según la necesidad del propio proyecto.

🇬🇧 [Read in English](README_EN.md)

## Características Principales

La programación de `get_next_line(fd)` implica el manejo de un file descriptor proporcionado por nosotros, en el que leemos línea a línea mediante la llamada repetida de la función, en un bucle. La función debe retornar con cada llamada la nueva línea que se acaba de leer (salto de línea incluido “\n”). Si no hay nada más que leer o ha ocurrido algún error, deberá devolver NULL. También debe leer desde `stdin` (standard input). Todo esto hay que manejarlo correctamente, permitiendo en última instancia leer archivos grandes sin leerlo todo de una vez en memoria.

## Archivos del Proyecto

- **get_next_line.c**: Contiene la función principal del programa, además de las auxiliares de este.
- **get_next_line_utils.c**: Contiene las funciones que ayudan a la consecución de la nueva línea.
- **get_next_line.h**: Es el header. Contiene todas las funciones, librerías y macros necesarios en el programa.
- **get_next_line_bonus.c**: Casi mismo código que sin bonus, solo cambiada una parte para cumplir con el bonus.
- **get_next_line_utils_bonus.c**: Igual. Casi mismo código que sin bonus, solo cambiada una parte para cumplir con el bonus. En este caso, es el mismo.
- **get_next_line_bonus.h**: También es el header pero del bonus. Mismo código pero con un macro añadido (MAX_FD).

## Bonus

Consiste en hacer nuestro programa capaz de gestionar varios file descriptors a la vez sin perder el hilo de la lectura en cada uno de los fd enviados. Simplemente hay que hacer la estática doble puntero, manejándola adecuadamente.
