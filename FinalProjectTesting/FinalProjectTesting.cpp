#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Animal.h"
#include "../Project1/Animal.cpp"
#include "../Project1/Controller.h"
#include "../Project1/Controller.cpp"
#include "../Project1/Ui.h"
#include "../Project1/Ui.cpp"
#include "../Project1/AnimalRepo.h"
#include "../Project1/AnimalRepo.cpp"
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FinalProjectTesting
{
	TEST_CLASS(FinalProjectTesting)
	{
	public:
		
		///ANIMAL CLASS TESTING
		TEST_METHOD(TestConstructor)
		{
			float size = 4.4, weight = 5.5, upkeep = 6.6;
			string name = "name";
			Animal A(1,name,3,size,weight,upkeep);
			Assert::AreEqual(A.getId(),1);
			Assert::AreEqual(A.getName(),name);
			Assert::AreEqual(A.getAge(), 3);
			Assert::AreEqual(A.getSize(), size);
			Assert::AreEqual(A.getWeight(), weight);
			Assert::AreEqual(A.getUpkeep(), upkeep);
		}
		TEST_METHOD(TestAssignKeeper)
		{
			float size = 4.4, weight = 5.5, upkeep = 6.6;
			string name = "name";
			string null = "";
			Animal A(1, name, 3, size, weight, upkeep);
			Assert::AreEqual(A.getKeeper(),null);
			A.assignKeeper(name);
			Assert::AreEqual(A.getKeeper(),name);
		}
	};
}
