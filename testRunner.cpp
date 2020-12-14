#include <fstream>
#include <chrono>
#include <gtest/gtest.h>
#include "grafo.h"

class GrafoTestFixture: public testing::Test
{
  public:
   GrafoTestFixture();
   virtual ~GrafoTestFixture();
   void SetUp() override;
   void TearDown() override;
   static void SetUpTestCase();
   static void TearDownTestCase();
  protected:
   Grafo grafo{"teste.txt", 6};

};

GrafoTestFixture::GrafoTestFixture()
{
  std::cout << "Constructor called\n";
}

GrafoTestFixture::~GrafoTestFixture()
{
  std::cout << "Destructor called\n";
}

void GrafoTestFixture::SetUpTestCase()
{
  std::cout << "SetUpTestCase called\n";
}

void GrafoTestFixture::TearDownTestCase()
{
  std::cout << "TearDownTestCase called\n";
}

void GrafoTestFixture::SetUp()
{
    std::cout << "SetUp called\n";
}

void GrafoTestFixture::TearDown()
{
    std::cout << "TearDown called\n";
}





TEST_F(GrafoTestFixture, contaGarrafa)
{ 
  std::cout << "Test body\n";

  ASSERT_EQ(5, grafo.totalGarrafas());
}


TEST_F(GrafoTestFixture, contaArestas)
{ 
  std::cout << "Test body\n";

  ASSERT_EQ(2, grafo.calculaAresta(1));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



