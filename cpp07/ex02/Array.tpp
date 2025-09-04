/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:35:48 by taung             #+#    #+#             */
/*   Updated: 2025/09/04 16:59:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
Array<T>::Array(void) : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	this->_array = new T(this->_size);
}

template<typename T>
Array<T>::Array(const Array &other) {
	if (this != &other) {
		*this = other;
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		if (this->_array)
			delete this->_array;
		this->_size = other._size;
		this->_array = new T(this->_size);
		for (size_t i = 0; i < other._size; i++) {
			this->_array[i] = other._array[i];
		}
	}
	return (*this);
}

template<typename T>
Array<T>::~Array() {}


template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= 0 && index < this->_size)
		return (this->_array[index]);
	else
		throw std::out_of_range("ERROR:: Index is out of range!");
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= 0 && index < this->_size)
		return (this->_array[index]);
	else
		throw std::out_of_range("ERROR:: Index is out of range!");
}

template<typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &arr) {
	std::string	output;

	for (size_t i = 0; i < arr.size(); i++)
	{
		os << "array: ";
		os << arr[i];
		i < arr.size() - 1 ? os << " ," : os << " ";
	}
	os << std::endl;
	return (os);
}
