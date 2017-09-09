#ifndef _LANGSALAD_H
#define _LANGSALAD_H

// Change a variable type without changing its bytes
#define TYPE_PUN(TYPE, VAR) (*(TYPE*) &VAR)

// Create an alias for a function (no performance loss)
// e.g.
// F_ALIAS(function, new_function_name);
#define F_ALIAS(F_OLD, F_NEW) constexpr auto F_NEW = F_OLD


// Extract a function's return type

template<typename ReturnType>
struct Function {
	typedef ReturnType Type;
};
template<typename ReturnType, typename ...Parameters>
inline Function<ReturnType> _extract_retype(ReturnType(*func_ptr)(Parameters...)) {
	return Function<ReturnType>();
}
#define FUNCTION_RETURN_TYPE(function_name) decltype(_extract_retype(&function_name))::Type


namespace salad {}

#endif
