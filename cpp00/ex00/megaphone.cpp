/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbakkas <zouhirbakkas@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:27:24 by zbakkas           #+#    #+#             */
/*   Updated: 2024/11/02 16:59:27 by zbakkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int main(int arc , char **arv)
{
   int i;
   int x;

   if(arc >1)
   {
      x = 1;
      loop()
      {
         
      }
      while (x < arc)
      {
         i = 0;
         while (arv[x][i])
         {
            if(islower(arv[x][i]))
               std::cout  << char(toupper(arv[x][i]));
            else
               std::cout << arv[x][i];
            i++;
         }
      x++;
      }

   }
   else
      std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
   return 1;
}