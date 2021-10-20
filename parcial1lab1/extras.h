#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED



#endif // EXTRAS_H_INCLUDED

/**
 * \brief Solicita un numero de opcion y lo valida
 * \param int maxOption La opcion maxima que se puede introducir
 * \return La opcion validada
 */
int getOption(int);

/**
 * \brief Solicita el numero de opcion de un menu para confirmar los cambios de acuerdo a ese menu
 * \param int menuOption El numero de la opcion del menu
 * \return (1) si se confirmaron los cambios, (0) si no se confirmaron
 * Le paso el numero de la opcion del menu y muestra el mensaje de confirmacion adecuado para la accion que vaya a realizar
 */
int confirm(int);
