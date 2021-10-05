#ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>
# include <string>

using std::string;

typedef struct _Data {
	int a;
	char c;
	std::string s;
}Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
