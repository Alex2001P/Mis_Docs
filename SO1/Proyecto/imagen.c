#include <gtk/gtk.h>
cairo_surface_t *barco;
cairo_surface_t *carro;
cairo_surface_t *puente;
cairo_surface_t *casa;
 
static void draw_function (GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {
   
   casa = cairo_image_surface_create_from_png("casa.png");
   cairo_set_source_surface(cr,casa, 50,50);
   
   cairo_paint(cr);
  
   barco = cairo_image_surface_create_from_png("barco.png");
   cairo_set_source_surface(cr,barco,1,1);
   
   cairo_paint(cr);
   
   carro = cairo_image_surface_create_from_png("carro.png");
   cairo_set_source_surface(cr,carro,1,100);
   
   cairo_paint(cr);
   
   puente = cairo_image_surface_create_from_png("puente.png");
   cairo_set_source_surface(cr,puente,250,250);
   
   cairo_paint(cr);
}
 
static void app_activate (GApplication *app, gpointer user_data) {
   GtkWidget *win = gtk_application_window_new (GTK_APPLICATION (app));
   GtkWidget *area = gtk_drawing_area_new ();
 
   gtk_window_set_title (GTK_WINDOW (win), "Dibujo");
   gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (area), draw_function, NULL, NULL);
   gtk_window_set_child (GTK_WINDOW (win), area);
 
   gtk_widget_show (win);
}
 
#define APPLICATION_ID "com.github.ToshioCP.da1"
 
int main (int argc, char **argv) {
   GtkApplication *app;
   int stat;
 
   app = gtk_application_new (APPLICATION_ID, G_APPLICATION_FLAGS_NONE);
   g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
   stat =g_application_run (G_APPLICATION (app), argc, argv);
   g_object_unref (app);
   cairo_surface_destroy(barco);
   cairo_surface_destroy(carro);
   cairo_surface_destroy(puente);
   cairo_surface_destroy(casa);
   return stat;
}


//////////////////////////////////////////////////////////////////////

// para correr el archivo es: gcc `pkg-config --cflags gtk4` imagen.c `pkg-config --libs gtk4` -o imagen
// luego el: ./imagen.

//////////////////////////////////////////////////////////////////////