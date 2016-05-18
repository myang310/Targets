// Ming Yang

#include "target.h"
#include <iostream>

Target::Target() {
	size = 0;
	health = 0;
	location = 0;
}

Target::Target(int size, int location) {
	this->size = size;
	this->health = size;
	this->location = location;
}

Target::Target(Target& original) {
	this->size = original.size;
	this->location = original.location;
	this->health = original.health;
}

Target
Target::operator=(const Target& right) {
	this->size = right.size;
	this->location = right.location;
	this->health = right.health;
	return *this;
}

void
Target::setup(int size, int location) {
	this->size = size;
	this->health = size;
	this->location = location;
}

void
Target::gotHit() {
	if (health > 0) health--;
}

bool
Target::isDead() const {
	if (health == 0)	return true;
	else					return false;
}

int
Target::getSize() const {
	return size;
}

int
Target::getLocation() const {
	return location;
}
