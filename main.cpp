 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Limb
{
    int startingPoint = 0;
    int footSize = 10;
    int speed = 1;

    void stepForward();
    int stepSize();
};

void Limb::stepForward()
{
    startingPoint += footSize;
}

int Limb::stepSize()
{
    footSize += speed;
    return footSize;
}

struct Person
{
    Limb leftFoot;
    Limb rightFoot;
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();

    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
    howFast = leftFoot.footSize + rightFoot.footSize;
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

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
        std::string memberName = "Steven Jones";
        double accountBalance = 1000.35;
        bool autoPayEnabled = true;
        int birthYear = 1989;
        double weight = 155.5;

        double getMemberAccountBalance(int accountNumber);
        double weighCurrentSelf(double startingWeight, bool finishedWorkout = true);
        void exercise(std::string machineType, int minutes = 60);
    };

    //bill member with monthly fee
    double billMonthlyFee(Member member, float discount = .10f);
    // turn on and off equipment (treadmills, workout machines)
    bool turnOnEquipment(std::string employeeName, bool equipmentState = false);
    // turn on and off electricity
    bool turnOffElectricity(bool switchSetting = true);

    Member gymMember;
};

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
    member.accountBalance -= static_cast<double>(discount * 35.5f);
    return member.accountBalance;
}

bool Gym::turnOnEquipment(std::string employeeName, bool equipmentState)
{
    if (equipmentState == false && employeeName != "None")
        equipmentState = true;
    else
        equipmentState = false;
    return equipmentState;
}

bool turnOffElectricity(bool switchSetting)
{
    if (switchSetting == true)
        switchSetting = false;
    else
        switchSetting = true;
    return switchSetting;
}

struct School
{
    // number of teachers
    int numTeachers = 100;
    // name of school with mascot
    std::string schoolName = "Berkeley Bears";
    // number of students
    int numStudents = 1000;
    // number of courses available
    int numCourses = 350;
    // total amount of education fund
    double educationFund = 150350.75;

    struct Teacher
    {
        std::string teacherName = "Jacqueline James";
        int numWorkingYears = 12;
        std::string deparment = "Mathematics";
        int gradeLevel = 10;
        std::string teacherEmail = "jjames@pausd.edu";

        void teachClass(std::string day, int classDuration = 60);
        bool askForPromotion(double payIncrease);
        void dismissClass(int minRemaining = 0, bool finishedLecture = true);
    };

    // hire or fire teacher
    bool hireOrFireTeacher(Teacher teacher);
    // add student to a class
    void addStudentToClass(Teacher teacher, std::string studentName);
    // add course to full course catalog
    void addCourse(std::string courseName, int gradeLevel = 9);

    Teacher mathTeacher; 
};

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
    bool hire;
    if (teacher.deparment == "Mathematics")
        hire = false;
    else
        hire = true;
    return hire;
}

void School::addStudentToClass(Teacher teacher, std::string studentName)
{
    if (teacher.numWorkingYears > 10 && studentName != "None")
        numStudents += 1;
    else
        numStudents -= 1;
}

void School::addCourse(std::string courseName, int gradeLevel)
{
    if (gradeLevel >= 9 && courseName != "None")
        numCourses += 1;
    else
        numCourses -= 1;
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
};

double PizzaStore::billCustomer(std::string pizzaType, int toppings, float discountSale)
{
    double bill;
    if (pizzaType == "regular")
        discountSale = .20f;
    bill = (20 + (.5 * toppings)) * static_cast<double>(discountSale); 
    return bill;
}

int PizzaStore::addToppings(std::string toppingName, bool maxedOutToppings)
{
    if (maxedOutToppings == false && toppingName != "Pineapple")
        numToppings += 1;
    return numToppings;
}

