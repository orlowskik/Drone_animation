#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"

#include "example.h"
#include "Vector3D.hh"
#include "Matrix3x3.hh"
#include "Drone.hh"
#include "Scene.hh"
#include "SceneObject.hh"
#include "Peak.hh"
#include "Slope.hh"
#include "Plateau.hh"
// This is all that is needed to compile a test-runner executable.
// More tests can be added here, or in a new tests/*.cpp file.

TEST_CASE("Test zliczania wektorow"){
    Vector3D V;

    CHECK( V.show_active_vectors() == 1);
}

TEST_CASE("Test zliczania wektorow"){
    Vector3D V;

    CHECK( V.show_all_vectors() == 2); /* Zlicza wektory z powyzszych testow wiec trzeba je uwzglednic */
}


TEST_CASE("Test zliczania wektorow"){
    Vector3D V, V2 = {2,4,1};

    CHECK( V.show_active_vectors() == 2);
}

TEST_CASE("Test zliczania wektorow"){
    Vector3D V, V2 = {2,4,1};

    CHECK( V.show_all_vectors() == 6); /* Zlicza wektory z powyzszych testow wiec trzeba je uwzglednic */
}



TEST_CASE("Test zliczania wektorow"){
    Vector3D V, V2 = {2,4,1};

    {
        Vector3D V3_tymczasowy;
    }

    CHECK( V.show_active_vectors() == 2);
}

TEST_CASE("Test zliczania wektorow"){
    Vector3D V, V2 = {2,4,1};

    {
        Vector3D V3_tymczasowy;
    }

    CHECK( V.show_all_vectors() == 12); /* Zlicza wektory z powyzszych testow wiec trzeba je uwzglednic */
}

TEST_CASE("Test zliczania wektorow"){
    Vector3D V, V2 = {2,4,1};

    V = V2 * 2;

    CHECK( V.show_active_vectors() == 2);
}

TEST_CASE("Test zliczania wektorow"){
    Vector3D V, V2 = {2,4,1};

    V = V2 * 2;

    CHECK( V.show_all_vectors() == 18); /* Zlicza wektory z powyzszych testow wiec trzeba je uwzglednic */
}



TEST_CASE("Test konstruktora dla klasy Solid"){
    Solid Test;
    Vector3D Vertex = {1,1,1};
    unsigned int Errors = 0;

    if(Test.TakeFilename_FinalSolid() != "" || Test.TakeFilename_TemplateSolid() != "" )
        ++Errors;

    CHECK(!Errors);

}


TEST_CASE("Test konstruktora dla klasy Solid"){
    Solid Test;
    Vector3D Vertex = {1,1,1}, V;

    CHECK( V == Test.Scale(Vertex) );
}


TEST_CASE("Test konstruktora parametrycznego dla klasy Solid"){
    Vector3D V1 = {2,2,2};
    Solid Test("abc","cdb",V1);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};

    CHECK( V == Test.Scale(Vertex) );
}

TEST_CASE("Test konstruktora parametrycznego dla klasy Solid"){
    Vector3D V1 = {2,2,2};
    Solid Test("abc","cdb",V1);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};
    unsigned int Errors = 0;

    if(Test.TakeFilename_FinalSolid() != "cdb" || Test.TakeFilename_TemplateSolid() != "abc" )
        ++Errors;

    CHECK(!Errors);
}



TEST_CASE("Test konstruktora dla klasy Cuboid (dziedziczenie)"){
    Cuboid Test;
    Vector3D Vertex = {1,1,1};
    unsigned int Errors = 0;

    if(Test.TakeFilename_FinalSolid() != "" || Test.TakeFilename_TemplateSolid() != "" )
        ++Errors;

    CHECK(!Errors);
}


TEST_CASE("Test konstruktora dla klasy Cuboid (dziedziczenie)"){
    Cuboid Test;
    Vector3D Vertex = {1,1,1}, V;

    CHECK( V == Test.Scale(Vertex) );
}

TEST_CASE("Test konstruktora  dla klasy Cuboid"){
    Cuboid Test;
    Vector3D  V = {0,0,0};
    unsigned int Errors = 1;

    if(Test.Take_Layout() == V && Test.Take_OrientAngle() == 0 )
        --Errors;

    CHECK(!Errors);
}



