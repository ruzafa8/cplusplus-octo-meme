#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
	private:
		T		*array;
		size_t	len;

	public:
		Array(): array(new T[0]), len(0) {}
		Array(int n): array(new T[n]), len(n) {}
		Array(const Array &other) {
			*this = other;
		}
		~Array() {
			delete []array;
		}

		Array &operator=(Array const &other) {
			if (this != &other) {
				if (this->len != other.len) {
					T *tmp = new T[other.len];
					delete []this->array;
					this->array = tmp;
					this->len = other.len;
				}
				std::copy(other.array, other.array + other.len, this->array);
			}
			return *this;
		}

		T &operator[](size_t i) {
			return this->array[i];
		}
};

#endif