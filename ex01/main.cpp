/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:44:42 by zbakkas           #+#    #+#             */
/*   Updated: 2024/11/07 16:58:14 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classs.hpp"


void enter_indx(const std::string& str, PhoneBook& phonebook) {
    int i = 0;
    int indx = 0 ;
    if(str.length()==1)
    {
        indx =(str[0] - '0');
        if (indx >= 0 && indx < phonebook.getindx() ) {
        phonebook.getContact(indx);
        } 
        else 
        {
            std::cout << "Bad index\n";
        }
    }
    else
        std::cout << "Bad index\n";

}

int main()
{
    std::string line;
    PhoneBook phonebook;
    phonebook.setindx(0);
    while (1)
    {
        std::cout  << "enter your command :\n    [*] ADD\n    [*] SEARCH\n    [*] EXIT\n";
        // std::cin >> ll;
        std::getline(std::cin, line);
        if(std::cin.eof())
            exit(0);
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
            std::cout<<"|-------------------------------------------|\n";
            while ((phonebook.getindx() <8 && phonebook.getindx()>i) || (phonebook.getindx() >=8 && 8 > i ) )
            {
                phonebook.getContactitems(i++);
            }
            
            std::cout  << "enter the index : ";
            std::getline(std::cin, index_line);
            if(std::cin.eof())
                exit(0);
            enter_indx(index_line,phonebook);
        }
        else if(line=="EXIT")
        {
            std::cout << "EXIT" ; 
            return 0;
        }
        else  
            std::cout << "    bad command -_-\n";
    }
    

}