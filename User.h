using namespace std;

//constant values used (atm) for testing login
#define MANAGER 000
#define MAINTENANCE 001
#define CUSTOMER 002

class User{
	int type;
	int userID;
    bool manager;
    bool maintenance;
    bool customer;

public:
    //constructor
    User(){

    }

    //overloaded constructor
    User(int givenType, int givenID){
        try{
          setType(givenType);
        }catch(string message){
            throw message;
        }
        setID(givenID);
    }

    //getter for type
    int getType(){
        if (manager == true && maintenance == false && customer == false) {
            return MANAGER;
        }else if(manager == false && maintenance == true && customer == false){
            return MAINTENANCE;
        }else if(manager == false && maintenance == false && customer == true){
            return CUSTOMER;
        }else{
            throw "userType is set to an invalid value";
        }
    }

    //getter for ID
    int getID(){
        return userID;
    }

    //setter for type
    void setType(int givenType){
        if (givenType > 002) {
            throw "Attempted to set UserType to an invalid type.\n";
        } else {
            if (givenType == MANAGER) {
                manager = true;
                maintenance = false;
                customer = false;
            }else if(givenType == MAINTENANCE){
                manager = false;
                maintenance = true;
                customer =false;
            }else{
                manager = false;
                maintenance =false;
                customer = true;
            }
        }
    }

    //setter for ID
    void setID(int givenID){
        userID = givenID;
    }

    //method to see if the user is a manager
    bool isManager(){
        return manager;
    }

    //method to see if they user is maintenance
    bool isMaintenance(){
        return maintenance;
    }

    //method to see if the user is a customer
    bool isCustomer(){
        return customer;
    }

}currentUser, manager, maintenance;

//a class that extends our User class for the purpose of modelling customers
class Customer: public User{
	Account savings;
	Chequing chequing;
public:
	Customer(int ID):User(CUSTOMER, ID){

    }

    Customer(){

    }
	Account * getSavings(){
		Account * acct = &savings;
        return acct;
	}
	Chequing * getChequing(){
		Chequing * cheq = &chequing;
        return cheq;
	}

}currentCustomer;
