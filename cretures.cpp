#include <iostream>
#include <string>


class GenericCreature 
{
	protected:
		std::string name = "None";

	public:
		GenericCreature() 
		{
			std::cout << "GenericCreature::obj created (def)" << std::endl;
		}

		GenericCreature(std::string name) : name(name) 
		{
			std::cout << "GenericCreature::obj created (init)" << std::endl;
		}

		GenericCreature(const GenericCreature& gc) : name(gc.name) 
		{
			std::cout << "GenericCreature::obj created (copy)" << std::endl;
		}

		~GenericCreature() 
		{
			std::cout << "GenericCreature::obj deleted" << std::endl;
		}

		std::string getName() const 
		{
			return name;
		}

		void setName(std::string name) 
		{
			this->name = name;
		}
};


class OceanCreature : public GenericCreature 
{
	public:
		OceanCreature() 
		{
			std::cout << "OceanCreature::obj created (def)" << std::endl;
		}

		OceanCreature(std::string name) : GenericCreature(name) 
		{
			std::cout << "OceanCreature::obj created (init)" << std::endl;
		}

		OceanCreature(const OceanCreature& gc) : GenericCreature(gc) 
		{
			std::cout << "OceanCreature::obj created (copy)" << std::endl;
		}

		~OceanCreature() 
		{
			std::cout << "OceanCreature::obj deleted" << std::endl;
		}
		
		void performActions() 
		{
			swim();
		}

	protected:
		void swim() 
		{
			std::cout << "  swim" << std::endl;
		}
};


class Amphibious : public OceanCreature 
{
	public:
		Amphibious() 
		{
			std::cout << "Amphibious::obj created (def)" << std::endl;
		}

		Amphibious(std::string name) : OceanCreature(name) 
		{
			std::cout << "Amphibious::obj created (init)" << std::endl;
		}

		Amphibious(const Amphibious& gc) : OceanCreature(gc) 
		{
			std::cout << "Amphibious::obj created (copy)" << std::endl;
		}

		~Amphibious() 
		{
			std::cout << "Amphibious::obj deleted" << std::endl;
		}

		void performActions() 
		{
			swim();
			walk();
		}

	protected:
		void walk() 
		{
			std::cout << "  walk" << std::endl;
		}
};


class TerrestrialCreature : public GenericCreature 
{
	public:
		TerrestrialCreature() 
		{
			std::cout << "TerrestrialCreature::obj created (def)" << std::endl;
		}

		TerrestrialCreature(std::string name) : GenericCreature(name) 
		{
			std::cout << "TerrestrialCreature::obj created (init)" << std::endl;
		}

		TerrestrialCreature(const TerrestrialCreature& gc) : GenericCreature(gc) 
		{
			std::cout << "TerrestrialCreature::obj created (copy)" << std::endl;
		}

		~TerrestrialCreature() 
		{
			std::cout << "TerrestrialCreature::obj deleted" << std::endl;
		}
		void performActions() 
		{
			walk();
		}

	protected:
		void walk() 
		{
			std::cout << "  walk" << std::endl;
		}
};


class Bird : public TerrestrialCreature 
{
	public:
		Bird() 
		{
			std::cout << "Bird::obj created (def)" << std::endl;
		}

		Bird(std::string name) : TerrestrialCreature(name) 
		{
			std::cout << "Bird::obj created (init)" << std::endl;
		}

		Bird(const Bird& gc) : TerrestrialCreature(gc) 
		{
			std::cout << "Bird::obj created (copy)" << std::endl;
		}

		~Bird() 
		{
			std::cout << "Bird::obj deleted" << std::endl;
		}
		
		void performActions()
		{
			walk();
			fly();
		}

	protected:
		void fly() 
		{
			std::cout << "  fly" << std::endl;
		}
};


class Waterfowl : public Bird
{
	public:
		Waterfowl() 
		{
			std::cout << "Waterfowl::obj created (def)" << std::endl;
		}

		Waterfowl(std::string name) : Bird(name)
		{
			std::cout << "Waterfowl::obj created (init)" << std::endl;
		}

		Waterfowl(const Waterfowl& gc) : Bird(gc)
		{
			std::cout << "Waterfowl::obj created (copy)" << std::endl;
		}

		~Waterfowl() 
		{
			std::cout << "Waterfowl::obj deleted" << std::endl;
		}
		
		void swim() 
		{
			std::cout << "  swim" << std::endl;
		}

		void performActions() 
		{
			walk();
			swim();
			fly();
		}
};

int main() {
    GenericCreature gc;
    gc.setName("Bob");
    std::cout << gc.getName() << std::endl;
	std::cout << "\n\n";
	
	OceanCreature fish("Sam");
	std::cout << fish.getName() << std::endl;
	fish.performActions();
	std::cout << "\n\n";
	
	TerrestrialCreature cat("Nimbus");
	std::cout << cat.getName() << std::endl;
	cat.performActions();
	std::cout << "\n\n";

	Bird sparrow("Lin");
	std::cout << sparrow.getName() << std::endl;
	sparrow.performActions();
	std::cout << "\n\n";

    Waterfowl goose("Henry");
	std::cout << goose.getName() << std::endl;
    std::cout << "Abilities: " << std::endl;
    goose.performActions();
	std::cout << "\n\n";

    Amphibious frog("Larry");
	std::cout << frog.getName() << std::endl;
    std::cout << "Abilities: " << std::endl;
    frog.performActions();
	std::cout << "\n\n";


    return 0;
}
