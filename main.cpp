/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()

struct Gym
{
    // number of treadmills
    int numTreadmills = 100;
    // number of dumbbells
    int numDumbells = 50;
    // number of squat racks
    int numSquatRacks = 10;
    // number of users who have a gym membership
    int numUsers = 2500;
    // cost of monthly electricity bill
    double costOfMonthlyElectricity = 1025.35;

    struct Member
    {
        std::string memberName = "";
        double accountBalance = 0.0;
        bool autoPayEnabled = false;
        int birthYear = 0;
        double weight = 0;

        double getMemberAccountBalance(int accountNumber);
        double weighCurrentSelf(double startingWeight, bool finishedWorkout = true);
        void exercise(std::string machineType, int minutes = 60);

        // new member function
        int findMemberYears(int threshold, int startingValue);

        Member();
    };

    //bill member with monthly fee
    double billMonthlyFee(Member member, float discount = .10f);
    // turn on and off equipment (treadmills, workout machines)
    bool turnOnEquipment(std::string employeeName, bool equipmentState = false);
    // turn on and off electricity
    bool turnOffElectricity(bool switchSetting = true);
    // new member function
    int findGymLocation(int threshold, int startingValue);

    Gym();
    
    Member gymMember;
};

Gym::Member::Member()
{
    std::cout << "Creating an object of the Member structure." << std::endl;
}

Gym::Gym() : numTreadmills(0), numDumbells(0), numSquatRacks(0), numUsers(0), costOfMonthlyElectricity(0.0)
{
    std::cout << "Creating an object of the Gym structure." << std::endl;
}

double Gym::Member::getMemberAccountBalance(int accountNumber)
{
    if (accountNumber < 0)
        accountBalance = 0;
    return accountBalance;
}

double Gym::Member::weighCurrentSelf(double startingWeight, bool finishedWorkout)
{
    if (finishedWorkout == true)
        startingWeight -= 1.5;
    else
        startingWeight += .5;
    return startingWeight;
}

void Gym::Member::exercise(std::string machineType, int minutes)
{
    if (minutes == 60 && machineType == "Treadmill")
        weight -= 5.5;
    else if (minutes == 30 && machineType == "Dumbbells")
        weight += 2.5;
    else
        weight += .5;
}

double Gym::billMonthlyFee(Member member, float discount)
{
    std::cout << "Initialized Value of accountBalance: " << member.accountBalance << std::endl;
    std::cout << "double Gym::billMonthlyFee(Member, float) " << member.accountBalance << std::endl;
    member.accountBalance -= static_cast<double>(discount * 35.5f);
    return member.accountBalance;
}

bool Gym::turnOnEquipment(std::string employeeName, bool equipmentState)
{
    std::cout << "Initialized Value of autoPayEnabled: " << gymMember.autoPayEnabled << std::endl;
    std::cout << "bool Gym::turnOnEquipment(std::string, bool) " << equipmentState << std::endl;
    if (equipmentState == false && employeeName != "None")
        equipmentState = true;
    else
        equipmentState = false;
    return equipmentState;
}

bool Gym::turnOffElectricity(bool switchSetting)
{
    std::cout << "Initalized Value of weight: " << gymMember.weight << std::endl;
    std::cout << "bool Gym::turnOffElectricity(bool) " << switchSetting << std::endl;
    if (switchSetting == true)
        switchSetting = false;
    else
        switchSetting = true;
    return switchSetting;
}

int Gym::findGymLocation(int threshold, int startingValue)
{
    Gym gym;
    while(startingValue < threshold)
    {
        gym.numTreadmills += 1;
        gym.numUsers += 1;
        startingValue += 1;
    }
    return gym.numUsers;
}

int Gym::Member::findMemberYears(int threshold, int startingValue)
{
    Member member;
    for (int i = startingValue; startingValue < threshold; i++)
    {
        member.birthYear += 5;
        if (member.birthYear >= threshold)
            break;
    }
    return member.birthYear;    
}

struct School
{
    // number of teachers
    int numTeachers = 0;
    // name of school with mascot
    std::string schoolName {"None"};
    // number of students
    int numStudents = 0;
    // number of courses available
    int numCourses {0};
    // total amount of education fund
    double educationFund = {0.00};

    struct Teacher
    {
        std::string teacherName = "Jacqueline James";
        int numWorkingYears = 12;
        std::string department = "Mathematics";
        int gradeLevel = 10;
        std::string teacherEmail = "jjames@pausd.edu";

        void teachClass(std::string day, int classDuration = 60);
        bool askForPromotion(double payIncrease);
        void dismissClass(int minRemaining = 0, bool finishedLecture = true);
        // new member function
        int returnTeacher(int threshold, int startingValue);

        // Constructor
        Teacher();
    };

    // hire or fire teacher
    bool hireOrFireTeacher(Teacher teacher);
    // add student to a class
    void addStudentToClass(Teacher teacher, std::string studentName);
    // add course to full course catalog
    void addCourse(std::string courseName, int gradeLevel = 9);
    // new member function
    double returnSchool(int threshold, int startingValue);

    // Constructor
    School();

    Teacher mathTeacher; 
};

