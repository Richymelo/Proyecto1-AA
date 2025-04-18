/*
            En esta sección se tienen las estructuras utilizadas en el programa.
            La estructura DatosUsuario guarda todos los datos que el usuario puede
            modificar. La estructura DatosGenerales es una estructura que guarda la
            estructura previamente mencionada y el builder de GTK, para que estos
            dos puedan ser llamados con un solo puntero.
*/

// Estructura que guarda los datos que ingresa el usuario
typedef struct {
    int *D;           // Puntero al vector de datos
    int *copia_datos;
    int N;            // Cantidad de rayos
    int k;            // Cantidad de datos
    bool usar_copia;  // Para saber cual vector de datos utilizar
    GdkRGBA color_1;  // Primer color elegido
    GdkRGBA color_2;  // Segundo color elegido
    int iterations;   // Contador para iteraciones
    int swaps;        // Contador para intercambios
} DatosUsuario;
// Estructura que guarda los datos del usuario y los del builder
typedef struct {
    GtkBuilder *builder;
    DatosUsuario *datos;
} DatosGenerales;