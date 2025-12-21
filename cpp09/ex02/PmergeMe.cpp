/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:31:47 by taung             #+#    #+#             */
/*   Updated: 2025/12/22 00:53:51 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char *numbers[]) {
	parseNumbers(numbers);
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		this->dq = other.dq;
		this->v = other.v;
		this->unsorted = other.unsorted;
	}
	return (*this);
}

const char* PmergeMe::NotANumber::what() const throw() {
	return ("Error");
}

const char* PmergeMe::InvalidInput::what() const throw() {
	return ("Error");
}

void	PmergeMe::parseNumbers(char* av[]) {
	for (size_t i = 0; av[i]; i++) {
		std::string str(av[i]);

		// Check for negative numbers or non-numeric characters
		if (str.empty() || (str[0] == '-') || !std::isdigit(str[0])) {
			throw PmergeMe::InvalidInput();
		}

		// Check if all characters are digits
		for (size_t j = 0; j < str.length(); j++) {
			if (!std::isdigit(str[j])) {
				throw PmergeMe::InvalidInput();
			}
		}

		int num = std::atoi(av[i]);
		this->unsorted.push_back(num);
		this->v.push_back(num);
		this->dq.push_back(num);
	}
}

void	PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right) {
	std::vector<int> temp;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp.push_back(arr[i++]);
		} else {
			temp.push_back(arr[j++]);
		}
	}

	while (i <= mid) {
		temp.push_back(arr[i++]);
	}

	while (j <= right) {
		temp.push_back(arr[j++]);
	}

	for (size_t k = 0; k < temp.size(); k++) {
		arr[left + k] = temp[k];
	}
}

void	PmergeMe::mergeInsertVector(std::vector<int>& arr) {
	// Ford-Johnson (Merge-Insert) Sort
	// First pass: merge pairs
	for (int i = 0; i + 1 < (int)arr.size(); i += 2) {
		if (arr[i] > arr[i + 1]) {
			std::swap(arr[i], arr[i + 1]);
		}
	}

	// Main merge-insert process
	int n = arr.size();
	for (int currSize = 2; currSize < n; currSize = currSize * 2) {
		for (int leftStart = 0; leftStart < n; leftStart += currSize * 2) {
			int mid = leftStart + currSize - 1;
			int rightEnd = std::min(leftStart + currSize * 2 - 1, n - 1);

			if (mid < rightEnd) {
				mergeVector(arr, leftStart, mid, rightEnd);
			}
		}
	}
}

void	PmergeMe::sortVector() {
	std::vector<int> vCopy = this->v;  // Make a copy
	mergeInsertVector(vCopy);
	this->v = vCopy;  // Copy back the sorted result
}

void	PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right) {
	std::deque<int> temp;
	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp.push_back(arr[i++]);
		} else {
			temp.push_back(arr[j++]);
		}
	}

	while (i <= mid) {
		temp.push_back(arr[i++]);
	}

	while (j <= right) {
		temp.push_back(arr[j++]);
	}

	for (size_t k = 0; k < temp.size(); k++) {
		arr[left + k] = temp[k];
	}
}

void	PmergeMe::mergeInsertDeque(std::deque<int>& arr) {
	// Ford-Johnson (Merge-Insert) Sort
	// First pass: merge pairs
	for (int i = 0; i + 1 < (int)arr.size(); i += 2) {
		if (arr[i] > arr[i + 1]) {
			std::swap(arr[i], arr[i + 1]);
		}
	}

	// Main merge-insert process
	int n = arr.size();
	for (int currSize = 2; currSize < n; currSize = currSize * 2) {
		for (int leftStart = 0; leftStart < n; leftStart += currSize * 2) {
			int mid = leftStart + currSize - 1;
			int rightEnd = std::min(leftStart + currSize * 2 - 1, n - 1);

			if (mid < rightEnd) {
				mergeDeque(arr, leftStart, mid, rightEnd);
			}
		}
	}
}

void	PmergeMe::sortDeque() {
	std::deque<int> dqCopy = this->dq;  // Make a copy
	mergeInsertDeque(dqCopy);
	this->dq = dqCopy;  // Copy back the sorted result
}

void	PmergeMe::dqOp(void) {
	sortDeque();
}

void	PmergeMe::vOp(void) {
	sortVector();
}

void	PmergeMe::displayResults(void) {
	// Display before
	std::cout << "Before: ";
	for (size_t i = 0; i < this->unsorted.size(); i++) {
		std::cout << this->unsorted[i];
		if (i < this->unsorted.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;

	// Display after
	std::cout << "After: ";
	for (size_t i = 0; i < this->v.size(); i++) {
		std::cout << this->v[i];
		if (i < this->v.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