TEST_CASE("Test konstruktora parametrycznego dla klasy Cuboid (dziedziczenie)"){
    Vector3D V1 = {2,2,2};
    Cuboid Test("abc","cdb",V1,V1,90);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};

    CHECK( V == Test.Scale(Vertex) );
}

TEST_CASE("Test konstruktora parametrycznego dla klasy Cuboid (dziedziczenie)"){
    Vector3D V1 = {2,2,2};
    Cuboid Test("abc","cdb",V1,V1,90);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};
    unsigned int Errors = 0;

    if(Test.TakeFilename_FinalSolid() != "cdb" || Test.TakeFilename_TemplateSolid() != "abc" )
        ++Errors;

    CHECK(!Errors);
}

TEST_CASE("Test konstruktora dla klasy Prism (dziedziczenie)"){
    Prism Test;
    Vector3D Vertex = {1,1,1};
    unsigned int Errors = 0;

    if(Test.TakeFilename_FinalSolid() != "" || Test.TakeFilename_TemplateSolid() != "" )
        ++Errors;

    CHECK(!Errors);
}


TEST_CASE("Test konstruktora parametrycznego dla klasy Cuboid"){
    Vector3D V1 = {2,2,2};
    Cuboid Test("abc","cdb",V1,V1,90);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};
    unsigned int Errors = 1;

    if(Test.Take_Layout() == V && Test.Take_OrientAngle() == 90 )
        --Errors;

    CHECK(!Errors);
}


TEST_CASE("Test konstruktora dla klasy Prism (dziedziczenie)"){
    Prism Test;
    Vector3D Vertex = {1,1,1};
    unsigned int Errors = 0;

    if(Test.TakeFilename_FinalSolid() != "" || Test.TakeFilename_TemplateSolid() != "" )
        ++Errors;

    CHECK(!Errors);
}


TEST_CASE("Test konstruktora dla klasy Prism (dziedziczenie)"){
    Prism Test;
    Vector3D Vertex = {1,1,1}, V;

    CHECK( V == Test.Scale(Vertex) );
}

TEST_CASE("Test konstruktora  dla klasy Prism"){
    Prism Test;
    Vector3D  V = {0,0,0};
    unsigned int Errors = 1;

    if(Test.Take_Layout() == V && Test.Take_OrientAngle() == 0 )
        --Errors;

    CHECK(!Errors);
}



TEST_CASE("Test konstruktora parametrycznego dla klasy Prism (dziedziczenie)"){
    Vector3D V1 = {2,2,2};
    Prism Test("abc","cdb",V1,V1,90);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};

    CHECK( V == Test.Scale(Vertex) );
}

TEST_CASE("Test konstruktora parametrycznego dla klasy Prism (dziedziczenie)"){
    Vector3D V1 = {2,2,2};
    Prism Test("abc","cdb",V1,V1,90);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};
    unsigned int Errors = 0;

    if(Test.TakeFilename_FinalSolid() != "cdb" || Test.TakeFilename_TemplateSolid() != "abc" )
        ++Errors;

    CHECK(!Errors);
}


TEST_CASE("Test konstruktora parametrycznego dla klasy Cuboid"){
    Vector3D V1 = {2,2,2};
    Prism Test("abc","cdb",V1,V1,90);
    Vector3D Vertex = {1,1,1}, V = {2,2,2};
    unsigned int Errors = 1;

    if(Test.Take_Layout() == V && Test.Take_OrientAngle() == 90 )
        --Errors;

    CHECK(!Errors);
}



TEST_CASE("Test konstruktora klasy Drone"){
    Drone Test;
    unsigned int Errors = 1;
    Vector3D V;

    if(Test.TakeLayout() == V && Test.TakeOrient() == 0 && Test.TakeRadius() == 0)
        --Errors;


    CHECK(!Errors);
}



TEST_CASE("Test tworzenia drona"){
    Drone Test;
    Vector3D V_Layout ={2,2,0}, V = {2,2,0};
    unsigned int number_of_drones = 0;
    unsigned int Errors = 1;

    Test.MakeDrone(V_Layout,90,number_of_drones);

    if(Test.TakeLayout() == V && Test.TakeOrient() == 90  && Test.TakeRadius() - 7.4 < 1e-5)
        --Errors;

    CHECK(!Errors);
}




