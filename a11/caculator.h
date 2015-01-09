#ifndef CACULATOR
#define CACULATOR

typedef struct my_struct *Fraction_T;

Fraction_T new_Fraction(const char * str);

int add_Fraction(Fraction_T, const Fraction_T, const Fraction_T);

int sub_Fraction(Fraction_T result, const Fraction_T lhs, const Fraction_T rhs);

int mul_Fraction(Fraction_T result, const Fraction_T lhs, const Fraction_T rhs);

int div_Fraction(Fraction_T result, const Fraction_T lhs, const Fraction_T rhs);

int print_Fraction(const Fraction_T);

int destroy_Fraction(Fraction_T * f);

#endif
