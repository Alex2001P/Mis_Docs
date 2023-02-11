#include <gtk/gtk.h>
#include <math.h>
#include <time.h>

cairo_surface_t *carro;
cairo_surface_t *barco;
cairo_surface_t *hospital;
cairo_surface_t *puente;
cairo_surface_t *rio;
gint x_carro;
gint y_carro;

static void draw_function (GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {

	y_carro += 1;
	rio = cairo_image_surface_create_from_png("rio.png");
	cairo_set_source_surface(cr,rio,150,0+y_carro);

	cairo_paint(cr);
		   
	barco = cairo_image_surface_create_from_png("barco.png");
	cairo_set_source_surface(cr,barco,200,0);
		   
	cairo_paint(cr);
		   
	carro = cairo_image_surface_create_from_png("carro.png");
	cairo_set_source_surface(cr,carro,0,150);
		   
	cairo_paint(cr);
		   
	hospital = cairo_image_surface_create_from_png("hospital.png");
	cairo_set_source_surface(cr,hospital,0,0);
		   
	cairo_paint(cr);
		   
	puente = cairo_image_surface_create_from_png("puente.png");
	cairo_set_source_surface(cr,puente,200,150);
		   
	cairo_paint(cr);
}

gboolean time_handler(GtkWidget* widget) {
	gtk_widget_queue_draw(widget);

	return TRUE;
}

static void app_activate (GApplication *app, gpointer user_data) {
	GtkWidget *ventana = gtk_application_window_new (GTK_APPLICATION (app));
	GtkWidget *dibujo = gtk_drawing_area_new ();
	
	gtk_window_set_title (GTK_WINDOW (ventana), "Dibujo");
	gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (dibujo), draw_function, NULL, NULL);
	gtk_window_set_child (GTK_WINDOW (ventana), dibujo);
   	gtk_window_set_default_size(GTK_WINDOW (ventana),500,500);
   	
	gtk_widget_set_hexpand(dibujo,true);
	gtk_widget_set_vexpand(dibujo,true);
	
	g_timeout_add(1000, (GSourceFunc) time_handler, (gpointer) dibujo);
	gtk_widget_show(ventana);
 
}
 

static void app_open (GApplication *app, GFile **files, gint n_files, gchar *hint, gpointer user_data) {
	app_activate(app,user_data);
}

#define APPLICATION_ID "info.lfac.puente"
 
int main (int argc, char **argv) {
	GtkApplication *app;
	int stat;
	x_carro = 0;
   	y_carro = 0;
	 
	app = gtk_application_new (APPLICATION_ID, G_APPLICATION_HANDLES_OPEN);
	g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
	g_signal_connect (app, "open", G_CALLBACK (app_open), NULL);
	stat = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	return stat;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// comando para compiar/ gcc `pkg-config --cflags gtk4` experimento.c `pkg-config --libs gtk4` -o juego
//  correr/  ./juego

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
