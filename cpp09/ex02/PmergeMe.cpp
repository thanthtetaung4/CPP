/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:31:47 by taung             #+#    #+#             */
/*   Updated: 2025/12/30 01:02:39 by taung            ###   ########.fr       */
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
	// Implement full Ford-Johnson (merge-insertion) for vector using Jacobsthal order.
	performFordJohnsonVector(arr);
}

void PmergeMe::recursiveMergeSortVector(std::vector<int>& arr, int left, int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	recursiveMergeSortVector(arr, left, mid);
	recursiveMergeSortVector(arr, mid + 1, right);
	mergeVector(arr, left, mid, right);
}

void PmergeMe::performFordJohnsonVector(std::vector<int>& arr) {
	size_t n = arr.size();
	if (n <= 1)
		return;

	// Phase 1: pairwise partition into mainChain (smaller) and pendants (larger)
	std::vector<int> mainChain;
	std::vector<int> pendants;
	for (size_t i = 0; i + 1 < n; i += 2) {
		if (arr[i] <= arr[i + 1]) {
			mainChain.push_back(arr[i]);
			pendants.push_back(arr[i + 1]);
		} else {
			mainChain.push_back(arr[i + 1]);
			pendants.push_back(arr[i]);
		}
	}
	// If odd element remains, treat it as a pendant
	if (n % 2 == 1) {
		pendants.push_back(arr[n - 1]);
	}

	// Recursively sort the main chain (use existing recursive merge sort)
	if (!mainChain.empty())
		recursiveMergeSortVector(mainChain, 0, static_cast<int>(mainChain.size()) - 1);

	// Generate Jacobsthal insertion order for pendants
	std::vector<int> order = jacobsthalOrder(static_cast<int>(pendants.size()));

	// Insert pendants into mainChain in Jacobsthal order using binary insertion
	for (size_t idx = 0; idx < order.size(); ++idx) {
		int pidx = order[idx];
		if (pidx < 0 || static_cast<size_t>(pidx) >= pendants.size())
			continue;
		binaryInsertVector(mainChain, pendants[pidx]);
	}

	// Replace arr with the fully merged mainChain
	arr = mainChain;
}

std::vector<int> PmergeMe::jacobsthalOrder(int m) {
	std::vector<int> order;
	if (m <= 0)
		return order;

	std::vector<bool> used(m, false);
	// Generate Jacobsthal numbers iteratively: J0=0, J1=1, Jn = Jn-1 + 2*Jn-2
	int a = 0; // J0
	int b = 1; // J1
	while (b <= m) {
		int idx = b - 1; // convert 1-based Jacobsthal to 0-based index
		if (idx >= 0 && idx < m && !used[idx]) {
			order.push_back(idx);
			used[idx] = true;
		}
		int c = b + 2 * a;
		a = b;
		b = c;
	}

	// Append any remaining pendants in order
	for (int i = 0; i < m; ++i) {
		if (!used[i])
			order.push_back(i);
	}

	return order;
}

void PmergeMe::binaryInsertVector(std::vector<int>& mainChain, int value) {
	std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(it, value);
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
	// Implement Ford-Johnson for deque by converting to vector, reusing vector variant,
	// then copy back to deque. This avoids duplicating complex insertion logic.
	std::vector<int> tmp(arr.begin(), arr.end());
	performFordJohnsonVector(tmp);
	// Assign sorted data back to deque
	arr.clear();
	for (size_t i = 0; i < tmp.size(); ++i)
		arr.push_back(tmp[i]);
}

void PmergeMe::recursiveMergeSortDeque(std::deque<int>& arr, int left, int right) {
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	recursiveMergeSortDeque(arr, left, mid);
	recursiveMergeSortDeque(arr, mid + 1, right);
	mergeDeque(arr, left, mid, right);
}

void PmergeMe::performFordJohnsonDeque(std::deque<int>& arr) {
	// Not used: we convert deque -> vector, use vector implementation, then convert back.
	std::vector<int> tmp(arr.begin(), arr.end());
	performFordJohnsonVector(tmp);
	arr.assign(tmp.begin(), tmp.end());
}

void PmergeMe::binaryInsertDeque(std::deque<int>& mainChain, int value) {
	std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(it, value);
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

