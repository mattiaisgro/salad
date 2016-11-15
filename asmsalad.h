#ifndef _ASMSALAD_H
#define _ASMSALAD_H

// TO-DO Find compiler using macros.
#ifdef _MSC_VER
#define COMP_MSVC
#endif

namespace asmsalad {


	union float_pun {

		float f;

		int i;
		unsigned int ui;

		struct {
			unsigned int mantissa : 23;
			unsigned int exp : 8;
			unsigned int sign : 1;
		} parts;

	};


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
		}
		__asm {
			fld num2
			fcos
			fst num2
		}

		#else

		asm("fsin" : "+t"(num));
		asm("fcos" : "+t"(num2));

		#endif

		return num / num2;
	}


	// Returns the absolute value of num.
	inline float fabs(float num) {

		#ifdef COMP_MSVC

		__asm {
			fld num
			fabs
			fst num
		}

		#else

		asm("fabs" : "+t"(num));

		#endif

		return num;

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


	// Executes an invalid instruction.
	inline void ud2() {

		#ifdef COMP_MSVC

		__asm {
			ud2
		}

		#else

		asm("ud2");

		#endif

	}


	// No operation on FPU.
	inline void fnop() {

		#ifdef COMP_MSVC

		__asm {
			fnop
		}

		#else

		asm("fnop");

		#endif

	}


	// Wait the FPU to handle all exceptions.
	inline void fwait() {

		#ifdef COMP_MSVC

		__asm {
			fwait
		}

		#else

		asm("fwait");

		#endif

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

	// Float type-punning functionss
	// Platform dependent, undefined behavior and unsecure: that's how we do.

	// Set sign of float pointed to by f.
	inline void setsign(float* f, int sign) {
		float_pun punner;
		punner.f = *f;
		punner.parts.sign = sign;
		*f = punner.f;
	}

	// Set exponent of float pointed to by f.
	inline void setexp(float* f, int exp) {
		float_pun punner;
		punner.f = *f;
		punner.parts.exp = exp;
		*f = punner.f;
	}

	// Set mantissa of float pointed to by f.
	inline void setmantissa(float* f, int mantissa) {
		float_pun punner;
		punner.f = *f;
		punner.parts.mantissa = mantissa;
		*f = punner.f;
	}

}


#undef COMP_MSVC

#endif
