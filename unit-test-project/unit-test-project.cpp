#include "pch.h"
#include "CppUnitTest.h"
#include "../cpp-console-library-subscription/roseWind.h"
#include "../cpp-console-library-subscription/process.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	TEST_CLASS(unittestproject)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			roseWind* windData[5];
			windData[0] = new roseWind{ 1, 1, "North", 10 };
			windData[1] = new roseWind{ 2, 1, "East", 15 };
			windData[2] = new roseWind{ 3, 1, "South", 20 };
			windData[3] = new roseWind{ 4, 2, "West", 5 };
			windData[4] = new roseWind{ 5, 2, "North", 12 };

			double averageSpeed = average_wind_speed_by_month(windData, 5, 1);
			Assert::AreEqual(15.0, averageSpeed);

			// Clean up allocated memory
			for (int i = 0; i < 5; ++i) {
				delete windData[i];
			}
		}

		TEST_METHOD(TestMethod2)
		{
			roseWind* windData[3];
			windData[0] = new roseWind{ {1, 3}, "North", 10 };
			windData[1] = new roseWind{ {2, 3}, "East", 15 };
			windData[2] = new roseWind{ {3, 3}, "South", 20 };

			double averageSpeed = average_wind_speed_by_month(windData, 3, 2);
			Assert::AreEqual(0.0, averageSpeed); // No data for the specified month

			// Clean up allocated memory
			for (int i = 0; i < 3; ++i) {
				delete windData[i];
			}
		}

		TEST_METHOD(TestMethod3)
		{
			roseWind* windData[4];
			windData[0] = new roseWind{ {10, 4}, "North", 10 };
			windData[1] = new roseWind{ {15, 4}, "East", 15 };
			windData[2] = new roseWind{ {20, 4}, "South", 20 };
			windData[3] = new roseWind{ {25, 4}, "West", 5 };

			double averageSpeed = average_wind_speed_by_month(windData, 4, 4);
			Assert::AreEqual(12.5, averageSpeed);

			// Clean up allocated memory
			for (int i = 0; i < 4; ++i) {
				delete windData[i];
			}
		}

		TEST_METHOD(TestMethod4)
		{
			roseWind* windData[2];
			windData[0] = new roseWind{ {1, 5}, "North", 10 };
			windData[1] = new roseWind{ {2, 5}, "East", 15 };

			double averageSpeed = average_wind_speed_by_month(windData, 2, 5);
			Assert::AreEqual(12.5, averageSpeed);

			// Clean up allocated memory
			for (int i = 0; i < 2; ++i) {
				delete windData[i];
			}
		}

		TEST_METHOD(TestMethod5)
		{
			roseWind* windData[1];
			windData[0] = new roseWind{ {1, 6}, "North", 10 };

			double averageSpeed = average_wind_speed_by_month(windData, 1, 6);
			Assert::AreEqual(10.0, averageSpeed);

			// Clean up allocated memory
			delete windData[0];
		}
	};
}