School::Teacher::Teacher() : teacherName("None"), numWorkingYears(0), department("None"), gradeLevel(9), teacherEmail("none@pausd.edu")
{
    std::cout << "Creating an object of the Teacher structure." << std::endl;
}

School::School()
{
    std::cout << "Creating an object of the School structure." << std::endl;
}

void School::Teacher::teachClass(std::string day, int classDuration)
{
    while (classDuration > 0 && day != "Weekend")
        classDuration -= 1;
}

bool School::Teacher::askForPromotion(double payIncrease)
{
    bool getPromotion;
    if (payIncrease < 15000)
        getPromotion = true;
    else
        getPromotion = false;
    return getPromotion;
}

void School::Teacher::dismissClass(int minRemaining, bool finishedLecture)
{
    if (finishedLecture == true && minRemaining == 0)
        numWorkingYears += 1;
}

bool School::hireOrFireTeacher(Teacher teacher)
{
    std::cout << "Initialized Value of numTeachers: " << numTeachers << std::endl;
    std::cout << "School::hireOrFireTeacher(Teacher) " << teacher.numWorkingYears << std::endl;
    bool hire;
    if (teacher.department == "Mathematics")
        hire = false;
    else
        hire = true;
    return hire;
}

void School::addStudentToClass(Teacher teacher, std::string studentName)
{
    std::cout << "Initialized Value of gradeLevel: " << mathTeacher.gradeLevel << std::endl;
    std::cout << "School::addStudentToClass(Teacher, std::string) " << numStudents << std::endl;
    if (teacher.numWorkingYears > 10 && studentName != "None")
        numStudents += 1;
    else
        numStudents -= 1;
}

void School::addCourse(std::string courseName, int gradeLevel)
{
    std::cout << "Initialized Value of teacherEmail: " << mathTeacher.teacherEmail << std::endl;
    std::cout << "School::addCourse(std::string, int) " << courseName << std::endl;
    if (gradeLevel >= 9 && courseName != "None")
        numCourses += 1;
    else
        numCourses -= 1;
}

int School::Teacher::returnTeacher(int threshold, int startingValue)
{
    Teacher t1;
    while (startingValue < threshold)
    {
        t1.numWorkingYears += 10;
        if (startingValue + threshold < t1.numWorkingYears)
            break;
    }
    return t1.numWorkingYears;
}

double School::returnSchool(int threshold, int startingValue)
{
    School s1;
    for (int i = startingValue; i < threshold; startingValue+=2)
    {
        s1.numTeachers += 1;
        s1.educationFund += 3.5;
        if (startingValue <= s1.numStudents)
            break;
    }
    return s1.educationFund;
}

struct PizzaStore
{
    // number of all employees
    int numEmployees = 15;
    // store'es name
    std::string storeName = "Jeff's Pizza Parlor";
    // number of total sales per month
    double totalMonthlySales = 2625.55;
    // number of pizza ovens
    int numOvens = 5;
    // number of pizza toppings 
    int numToppings = 14;

    // bill customer for pizza
    double billCustomer(std::string pizzaType, int toppings, float discountSale = .10f);
    // add toppings to pizza
    int addToppings(std::string toppingName, bool maxedOutToppings = false);
    // hire or fire employee
    bool hireOrFireEmployee(std::string employeeName, int totalStaffMembers);
    // new member function
    double getPizzaStore(int threshold, int startingValue);

    // Constructor
    PizzaStore();
};

PizzaStore::PizzaStore() : 
numEmployees(0),
storeName("None"),
totalMonthlySales(0.00),
numOvens(5),
numToppings(0)
{
    std::cout << "Creating an object of the PizzaStore structure." << std::endl;
}

double PizzaStore::billCustomer(std::string pizzaType, int toppings, float discountSale)
{
    std::cout << "Initialized Value of storeName: " << storeName << std::endl;
    std::cout << "double PizzaStore::billCustomer(std::string, int, float) " << pizzaType << std::endl;
    double bill;
    if (pizzaType == "regular")
        discountSale = .20f;
    bill = (20 + (.5 * toppings)) * static_cast<double>(discountSale); 
    return bill;
}

int PizzaStore::addToppings(std::string toppingName, bool maxedOutToppings)
{
    std::cout << "Initialized Value of numOvens: " << std::endl;
    std::cout << "int PizzaStore::addToppings(std::string, bool) " << toppingName << std:: endl;
    if (maxedOutToppings == false && toppingName != "Pineapple")
        numToppings += 1;
    return numToppings;
}

bool PizzaStore::hireOrFireEmployee(std::string employeeName, int totalStaffMembers)
{
    std::cout << "Initialized Value of totalMonthlySales: " << totalMonthlySales << std::endl;
    std::cout << "bool PizzaStore::hireOrFireEmployee(std::string, int) " << employeeName << std::endl;
    bool hire;
    if (employeeName != "None" || totalStaffMembers < 25)
    {
        numEmployees += 1;
        hire = true;
    }
    else
    {
        numEmployees -= 1;
        hire = false;
    }
    return hire;
}

