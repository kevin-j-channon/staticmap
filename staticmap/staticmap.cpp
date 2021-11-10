
#include "static_map.hpp"

#include "CppUnitTest.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace staticmap
{
	TEST_CLASS(TestStaticMap)
	{
	public:
		
		TEST_METHOD(Create)
		{
			const auto m = StaticMap<int, int, 2>{ {1, 2}, {3, 4} };
		}

		TEST_METHOD(Size)
		{
			const auto m = StaticMap<int, std::string, 5>{ {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"} };
			Assert::AreEqual(size_t{ 5 }, m.size());
		}

		TEST_METHOD(At)
		{
			const auto m = StaticMap<int, std::string, 5>{ {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"} };
			
			const auto expected = std::array<std::string, 5>{ "One", "Two", "Three", "Four", "Five" };

			for (auto i : {0, 1, 2, 3, 4})
			{
				Assert::AreEqual(expected[i], m.at(i + 1));
			}
		}

		TEST_METHOD(AtThrowsOutOfRangeIfKeyNotFound)
		{
			const auto m = StaticMap<int, std::string, 5>{ {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"} };
			Assert::ExpectException<std::out_of_range>([&m]() {m.at(10); });
		}

		TEST_METHOD(With)
		{

			const auto m = StaticMap<int, std::string, 5>{ {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"} };

			const auto values = std::array<std::string, 5>{ "One", "Two", "Three", "Four", "Five" };

			for (auto i : { 0, 1, 2, 3, 4 })
			{
				Assert::AreEqual(i + 1, m.with(values[i]));
			}
		}

		TEST_METHOD(WithThrowsOutOfRangeIfValueNotFound)
		{
			const auto m = StaticMap<int, std::string, 5>{ {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"} };
			Assert::ExpectException<std::out_of_range>([&m]() {m.with("Foo"); });
		}
	};
}