bool PizzaStore::hireOrFireEmployee(std::string employeeName, int totalStaffMembers)
{
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

struct Laundromat
{
    // number of washing machines
    int numWashingMachines = 54;
    // number of dryers
    int numDryers = 54;
    // number of change machines / coin dispensers
    int coinDispensers = 3;
    // monthly profits
    double monthlyProfits = 1515.53;
    // number of employees
    int numEmployees = 6;

    // increase number of washing machines
    int addWashingMachine(int numberOfMachines, std::string brandName);
    // increase number of change machines
    int addCoinDispenser(int numberOfDispensers = 1, std::string coinType = "Quarter");
    // increase number of employees
    int hireEmployee(int staffTotal, std::string employeeName, bool nowHiring = true);
};

int Laundromat::addWashingMachine(int numberOfMachines, std::string brandName)
{
    if (numberOfMachines > 0 && brandName == "LG")
        numWashingMachines += numberOfMachines;
    return numWashingMachines;
}

int Laundromat::addCoinDispenser(int numberOfDispensers, std::string coinType)
{
    if (coinType == "Quarter" || coinType == "Dimes")
        coinDispensers += numberOfDispensers;
    return coinDispensers;
}

int Laundromat::hireEmployee(int staffTotal, std::string employeeName, bool nowHiring)
{
    if (nowHiring == true && staffTotal < 25 && employeeName != "None")
        numEmployees += 1;
    else
        numEmployees -= 1;
    return numEmployees;
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
};

void Display::changePixelResolution(int newPixelSetting, std::string settingName)
{
    if (colorSetting != settingName)
        numPixels = newPixelSetting;
}

void Display::displayDisplayInfo(std::string brandName, int year, std::string modelName)
{
    std::cout << "Brand Name: " << brandName << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Model Name: " << modelName << std::endl;
}

std::string Display::changeColorCalibration(std::string displayPreference)
{
    colorSetting = displayPreference;
    return colorSetting;
}

struct Memory
{
    // brand
    std::string brand = "Crucial";
    // RAM consumption
    double memoryConsumption = 35.4;
    // memory capacity
    int memoryCapacity = 16;
    // memory speed
    std::string memorySpeed = "DDR4 3200";
    // memory type
    std::string memoryType = "RAM";

    // run programs simultaneously
    void runPrograms(int numPrograms, double totalProgramSize, bool systemOn = true);
    // limit amount of RAM consumption
    int limitRamConsumption(double limitAmount, int totalAppsAllowed = 3);
    // overclock RAM
    bool overclockRam(bool overheated = false);
};

void Memory::runPrograms(int numPrograms, double totalProgramSize, bool systemOn)
{
    if (systemOn == true && numPrograms < 20)
        memoryConsumption = totalProgramSize;
    else
        memoryConsumption = 0;
}

int Memory::limitRamConsumption(double limitAmount, int totalAppsAllowed)
{
    if (totalAppsAllowed <= 3)
        memoryCapacity -= limitAmount;
    return memoryCapacity;
}

bool Memory::overclockRam(bool overheated)
{
    bool engage;
    if (overheated == false)
        engage = true;
    else
        engage = false;
    return engage;
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
};

int CPU::increaseNumCores(int increasedCores)
{
    numCores += increasedCores;
    return numCores;
}

void CPU::overclockCpu(bool overclockedState)
{
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
};

bool Program::checkForUpdates(std::string software, std::string companyName, float versionNum)
{
    bool update;
    if (softwareName == software && softwareCompany == companyName && version < versionNum)
        update = true;
    else
        update = false;
    return update;
}

float Program::installUpdates(float currentVersion, bool update)
{
    float installVersion;
    if (update == true)
        installVersion = currentVersion;
    else
        installVersion = version;
    return installVersion;
}

void Program::displayProgramDetails(float installedVersion, std::string system)
{
    std::cout << "Installed Version: " << installedVersion << std::endl;
    std::cout << "Operation System: " << system << std::endl;
}

struct Storage
{
    // capacity
    int capacity = 5000000;
    // storage type
    std::string storageType = "SSD";
    // dimension size
    double dimensions = 2.5;
    // brand
    std::string brand = "Crucial";
    // type of storage interface
    std::string storageInterface = "SATA III";

    // change boot drive
    bool changeBootDrive(std::string bootDevice);
    // partition drives
    bool partitionDrive(char driveLetter, double shrinkSize, int sizeAvailable);
    // store data to drive
    bool storeDataToDrive(std::string fileName, double memorySize, char driveLetter = 'C');
};

bool Storage::changeBootDrive(std::string bootDevice)
{
    bool changeDrive;
    if (storageType == bootDevice)
        changeDrive = true;
    else
        changeDrive = true;
    return changeDrive;
}

bool Storage::partitionDrive(char driveLetter, double shrinkSize, int sizeAvailable)
{
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
    // 

    // install program
    void installProgram(Program newProgram);
    // increase brightness for screen
    void increaseScreenBrightness(Display screen, double numBrightness = 0.5);
    // increase number of core processing for CPU
    bool increaseCoreProcessing(CPU currentCpu, int numCores = 1);
};

void Computer::installProgram(Program newProgram)
{
    std::cout << "Installed " << newProgram.softwareName << " version " << newProgram.version << std::endl;
}

void Computer::increaseScreenBrightness(Display screen, double numBrightness)
{
    if (numBrightness > 50)
        screen.colorSetting = "Default";
    else
        screen.colorSetting = "Movie";
}

bool increaseCoreProcessing(CPU currentCpu, int numCores)
{
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
    std::cout << "good to go!" << std::endl;
}
