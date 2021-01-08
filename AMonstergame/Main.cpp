#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//First, let’s create an enumeration of monster types named MonsterType. Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie. 
//Add an additional max_monster_types enum so we can count how many enumerators there are.




//Now, let’s create our Monster class. Our Monster will have 4 attributes (member variables): a type (MonsterType), a name (std::string), a roar (std::string), 
//and the number of hit points (int). Create a Monster class that has these 4 member variables.

class Monster{
	
	public:
		enum class MonsterType{
	
				Dragon, 
				Goblin, 
				Ogre, 
				Orc, 
				Skeleton, 
				Troll, 
				Vampire, 
				Zombie,
				max_monster_types
};
	
	private:
		MonsterType m_monstertype;
	    std::string m_name;
	    std::string m_roar;
	    int m_hitpoints;
	    
	    
	public:
	Monster(MonsterType monstertype,std::string name,std::string roar,int hitpoints): m_monstertype{monstertype},m_name{name},m_roar{roar},m_hitpoints{hitpoints} {
	}
	//std::cout << static_cast<int>(color)
	
	std::string getTypeString() const
	{
		switch (m_monstertype)
		{
		case MonsterType::Dragon: return "dragon";
		case MonsterType::Goblin: return "goblin";
		case MonsterType::Ogre: return "ogre";
		case MonsterType::Orc: return "orc";
		case MonsterType::Skeleton: return "skeleton";
		case MonsterType::Troll: return "troll";
		case MonsterType::Vampire: return "vampire";
		case MonsterType::Zombie: return "zombie";
		default: return "???";
		}
	}
	
	void print(){
		//Bones the skeleton has 4 hit points and says *rattle*
		cout<<m_name<<" the "<<getTypeString()<<" has "<<m_hitpoints<<" and says "<<m_roar<<'\n';
	}   
};

class MonsterGenerator {
	
	public:
public:
 
	// Generate a random number between min and max (inclusive)
	// Assumes std::srand() has already been called
	// Assumes max - min <= RAND_MAX
	static int getRandomNumber(int min, int max)
	{
		static constexpr double fraction { 1.0 / (RAND_MAX + 1.0) };  // static used for efficiency, so we only calculate this value once
		// evenly distribute the random number across our range
		return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
	}
 
	static Monster generateMonster()
	{
		return { MonsterType::skeleton, "Bones", "*rattle*", 4 };
	}
};

int main(){
	
	Monster m{ MonsterGenerator::generateMonster() };
	//////
	m.print();
	return 0;
}
