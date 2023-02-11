#include <gtk/gtk.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

cairo_surface_t *avion;
cairo_surface_t *carro;
cairo_surface_t *barco;
cairo_surface_t *principal;
cairo_surface_t *puente;
gint x_avion;
gint y_avion;
gint x_carro;
gint y_carro;
gint x_barco;
gint y_barco;
gint puente_normal;
static GMutex mutex;

// Creacion para Hilos

//Hilo para el carro
void* hilo_carro(void* arg){
	
	while (1){
		sleep(1);	
			if (x_carro < 500){
				if (x_carro == 70){
					g_mutex_lock(&mutex);
					if (puente_normal){
				
				}else{
					x_carro += 1;
					puente_normal += 1;
				}
				g_mutex_unlock (&mutex);
			}else if (x_carro == 350){
				g_mutex_lock (&mutex);
				puente_normal -= 1;
				g_mutex_unlock (&mutex);
				x_carro += 1;
			}else{
				x_carro += 1;
			}
			}else{
				x_carro = 0;
		}
	}
}

// Hilo para el barco
void* hilo_barco(void* arg){
	
	while (1){
		sleep(1);	
			if (y_barco < 500){
				if (y_barco == 100){
					g_mutex_lock(&mutex);
					if (puente_normal){
				 
				}else{
					x_carro += 1;
					puente_normal += 1;
				}
				g_mutex_unlock (&mutex);
			}else if(y_barco == 330){
				g_mutex_lock (&mutex);
				puente_normal -= 1;
				g_mutex_unlock (&mutex);
				y_barco += 1;
			}else{
				y_barco += 1;
			}
			}else{
				y_barco = 0;
		}
	}
}


static void funcion_dibujar (GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer user_data) {

	//PRINCIPAL
	principal = cairo_image_surface_create_from_png("principal.png");
	cairo_set_source_surface(cr,principal,1,1);	
	
	cairo_paint(cr);
	
	/*//CARRO
	if (x_carro < 500){
		x_carro += 1;
	}else{
		x_carro = 0;
	}
	carro = cairo_image_surface_create_from_png("carro.png");
	cairo_set_source_surface(cr,carro,0+x_carro,260);
		   
	cairo_paint(cr);*/	
	
	
	
	//BARCO
	if (y_barco <= 100 ){
		puente = cairo_image_surface_create_from_png("puente_abajo.png");
	}else if(y_barco > 100 && y_barco <= 120){
		puente = cairo_image_surface_create_from_png("puente_subiendo1.png");
	}
	else if (y_barco > 120 && y_barco <= 140){
		puente = cairo_image_surface_create_from_png("puente_subiendo2.png");
	}
	else if (y_barco > 140 && y_barco <= 330){
		puente = cairo_image_surface_create_from_png("puente_arriba.png");
	}
	else if (y_barco >= 330){
		puente = cairo_image_surface_create_from_png("puente.png");
	}
	cairo_set_source_surface(cr,puente,155,308);
	
	cairo_paint(cr);
	/* 
	if (y_barco<500){
		y_barco += +1;
	}else{
		y_barco = 0;
	}*/
	
	barco = cairo_image_surface_create_from_png("barco.png");
	cairo_set_source_surface(cr,barco,220,0+y_barco);

	cairo_paint(cr);
	
	carro = cairo_image_surface_create_from_png("carro.png");
	cairo_set_source_surface(cr,carro,0+x_carro,260);
	
	cairo_paint(cr);
	////////////////////////////////////////////////////////////////////////////
	//AVION
	if (x_avion < 500){
		x_avion += 1;
	}else{
		x_avion = 0;
	}
	avion = cairo_image_surface_create_from_png("avion.png");
	cairo_set_source_surface(cr,avion,500-x_avion,45);
		   
	cairo_paint(cr);
	
}

gboolean time_handler(GtkWidget* widget) {
	gtk_widget_queue_draw(widget);

	return TRUE;
}

static void app_activate (GApplication *app, gpointer user_data) {
	GtkWidget *ventana = gtk_application_window_new (GTK_APPLICATION (app));
	GtkWidget *dibujo = gtk_drawing_area_new ();
	
	gtk_window_set_title (GTK_WINDOW (ventana), "PROYECTO");
	gtk_drawing_area_set_draw_func (GTK_DRAWING_AREA (dibujo), funcion_dibujar, NULL, NULL);
	gtk_window_set_child (GTK_WINDOW (ventana), dibujo);
   	gtk_window_set_default_size(GTK_WINDOW (ventana),500,500);
   	
	gtk_widget_set_hexpand(dibujo,true);
	gtk_widget_set_vexpand(dibujo,true);
	
	g_timeout_add(50, (GSourceFunc) time_handler, (gpointer) dibujo);
	gtk_widget_show(ventana);
 
}

static void app_open (GApplication *app, GFile **files, gint n_files, gchar *hint, gpointer user_data) {
	app_activate(app,user_data);
}

#define APPLICATION_ID "info.lfac.puente"
 
int main (int argc, char **argv) {
	GtkApplication *app;
	int stat;
	x_barco = 0;
	y_barco = 50;
	x_carro = 50;
   	y_carro = 0;
   	x_avion = 0;
   	y_avion = 0;
   	puente_normal = 0;
   	
   	pthread_t id1;
   	int ret1;
   	
   	ret1 = pthread_create(&id1,NULL,&hilo_carro,NULL);
   	
   	pthread_t id2;
   	int ret2;
   	
   	ret2 = pthread_create(&id2,NULL,&hilo_barco,NULL);
	 
	app = gtk_application_new (APPLICATION_ID, G_APPLICATION_HANDLES_OPEN);
	g_signal_connect (app, "activate", G_CALLBACK (app_activate), NULL);
	g_signal_connect (app, "open", G_CALLBACK (app_open), NULL);
	stat = g_application_run (G_APPLICATION (app), argc, argv);
	g_object_unref (app);
	return stat;
}

//////////////////////////////////////////////////////////////////////

// para correr el archivo es: gcc `pkg-config --cflags gtk4` imagen1.c `pkg-config --libs gtk4` -o imagen1
// luego el: ./imagen1.

//////////////////////////////////////////////////////////////////////