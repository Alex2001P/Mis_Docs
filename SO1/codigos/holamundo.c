#include <gtk/gtk.h>
int main( int argc, char *argv[] )
{
   /* Inicializa los widgets que se van a utilizar (inicialmente la ventana)*/
      GtkWidget *ventana;

   /* Arranca GTK+ */
      gtk_init (&argc, &argv);

   /* Define los tipos de widget y los configura*/
   // creamos la ventana
      ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);

   // ponemos título a la ventana
      gtk_window_set_title(GTK_WINDOW(ventana), "Hola Mundo, Bienvenidos a Sistemas Operativos 1");

   // Esta linea de codigo es para que nos muetres la ventana.
      gtk_widget_show (ventana);

   /* Comando para que nos pueda funcinar el programa*/
      gtk_main ();

   /* Finaliza el programa*/
      return 0;
} 
// gcc -o holamundo holamundo.c `pkg-config --cflags --libs gtk+-3.0` 
// codigo para corrre en termina luego el ./holamundo

