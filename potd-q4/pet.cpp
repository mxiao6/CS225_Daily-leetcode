#include "pet.h"

// Put your constructor code here!
Pet::Pet() {
    name = "Rover";
    birth_year = 2016;
    type = "dog";
    owner_name = "Cinda";
}

Pet::Pet(std::string n, int b, std::string t, std::string o) {
    name = n;
    birth_year = b;
    type = t;
    owner_name = o;
}

void Pet::setName(std::string newName) {
  name = newName;
}

void Pet::setBY(int newBY) {
  birth_year = newBY;
}

void Pet::setType(std::string newType) {
  type = newType;
}

void Pet::setOwnerName(std::string newName) {
  owner_name = newName;
}

std::string Pet::getName() {
  return name;
}

int Pet::getBY() {
  return birth_year;
}

std::string Pet::getType() {
  return type;
}

std::string Pet::getOwnerName() {
  return owner_name;
}