double PizzaStore::getPizzaStore(int threshold, int startingValue)
{
    PizzaStore ps1;
    while (startingValue <= threshold)
    {
        ps1.numToppings += (startingValue + 4);
        ps1.totalMonthlySales += 100.25;
        if (ps1.numToppings > threshold)
            break;
    }
    return ps1.totalMonthlySales;
}

struct Laundromat
{
    // number of washing machines
    int numWashingMachines = 0;
    // number of dryers
    int numDryers = 0;
    // number of change machines / coin dispensers
    int coinDispensers = 0;
    // monthly profits
    double monthlyProfits {0.00};
    // number of employees
    int numEmployees = 0;

    // increase number of washing machines
    int addWashingMachine(int numberOfMachines, std::string brandName);
    // increase number of change machines
    int addCoinDispenser(int numberOfDispensers = 1, std::string coinType = "Quarter");
    // increase number of employees
    int hireEmployee(int staffTotal, std::string employeeName, bool nowHiring = true);
    // new member function
    double getNewLaundromat(int threshold, int startingValue);

    // Constructor
    Laundromat();
};

Laundromat::Laundromat()
{
    std::cout << "Creating an object of the Laundromat structure." << std::endl;
}

int Laundromat::addWashingMachine(int numberOfMachines, std::string brandName)
{
    std::cout << "Initialized Value of monthlyProfits: " << monthlyProfits << std::endl;
    std::cout << "int LaundroMat::addWashingMachine(int, std::string) " << brandName << std::endl;
    if (numberOfMachines > 0 && brandName == "LG")
        numWashingMachines += numberOfMachines;
    return numWashingMachines;
}

int Laundromat::addCoinDispenser(int numberOfDispensers, std::string coinType)
{
    std::cout << "Initialized Value of numDryers: " << numDryers << std::endl;
    std::cout << "int Laundromat::addCoinDispenser(int, std::string) " << coinType << std::endl;
    if (coinType == "Quarter" || coinType == "Dimes")
        coinDispensers += numberOfDispensers;
    return coinDispensers;
}

int Laundromat::hireEmployee(int staffTotal, std::string employeeName, bool nowHiring)
{
    std::cout << "Initialized Value of numEmployees: " << numEmployees << std::endl;
    std::cout << "int Laundromat::hireEmployee(int, std::string, bool) " << employeeName << std::endl;
    if (nowHiring == true && staffTotal < 25 && employeeName != "None")
        numEmployees += 1;
    else
        numEmployees -= 1;
    return numEmployees;
}

double Laundromat::getNewLaundromat(int threshold, int startingValue)
{
    Laundromat l;
    for (int i = startingValue; i < threshold; startingValue++)
    {
        l.monthlyProfits += 15.15;
        l.numEmployees -= 10;
        if (threshold + numEmployees < startingValue)
            break;
    }
    return l.monthlyProfits;
}

struct Display
{
    // color calibration setting
    std::string colorSetting = "Movie";
    // total number of pixels
    int numPixels = 3800;
    // brand
    std::string brand = "Samsung";
    // year of make
    int yearOfMake = 2020;
    // model type
    std::string modelType = "SyncMaster 8000";

    // change pixel resolution
    void changePixelResolution(int newPixelSetting = 2073600, std::string settingName = "Default");
    // display brand, year of make and model type
    void displayDisplayInfo(std::string brandName, int year, std::string modelName);
    // set color calibration
    std::string changeColorCalibration(std::string displayPreference = "None");
    // new member function
    std::string getNewDisplay(int threshold, int startingValue);

    // Constructor
    Display();
};

Display::Display() : colorSetting("None"), numPixels(0), brand("None"), yearOfMake(0), modelType("None")
{
    std::cout << "Creating an object of the Display structure." << std::endl;
}

void Display::changePixelResolution(int newPixelSetting, std::string settingName)
{
    std::cout << "Initialized Value of numPixels: " << numPixels << std::endl;
    std::cout << "void Display::changePixelResolution(int, std::string) " << newPixelSetting << std::endl;
    if (colorSetting != settingName)
        numPixels = newPixelSetting;
}

void Display::displayDisplayInfo(std::string brandName, int year, std::string modelName)
{
    std::cout << "Initialized Value of brand: " << brand << std::endl;
    std::cout << "void Display::displayDisplayInfo(std::string, int, std::string) " << modelName << std::endl;
    std::cout << "Brand Name: " << brandName << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Model Name: " << modelName << std::endl;
}

std::string Display::changeColorCalibration(std::string displayPreference)
{
    std::cout << "Initialized Value of colorSetting: " << colorSetting << std::endl;
    std::cout << "std::string Display::changeColorCalibration(std::string) " << displayPreference << std::endl;
    colorSetting = displayPreference;
    return colorSetting;
}

std::string Display::getNewDisplay(int threshold, int startingValue)
{
    Display d1;
    while (startingValue < threshold)
    {
        d1.colorSetting += "i";
        d1.numPixels += 10;
        if (d1.numPixels + startingValue > threshold)
            break;
    }
    return d1.colorSetting;
}

struct Memory
{
    // brand
    std::string brand {"None"};
    // RAM consumption
    double memoryConsumption {0.00};
    // memory capacity
    int memoryCapacity {0};
    // memory speed
    std::string memorySpeed {"None"};
    // memory type
    std::string memoryType {"None"};

