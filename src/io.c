#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

void show_menu()
{
    system("clear");
    printf("=== SVG Shape Creator ===\n");
    printf("1. Line\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Ellipse\n");
    printf("5. modify a shape\n");
    printf("6. Quit\n");
}

void show_mmenu()
{
    system("clear");
    printf("=== SVG Modification Menu ===\n");
    printf("1. Line\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Ellipse\n");
    printf("5. Return to the main menu\n");
}

void show_m1menu()
{
    system("clear");
    printf("=== SVG Shape Modification Menu ===\n");
    printf("1. Location\n");
    printf("2. Shape\n");
    printf("3. Color\n");
    printf("4. Return to the SVG Modification Menu\n");
}

char press_enter()
{
    printf("Press ENTER to continue : ");
    getchar();
    while (getchar() != '\n')
        ;
}

void error_message()
{
    printf("❌ Error : Please enter a valid answer.\n");
}

void no_line()
{
    printf("⚠️ No line to modify.\n");
}
void added_line()
{
    printf("✅ Line added successfully.\n");
}
void relocated_line()
{
    printf("✅ Line relocated successfully.\n");
}
void rescaled_line()
{
    printf("✅ Line rescaled successfully.\n");
}
void recolored_line()
{
    printf("✅ Line recolored successfully.\n");
}

void no_rect()
{
    printf("⚠️ No rectangle to modify.\n");
}
void added_rect()
{
    printf("✅ Rectangle added successfully.\n");
}
void relocated_rect()
{
    printf("✅ Rectangle relocated successfully.\n");
}
void rescaled_rect()
{
    printf("✅ Rectangle rescaled successfully.\n");
}
void recolored_rect()
{
    printf("✅ Rectangle recolored successfully.\n");
}

void no_circle()
{
    printf("⚠️ No circle to modify.\n");
}
void added_circle()
{
    printf("✅ circle added successfully.\n");
}
void relocated_circle()
{
    printf("✅ circle relocated successfully.\n");
}
void rescaled_circle()
{
    printf("✅ circle rescaled successfully.\n");
}
void recolored_circle()
{
    printf("✅ circle recolored successfully.\n");
}

void no_ellipse()
{
    printf("⚠️ No ellipse to modify.\n");
}
void added_ellipse()
{
    printf("✅ ellipse added successfully.\n");
}
void relocated_ellipse()
{
    printf("✅ ellipse relocated successfully.\n");
}
void rescaled_ellipse()
{
    printf("✅ ellipse rescaled successfully.\n");
}
void recolored_ellipse()
{
    printf("✅ ellipse recolored successfully.\n");
}

Style *input_style()
{
    char fill[50], stroke[50];
    int stroke_width;

    printf("Enter fill color (or 'none'): ");
    scanf("%49s", fill);

    printf("Enter stroke color: ");
    scanf("%49s", stroke);

    printf("Enter stroke width: ");
    scanf("%d", &stroke_width);

    return create_style(fill, stroke, stroke_width);
}

Line *input_line(Style *style)
{
    int x1, y1, x2, y2;
    printf("Enter x1 y1 x2 y2:\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    return create_line(x1, y1, x2, y2, style);
}

Rect *input_rect(Style *style)
{
    int x, y, width, height;
    printf("Enter x y width height:\n");
    scanf("%d %d %d %d", &x, &y, &width, &height);
    return create_rect(x, y, width, height, style);
}

Circle *input_circle(Style *style)
{
    int cx, cy, radius;
    printf("Enter cx cy radius:\n");
    scanf("%d %d %d", &cx, &cy, &radius);
    return create_circle(cx, cy, radius, style);
}

Ellip *input_ellip(Style *style)
{
    int cx, cy, rx, ry;
    printf("Enter cx cy rx ry:\n");
    scanf("%d %d %d %d", &cx, &cy, &rx, &ry);
    return create_ellipse(cx, cy, rx, ry, style);
}