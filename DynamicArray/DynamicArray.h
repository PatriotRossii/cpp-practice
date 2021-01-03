#pragma once

#include <utility>
#include <stdexcept>

template<typename T>
class DynamicArray {
public:
	DynamicArray();
	DynamicArray(size_t capacity);
	DynamicArray(size_t capacity, T initial_value);
	
	size_t size() const;
	size_t capacity() const;
	bool is_empty() const;

	T& at(size_t index) const;
	
	void prepend(T value);
	void push(T value);
	void insert(size_t index, T value);

	void del(size_t index);
	void remove(T value);
	
	size_t find(T value) const;
private:
	size_t size_;
	size_t capacity_;

	T* storage;

	void resize(size_t new_capacity);
};


template<typename T>
DynamicArray<T>::DynamicArray() : storage(new T[1]), capacity_(1), size_(0) {}

template<typename T>
DynamicArray<T>::DynamicArray(size_t capacity) : storage(new T[capacity]), capacity_(capacity), size_(0) {}

template<typename T>
DynamicArray<T>::DynamicArray(size_t capacity, T initial_value) : storage(new T[capacity]), capacity_(capacity), size_(capacity) {
	for (int i = 0; i < capacity; ++i) {
		storage[i] = initial_value;
	}
}

template<typename T>
size_t DynamicArray<T>::size() const {
	return this->size_;
}

template<typename T>
size_t DynamicArray<T>::capacity() const {
	return this->capacity_;
}

template<typename T>
bool DynamicArray<T>::is_empty() const {
	return this->size == 0 ? true : false;
}

template<typename T>
T& DynamicArray<T>::at(size_t index) const {
	if (index < 0 or index >= this->size_) {
		throw std::runtime_error("Invalid index");
	}
	return this->storage[index];
}

template<typename T>
void DynamicArray<T>::prepend(T value) {
	this->insert(0, value);
}

template<typename T>
void DynamicArray<T>::push(T value) {
	this->insert(this->size_, value);
}

template<typename T>
void DynamicArray<T>::insert(size_t index, T value) {
	if (this->size_ == this->capacity_) {
		this->resize(this->capacity_ * 2);
	}
	for (int i = this->size_ - 1; i >= index && i >= 0; --i) {
		this->storage[i + 1] = this->storage[i];
	}
	this->storage[index] = value;
	this->size_ += 1;
}

template<typename T>
void DynamicArray<T>::del(size_t index) {
	if (index < 0 or index >= this->size_) {
		throw std::runtime_error("Invalid index");
	}
	for (int i = index; i < this->size_; ++i) {
		this->storage[i] = this->storage[i + 1];
	}
	this->size_ -= 1;
}

template<typename T>
void DynamicArray<T>::remove(T value) {
	if (this->size_ == this->capacity_ / 4) {
		this->resize(this->capacity_ / 2);
	}

	int index = this->find(value);
	if (index == -1) {
		return;
	}
	this->del(index);
}

template<typename T>
size_t DynamicArray<T>::find(T value) const {
	for (int i = 0; i < this->size_; ++i) {
		if (this->storage[i] == value) {
			return i;
		}
	}
	return -1;
}

template<typename T>
void DynamicArray<T>::resize(size_t new_capacity) {
	T* new_buffer = new T[new_capacity];
	for (size_t i = 0; i < this->size_; ++i) {
		new_buffer[i] = std::move(this->storage[i]);
	}
	this->storage = new_buffer;
	this->capacity_ = new_capacity;
}