    // run programs simultaneously
    void runPrograms(int numPrograms, double totalProgramSize, bool systemOn = true);
    // limit amount of RAM consumption
    int limitRamConsumption(double limitAmount, int totalAppsAllowed = 3);
    // overclock RAM
    bool overclockRam(bool overheated = false);
    // new member function
    double newMemoryComponent(int threshold, int startingValue);

    // Constructor
    Memory();
};

Memory::Memory()
{
    std::cout << "Creating an object of the Memory structure." << std::endl;
}

void Memory::runPrograms(int numPrograms, double totalProgramSize, bool systemOn)
{
    std::cout << "Initialized Value of memoryConsumption: " << memoryConsumption << std::endl; 
    std::cout << "void Memory::runPrograms(int, double, bool) " << numPrograms << std::endl;
    if (systemOn == true && numPrograms < 20)
        memoryConsumption = totalProgramSize;
    else
        memoryConsumption = 0;
}

int Memory::limitRamConsumption(double limitAmount, int totalAppsAllowed)
{
    std::cout << "Initialized Value of memorySpeed: " << memorySpeed << std::endl;
    std::cout << "int Memory::limitRamConsumption(double, int) " << limitAmount << std::endl;
    if (totalAppsAllowed <= 3)
        memoryCapacity -= limitAmount;
    return memoryCapacity;
}

bool Memory::overclockRam(bool overheated)
{
    std::cout << "Initialied Value of memoryType: " << memoryType << std::endl;
    std::cout << "bool Memory::overclockRam(bool) " << overheated << std::endl;
    bool engage;
    if (overheated == false)
        engage = true;
    else
        engage = false;
    return engage;
}

double Memory::newMemoryComponent(int threshold, int startingValue)
{
    Memory m1;
    for (int i = startingValue; i < threshold; i++)
    {
        m1.memoryConsumption += .10;
        m1.memoryCapacity += 4;
        if (m1.memoryCapacity + startingValue >= threshold)
            break;
    }
    return m1.memoryConsumption;
}

struct CPU
{
    // brand
    std::string brand = "Intel";
    // number of cores
    int numCores = 8;
    // core clock speed
    float clockSpeed = 3.6f;
    // integrated graphics
    std::string graphics = "Intel UHD Graphics 750";
    // amount of power consumption / TDP 
    double powerConsumption = 125.0;

    // increase number of cores being used
    int increaseNumCores(int increasedCores = 4);
    // overclock CPU
    void overclockCpu(bool overclockedState = false);
    // launch an application
    bool launchApplication(std::string programName, double memorySize);
    // new member function
    float swapCpu(int threshold, int startingValue);

    // Constructor
    CPU();
};

CPU::CPU() :
brand("None"),
numCores(0),
clockSpeed(0.0f),
graphics("None"),
powerConsumption(0.0)
{
    std::cout << "Creating an object of the CPU structure." << std::endl;
}

int CPU::increaseNumCores(int increasedCores)
{
    std::cout << "Initialized Value of powerConsumption: " << powerConsumption << std::endl;
    std::cout << "int CPU::increaseNumCores(int) " << increasedCores << std::endl;
    numCores += increasedCores;
    return numCores;
}

void CPU::overclockCpu(bool overclockedState)
{
    std::cout << "Initialized Value of clockSpeed: " << clockSpeed << std::endl;
    std::cout << "void CPU::overclockCpu(bool) " << overclockedState << std::endl;
    if (overclockedState == false)
    {
        clockSpeed -= .1f;
        powerConsumption += .5;
    }
    else
        std::cout << "Can not overclock CPU." << std::endl;
}

bool CPU::launchApplication(std::string programName, double memorySize)
{
    std::cout << "Initialized Value of graphics: " << graphics << std::endl;
    std::cout << "bool CPU::launchApplication(std::string, double) " << programName << std::endl;
    bool launch;
    if (memorySize < 499999.99)
    {
        std::cout << "Launching " << programName << std::endl;
        launch = true;
    }
    else
    {
        std::cout << "Can not launch " << programName << std::endl;
        launch = false;
    }
    return launch;
}
float CPU::swapCpu(int threshold, int startingValue)
{
    CPU c;
    while(startingValue < threshold)
    {
        c.clockSpeed += .1f;
        c.numCores += 1;
        startingValue += 5;
        if (startingValue + numCores >= threshold)
           break;
    }
    return c.clockSpeed;
}

struct Program
{
    // name of software
    std::string softwareName = "Pycharm";
    // current installed version
    float version = 3.6f;
    // new update availability
    bool availableUpdate = true;
    // name of software company
    std::string softwareCompany = "JetBrains";
    // operating system
    std::string operatingSystem = "Windows";

    // check for any updates
    bool checkForUpdates(std::string softwareName, std::string companyName, float versionNum);
    // install updates
    float installUpdates(float currentVersion, bool update);
    // display installed version and operating system details
    void displayProgramDetails(float installedVersion, std::string operatingSystem);
    // new member function
    float startNewApplication(int threshold, int startingValue);

    // Constructor
    Program();
};

Program::Program() : softwareName("None"), version(0.0f), availableUpdate(false), softwareCompany("None"), operatingSystem("None")
{
    std::cout << "Creating an object of the Program structure." << std::endl;
}

