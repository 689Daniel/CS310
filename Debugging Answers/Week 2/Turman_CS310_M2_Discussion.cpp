/**
 * =======================================================================
 * CS310-T301 Programming with C++
 * Instructor: Dr. Robert Flowers
 * Assignment: M2 Discussion
 * Author: Eric J. Turman
 * Date: 2026-03-21
 * Email: ejturman@my365.bellevue.edu
 *
 * Description:
 * Prompts the user for a project name and echoes it back.
 *
 * Note:
 * This version intentionally contains syntax errors and will not compile.
 * =======================================================================
 * Modified by Daniel Preller
 * 26 March 2026
 */

// =======================================================================
// Imports (Includes)
// =======================================================================
#include <iostream>
#include <string>

// ========================================================================
// Namespace
// ========================================================================
using namespace std;

// ========================================================================
// Function Declarations
// ========================================================================
string get_project_name();

// ========================================================================
// Main Execution
// ========================================================================
int main()
{
    string project_name = get_project_name();
    //Daniel Preller: Corrected function name from get_prject_name to get project name

    cout << "Active project: " << project_name << endl;//Daniel Preller: Added missing semicolon

    return 0;
}

// ========================================================================
// Function Definitions
// ========================================================================

/**
 * Prompt for a project name.
 *
 * Returns
 * -------
 * string
 *     The raw project name entered by the user.
 *
 * Notes
 * -----
 * getline() is used to preserve spaces in multi-word names.
 */
string get_project_name()
{
    string project_name;

    cout << "Enter the name of your current project: ";
    getline(cin, project_name);//Daniel Preller: Corrected function name from get_line to getline

    return project_name;//Daniel Preller: Corrected variable name from projct_name to project_name
}