TEST_CASE("Transforamcja miedzy ukladem prostokata a drona"){
    Vector3D Layout = {2,2,1};
    Vector3D Scale = {2,2,2};
    Vector3D Transform = {3,3,1};
    Vector3D Result = {8,8,3};
    Cuboid Test("abc","cdb",Scale,Layout,0);

    CHECK( Test.TranformToParentialCoordinate(Transform) == Result);
}

TEST_CASE("Transforamcja miedzy ukladem prostokata a drona"){
    Vector3D Layout = {2,2,1};
    Vector3D Scale = {2,2,2};
    Vector3D Transform = {3,3,1};
    Vector3D Result = {-8,8,3};
    Cuboid Test("abc","cdb",Scale,Layout,90);

    CHECK( Test.TranformToParentialCoordinate(Transform) == Result);
}


TEST_CASE("Transforamcja miedzy ukladem graniastoslupa a drona"){
    Vector3D Layout = {2,2,1};
    Vector3D Scale = {2,2,2};
    Vector3D Transform = {3,3,1};
    Vector3D Result = {8,8,3};
    Prism Test("abc","cdb",Scale,Layout,0);

    CHECK( Test.TranformToParentialCoordinate(Transform) == Result);
}

TEST_CASE("Transforamcja miedzy ukladem graniastoslupa a drona"){
    Vector3D Layout = {2,2,1};
    Vector3D Scale = {2,2,2};
    Vector3D Transform = {3,3,1};
    Vector3D Result = {-4,8,3};
    Prism Test("abc","cdb",Scale,Layout,-270);

    CHECK( Test.TranformToParentialCoordinate(Transform) == Result);
}



TEST_CASE("Zmiana orientacji graniastoslupa w ukladzie lokalnym (obrot wokol wlasnej osi)"){
    Vector3D Layout = {2,2,1};
    Vector3D Scale = {2,2,2};
    Prism Test("abc","cdb",Scale,Layout,90);

    Test.Rotate(90);

    CHECK( Test.Take_OrientAngle() == 180);
}


TEST_CASE("Test metod wirtualnych dla Solid"){
    Solid test;

    CHECK( test.ObjectType() == "Bryla geometryczna");
}

TEST_CASE("Test metod wirtualnych dla Prism"){
    Prism test;

    CHECK( test.ObjectType() == "Graniastoslup");
}

TEST_CASE("Test metod wirtualnych dla Cuboid"){
    Cuboid test;

    CHECK( test.ObjectType() == "Prostopadloscian");
}

TEST_CASE("Test metod wirtualnych dla Drone"){
    Drone test;

    CHECK( test.ObjectType() == "Drone");
}

TEST_CASE("Test metod wirtualnych dla Peak"){
    Peak test;

    CHECK( test.ObjectType() == "Gora z ostrym szczytem");
}

TEST_CASE("Test metod wirtualnych dla Slope"){
    Slope test;

    CHECK( test.ObjectType() == "Gora z dluga grania");
}

TEST_CASE("Test metod wirtualnych dla Plateau"){
    Plateau test;

    CHECK( test.ObjectType() == "Plaskowyz");
}


TEST_CASE("Test wykrywania kolizji - na lewo od gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({25,30,0},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - na prawo od gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({75,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone());
}



