/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:11:59 by zbakkas           #+#    #+#             */
/*   Updated: 2024/11/02 21:49:03 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include  "classs.hpp"
#include <iomanip>



////////// ste //////////
void Contact :: setFirstName(std::string str)
{
    first_name = str;
}
void Contact :: setLastName(std::string str)
{
    last_name = str;
}

void Contact :: setNickname(std::string str)
{
    nickname = str;
}
void Contact :: setPhoneNumber(std::string str)
{
    phone_number = str;
}
void Contact :: setDarkestSecret(std::string str)
{
    darkest_secret = str;
}

/////// get /////////
std::string Contact :: getFirstName()
{
    return first_name;
}
std::string Contact :: getLastName()
{
    return last_name ;
}
std::string Contact :: getNickname()
{
    return nickname ;
}
std::string Contact :: getPhoneNumber()
{
    return phone_number ;
}
std::string Contact :: getDarkestSecret()
{
    return phone_number ;
}
///////////////////////

std::string inputLine(std::string com)
{
    std::string str;
    while (str.empty())
    {
        std::cout  << com;
        std::getline(std::cin, str);
    }
    return str;
}
void PhoneBook :: setindx(int n)
{
    indx = n;
}
void PhoneBook :: setContact()
{
    
    contact[(indx)%8].setFirstName(inputLine("enter the first name : "));
    contact[(indx)%8].setLastName(inputLine("enter the last name : "));
    contact[(indx)%8].setNickname(inputLine("enter the nickname : "));
    contact[(indx)%8].setPhoneNumber(inputLine("enter the phone number: "));
    contact[(indx)%8].setDarkestSecret(inputLine("enter the darkest secret : "));
    indx++;
    std::cout <<"added successfully\n";
}

void PhoneBook :: getContactitems(int n)
{
    std::cout << "|"<< n << "         |";
    if (contact[n].getFirstName().length() >= 10)
		std::cout << contact[n].getFirstName().substr(0,9) << "." << "|";
	else
	    std::cout << std::right << std::setw(10) << contact[n].getFirstName() << "|";

    if (contact[n].getLastName().length() >= 10)
		std::cout << contact[n].getLastName().substr(0,9) << "." << "|";
	else
	    std::cout << std::right << std::setw(10) << contact[n].getLastName() << "|";

    if (contact[n].getNickname().length() >= 10)
		std::cout << contact[n].getNickname().substr(0,9) << "." << "|";
	else
	    std::cout << std::right << std::setw(10) << contact[n].getNickname() << "|\n";

}
void PhoneBook :: getContact(int n)
{
    
    std::cout << contact[n].getFirstName() <<"\n";
    std::cout << contact[n].getLastName() << "\n";
    std::cout << contact[n].getNickname()<<"\n";
    std::cout << contact[n].getPhoneNumber()<<"\n";
    std::cout << contact[n].getDarkestSecret() <<"\n";
}
int PhoneBook :: getindx()
{
    return indx;
}
void enter_indx(const std::string& str, PhoneBook& phonebook) {
    int i = 0;
    int indx = 0;
    
    // Convert the string to an integer
    while (str[i]) {
        if (isdigit(str[i])) {  // Ensure we are working with numeric characters
            indx = (indx * 10) + (str[i] - '0');
        } else {
            std::cout << "Invalid index input.\n";
            return;
        }
        i++;
    }
    
    // Check if the index is within the valid range
    if (indx >= 0 && indx < phonebook.getindx() ) {
        phonebook.getContact(indx);
    } else {
        std::cout << "Bad index\n";
    }
}

int main()
{
    std::string line;
    PhoneBook phonebook;
    phonebook.setindx(0);
    while (1)
    {
        std::cout  << "enter your command\nADD\nSEARCH\nEXIT\n";
        // std::cin >> ll;
        std::getline(std::cin, line);
            // std::cout << "line is ::"<< line << "\n";
        if(line == "ADD")
        {
            phonebook.setContact();
        }
        else if(line=="SEARCH")
        {
            int i =0;
            std::string index_line;
            std::cout << "|" << "     index" <<"|"<< "first name"<< "|"<< " last name" << "|"<< "  nickname"<< "|\n";
            while ((phonebook.getindx() <8 && phonebook.getindx()>i) || (phonebook.getindx() >=8 && 8 > i ) )
            {
                phonebook.getContactitems(i++);
            }
            
            std::cout  << "enter the index : ";
            std::getline(std::cin, index_line);
            enter_indx(index_line,phonebook);
        }
        else if(line=="EXIT")
        {
            std::cout << "EXIT" ; 
            return 0;
        }
        else  
            std::cout << "bad command\n";
    }
    

}