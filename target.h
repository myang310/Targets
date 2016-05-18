// Ming Yang

#ifndef TARGET_H
#define TARGET_H

class Target {
	public:
		Target();
		Target(int size, int location);
		Target(Target& original);
		Target operator=(const Target& right);
		void setup(int size, int location);
		void gotHit();
		bool isDead() const;
		int getSize() const;
		int getLocation() const;
	private:
		int size;
		int location;
		int health;
};

#endif
