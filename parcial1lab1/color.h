#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char colorName[20];
} eColor;

#endif // COLOR_H_INCLUDED

/** \brief Muestra los colores cargados en una lista
 *
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array
 * \return void
 *
 */
void color_show(eColor colors[], int sizeColors);

/** \brief Muestra un solo color
 *
 * \param color eColor El color a mostrar
 * \return void
 *
 */
void color_showOne(eColor color);

/** \brief Verifica la existencia de otro color con el mismo ID
 *
 * \param id int El ID a buscar
 * \param colors[] eColor El array de colores
 * \param sizeColors int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int color_findOne(int id, eColor colors[], int sizeColors);
