#include "Address.h"
Address::Address(){

}
Address::Address(string postal_code, int number_of_citizens){
    this->postal_code = postal_code;
    this->number_of_citizens = number_of_citizens;
}
string Address::getPostalCode(){
    return postal_code;
}
int Address::getNumberOfCitizens(){
    return number_of_citizens;
}
void Address::increase_number_of_citizens() {
    this->number_of_citizens=this->number_of_citizens+1;
}
