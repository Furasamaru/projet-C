#ifndef IO_H
#define IO_H

#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"
#include "style.h"

/**
 * Main Menu
 */
void show_menu();

/**
 * Modification Menu
 */
void show_mmenu();

/**
 * Second Modification Menu
 */
void show_m1menu();

/**
 * Error message function
 */
void error_message();

/**
 * @brief all functions which will give responses regarding the line in the different menus
 */
void no_line();
void added_line();
void relocated_line();
void rescaled_line();
void recolored_line();

/**
 * @brief all functions which will give responses regarding the rectangle in the different menus
 */
void no_rect();
void added_rect();
void relocated_rect();
void rescaled_rect();
void recolored_rect();

/**
 * @brief all functions which will give responses regarding the circle in the different menus
 */
void no_circle();
void added_circle();
void relocated_circle();
void rescaled_circle();
void recolored_circle();

/**
 * @brief all functions which will give responses regarding the ellipse in the different menus
 */
void no_ellipse();
void added_ellipse();
void relocated_ellipse();
void rescaled_ellipse();
void recolored_ellipse();

/**
 * Function to continue (after that the terminal is cleared)
 */
char press_enter();

/**
 * Function to pick a style
 */
Style *input_style();

/**
 * Functions to pick all the different forms/shapes
 */
Line *input_line(Style *style);
Rect *input_rect(Style *style);
Circle *input_circle(Style *style);
Ellip *input_ellip(Style *style);

#endif
