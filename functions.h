/*!
 * \file
 * \brief Header with descriptions of used in this project functions
 * 
 * This file contains definitions of all functions which were used
 * in the "Square Equation Solver" project
 */

///Constants to display number of roots of the equation
enum Roots
{
    Roots_DEFAULT,            ///< The value assigned before the start of work
    Roots_ONE,                ///< Shows that equation has only one root
    Roots_TWO,                ///< Shows thar equation has two roots
    Roots_NOSOLUTION = 100500,///< Shows that equation has no solution (in case of discriminant < 0)
    Roots_INFSOLUTIONS = 993  ///< Shows that equation has infinite number of solutions
};

//! Constants to interact with user
enum Options 
{
    Options_quit,   //< End the program
    Options_help,   //< Print the help note
    Options_meow,   //< Print the cat picture
    Options_default //< Solve the equation
};

/*! \defgroup solve_equation Solve Equation
 *  \brief This module contains functions which are necessary to solve the equation
 * 
 * At present it contains such functions: solve_square, solve_linear, is_zero
 * 
 *  @{
 */

/*!
 * \brief Solve a square equation of the form: ax^2 + bx + c = 0
 * 
 * solve_square solves a square equation of the standart form ax^2 + bx + c = 0.
 * It is also can solve linear equation (if the a param = 0). In this case it calls
 * solve_linear function.
 * Receives three coefficients of the equation and puts values of roots in the x1
 * and x2 variables (in the x1 in case of the only root).
 * \param[in] a The coefficient of equation before x^2
 * \param[in] b The coefficient of equation before x
 * \param[in] c The free coefficient of equation
 * \param[out] x1 The pointer to the first root of equation
 * \param[out] x2 The pointer to the second root of equation
 * \return Number of roots of the equation
 */
enum Roots solve_square (double a, double b, double c, double *x1, double *x2);

/*!
 *\brief Solve a linear equation of the form bx + c = 0
 * 
 * solve_linear solves a linear equation of the standart form bx + c = 0.
 * Receives coefficient b and c according to the form given above and the
 * pointer to unknown variable. It will put the answer in the given 
 * unknown variable
 * If b = 0 but c != 0 then function returns NOSOLUTION
 * If b = 0 and c = 0 then function returns INFSOLUTIONS
 * In the standart case it returns ONE
 * \param[in] b The coefficient of equation before x
 * \param[in] c The free coefficient of equation
 * \param[out] x The pointer to the root of equation
 * \return Number of roots (one or special cases)
 */
enum Roots solve_linear (double b, double c, double *x);

/*! 
 * \defgroup user_interaction Interaction with user 
 * \brief Input and output functions
 * 
 * At present it contains such functions: input, output
 * 
 *  @{
 */
/*!
 * \brief Receive values to equation from user
 * 
 * input function asks user to input a, b, c variables of
 * equation ax^2 + bx + c and places them by the given pointers
 * \param[in] a The coefficient of equation before x^2
 * \param[in] b The coefficient of equation before x
 * \param[in] c The free coefficient of equation
 */
int input (double *a, double *b, double *c);
/*!
 * \brief Output roots of the equation
 * 
 * output function outputs roots of equation according to
 * their quantity (considers cases of infinite number of 
 * roots and absence of roots). Uses enum ROOTS constants.
 * If root is the only then x2 may be any.
 * If the are no/infinite roots then x1 and x2 may be any.
 * \param[in] nroots Number of roots of equation
 * \param[in] x1 The first root
 * \param[in] x2 The second root
 */
void output (enum Roots nroots, double x1, double x2);

//! Paint a cat
void purr_paint (void);

//! Show the user manual
void help_desk (void); 
/*! @} */

/*!
 * \defgroup unit_tests Unit tests of the program
 * \brief Test functions
 * 
 * At present it contains such functions: unit_test
 * 
 *  @{
 */
/*!
 * \brief Test solve_square function
 * 
 * Takes different values which could be entered by
 * user and compares results of work solve_square function
 * with templates
 */
void unit_test (void); 

/*! @} */
