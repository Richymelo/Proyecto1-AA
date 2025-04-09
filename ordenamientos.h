#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *arr, int n, gpointer user_data) {
    DatosGenerales *general = (DatosGenerales *)user_data;
    GtkBuilder *builder = general->builder;
    DatosUsuario *datos = general->datos;

    GtkWidget *area = GTK_WIDGET(gtk_builder_get_object(builder, "area_circulo"));
    gtk_widget_queue_draw(area);

    // Allow GTK to process the drawing event and update the display
    while (gtk_events_pending()) {
        gtk_main_iteration();  // Process all pending GTK events
    }

    g_usleep(800000);  // Delay for half a second to visualize each step
                
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            datos->iterations++;
            // Trigger a redraw to update the display after the swap
            gtk_widget_queue_draw(area);
            // Allow GTK to process the drawing event and update the display
            while (gtk_events_pending()) {
                gtk_main_iteration();  // Process all pending GTK events
            }
            g_usleep(500000);
            if (arr[j] < arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                
                datos->swaps++;
                // Trigger a redraw to update the display after the swap
                gtk_widget_queue_draw(area);

                // Allow GTK to process the drawing event and update the display
                while (gtk_events_pending()) {
                    gtk_main_iteration();  // Process all pending GTK events
                }

                g_usleep(800000);  // Delay for half a second to visualize each step
            }
        }
        if (!swapped) {
            break;  // No swapping, array is already sorted
        }
    }
}