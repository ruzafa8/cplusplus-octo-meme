#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>

typedef struct TData {
	int age;
	std::string name;
	bool isRich;
} Data;

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const &other);

	public:
		~Serializer();
		Serializer &operator=(const Serializer &other);

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif