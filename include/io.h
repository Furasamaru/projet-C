#ifndef IO_H
#define IO_H

#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"
#include "style.h"

// Menu principal
void show_menu();

// Menu de modification
void show_mmenu();

// Menu de modification de
void show_m1menu();

void error_message();

/**
 * @brief all responses regarding the line in the different menus
 */
void no_line();
void added_line();
void relocated_line();
void rescaled_line();
void recolored_line();

/**
 * @brief all responses regarding the rectangle in the different menus
 */
void no_rect();
void added_rect();
void relocated_rect();
void rescaled_rect();
void recolored_rect();

/**
 * @brief all responses regarding the circle in the different menus
 */
void no_circle();
void added_circle();
void relocated_circle();
void rescaled_circle();
void recolored_circle();

/**
 * @brief all responses regarding the ellipse in the different menus
 */
void no_ellipse();
void added_ellipse();
void relocated_ellipse();
void rescaled_ellipse();
void recolored_ellipse();

char press_enter();

// Fonction pour saisir un style
Style *input_style();

// Fonctions pour saisir les différentes formes
Line *input_line(Style *style);
Rect *input_rect(Style *style);
Circle *input_circle(Style *style);
Ellip *input_ellip(Style *style);

#endif
