#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <stddef.h>

char* generate_password(size_t length, int include_special_chars, int include_capital_letters);

#endif // PASSWORD_GENERATOR_H