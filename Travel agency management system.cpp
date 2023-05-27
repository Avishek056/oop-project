#include <iostream>
#include <cstring>

using namespace std;

// Base class for TravelPackage
class TravelPackage {
protected:
    int packageId;
    char destination[50];
    int duration;

public:
    // Parameterized constructor
    TravelPackage(int id, const char* dest, int dur) : packageId(id), duration(dur) {
        strcpy(destination, dest);
    }

    // Display package details
    virtual void displayDetails() {
        cout << "Package ID: " << packageId << endl;
        cout << "Destination: " << destination << endl;
        cout << "Duration: " << duration << " days" << endl;
    }
};

// Derived class for AdventurePackages
class AdventurePackage : public TravelPackage {
private:
    char activity[50];

public:
    // Parameterized constructor
    AdventurePackage(int id, const char* dest, int dur, const char* act)
        : TravelPackage(id, dest, dur) {
        strcpy(activity, act);
    }

    // Display package details
    void displayDetails() override {
        cout << "=== Adventure Package ===" << endl;
        TravelPackage::displayDetails();
        cout << "Activity: " << activity << endl;
    }
};

// Derived class for LeisurePackages
class LeisurePackage : public TravelPackage {
private:
    char hotel[50];
    char mealPlan[20];

public:
    // Parameterized constructor
    LeisurePackage(int id, const char* dest, int dur, const char* htl, const char* meal)
        : TravelPackage(id, dest, dur) {
        strcpy(hotel, htl);
        strcpy(mealPlan, meal);
    }

    // Display package details
    void displayDetails() override {
        cout << "=== Leisure Package ===" << endl;
        TravelPackage::displayDetails();
        cout << "Hotel: " << hotel << endl;
        cout << "Meal Plan: " << mealPlan << endl;
    }
};

// Base class for TravelAgency
class TravelAgency {
protected:
    int agencyId;
    char agencyName[50];

public:
    // Parameterized constructor
    TravelAgency(int id, const char* name) : agencyId(id) {
        strcpy(agencyName, name);
    }

    // Virtual function to book a package
    virtual void bookPackage() {
        cout << "Booking a package from the base class" << endl;
    }

    // Display agency details
    virtual void displayDetails() {
        cout << "Agency ID: " << agencyId << endl;
        cout << "Agency Name: " << agencyName << endl;
    }
};

// Derived class for OnlineTravelAgency
class OnlineTravelAgency : public TravelAgency {
private:
    char website[50];

public:
    // Parameterized constructor
    OnlineTravelAgency(int id, const char* name, const char* site)
        : TravelAgency(id, name) {
        strcpy(website, site);
    }

    // Book a package
    void bookPackage() override {
        cout << "Booking a package from the OnlineTravelAgency" << endl;
    }

    // Display agency details
    void displayDetails() override {
        cout << "=== Online Travel Agency ===" << endl;
        TravelAgency::displayDetails();
        cout << "Website: " << website << endl;
    }
};

// Derived class for OfflineTravelAgency
class OfflineTravelAgency : public TravelAgency {
private:
    char address[100];
public:
    OfflineTravelAgency(int id, const char* name, const char* addr)
        : TravelAgency(id, name) {
        strcpy(address, addr);
    }
    void bookPackage() override {
        cout << "Booking a package from the OfflineTravelAgency" << endl;
    }

    // Display agency details
    void displayDetails() override {
        cout << "=== Offline Travel Agency ===" << endl;
        TravelAgency::displayDetails();
        cout << "Address: " << address << endl;
    }
};

int main() {
    // Create objects of TravelPackages
    TravelPackage package1(1, "Mountains", 7);
    AdventurePackage package2(2, "Beach", 5, "Scuba Diving");
    LeisurePackage package3(3, "City Tour", 3, "Luxury Hotel", "All-Inclusive");

    // Display package details
    cout << "=== Travel Package Details ===" << endl;
    package1.displayDetails();
    cout << endl;
    package2.displayDetails();
    cout << endl;
    package3.displayDetails();
    cout << endl;

    // Create objects of TravelAgency
    TravelAgency* agency1 = new OnlineTravelAgency(101, "TravelNow", "www.travelnow.com");
    TravelAgency* agency2 = new OfflineTravelAgency(102, "Global Travel", "123 Main St");

    // Display agency details
    cout << "=== Travel Agency Details ===" << endl;
    agency1->displayDetails();
    cout << endl;
    agency2->displayDetails();
    cout << endl;

    // Book a package
    agency1->bookPackage();
    cout << endl;
    agency2->bookPackage();
    cout << endl;

    // Clean up
    delete agency1;
    delete agency2;
    return 0;
}

