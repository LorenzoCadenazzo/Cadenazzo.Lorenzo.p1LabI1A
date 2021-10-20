#ifndef TYPE_H_INCLUDED
#define TYPE_H_INCLUDED

typedef struct
{
    int id;
    char description[20];
}eType;

#endif // TYPE_H_INCLUDED


/** \brief Muestra los tipos cargados en una lista
 *
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array
 * \return void
 *
 */
void type_show(eType types[], int sizeTypes);

/** \brief Muestra un solo tipo
 *
 * \param type eType EL tipo a mostrar
 * \return void
 *
 */
void type_showOne(eType type);

/** \brief Verifica la existencia de otro tipo con el mismo ID
 *
 * \param id int El ID a buscar
 * \param types[] eType El array de tipos
 * \param sizeTypes int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int type_findOne(int id, eType types[], int sizeTypes);
