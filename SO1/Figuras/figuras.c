#include <gtk/gtk.h>

/* ----- Colors -----
https://www.rubydoc.info/gems/cairo/1.12.6/Cairo/Color
1. Color EMERALD -> cairo_set_source_rgb(cr, 0.313725490196078, 0.784313725490196, 0.470588235294118);  
2. Color PEACH -> cairo_set_source_rgb(cr, 1.0, 0.898039215686275, 0.705882352941177);
3. Color ALICE_BLUE -> cairo_set_source_rgb(cr, 0.890196078431372, 0.149019607843137, 0.211764705882353);
4. Color VIOLET_EGGPLANT -> cairo_set_source_rgb(cr, 0.6, 0.0666666666666667, 0.6);  
5. Color AMBER -> cairo_set_source_rgb(cr, 1.0, 0.749019607843137, 0.0);  
6. Color BURNT_UMBER -> cairo_set_source_rgb(cr, 0.541176470588235, 0.2, 0.141176470588235);
7. Color HOT_MAGENTA -> cairo_set_source_rgb(cr, 1.0, 0.0, 0.8);  
8. Color MOSS_GREEN -> cairo_set_source_rgb(cr, 0.67843137254902, 0.874509803921569, 0.67843137254902);
9. Color STEEL_BLUE -> cairo_set_source_rgb(cr, 0.274509803921569, 0.509803921568627, 0.705882352941177);  
10. Color TEAL -> cairo_set_source_rgb(cr, 0.0, 0.501960784313725, 0.501960784313725);  
*/


gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    guint width, height;
    GdkRGBA color;
    GtkStyleContext *context;
    
    context = gtk_widget_get_style_context (widget);
    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    
    /*cairo_arc (cr, width/2.0, height/2.0, MIN (width, height) / 2.0, 0, 2 * G_PI);
    cairo_set_source_rgb(cr, 1.0, 0.0, 0.8);    
    cairo_fill(cr);*/
        
    /*----- Figura Rectangulo 1 -----*/
    /*Color EMERALD*/
    cairo_set_source_rgb(cr, 0.313725490196078, 0.784313725490196, 0.470588235294118);
    
    /*( Left, Top, width, Height )*/
    cairo_rectangle(cr, 20, 20, 100, 100);
    
    /*Rellenar*/
    cairo_fill(cr);

    /*----- Figura Rectangulo 2 -----*/
    /*Color PEACH*/
    cairo_set_source_rgb(cr, 1.0, 0.898039215686275, 0.705882352941177);
    
    /*( Left, Top, width, Height )*/
    cairo_rectangle(cr, 150, 20, 100, 100);
    /*Rellenar*/    
    cairo_fill(cr);
 
     /*----- Figura Rectangulo 3 -----*/
    /*Color HOT_MAGENTA*/
    cairo_set_source_rgb(cr, 1.0, 0.0, 0.8);
    
    /*( Left, Top, width, Height )*/
    cairo_rectangle(cr, 20, 140, 100, 100);
    /*Rellenar*/    
    cairo_fill(cr);

    /*----- Figura Rectangulo 4 -----*/
    /*Color ALICE_BLUE*/
    cairo_set_source_rgb(cr, 0.890196078431372, 0.149019607843137, 0.211764705882353);
    
    /*( Left, Top, width, Height )*/    
    cairo_rectangle(cr, 150, 140, 100, 100);

    /*Rellenar*/    
    cairo_fill(cr);
    
    /*----- Figura Triangulo Rectangulo -----*/
    /*Color AMBER*/
    cairo_set_source_rgb(cr, 1.0, 0.749019607843137, 0.0);
    
    /*Linea Vertical (Left, Top)*/
    cairo_move_to(cr, 280, 20);
    /*Linea Diagonal (Left, Top)*/    
    cairo_line_to(cr, 280, 120);
    /*Linea Horizontal (Left, Top)*/    
    cairo_line_to(cr, 380, 120);
    cairo_fill(cr);
    
    /*----- Figura Triangulo Rectangulo Curvo -----*/
    /*Color STEEL_BLUE*/
    cairo_set_source_rgb(cr, 0.274509803921569, 0.509803921568627, 0.705882352941177);    
    cairo_move_to(cr, 380, 40);
    cairo_line_to(cr, 380, 160);
    cairo_line_to(cr, 450, 160);
    cairo_curve_to(cr, 440, 155, 380, 145, 380, 40);
    
    /*Rellenar*/
    cairo_fill(cr);
    
    
    /*----- Figura Circulo -----*/
    /*Color BURNT_UMBER*/    
    cairo_set_source_rgb(cr, 0.541176470588235, 0.2, 0.141176470588235); 
       
    cairo_arc(cr, 330, 60, 40, 0, 2*G_PI);
    cairo_stroke_preserve(cr);
    
    /*Rellenar*/    
    cairo_fill(cr);
    
    /*----- Figura Medio Circulo -----*/
    /*Color MOSS_GREEN*/
    cairo_set_source_rgb(cr, 0.67843137254902, 0.874509803921569, 0.67843137254902);
    
    cairo_arc(cr, 90, 160, 40, G_PI/4, G_PI);
    cairo_close_path(cr);
    cairo_stroke_preserve(cr);
    
    /*Rellenar*/    
    cairo_fill(cr);
    
    /*----- Figura Ovalo -----*/
    /*Color VIOLET_EGGPLANT*/
    cairo_set_source_rgb(cr, 0.6, 0.0666666666666667, 0.6);
    
    cairo_translate(cr, 220, 180);
    cairo_scale(cr, 1, 0.7);
    cairo_arc(cr, 0, 0, 50, 0, 2*G_PI);
    cairo_stroke_preserve(cr);
    
    /*Rellenar*/
    cairo_fill(cr);           
       
    gtk_style_context_get_color (context, gtk_style_context_get_state (context), &color);
    gdk_cairo_set_source_rgba (cr, &color);
    gdk_cairo_set_source_rgba (cr, &color);
    cairo_fill (cr);
    return FALSE;
}

gint main(int argc,char *argv[])
{
    GtkWidget *window, *drawing_area;
    
    gtk_init (&argc, &argv);
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
    
    drawing_area = gtk_drawing_area_new();
    gtk_container_add (GTK_CONTAINER (window), drawing_area);
    gtk_widget_set_size_request (drawing_area, 800, 600);
    g_signal_connect (G_OBJECT (drawing_area), "draw", G_CALLBACK (draw_callback), NULL);
    gtk_widget_show_all (window);
    gtk_main ();
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// gcc figuras.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o figuras
// codigo para correr en la terminal luego el ./figuras
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

