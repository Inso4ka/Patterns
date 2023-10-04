#include <iostream>

class Building
{
  public:
    virtual void build() = 0;
    virtual ~Building() { }
};

class House : public Building
{
  public:
    void build() override {
        std::cout << "House\n";
    }
};

class Wall : public Building
{
  public:
    void build() override {
        std::cout << "Wall\n";
    }
};

class Tower : public Building
{
  public:
    void build() override {
        std::cout << "Tower\n";
    }
};

class BuildingFactory
{
  public:
    virtual Building* createHouse() = 0;
    virtual Building* createWall()  = 0;
    virtual Building* createTower() = 0;
    virtual ~BuildingFactory() { }
};

class MyBuildingFactory : public BuildingFactory
{
  public:
    Building* createHouse() override {
        return new House;
    }
    Building* createWall() override {
        return new Wall;
    }
    Building* createTower() override {
        return new Tower;
    }
};

class YourBuildingFactory : public BuildingFactory
{
  public:
    Building* createHouse() override {
        return new House;
    }
    Building* createWall() override {
        return new Wall;
    }
    Building* createTower() override {
        return new Tower;
    }
};

class Game
{
  public:
    std::vector<Building*> game(BuildingFactory* factory) {
        std::vector<Building*> p;
        p.push_back(factory->createHouse());
        p.push_back(factory->createTower());
        p.push_back(factory->createWall());
        return p;
    }
};

int main() {
    Game*                game          = new Game;
    MyBuildingFactory*   ivanBuilding  = new MyBuildingFactory;
    YourBuildingFactory* alibekBuilind = new YourBuildingFactory;
    std::cout << "Ivan's buildings: \n";
    std::vector<Building*> ib = game->game(ivanBuilding);
    for (Building* building : ib) {
        building->build();
    }
    std::cout << "Alibek's buildings: \n";
    std::vector<Building*> ab = game->game(alibekBuilind);
    for (Building* building : ab) {
        building->build();
    }

    delete game;
    delete ivanBuilding;
    delete alibekBuilind;
    for (Building* building : ib) {
        delete building;
    }

    for (Building* building : ab) {
        delete building;
    }

    return 0;
}