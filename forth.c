/***************************************************************************
 * forth.c
 * Regex-based parser for Forth programs
 **************************************************************************/
/* INCLUDE FILES */
#include "general.h"    /* always include first */
#include "parse.h"      /* always include */

/* FUNCTION DEFINITIONS */

static void installForthRegex (const langType language)
{
    addTagRegex (language, "^:[ \t]+([A-Z0-9_]+)[ \t\n]", "\\1", "d,definition", "i");
}

/* Create parser definition stucture */
extern parserDefinition* ForthParser (void)
{
    static const char *const patterns [] = { NULL };
    static const char *const extensions [] = { "fth", "4th", NULL };
    parserDefinition* const def = parserNew ("Forth");
    def->patterns   = patterns;
    def->extensions = extensions;
    def->initialize = installForthRegex;
    def->regex      = TRUE;
    return def;
}

