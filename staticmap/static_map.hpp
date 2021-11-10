#pragma once

#include <array>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <format>

template<typename Key_T, typename Value_T, size_t ITEM_COUNT>
class StaticMap
{
public:
	using value_type = std::pair<Key_T, Value_T>;
	using size_type = size_t;

	StaticMap(std::initializer_list<value_type>&& init)
	{
		std::copy(init.begin(), init.end(), m_items.begin());
		std::sort(m_items.begin(), m_items.end());
	}

	constexpr size_type size() const { return m_items.size(); }

	const Value_T& at(const Key_T& k) const
	{
		const auto it = std::lower_bound(m_items.cbegin(), m_items.cend(), k, [](const auto& x1, const Key_T& x2) { return x1.first <= x2; });
		if (m_items.cend() == it) {
			throw std::out_of_range("Invalid item");
		}

		return it->second;
	}

private:
	std::array<value_type, ITEM_COUNT> m_items;
};
