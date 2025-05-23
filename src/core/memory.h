#pragma once

#include <memory>

// Unique Pointer
template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T, typename ... Args>
inline Unique<T> create_unique(Args&& ... args) {
	return std::make_unique<T>(std::forward<Args>(args)...);
}

// Shared Pointer
template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T, typename ... Args>
inline Shared<T> create_shared(Args&& ... args) {
	return std::make_shared<T>(std::forward<Args>(args)...);
}

// Weak Pointer
template<typename T>
using Weak = std::weak_ptr<T>;