bool Program::checkForUpdates(std::string software, std::string companyName, float versionNum)
{
    std::cout << "Initialized Value of version: " << version << std::endl;
    std::cout << "bool Program::checkForUpdates(std::string, std::string, float) " << software << std::endl;
    bool update;
    if (softwareName == software && softwareCompany == companyName && version < versionNum)
        update = true;
    else
        update = false;
    return update;
}

float Program::installUpdates(float currentVersion, bool update)
{
    std::cout << "Initialized Value of availableUpdate: " << availableUpdate << std::endl;
    std::cout << "float Program::installUpdates(float, bool) " << currentVersion << std::endl;
    float installVersion;
    if (update == true)
        installVersion = currentVersion;
    else
        installVersion = version;
    return installVersion;
}

void Program::displayProgramDetails(float installedVersion, std::string system)
{
    std::cout << "Initialized Value of softwareName: " << softwareName << std::endl;
    std::cout << "void Program::displayProgramDetails(float, std::string) " << system << std::endl;
    std::cout << "Installed Version: " << installedVersion << std::endl;
    std::cout << "Operation System: " << system << std::endl;
}

float Program::startNewApplication(int threshold, int startingValue)
{
    Program p;
    while (startingValue < threshold)
    {
        p.version += 1.1f;
        p.operatingSystem += "e";
        startingValue++;
    }
    return p.version;
}

struct Storage
{
    // capacity
    int capacity = 0;
    // storage type
    std::string storageType = "None";
    // dimension size
    double dimensions = 0.0;
    // brand
    std::string brand = "None";
    // type of storage interface
    std::string storageInterface = "None";

    // change boot drive
    bool changeBootDrive(std::string bootDevice);
    // partition drives
    bool partitionDrive(char driveLetter, double shrinkSize, int sizeAvailable);
    // store data to drive
    bool storeDataToDrive(std::string fileName, double memorySize, char driveLetter = 'C');
    // new member function
    double installNewStorage(int threshold, int startingValue);

    // Constructor
    Storage();
};

Storage::Storage()
{
    std::cout << "Creating an object of the Storage structure." << std::endl;
}

bool Storage::changeBootDrive(std::string bootDevice)
{
    std::cout << "Initialized Value of storageType: " << storageType << std::endl;
    std::cout << "bool Storage::changeBootDrive(std::string) " << bootDevice << std::endl;
    bool changeDrive;
    if (storageType == bootDevice)
        changeDrive = true;
    else
        changeDrive = true;
    return changeDrive;
}

bool Storage::partitionDrive(char driveLetter, double shrinkSize, int sizeAvailable)
{
    std::cout << "Initialized Value of brand: " << brand << std::endl;
    std::cout << "bool Storage::partitionDrive(char, double, int) " << driveLetter << std::endl;
    bool status;
    if (driveLetter == 'C' && sizeAvailable > 0)
    {
        capacity -= shrinkSize;
        status = true;
    }
    else
        status = false;
    return status;
}

bool Storage::storeDataToDrive(std::string fileName, double memorySize, char driveLetter)
{
    std::cout << "Initialized Value of storageInterface: " << storageInterface << std::endl;
    std::cout << "bool Storage::storeDataToDrive(std::string, double, char) " << fileName << std::endl;
    bool status;
    if (driveLetter == 'C' && (capacity - memorySize) > 0)
    {
        std::cout << fileName << " has been added to harddrive." << std::endl;
        capacity -= memorySize;
        status = true;
    }
    else
    {
        std::cout << fileName << " can not be added to harddrive." << std::endl;
        status = false;
    }
    return status;
}

double Storage::installNewStorage(int threshold, int startingValue)
{
    Storage s;
    for (int i = startingValue; i < threshold; i++)
    {
        s.capacity += 5;
        s.dimensions += .7;
        if (startingValue + s.capacity >= threshold)
            break;
    }
    return s.dimensions;
}

struct Computer
{
    // Display
    Display displayScreen;
    // Memory
    Memory memoryRam;
    // CPU
    CPU centralProcessingUnit;
    // Programs
    Program program;
    // Storage
    Storage storage;

    // install program
    void installProgram(Program newProgram);
    // increase brightness for screen
    void increaseScreenBrightness(Display screen, double numBrightness = 0.5);
    // increase number of core processing for CPU
    bool increaseCoreProcessing(CPU currentCpu, int numCores = 1);
    // new member function
    int purchaseNewComputer(int threshold, int startingValue);

    // Constructor
    Computer();
};

Computer::Computer() : displayScreen(Display()), memoryRam(Memory()), centralProcessingUnit(CPU()), program(Program()), storage(Storage()) 
{
    std::cout << "Creating an object of the Computer structure." << std::endl;
}

void Computer::installProgram(Program newProgram)
{
    std::cout << "Initialized Value of displayScreen's yearOfMake: " << displayScreen.yearOfMake << std::endl;
    std::cout << "void Computer::installprogram(Program) " << newProgram.softwareName << std::endl;
    std::cout << "Installed " << newProgram.softwareName << " version " << newProgram.version << std::endl;
}

