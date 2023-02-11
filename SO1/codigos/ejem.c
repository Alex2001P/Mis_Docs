// Incluir gtk
#include <gtk/gtk.h>

static void on_activate (GtkApplication *app) {
  // Crear una nueva ventana
  GtkWidget *window = gtk_application_window_new (app);
  // Crear un nuevo boton
  GtkWidget *button = gtk_button_new_with_label ("¡Hola Wikipedia!");
  // Cuando se hace clic en el botón, destruye la ventana pasada como un argumento
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  gtk_container_add (GTK_CONTAINER (window), button);
  gtk_widget_show_all (window);
}

int main (int argc, char *argv[]) {
  // Crear una nueva aplicación
  GtkApplication *app = gtk_application_new ("com.example.GtkApplication",
                                             G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (on_activate), NULL);
  return g_application_run (G_APPLICATION (app), argc, argv);
}
// gcc ejem.c -o ejem `pkg-config --cflags --libs gtk+-3.0`
// codigo para la ejecucion luego el ./ejem