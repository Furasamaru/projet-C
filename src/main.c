#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "style.h"
#include "line.h"
#include "rect.h"
#include "circle.h"
#include "ellipse.h"
#include "io.h"
#include "transform.h"

// 🔹 Lecture sécurisée d’un entier
int resp(const char *message)
{
    char ligne[100];
    int valeur;
    char *endptr;

    while (1)
    {
        printf("%s", message);
        if (!fgets(ligne, sizeof(ligne), stdin))
        {
            clearerr(stdin);
            continue;
        }
        ligne[strcspn(ligne, "\n")] = '\0';
        valeur = strtol(ligne, &endptr, 10);
        if (*endptr == '\0')
            return valeur;

        error_message();
    }
}

int main()
{
    int choice = 0, mchoice = 0, m1choice = 0;
    int mainRunning = 1, modifyRunning = 0, modifyShapeRunning = 0;

    // 🔹 Stockage des formes
    Line *lines[100];
    int lineCount = 0;
    Rect *rects[100];
    int rectCount = 0;
    Circle *circles[100];
    int circleCount = 0;
    Ellip *ellipses[100];
    int ellipseCount = 0;

    // 🔹 Préparation du fichier SVG
    system("mkdir -p test/svg_output");
    FILE *f = fopen("test/svg_output/test.svg", "w");
    if (!f)
    {
        perror("fopen");
        return 1;
    }
    fprintf(f, "<svg width=\"500\" height=\"400\" xmlns=\"http://www.w3.org/2000/svg\">\n");

    // 🔹 Boucle principale
    while (mainRunning)
    {
        show_menu();
        choice = resp("Your choice: ");

        switch (choice)
        {
        case 1: // Lignes
        {
            system("clear");
            Style *style = input_style();
            Line *line = input_line(style);
            draw_line(f, line);
            lines[lineCount++] = line; // sauvegarde
            system("clear");
            added_line();
            for (int i = 0; i < lineCount; i++)
            {
                printf("[%d] ", i);
                print_line(lines[i]);
            }
            press_enter();
            break;
        }

        case 2: // Rectangles
        {
            system("clear");
            Style *style = input_style();
            Rect *rect = input_rect(style);
            draw_rect(f, rect);
            rects[rectCount++] = rect;
            system("clear");
            added_rect();
            for (int i = 0; i < rectCount; i++)
            {
                printf("[%d] ", i);
                print_rect(rects[i]);
            }
            press_enter();
            break;
        }

        case 3: // Cercles
        {
            system("clear");
            Style *style = input_style();
            Circle *circle = input_circle(style);
            draw_circle(f, circle);
            circles[circleCount++] = circle;
            system("clear");
            added_circle();
            for (int i = 0; i < circleCount; i++)
            {
                printf("[%d] ", i);
                print_circle(circles[i]);
            }
            press_enter();
            break;
        }

        case 4: // Ellipses
        {
            system("clear");
            Style *style = input_style();
            Ellip *ellip = input_ellip(style);
            draw_ellipse(f, ellip);
            ellipses[ellipseCount++] = ellip;
            system("clear");
            added_ellipse();
            for (int i = 0; i < ellipseCount; i++)
            {
                printf("[%d] ", i);
                print_ellipse(ellipses[i]);
            }
            press_enter();
            break;
        }

        case 5: // 🔸 Menu de modification
        {
            modifyRunning = 1;
            while (modifyRunning)
            {
                show_mmenu();
                mchoice = resp("Choose a form to modify: ");

                switch (mchoice)
                {
                case 1: // 🔹 Modifier une ligne
                    if (lineCount == 0)
                    {
                        system("clear");
                        no_line();
                        press_enter();
                        break;
                    }
                    system("clear");

                    for (int i = 0; i < lineCount; i++)
                    {
                        printf("[%d] ", i);
                        print_line(lines[i]);
                    }

                    int li = resp("Choose which line to modify: ");
                    if (li < 0 || li >= lineCount)
                    {
                        printf("Invalid.\n");
                        break;
                    }

                    modifyShapeRunning = 1;
                    while (modifyShapeRunning)
                    {
                        show_m1menu();
                        m1choice = resp("Your choice: ");
                        switch (m1choice)
                        {
                        case 1:
                        {
                            system("clear");
                            int dx = resp("X new location: ");
                            int dy = resp("Y new location: ");
                            move_line(lines[li], dx, dy);
                            system("clear");
                            relocated_line();
                            for (int i = 0; i < lineCount; i++)
                            {
                                printf("[%d] ", i);
                                print_line(lines[i]);
                            }
                            press_enter();
                            break;
                        }
                        case 2:
                        {
                            system("clear");
                            float factor = resp("New scale: ");
                            rescale_line(lines[li], factor);
                            system("clear");
                            rescaled_line();
                            for (int i = 0; i < lineCount; i++)
                            {
                                printf("[%d] ", i);
                                print_line(lines[i]);
                            }
                            press_enter();
                            break;
                        }
                        case 3:
                        {
                            system("clear");
                            Style *newStyle = input_style();
                            recolor_line(lines[li], newStyle);
                            system("clear");
                            recolored_line();
                            for (int i = 0; i < lineCount; i++)
                            {
                                printf("[%d] ", i);
                                print_line(lines[i]);
                            }
                            press_enter();
                            break;
                        }
                        case 4:
                            modifyShapeRunning = 0;
                            break;
                        default:
                            error_message();
                        }
                    }
                    break;

                case 2: // 🔹 Modifier un rectangle
                    if (rectCount == 0)
                    {
                        system("clear");
                        no_rect();
                        press_enter();
                        break;
                    }
                    system("clear");

                    for (int i = 0; i < rectCount; i++)
                    {
                        printf("[%d] ", i);
                        print_rect(rects[i]);
                    }

                    int ri = resp("Choose which rectangle to modify: ");
                    if (ri < 0 || ri >= rectCount)
                    {
                        printf("Invalid.\n");
                        break;
                    }

                    modifyShapeRunning = 1;
                    while (modifyShapeRunning)
                    {
                        show_m1menu();
                        m1choice = resp("Your choice: ");
                        switch (m1choice)
                        {
                        case 1:
                        {
                            system("clear");
                            int dx = resp("X New Location: ");
                            int dy = resp("Y New Location: ");
                            move_rect(rects[ri], dx, dy);
                            system("clear");
                            relocated_rect();
                            for (int i = 0; i < rectCount; i++)
                            {
                                printf("[%d] ", i);
                                print_rect(rects[i]);
                            }
                            break;
                        }
                        case 2:
                        {
                            system("clear");
                            float factor = resp("New scale: ");
                            rescale_rect(rects[ri], factor);
                            system("clear");
                            rescaled_rect();
                            for (int i = 0; i < rectCount; i++)
                            {
                                printf("[%d] ", i);
                                print_rect(rects[i]);
                            }
                            break;
                        }
                        case 3:
                        {
                            system("clear");
                            Style *newStyle = input_style();
                            recolor_rect(rects[ri], newStyle);
                            system("clear");
                            recolored_rect();
                            for (int i = 0; i < rectCount; i++)
                            {
                                printf("[%d] ", i);
                                print_rect(rects[i]);
                            }
                            break;
                        }
                        case 4:
                            modifyShapeRunning = 0;
                            break;
                        default:
                            error_message();
                        }
                    }
                    break;

                case 3:
                    if (circleCount == 0)
                    {
                        system("clear");
                        no_circle();
                        press_enter();
                        break;
                    }
                    system("clear");

                    for (int i = 0; i < circleCount; i++)
                    {
                        printf("[%d] ", i);
                        print_circle(circles[i]);
                    }

                    int ci = resp("Choose which cercle to modify: ");
                    if (ci < 0 || ci >= circleCount)
                    {
                        printf("Invalid.\n");
                        break;
                    }

                    modifyShapeRunning = 1;
                    while (modifyShapeRunning)
                    {
                        show_m1menu();
                        m1choice = resp("Your choice: ");
                        switch (m1choice)
                        {
                        case 1:
                        {
                            system("clear");
                            int dx = resp("X new location: ");
                            int dy = resp("Y new location: ");
                            move_circle(circles[ci], dx, dy);
                            system("clear");
                            relocated_circle();
                            for (int i = 0; i < circleCount; i++)
                            {
                                printf("[%d] ", i);
                                print_circle(circles[i]);
                            }
                            break;
                        }
                        case 2:
                        {
                            system("clear");
                            float factor = resp("New scale: ");
                            rescale_circle(circles[ci], factor);
                            system("clear");
                            rescaled_circle();
                            for (int i = 0; i < circleCount; i++)
                            {
                                printf("[%d] ", i);
                                print_circle(circles[i]);
                            }
                            break;
                        }
                        case 3:
                        {
                            system("clear");
                            Style *newStyle = input_style();
                            recolor_circle(circles[ci], newStyle);
                            system("clear");
                            recolored_circle();
                            for (int i = 0; i < circleCount; i++)
                            {
                                printf("[%d] ", i);
                                print_circle(circles[i]);
                            }
                            break;
                        }
                        case 4:
                            modifyShapeRunning = 0;
                            break;
                        default:
                            error_message();
                        }
                    }
                    break;

                case 4: // 🔹 Modifier une ellipse
                    if (ellipseCount == 0)
                    {
                        system("clear");
                        no_ellipse();
                        press_enter();
                        break;
                    }
                    system("clear");

                    for (int i = 0; i < ellipseCount; i++)
                    {
                        printf("[%d] ", i);
                        print_ellipse(ellipses[i]);
                    }

                    int ei = resp("Choose which ellipse to modify: ");
                    if (ei < 0 || ei >= ellipseCount)
                    {
                        printf("Invalid.\n");
                        break;
                    }

                    modifyShapeRunning = 1;
                    while (modifyShapeRunning)
                    {
                        show_m1menu();
                        m1choice = resp("Your choice: ");
                        switch (m1choice)
                        {
                        case 1:
                        {
                            system("clear");
                            int dx = resp("X new location: ");
                            int dy = resp("Y new location: ");
                            move_ellipse(ellipses[ei], dx, dy);
                            system("clear");
                            relocated_ellipse();
                            for (int i = 0; i < ellipseCount; i++)
                            {
                                printf("[%d] ", i);
                                print_ellipse(ellipses[i]);
                            }
                            break;
                        }
                        case 2:
                        {
                            system("clear");
                            float factor = resp("New scale: ");
                            rescale_ellipse(ellipses[ei], factor);
                            system("clear");
                            rescaled_ellipse();
                            for (int i = 0; i < ellipseCount; i++)
                            {
                                printf("[%d] ", i);
                                print_ellipse(ellipses[i]);
                            }
                            break;
                        }
                        case 3:
                        {
                            system("clear");
                            Style *newStyle = input_style();
                            recolor_ellipse(ellipses[ei], newStyle);
                            system("clear");
                            recolored_ellipse();
                            for (int i = 0; i < ellipseCount; i++)
                            {
                                printf("[%d] ", i);
                                print_ellipse(ellipses[i]);
                            }
                            break;
                        }
                        case 4:
                            modifyShapeRunning = 0;
                            break;
                        default:
                            error_message();
                        }
                    }
                    break;

                case 5:
                    modifyRunning = 0;
                    break;

                default:
                    error_message();
                }
            }
            break;
        }

        case 6:
            mainRunning = 0;
            break;

        default:
            error_message();
        }
    }

    fprintf(f, "</svg>\n");
    fclose(f);
    printf("✅ SVG generated : test/svg_output/test.svg\n");

    for (int i = 0; i < lineCount; i++)
        free_line(lines[i]);
    for (int i = 0; i < rectCount; i++)
        free_rect(rects[i]);
    for (int i = 0; i < circleCount; i++)
        free_circle(circles[i]);
    for (int i = 0; i < ellipseCount; i++)
        free_ellipse(ellipses[i]);

    return 0;
}
