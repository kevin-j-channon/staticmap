
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
	};
}
