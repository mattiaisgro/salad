#ifndef _ASMSALAD_H
#define _ASMSALAD_H

#include "langsalad.h"
#include "bitsalad.h"

// TO-DO Find compiler using macros.
#ifdef _MSC_VER
#define COMP_MSVC
#endif

namespace salad {


	// Calculate square root of num.
	inline float fsqrt(float num) {

		#ifdef COMP_MSVC

		__asm {
			fld num
			fsqrt
			fst num
		}

		#else

		asm("fsqrt" : "+t"(num));

		#endif

		return num;
	}


	// Calculate inverse square root of num.
	inline float invsqrt(float num) {

		float buff = num;

		#ifdef COMP_MSVC

		__asm {
			fld num
			fsqrt
			fst num
		}

		#else

		asm("fsqrt" : "+t"(num));

		#endif

		return num / buff;

	}


	// Calculate inverse square root of num using the fast inverse square root method.
	inline float invsqrt_fast(float num) {

		float buff = num;
		int i = TYPE_PUN(int, num);
		i = 0x5f3759df - (i >> 1);
		num = TYPE_PUN(float, i);

		num = num * (1.5f - ((buff / 2.f) * num * num));
		num = num * (1.5f - ((buff / 2.f) * num * num));
		num = num * (1.5f - ((buff / 2.f) * num * num)); // Three iterations for better precision.

		return num;
	}


	// Calculate sine of num.
	inline float fsin(float num) {

		#ifdef COMP_MSVC

		__asm {
			fld num
			fsin
			fst num
		}

		#else

		asm("fsin" : "+t"(num));

		#endif

		return num;
	}


	// Calculate cosine of num.
	inline float fcos(float num) {

		#ifdef COMP_MSVC

		__asm {
			fld num
			fcos
			fst num
		}

		#else

		asm("fcos" : "+t"(num));

		#endif

		return num;
	}


	// Calculate tangent of num.
	inline float ftan(float num) {

		float num2 = num;

		// TO-DO Implement using 'fsincos'.

		#ifdef COMP_MSVC

		__asm {
			fld num
			fsin
			fst num

			fld num2
			fcos
			fst num2
		}

		#else

		//asm("fsincos" : "+t"(num, num2));

		asm("fsin" : "+t"(num));
		asm("fcos" : "+t"(num2));

		#endif

		return num / num2;
	}


	// Calculate cotangent of num.
	inline float fcot(float num) {

		float num2 = num;

		// TO-DO Implement using 'fsincos'.

		#ifdef COMP_MSVC

		__asm {
			fld num
			fsin
			fst num

			fld num2
			fcos
			fst num2
		}

		#else

		//asm("fsincos" : "+t"(num, num2));

		asm("fsin" : "+t"(num));
		asm("fcos" : "+t"(num2));

		#endif

		return num2 / num;
	}


	// Calculate (2 ^ num) - 1 where num is between -1 and 1.
	inline float f2xm1(float num) {

		#ifdef COMP_MSVC

		__asm {
			fld num
			f2xm1
			fst num
		}

		#else

		asm("f2xm1" : "+t"(num));

		#endif

		return num;

	}


	// Trap to debugger (int 3).
	inline void int3() {

		#ifdef COMP_MSVC

		__asm {
			int 3
		}

		#else

		asm("int3");

		#endif

	}


}


#undef COMP_MSVC

#endif
