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
void Contact :: getFirstName()
{
    std::cout << first_name;
}
void Contact :: getLastName()
{
    std::cout << last_name;
}
void Contact :: getNickname()
{
    std::cout << nickname;
}
void Contact :: getPhoneNumber()
{
    std::cout << phone_number;
}
void Contact :: getDarkestSecret()
{
    std::cout << darkest_secret;
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
    contact[indx].setFirstName(inputLine("enter the first name :\n"));
    contact[indx].setLastName(inputLine("enter the last name :\n"));
    contact[indx].setNickname(inputLine("enter the nickname :\n"));
    contact[indx].setPhoneNumber(inputLine("enter the phone number: \n"));
    contact[indx].setDarkestSecret(inputLine("enter the darkest secret :\n"));
    indx++;
    std::cout <<"added successfully\n";
}
void PhoneBook :: getContact(int n)
{
    std::cout << "|" << n <<"|";
    contact[n].getFirstName();
    std::cout << "|";
    contact[n].getLastName();
    std::cout << "|";
    contact[n].getNickname();
    std::cout << "|";
    std::cout << "\n";
  
}
int PhoneBook :: getindx()
{
    return indx;
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
            // cont.setFirstName(inputLine("enter the first name :\n"));
            // cont.setLastName(inputLine("enter the last name :\n"));
            
            // cont.setValues();
            // std::cout << "enter the first name :\n";
            // std::cin >> first_name;
            // std::cout << "enter the last name :\n";
            // std::cin >> last_name;
            // std::cout << "enter the nickname :\n";
            // std::cin >> nickname;
            // std::cout << "enter the phone number: \n";
            // std::cin >> phone_number;
            // std::cout << "enter the darkest secret :\n";
            // std::cin >> darkest_secret;
            // if(first_name.empty() || last_name.empty()|| nickname.empty() || phone_number.empty() || darkest_secret.empty())
            //     std::cout << "is empty";
        }
        else if(line=="SEARCH")
        {
            int i =0;
            std::string index_line;
            std::cout << "|" << "index" <<"|"<< "first name"<< "|"<< "last name" << "|"<< "nickname"<< "|\n";
            while (phonebook.getindx()>i)
            {
                phonebook.getContact(i++);
            }
            
            std::cout  << "enter the index";
            std::getline(std::cin, index_line);
            i = atoi(index_line)
            if(i>=0&&i<=phonebook.getindx())
                phonebook.getContact(i);
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