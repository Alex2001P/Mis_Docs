#include <gtk/gtk.h>
gboolean draw_callback (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    guint width, height;
    GdkRGBA color;
    GtkStyleContext *context;
    
    context = gtk_widget_get_style_context (widget);
    width = gtk_widget_get_allocated_width (widget);
    height = gtk_widget_get_allocated_height (widget);
    gtk_render_background(context, cr, 0, 0, width, height);
    
	cairo_set_source_rgb(cr, 0.313725490196078, 0.784313725490196, 0.470588235294118);
    
    // Esta Funcion es para darle forma a un cuadrado la cual son las medidas de IZQUIERDA, SUPERIORIDAD, ANCHURA, ALTURA//  
    cairo_rectangle(cr, 40, 40, 200, 200);
    
    // La funcion cairo_fill(cr) es una funcion para poder rellenar
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

// gcc Cuadrado.c `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0` -o Cuadrado
// codigo para correr en la terminal luego el ./Cuadrado

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

