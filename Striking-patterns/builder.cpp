#include <iostream>
#include <vector>
#include <memory>

class Dish
{
  private:
    std::string m_name;
    std::string m_description;
    double      m_price;

  public:
    Dish(const std::string& name, const std::string& description, double price) : m_name(name), m_description(description), m_price(price) { }

    const std::string& getName() const {
        return m_name;
    }

    const std::string& getDescription() const {
        return m_description;
    }

    double getPrice() const {
        return m_price;
    }
};

class Menu
{
  private:
    std::string       m_name;
    std::vector<Dish> m_dishes;

  public:
    Menu(const std::string& name, const std::vector<Dish>& dishes) : m_name(name), m_dishes(dishes) { }

    const std::string& getName() const {
        return m_name;
    }

    const std::vector<Dish>& getDishes() const {
        return m_dishes;
    }
};

class Restaurant
{
  private:
    std::string       m_name;
    std::vector<Menu> m_menu;

  public:
    Restaurant(const std::string& name, const std::vector<Menu>& menu) : m_name(name), m_menu(menu) { }

    void printMenu() const {
        std::cout << "Restaurant: " << m_name << "\n";
        for (const Menu& menu : m_menu) {
            std::cout << "Menu: " << menu.getName() << std::endl;
            std::cout << "Dishes: " << std::endl;
            for (const Dish& dish : menu.getDishes()) {
                std::cout << "- " << dish.getName() << ": " << dish.getDescription() << ", $" << dish.getPrice() << std::endl;
            }
        }
    }
};

class DishBuilder
{
  private:
    std::string m_name;
    std::string m_description;
    double      m_price;

  public:
    DishBuilder& setName(const std::string& name) {
        m_name = name;
        return *this;
    }

    DishBuilder& setDescription(const std::string& description) {
        m_description = description;
        return *this;
    }

    DishBuilder& setPrice(double price) {
        m_price = price;
        return *this;
    }

    Dish build() const {
        return Dish(m_name, m_description, m_price);
    }
};

class MenuBuilder
{
  private:
    std::string       m_name;
    std::vector<Dish> m_dishes;

  public:
    MenuBuilder& setName(const std::string& name) {
        m_name = name;
        return *this;
    }

    MenuBuilder& addDish(const Dish& dish) {
        m_dishes.push_back(dish);
        return *this;
    }

    Menu build() const {
        return Menu(m_name, m_dishes);
    }
};

class RestaurantBuilder
{
  private:
    std::string       m_name;
    std::vector<Menu> m_menus;

  public:
    RestaurantBuilder& setName(const std::string& name) {
        m_name = name;
        return *this;
    }

    RestaurantBuilder& addMenu(const Menu& menu) {
        m_menus.push_back(menu);
        return *this;
    }

    Restaurant build() const {
        return Restaurant(m_name, m_menus);
    }
};

class Director
{
  public:
    static Restaurant generate() {
        std::vector<Dish> dishes;

        dishes.push_back(DishBuilder().setName("Steak").setDescription("Grilled steak").setPrice(15.99).build());
        dishes.push_back(DishBuilder().setName("Salad").setDescription("Fresh salad with vegetables").setPrice(8.99).build());
        dishes.push_back(DishBuilder().setName("Pasta").setDescription("Homemade pasta with tomato sauce").setPrice(12.99).build());
        dishes.push_back(DishBuilder().setName("Pizza").setDescription("Margherita pizza").setPrice(11.99).build());
        dishes.push_back(DishBuilder().setName("Soup").setDescription("Creamy tomato soup").setPrice(6.99).build());

        std::vector<Menu> menus;
        menus.push_back(MenuBuilder().setName("Main Menu").addDish(dishes[0]).addDish(dishes[1]).addDish(dishes[2]).build());
        menus.push_back(MenuBuilder().setName("Lunch Menu").addDish(dishes[3]).addDish(dishes[4]).build());

        return RestaurantBuilder().setName("Mushroom Restaurant").addMenu(menus[0]).addMenu(menus[1]).build();
    }
};

int main() {
    Restaurant restaurant = Director::generate();
    restaurant.printMenu();

    return 0;
}
