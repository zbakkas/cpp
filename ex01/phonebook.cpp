/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:11:59 by zbakkas           #+#    #+#             */
/*   Updated: 2024/11/09 16:14:37 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include  "classs.hpp"




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
    return darkest_secret ;
}
///////////////////////

std::string inputLine(std::string com)
{
    std::string str;
    while (str.empty())
    {
        std::cout  << com;
        std::getline(std::cin, str);
        if(std::cin.eof())
            exit(0);
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
    std::cout << "|         "<< n << "|";
    if (contact[n].getFirstName().length() > 10)
		std::cout << contact[n].getFirstName().substr(0,9) << "." << "|";
	else
	    std::cout << std::right << std::setw(10) << contact[n].getFirstName() << "|";

    if (contact[n].getLastName().length() > 10)
		std::cout << contact[n].getLastName().substr(0,9) << "." << "|";
	else
	    std::cout << std::right << std::setw(10) << contact[n].getLastName() << "|";

    if (contact[n].getNickname().length() > 10)
		std::cout << contact[n].getNickname().substr(0,9) << "." << "|\n";
	else
	    std::cout << std::right << std::setw(10) << contact[n].getNickname() << "|\n";

}
void PhoneBook :: getContact(int n)
{
    
    std::cout << "   [-] First Name: "<<contact[n].getFirstName() <<"\n";
    std::cout << "   [-] Last Name: "<<contact[n].getLastName() << "\n";
    std::cout << "   [-] Nickname: " <<contact[n].getNickname()<<"\n";
    std::cout << "   [-] PhoneNumber"<<contact[n].getPhoneNumber()<<"\n";
    std::cout << "   [-] Darkest Secret: "<<contact[n].getDarkestSecret() <<"\n";
}
int PhoneBook :: getindx()
{
    return indx;
}