TEST_CASE("Test wykrywania kolizji - na lewo od gory (kolizja) "){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({40,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - na prawo od gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({60,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - w srodku gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - powyzej gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,80,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - ponizej gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,20,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - powyzej gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,65,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - ponizej gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,35,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - lewy gorny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({30,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - prawy gorny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({70,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - lewy dolny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({30,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - prawy dolny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({70,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - rog (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({35,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - rog (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Peak>   P1(new Peak("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({65,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - na lewo od gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({25,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - na prawo od gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({75,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - na lewo od gory (kolizja) "){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({40,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - na prawo od gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({60,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - w srodku gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - powyzej gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,80,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - ponizej gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,20,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - powyzej gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,65,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - ponizej gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,35,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - lewy gorny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({30,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - prawy gorny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({70,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - lewy dolny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({30,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - prawy dolny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({70,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - rog (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({35,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - rog (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({65,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - na lewo od gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Plateau>   P1(new Plateau("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({25,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - na prawo od gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({75,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - na lewo od gory (kolizja) "){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({40,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - na prawo od gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({60,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - w srodku gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,50,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - powyzej gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,80,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - ponizej gory"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,20,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - powyzej gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,65,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - ponizej gory (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({50,35,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - lewy gorny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({30,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - prawy gorny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({70,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - lewy dolny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({30,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - prawy dolny rog"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({70,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - rog (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({35,70,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - rog (kolizja)"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone(new Drone());
    std::shared_ptr<Slope>   P1(new Slope("../datasets/templates/obstacle.dat","../datasets/dat/test.dat",{20,20,60},{50,50,0},0)); 

    TestDrone->MakeDrone({65,30,80},0,number_of_drones);
    TestDrone->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone);
    Scene.AddObject(P1);


    CHECK( Scene.Check_Landing_Zone() );
}


TEST_CASE("Test wykrywania kolizji - dwa drony bez kolizji"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone1(new Drone());
    std::shared_ptr<Drone> TestDrone2(new Drone());

    TestDrone1->MakeDrone({30,30,80},0,number_of_drones);
    TestDrone1->Count_Save_GlobalCoor();
    TestDrone2->MakeDrone({53,30,0},0,number_of_drones);
    TestDrone2->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone1);
    Scene.AddObject(TestDrone2);
    


    CHECK( !Scene.Check_Landing_Zone() );
}




TEST_CASE("Test wykrywania kolizji - dwa drony na sobie"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone1(new Drone());
    std::shared_ptr<Drone> TestDrone2(new Drone());

    TestDrone1->MakeDrone({30,30,80},0,number_of_drones);
    TestDrone1->Count_Save_GlobalCoor();
    TestDrone2->MakeDrone({30,30,0},0,number_of_drones);
    TestDrone2->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone1);
    Scene.AddObject(TestDrone2);
    


    CHECK( Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - dwa drony kolizja"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone1(new Drone());
    std::shared_ptr<Drone> TestDrone2(new Drone());

    TestDrone1->MakeDrone({30,40,80},0,number_of_drones);
    TestDrone1->Count_Save_GlobalCoor();
    TestDrone2->MakeDrone({41,51,0},-10,number_of_drones);
    TestDrone2->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone1);
    Scene.AddObject(TestDrone2);
    


    CHECK( Scene.Check_Landing_Zone() );
}




TEST_CASE("Test wykrywania kolizji - dwa drony po przekatnych"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone1(new Drone());
    std::shared_ptr<Drone> TestDrone2(new Drone());

    TestDrone1->MakeDrone({30,40,80},0,number_of_drones);
    TestDrone1->Count_Save_GlobalCoor();
    TestDrone2->MakeDrone({49,19,0},45,number_of_drones);
    TestDrone2->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone1);
    Scene.AddObject(TestDrone2);
    


    CHECK( !Scene.Check_Landing_Zone() );
}



TEST_CASE("Test wykrywania kolizji - dwa drony kolizja"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone1(new Drone());
    std::shared_ptr<Drone> TestDrone2(new Drone());

    TestDrone1->MakeDrone({30,30,80},0,number_of_drones);
    TestDrone1->Count_Save_GlobalCoor();
    TestDrone2->MakeDrone({52,30,0},0,number_of_drones);
    TestDrone2->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone1);
    Scene.AddObject(TestDrone2);
    


    CHECK( Scene.Check_Landing_Zone() );
}




TEST_CASE("Test wykrywania kolizji - brak kolizyjnosci ze soba"){
    unsigned int number_of_drones = 0;
    PzG::LaczeDoGNUPlota Link;
    std::vector<std::shared_ptr<Drone>>     Drones;
    std::list<std::shared_ptr<SceneObject>> Objects;
    Scene Scene(Drones,Objects,"../datasets/templates/surface.dat",Link);
    std::shared_ptr<Drone> TestDrone1(new Drone());

    TestDrone1->MakeDrone({30,30,80},0,number_of_drones);
    TestDrone1->Count_Save_GlobalCoor();
    Scene.AddObject(TestDrone1);


    CHECK( !Scene.Check_Landing_Zone() );
}




