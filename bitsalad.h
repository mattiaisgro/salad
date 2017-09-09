#ifndef _BITSALAD_H
#define _BITSALAD_H


namespace salad {


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


	// Float type-punning functions.
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


	// Bit twiddling

	// Return the lower nibble of the given byte.
	inline char get_lower_nibble(char c) {

		return c & 0x0F;
	}

	// Return the higher nibble of the given byte.
	inline char get_higher_nibble(char c) {

		return c >> 4;
	}

	// Clear nth bit of given byte.
	template<typename T>
	inline T bit_clear(T t, unsigned int n) {

		return (t & ~(1 << n));
	}

	// Set nth bit of given byte.
	template<typename T>
	inline T bit_set(T t, unsigned int n) {

		return (t | (1 << n));
	}

}

#endif
