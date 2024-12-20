/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classs.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:21 by zbakkas           #+#    #+#             */
/*   Updated: 2024/11/07 16:59:22 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSS_HPP
#define CLASSS_HPP
#include <iostream>
#include <iomanip>

class Contact
{
    private:
        std::string first_name, last_name ,nickname ,phone_number ,darkest_secret;
    public:
        void setFirstName(std::string str);
        void setLastName(std::string str);
        void setNickname(std::string str);
        void setPhoneNumber(std::string str);
        void setDarkestSecret(std::string str);
        std::string getFirstName();
        std::string getLastName();
        std::string getNickname();
        std::string getPhoneNumber();
        std::string getDarkestSecret();


};


class PhoneBook  
{
    private:
        Contact contact[8];
        int indx;
    public:
        void setindx(int n);
        void setContact();
        void getContact(int n);
        void getContactitems(int n);
        int getindx();
};
#endif