void Computer::increaseScreenBrightness(Display screen, double numBrightness)
{
    std::cout << "Initialized Value of memoryRam's memoryCapacity: " << memoryRam.memoryCapacity << std::endl;
    std::cout << "void Computer::increaseScreenBrightness(Display, double) " << numBrightness << std::endl;
    if (numBrightness > 50)
        screen.colorSetting = "Default";
    else
        screen.colorSetting = "Movie";
}

bool Computer::increaseCoreProcessing(CPU currentCpu, int numCores)
{
    std::cout << "Initialized Value of storage's dimensions: " << storage.dimensions << std::endl;
    std::cout << "bool increaseCoreProcessing(CPU, int) " << numCores << std::endl;
    bool increased;
    if (numCores % 2 == 0)
    {
        currentCpu.numCores += numCores;
        increased = true;
    }
    else
        increased = false;
    return increased;
}

int Computer::purchaseNewComputer(int threshold, int startingValue)
{
    Computer c;
    while (startingValue < threshold)
    {
        c.displayScreen.numPixels += 100;
        c.program.version += .1f;
        c.centralProcessingUnit.numCores += 2;
        c.memoryRam.memoryConsumption += 1.1;
        c.storage.capacity += 10;
        if (startingValue + c.storage.capacity > threshold)
            break;
    }
    return c.displayScreen.numPixels;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();

    // Instanstiating Gym object
    std::cout << std::endl;
    Gym gym1;
    double returnedDouble;
    bool returnedBool;
    // Calling each of gym1's member functions and displaying return values
    auto num = gym1.findGymLocation(10, 1);
    std::cout << "return value of gym1.findGymLocation(int, int): " << num << std::endl;
    num = gym1.gymMember.findMemberYears(10, 0);
    std::cout << "gym1.gymMember.findMemberYears(int, int) returns: " << num << std::endl;
    returnedDouble = gym1.billMonthlyFee(gym1.gymMember, .1f);
    std::cout << "Return Value of double Gym::billMonthlyFee(Member, float): " << returnedDouble << std::endl;
    returnedBool = gym1.turnOnEquipment("", false);
    std::cout << "Return Value of bool Gym::turnOnEquipment(string, bool): " << returnedBool << std::endl;
    returnedBool = gym1.turnOffElectricity(false);
    std::cout << "Return Value of bool Gym::turnOffElectricity(bool): " << returnedBool << std::endl;
    // Displaying gym1's member vairiable values
    std::cout << "Value of gym1's member variable numTreadmills: " << gym1.numTreadmills << std::endl;
    std::cout << "Value of gym1's member variable numDumbells: " << gym1.numDumbells << std::endl;
    std::cout << "Value of gym1's member variable numSquatRacks: " << gym1.numSquatRacks << std::endl;
    std::cout << "Value of gym1's member variable numUsers: " << gym1.numUsers << std::endl;
    std::cout << "Value of gym1's member variable costOfMonthlyElectricity: " << gym1.costOfMonthlyElectricity << std::endl;
    std::cout << std::endl;

    // Instansiating School object
    School school1;
    // Calling each of school1's member functions
    returnedDouble = school1.returnSchool(20, 0);
    std::cout << "Return Value of school1.returnSchool(int, int): " << returnedDouble << std::endl;
    num = school1.mathTeacher.returnTeacher(30, 1);
    std::cout << "Return Value of school1.mathTeacher.returnTeacher(int, int): " << num << std::endl;
    returnedBool = school1.hireOrFireTeacher(school1.mathTeacher);
    std::cout << "Return Value of bool School::hireOrFireTeacher(Teacher): " << returnedBool << std::endl;
    school1.addStudentToClass(school1.mathTeacher, "Bill");
    school1.addCourse("Biology", 11);
    // Displaying school1's member variables
    std::cout << "Value of school1's member variable numTeachers: " << school1.numTeachers << std::endl;
    std::cout << "Value of school1's member variable schoolName: " << school1.schoolName << std::endl;  
    std::cout << "Value of school1's member variable numStudents: " << school1.numStudents << std::endl;
    std::cout << "Value of school1's member variable numCourses: " << school1.numCourses << std::endl;
    std::cout << "Value of school1's member variable educationFund: " << school1.educationFund << std::endl;
    std::cout << std::endl;

    // Instanstiating PizzaStore object
    PizzaStore pizza1;

    // Calling each of pizza1's member functions
    returnedDouble = pizza1.getPizzaStore(50, 3);
    std::cout << "Return Value of pizza1.getPizzaStore(int, int): " << returnedDouble << std::endl;
    returnedDouble = pizza1.billCustomer("Pepperoni", 10, .05f);
    std::cout << "Return Value of double PizzaStore::billCustomer(std::string, int, float): " << returnedDouble << std::endl;
    int returnedInt = pizza1.addToppings("Pepperoni", false);
    std::cout << "Return Value of int PizzaStore::addToppings(std::string, bool): " << returnedInt << std::endl;
    returnedBool = pizza1.hireOrFireEmployee("Bob", 5);
    std::cout << "Return Value of bool PizzaSTore:: addToppings(std::string, int): " << returnedBool << std::endl;
    // Displaying pizza1's member variables
    std::cout << "Value of pizza1's member variable numEmployees: " << pizza1.numEmployees << std::endl;
    std::cout << "Value of pizza1's member variable storeName: " << pizza1.storeName << std::endl;
    std::cout << "Value of pizza1's member variable totalMonthlySales: " << pizza1.totalMonthlySales << std::endl;
    std::cout << "Value of pizza1's member variable numOvens: " << pizza1.numOvens << std::endl;
    std::cout << "Value of pizza1's member variable numToppings " << pizza1.numToppings << std::endl;
    std::cout << std::endl;

    // Instanstiating Laundromat object
    Laundromat laundromat1;

    // Calling each of laundromat1's member functions
    returnedDouble = laundromat1.getNewLaundromat(100, 10);
    std::cout << "Return Value of laundromat1.getNewLaundromat(int, int): " << returnedDouble << std::endl;
    returnedInt = laundromat1.addWashingMachine(2, "LG");
    std::cout << "Return Value of int Laundromat::addWashingMachine(int, std::string): " << returnedInt << std::endl;
    returnedInt = laundromat1.addCoinDispenser(1, "Nickel");
    std::cout << "Return Value of int Laundromat::addCoinDispenser(int, std::string): " << returnedInt << std::endl;
    returnedInt = laundromat1.hireEmployee(5, "Alicia", true);
    std::cout << "Return Value of int Laundromat::hireEmployee(int, std::string, bool): " << returnedInt << std::endl;

    // Displaying laundromat1's member variables
    std::cout << "Value of laundromat1's member variable numWashingMachines: " << laundromat1.numWashingMachines << std::endl;
    std::cout << "Value of laundromat1's member variable numDryers: " << laundromat1.numDryers << std::endl;
    std::cout << "Value of laundromat1's member variable coinDispensers: " << laundromat1.coinDispensers << std::endl;
    std::cout << "Value of laundromat1's member variable monthlyProfits: " << laundromat1.monthlyProfits << std::endl;
    std::cout << "Value of laundromat1's member variable numEmployees: " << laundromat1.numEmployees << std::endl;
    std::cout << std::endl;

    // Instanstiating Display object
    Display display1;

    // Calling each of display1's member functions
    auto string = display1.getNewDisplay(40, 5);
    std::cout << "Return Value of display1.getNewDisplay(int, int): " << string << std::endl;
    display1.changePixelResolution(1500, "Unknown");
    display1.displayDisplayInfo("Samsung", 2020, "SyncMaster 3000");
    std::string returnedString = display1.changeColorCalibration("Sports");
    std::cout << "Return value of std::string Display::changeColorCalibration(std::string): " << returnedString << std::endl;

    // Displaying display1's member variables
    std::cout << "Value of display1's member variable colorSetting: " << display1.colorSetting << std::endl;
    std::cout << "Value of display1's member variable numPixels: " << display1.numPixels << std::endl;
    std::cout << "Value of display1's member variable brand: " << display1.brand << std::endl;
    std::cout << "Value of display1's member variable yearOfMake: " << display1.yearOfMake << std::endl;
    std::cout << "Value of display1's member variable modelType: " << display1.modelType << std::endl;
    std::cout << std::endl;

    // Instantiating Memory object
    Memory memory1;

    // Calling each of memory1's member functions
    returnedDouble = memory1.newMemoryComponent(100, 0);
    std::cout << "Return Value of memory1.newMemoryComponent(int, int): " << returnedDouble << std::endl;
    memory1.runPrograms(10, 5.5, true);
    returnedInt = memory1.limitRamConsumption(10.50, 5);
    std::cout << "Return Value of int Memory::limitRamConsumption(double, int): " << returnedInt << std::endl;
    returnedBool = memory1.overclockRam(true);
    std::cout << "Return Value of bool Memory::overclockRam(bool): " << returnedBool << std::endl;

    // Displaying each of memory1's member variables
    std::cout << "Value of memory1's member variable brand: " << memory1.brand << std::endl;
    std::cout << "Value of memory1's member variable memoryConsumption: " << memory1.memoryConsumption << std::endl;
    std::cout << "Value of memory1's member variable memoryCapacity: " << memory1.memoryCapacity << std::endl;
    std::cout << "Value of memory1's member variable memorySpeed: " << memory1.memorySpeed << std::endl;
    std::cout << "Value of memory1's member variable memoryType: " << memory1.memoryType << std::endl;
    std::cout << std::endl;

    // Instantiating CPU object
    CPU cpu1;

    // Calling each of cpu1's member functions
    auto flt = cpu1.swapCpu(200, 0);
    std::cout << "Return Value of cpu1.swapCpu(int, int): " << flt << std::endl;
    returnedInt = cpu1.increaseNumCores(6);
    std::cout << "Return Value of int CPU::increaseNumCores(int): " << returnedInt << std::endl;
    cpu1.overclockCpu(false);
    returnedBool = cpu1.launchApplication("Ableton", 150.35);
    std::cout << "Return Value of bool CPU::launchApplication(std::string, double): " << returnedBool << std::endl;

    // Displaying each of cpu1's member variables
    std::cout << "Value of cpu1's member variable brand: " << cpu1.brand << std::endl;
    std::cout << "Value of cpu1's member variable numCores: " << cpu1.numCores << std::endl;
    std::cout << "Value of cpu1's member variable clockSpeed: " << cpu1.clockSpeed << std::endl;
    std::cout << "Value of cpu1's member variable graphics: " << cpu1.graphics << std::endl;
    std::cout << "Value of cpu1's member variable powerConsumption: " << cpu1.powerConsumption << std::endl;
    std::cout << std::endl;

    // Instantiating Program object
    Program program1;

    // Calling each of program1's member functions
    flt = program1.startNewApplication(150, 0);
    std::cout << "Return Value of program1.startNewApplication(int, int): " << flt << std::endl;
    returnedBool = program1.checkForUpdates("Visual Studio", "Microsoft", 3.2f);
    std::cout << "Return Value of bool Program::checkForUpdates(std::string, std::string, float): " << returnedBool << std::endl;
    float returnedFloat = program1.installUpdates(3.3f, true);
    std::cout << "Return Value of float Program::installUpdates(float, bool): " << returnedFloat << std::endl;
    program1.displayProgramDetails(5.5, "MacOS");

    // Displaying each of program1's member variables
    std::cout << "Value of program1's member variable softwareName: " << program1.softwareName << std::endl;
    std::cout << "Value of program1's member variable version: " << program1.version << std::endl;
    std::cout << "Value of program1's member variable availableUpdate: " << program1.availableUpdate << std::endl;
    std::cout << "Value of program1's member variable softwareCompany: " << program1.softwareCompany << std::endl;
    std::cout << "Value of program1's member variable operatingSystem: " << program1.operatingSystem << std::endl;
    std::cout << std::endl;

    // Instantiating Storage object
    Storage storage1;

    // Calling each of storage1's member functions
    returnedDouble = storage1.installNewStorage(50, 0);
    std::cout << "Return Value of storage1.installNewStorage(int, int): " << returnedDouble << std::endl;
    returnedBool = storage1.changeBootDrive("USB Flash Drive");
    std::cout << "Return Value of bool Storage::changeBootDrive(std::string): " << returnedBool << std::endl;
    returnedBool = storage1.partitionDrive('D', 300.35, 3500);
    std::cout << "Return Value of bool Storage::partitionDrive(char, double, int): " << returnedBool << std::endl;
    returnedBool = storage1.storeDataToDrive("HelloWorld.png", .55, 'C');
    std::cout << "Return Value of bool Storage::storeDataToDrive(std::string, double, char): " << returnedBool << std::endl;

    // Displaying each of storage1's member variables
    std::cout << "Value of storage1's member variable capacity: " << storage1.capacity << std::endl;
    std::cout << "Value of storage1's member variable storageType: " << storage1.storageType << std::endl;
    std::cout << "Value of storage1's member variable dimensions: " << storage1.dimensions << std::endl;
    std::cout << "Value of storage1's member variable brand: " << storage1.brand << std::endl;
    std::cout << "Value of storage1's member variable storageInterface: " << storage1.storageInterface << std::endl;
    std::cout << std::endl; 

    // Instantiating Computer object
    Computer computer1;

    // Calling each of computer1's member functions
    num = computer1.purchaseNewComputer(100, 0);
    std::cout << "Return Value of computer1.purchaseNewComputer(int, int): " << num << std::endl;
    computer1.installProgram(program1);
    computer1.increaseScreenBrightness(display1, 5.55);
    returnedBool = computer1.increaseCoreProcessing(cpu1, 6);
    std::cout << "Return Value of bool Computer::increaseCoreProcessing(CPU, int): " << returnedBool << std::endl;

    // Displaying each of computer1's member variables
    std::cout << "Value of computer1's member variable displayScreen: " << computer1.displayScreen.colorSetting << " " << computer1.displayScreen.numPixels << " " << computer1.displayScreen.brand << " " << computer1.displayScreen.yearOfMake << " " << computer1.displayScreen.modelType << std::endl;
    std::cout << "Value of computer1's member variable memoryRam: " << computer1.memoryRam.brand << " " << computer1.memoryRam.memoryConsumption << " " << computer1.memoryRam.memoryCapacity << " " << computer1.memoryRam.memorySpeed << " " << computer1.memoryRam.memoryType << std::endl;
    std::cout << "Value of computer1's member variable centralProcessingUnit: " << computer1.centralProcessingUnit.brand << " " << computer1.centralProcessingUnit.numCores << " " << computer1.centralProcessingUnit.clockSpeed << " " << computer1.centralProcessingUnit.graphics << " " << computer1.centralProcessingUnit.powerConsumption << std::endl;
    std::cout << "Value of computer1's member variable program: " << computer1.program.softwareName << " " << computer1.program.version << " " << computer1.program.availableUpdate << " " << computer1.program.softwareCompany << " " << computer1.program.operatingSystem << std::endl;
    std::cout << "Value of computer1's member variable storage: " << computer1.storage.capacity << " " << computer1.storage.storageType << " " << computer1.storage.dimensions << " " << computer1.storage.brand << " " << computer1.storage.storageInterface << std::endl;

    std::cout << "good to go!" << std::endl;
}
