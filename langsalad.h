#ifndef _LANGSALAD_H
#define _LANGSALAD_H

// Change a variable type without changing its bytes
#define TYPE_PUN(TYPE, VAR) (*(TYPE*) &VAR)

// Create an alias for a function (no performance loss)
// e.g.
// F_ALIAS(function, new_function_name);
#define F_ALIAS(F_OLD, F_NEW) constexpr auto F_NEW = F_OLD

#endif
