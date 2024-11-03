#ifndef CLASSS_HPP
#define CLASSS_HPP


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
        void getFirstName();
        void getLastName();
        void getNickname();
        void getPhoneNumber();
        void getDarkestSecret();


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
        int getindx();
};
#endif