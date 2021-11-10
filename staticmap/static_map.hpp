#pragma once

#include <array>
#include <utility>
#include <algorithm>

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

private:
	std::array<value_type, ITEM_COUNT> m_items;
};
