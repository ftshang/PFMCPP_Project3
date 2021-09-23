/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car car); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car car);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  
};


/*
Thing 1) Indoor Gym
5 properties:
    1) number of treadmills (int)
    2) number of dumbbells (int)
    3) number of squat racks (int)
    4) number of users who have a gym membership (int)
    5) cost of monthly electricity bill (double)
3 things it can do:
    1) bill member with monthly fee
    2) turn on and off equipment (treadmills, workout machines)
    3) turn on and off electricity
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

/*
Thing 2) School
5 properties:
    1) number of teachers (int)
    2) name of school with mascot (std::string)
    3) number of students (int)
    4) number of courses available (int)
    5) total amount of education fund (double)
3 things it can do:
    1) hire or fire teacher
    2) add student to a class
    3) add course to full course catalog
 */

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

/*
Thing 3) Pizza Store
5 properties:
    1) number of all employees (int)
    2) store's name (std::string)
    3) number of total sales per month (double)
    4) number of pizza ovens (int)
    5) number of pizza toppings (int)
3 things it can do:
    1) bill customer for pizza
    2) add toppings to pizza
    3) hire or fire employee
 */

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
    double billCustomer(std::string pizzaType, int numToppings, float discountSale = .10f);
    // add toppings to pizza
    int addToppings(std::string toppingName, bool maxedOutToppings = false);
    // hire or fire employee
    bool hireOrFireEmployee(std::string employeeName, int totalStaffMembers);
};

/*
Thing 4) Laundromat 
5 properties:
    1) number of washing machines (int)
    2) number of dryers (int)
    3) number of change machines / coin dispensers (int) 
    4) monthly profits (double)
    5) number of employees (int)
3 things it can do:
    1) increase number of washing machines
    2) increase number of change machines
    3) increase number of employees
 */

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

/*
Thing 5) Display
5 properties:
    1) color calibration setting (std::string)
    2) total number of pixels (int)
    3) brand (std::string)
    4) year of make (int)
    5) model type (std::string)
3 things it can do:
    1) change pixel resolution
    2) display brand, year of make, and model type
    3) set color calibration setting
 */

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

/*
Thing 6) Memory
5 properties:
    1) brand (std::string)
    2) RAM consumption (double)
    3) memory capacity (int)
    4) memory speed (std::string)
    5) memory type (std::string)
3 things it can do:
    1) run programs simultaneously 
    2) limit amount of RAM consumption
    3) overclock RAM
 */

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

/*
Thing 7) CPU
5 properties:
    1) brand (std::string)
    2) number of cores (int)
    3) core clock speed (float)
    4) integrated graphics (std::string)
    5) amount of power consumption / TDP (double)
3 things it can do:
    1) increase number of cores being used
    2) overclock CPU
    3) launch an application
 */

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

/*
Thing 8) Programs
5 properties:
    1) name of software (std::string)
    2) current installed version (float)
    3) new update availability (bool)
    4) name of software company (std::string)
    5) operating system (std::string)
3 things it can do:
    1) check for any updates
    2) install updates
    3) display installed version and operating system details 
 */

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
    float installUpdates(float currentVersion, bool availableUpdate);
    // display installed version and operating system details
    void displayProgramDetails(float installedVersion, std::string operatingSystem);
};

/*
Thing 9) Storage
5 properties:
    1) capactiy (int)
    2) storage type (std::string)
    3) dimension size (double)
    4) brand (std::string)
    5) type of storage interface (std::string)
3 things it can do:
    1) change boot drive
    2) partition drives
    3) store data to drive
 */

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

/*
Thing 10) Computer
5 properties:
    1) Display
    2) Memory
    3) CPU
    4) Programs
    5) Storage 

3 things it can do:
    1) install program
    2) increase brightness for screen
    3) increase number of core processing for CPU
 */

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
