// OOPS: revision + more concepts

#include <iostream>
#include <string.h> // for C style string functions
using namespace std;

// Class: user-defined or custom data type

// Access modifiers:
// private: only in that class
// public: anywhere
// protected: only in that class and it's inherited class

// Using Macros
#define FAKE_PASSWORD "@3SxLy&i94/2aH137$"
#define NEW_LINE cout << endl

class Hero
{
// everything is private by default if not mentioned!
private:
    // data-members
    // also called properties/states
    int health;
    char level;
    char const* name;
    int hero_no;
    static int count;
public:
    char* message;

    // CONSTRUCTORS & DESTRUCTORS
    // If we don't define Constructor and Destructor, they are automatically called using a general definition behind the scenes by the compiler.
    // But everytime, an object is created and then deleted, then the compiler calls its own implementation of Default Constructor or Default Destructor respectively
    // If we write even one implementation of a Constructor or a Destructor, then the default one called behind the scenes is unimplemented by the compiler. So by defining our own implementations of Constructors or Destructors respectively, we ignore (& overwrite for that class) the in-built implementations in the compiler

    Hero() // Default Constructor
    {
        name = new char[100];
        health = 100;
        level = 'A';
        count++;
        hero_no = count;
        NEW_LINE;
        cout << "Hero No. " << hero_no << " created." << endl;
    }

    // this pointer
    // stores the address of the current object & hence it is a pointer to the current object

    // Constructor Overloading
    Hero(int health, char level = 'A') // Parameterised Constructor
    {
        (health < 200)? this->health = health : this->health = 100;
        (level < 'G')? this->level = level : this->level = 'A';
        count++;
        hero_no = count;
        NEW_LINE;
        cout << "Hero No. " << hero_no << " created." << endl;
    }

    // Copy Constructor: By default, already implemented by the compiler.
    // here, just a custom implementation
    Hero(Hero& H)
    {
        // we must use reference & NOT pass by value in copy constructor. Because then it will become infinite never ending loop of copy constructor calling copy constructor. (when we pass by value, a copy of the object is created, and there the copy constructor is called.)

        this->health = H.health;
        this->level = H.level;
        this->name = H.name;
        // this->message = H.message; // shallow copy

        // Deep Copy implementation
        int size = 0;
        char ch = *(H.message + 1);
        while (ch != '\0')
        {
            ch = *(H.message + size);
            size++;
        }
        // char* temp = new char[size];
        char* temp = new char[size + 1](); // all initialised with null terminator '\0'
        for (int i = 0; i < size; i++)
        {
            temp[i] = *(H.message + i);
        }
        this->message = temp;

        // Deep Copy implementation using built-in functions of C strings
        // char *temp = new char[strlen(H.message) + 1](); // strlen() gives size of string till '\0'
        // strcpy(temp, H.message);
        // this->message = temp;

        count++;
        this->hero_no = count;
        NEW_LINE;
        cout << "Copy Constructor called.";
        NEW_LINE;
        cout << "Hero No. " << hero_no << " created." << endl;
    }

    ~Hero() //Destructor
    {
        delete[] name;
        delete[] message; // will delete if allocated dynamically (will work only in case of copied object, & when the custom copy constructor above will be called)
    }
    
    // Functions
    // also called Methods
    void setVal(int health = 100, char level = 'A')
    {
        if (health < 200 && level < 'G')
        {
            this->health = health;
            this->level = level;
        }
        else
        {
            this->health = 100;
            this->level = 'A';
        }
    }
    void setVal_with_Passwd(char const*& passwd, int health = 200, char level = 'G')
    {
        if (passwd == FAKE_PASSWORD && health >= 200 && level >= 'G')
        {
            this->health = health;
            this->level = level;
        }
        else
        {
            this->health = 100;
            this->level = 'A';
        }
    }
    void setName(char const* name)
    {
        this->name = name;
    }
    void setMessage(char* const& message) // char*& gives error because here we need a const pointer
    {
        this->message = message; // this is allowed bcz the pointer data-type is same: char* , though it is a const pointer and the other one is non-const!
    }
    void printProperties()
    {
        NEW_LINE;
        cout << "Printing Properties of Hero No. " << hero_no << " :" << endl;
        cout << "Name: " << getName() << endl;
        cout << "Health: " << getHealth() << endl;
        cout << "Level: " << getLevel() << endl;
        cout << "Message: " << getMessage() << endl;
    }
    char* getMessage()
    {
        return message;
    }
    char const* getName()
    {
        return name;
    }
    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }
};
int Hero::count = 0; // static property of the class initialised outside

// Value setting functions are called setters()
// Functions for getting the values are getters()

int main(int argc, char const* argv[])
{
    char message1[] = "Kaintt";
    char message2[] = "Mauja";
    char message3[] = "O Balle";
    char message4[] = "Kya Baat Ae";
    Hero spiderman;
    // An Object has min size of 1 byte if it has no properties
    // Otherwise,
    // Size of Object >= (total size of all its properties)
    // cout << sizeof(spiderman) << endl;

    spiderman.setVal(97, 'B');
    spiderman.setName("Spiderman");
    spiderman.setMessage(message1);

    Hero batman(112);
    batman.setName("Batman");
    batman.setMessage(message3);

    Hero hulk;
    char const* passwd = FAKE_PASSWORD;
    hulk.setVal_with_Passwd(passwd, 299, 'X');
    hulk.setName("Hulk");
    hulk.setMessage(message2);

    // cout << endl << "==>> Printing all Heroes one by one:" << endl << endl;

    spiderman.printProperties();
    batman.printProperties();
    hulk.printProperties();

    // Copy Constructor (It is implemented by default behind the scenes)
    // when we pass by value, a copy of the object is created, and there also the copy constructor is called
    Hero my_hero(spiderman); // it copies all the properties of the given object to this object
    
    // Hero my_hero = spiderman; //this also calls the copy constructor and works similarly to the above statement

    my_hero.printProperties();

    // The Default Copy Constructor uses Shallow Copy.
    // Shallow Copy illustration:
    spiderman.message[0] = 'G';
    cout << spiderman.getMessage() << endl;
    cout << my_hero.getMessage() << endl;
    // Shallow copy: just copies the properties as it is. Now if there is a pointer, as in this case char*, the address of the memory which stores value, gets copied. When we change anything, it is reflected by both the pointers (of the copied and original obj), as they both point to the same memory.

    // Dynamic Memory Allocation of Objects:
    Hero* shaktimaan = new Hero;
    (*shaktimaan).setVal_with_Passwd(passwd, 315, 'Y');
    shaktimaan->setName("Shaktimaan");
    shaktimaan->setMessage(message4);
    shaktimaan->printProperties(); // (*shaktimaan).printProperties();

    // release the memory allocated to the object pointed by the 'shaktimaan' pointer
    delete shaktimaan; // calls Destructor automatically
    // Remember: the pointer is not deleted. It is in the stack memory and will be automatically cleared once it is out of scope and function is over.
    return 0;
}