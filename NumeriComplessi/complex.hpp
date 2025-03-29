#pragma once

/* Templates: recall that where you see `template<typename T>` you should
 * read `for all T`.
 * C++20 introduces a feature called "concepts", which in some way allows
 * you to put constraints on the universal quantifier. For example, when you
 * see
 *
 *      template<typename T> requires std::integral<T>
 *
 * you should read it as
 *
 *      for all T   such that   std::integral<T> is true
 *
 * In addition, std::integral<T> is true if and only if the type T is some
 * kind of integer (short, int, long...)
 */
  
/* A class modeling a complex number. Remember that a class is the same of
 * a struct but all of its members are private by default. */
 
template<typename F> requires std::floating_point<F>
class complex_number
{
    /* Private members */
    F re, im;
    
public:
    /* Default constructor */
    complex_number()
        : re(0), im(0) // inizializzazione di parte reale e immaginaria
    {}
    
    /* User-defined constructor. This is marked `explicit` to avoid
     * making a "converting constructor".
     */
    explicit complex_number(F n)
        : re(n), im(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }
    
    /* User-defined constructor. Takes two parameters, numerator and
     * denominator */
    complex_number(F n, F d)
        : re(n), im(d)
    {}
    
    /* Return the real part. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    F parte_reale(void) const {
        return re;
    }
    
    /* Return the immaginary part. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    F parte_im(void) const {
        return im;
    }
	
	/* Define the += operator between complex numbers. When you do
     * 
     *  c1 += c2
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
    complex_number& operator+=(const complex_number& other) 
	{
        
        re += other.parte_reale(); // re += other.re; 
        im += other.parte_im(); // im += other.im;
        return *this;
	}
	
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	 
	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	 /* Define the += operator between a complex number on the left
     * and an F on the right. When you do
     * 
     *  r1 += f
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
     complex_number& operator+=(const F& other) {
        re += other;
        return *this;
	 }
	
/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	complex_number operator+(const F& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }	
	
	/* Define the *= operator between complex numbers. When you do
     * 
     *  c1 *= c2
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
    complex_number& operator*=(const complex_number& other) 
	{
		F a = re;
		F b = im;
        F c = other.parte_reale();
        F d = other.parte_im();
		re = a*c - b*d;
		im = a*d + b*c;
		
        return *this;
	}
	
		/* Define operator* in terms of operator *=. Notice that * does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	 
	complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
	
     /* Define the *= operator between a complex number on the left
     * and an F on the right. When you do
     * 
     *  r1 *= f
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which *= is called.
     */
     complex_number& operator*=(const F& other) {
        re *= other;
		im *= other;
        return *this;
	 }
	
/* Define operator* in terms of operator *=. Notice that * does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	complex_number operator*(const F& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }	
};
/* This operator is defined outside the complex numbers class and is needed
 * to compute the sum of an F on the left and a complex_number<F> on the
 * right. */
template<typename F>
complex_number<F> 
operator+(const F& f, const complex_number<F>& c)
{
    return c + f;
}

/* This operator is defined outside the complex numbers class and is needed
 * to compute the multiplication of an F on the left and a complex_number<F> on the
 * right. */
template<typename F>
complex_number<F> 
operator*(const F& f, const complex_number<F>& c)
{
    return c * f;
}


/* Overload of <<, to make the complex printable. */
template<typename F>
std::ostream&
operator<<(std::ostream& os, const complex_number<F>& r) {
    if (r.parte_im() != 0) {
		if (r.parte_im() <0) {
			F tmp= -r.parte_im();
			os << r.parte_reale() << "-" << tmp << "i"; 
		}
		else
			os << r.parte_reale() << "+" << r.parte_im()<<"i"; 
	}
    else
        os << r.parte_reale();

    return os;
}

template<typename F>
complex_number<F> coniugato(const complex_number<F>& r) // funzione per il coniugato, complex_number<F> è il tipo
{
	return complex_number<F>(r.parte_reale(), -r.parte_im()); //utilizza il costruttore di default con i due parametri
}