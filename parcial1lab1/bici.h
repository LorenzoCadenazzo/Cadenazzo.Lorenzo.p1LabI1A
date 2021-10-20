#include "type.h"
#include "color.h"

#ifndef BICI_H_INCLUDED
#define BICI_H_INCLUDED

typedef struct
{
    int id;
    char brand[20];
    int idType;
    int idColor;
    int rodado;
    int state;

} eBici;


/** \brief Hardcodea las bicis
 *
 * \param bicicleta[] eBici El array de bicis
 * \param bicicletaToHardcode int La cantidad de bicis a harcodear
 * \return void
 *
 */
void moto_hardcode(eBici bicicleta[], int bicicletaToHardcode);
/** \brief Inicializa el array de bicis en 0 o vacio
 *
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array
 * \return void
 *
 */
void bici_initializate(eBici bicicleta[], int sizeBicicleta);
/** \brief Busca lugar libre en el array de bicis para guardar nuevos datos
 *
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array
 * \return int (El indice) para guardar datos, (-1) si no hay lugar libre
 *
 */
int bici_findFreeSpace(eBici bicicleta[], int sizeBicicleta);
/** \brief Verifica la existencia de otra bici con el mismo ID
 *
 * \param id int El ID a buscar
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array
 * \return int (El indice) si el ID ya existe, (-1) si no existe
 *
 */
int bici_findOne(int id, eBici bicicleta[], int sizeBicicleta);


/** \brief Da de alta una bici
 *
 * \param int id El id que se le asignara a la bici
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bici
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bici
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
int bici_load(int id, eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Da de baja una bici
 *
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bici_delate(eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Modifica una bici
 *
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bici_modify(eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Muestra las bicis cargadas en una lista
 *
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bici_show(eBici bicicleta[], int sizeBicicleta, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief MuestraeBici solo una bici
 *
 * \param eBici La bici a mostrar
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */
void bici_showOne(eBici, eType types[], int sizeTypes, eColor colors[], int sizeColors);
/** \brief Ordena las bicis
 *
 * \param bicicleta[] eBici El array de bicis
 * \param sizeBicicleta int El tamaño del array de bicis
 * \param types[] eType El array de tipos de bicis
 * \param sizeTypes int El tamaño del array de tipos
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return void
 *
 */

int bici_loadTypeDescription(char description[], int id, eType types[], int sizeTypes);
/** \brief Carga el nombre de los colores de bicis
 *
 * \param colorName[] char Donde se cargara la informacion
 * \param id int El id de la estructura Color
 * \param colors[] eColor El array de colores de bicis
 * \param sizeColors int El tamaño del array de colores
 * \return int (1) si se pudo cargar (0) si no se pudo
 *
 */
int bici_loadColorName(char colorName[], int id, eColor colors[], int sizeColors);

#endif // BICI_H_INCLUDED
