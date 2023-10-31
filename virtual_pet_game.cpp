#include <iostream>
#include <string>
#include <ctime>

class VirtualPet {
public:
    VirtualPet(const std::string& name) : name(name), hunger(50), happiness(50) {}

    void feed() {
        hunger -= 10;
        if (hunger < 0) hunger = 0;
        std::cout << name << " has been fed. Hunger: " << hunger << std::endl;
    }

    void play() {
        happiness += 10;
        if (happiness > 100) happiness = 100;
        std::cout << name << " is happy! Happiness: " << happiness << std::endl;
    }

    void checkStatus() {
        std::cout << name << "'s Status:" << std::endl;
        std::cout << "Hunger: " << hunger << std::endl;
        std::cout << "Happiness: " << happiness << std::endl;
    }

    bool isAlive() {
        return hunger > 0 && happiness > 0;
    }

private:
    std::string name;
    int hunger;
    int happiness;
};

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr));

    std::string petName;
    std::cout << "Welcome to your Virtual Pet Simulator!" << std::endl;
    std::cout << "Give your pet a name: ";
    std::cin >> petName;

    VirtualPet pet(petName);

    while (pet.isAlive()) {
        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Feed " << petName << std::endl;
        std::cout << "2. Play with " << petName << std::endl;
        std::cout << "3. Check " << petName << "'s status" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                pet.feed();
                break;
            case 2:
                pet.play();
                break;
            case 3:
                pet.checkStatus();
                break;
            case 4:
                std::cout << "Goodbye! " << petName << " will miss you!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    std::cout << "Oh no, " << petName << " is no longer with us. Game over." << std::endl;

    return 0;
}
