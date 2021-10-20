#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

typedef struct
{
    int id;
    char description[25];
    float price;
}eService;


#endif // SERVICE_H_INCLUDED

/** \brief Muestra los servicios cargados en una lista
 *
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array
 * \return void
 *
 */
void service_show(eService services[], int sizeServices);

/** \brief Muestra un solo servicio
 *
 * \param service eService El servicio a mostrar
 * \return void
 *
 */
void service_showOne(eService service);

/** \brief Verifica la existencia de otro servicio con el mismo ID
 *
 * \param id int El ID a buscar
 * \param services[] eService El array de servicios
 * \param sizeServices int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int service_findOne(int id, eService services[], int sizeServices);

