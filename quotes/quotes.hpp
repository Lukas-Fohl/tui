#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>
#include <time.h>   
#include "quote_dictionary.hpp"

using namespace std;


class quote
{
    public:
        const int qoute_lenght = 11;
        vector<vector<string>> final_output_quote;
        quote()
        {
            srand (time(NULL));
            quote_strc new_quote = return_rnd_quote(rand() % qoute_lenght + 1);
            vector<string> n;
            int len;
            if(new_quote.quote.length() > new_quote.name.length())
            {
                len = new_quote.quote.length();
            }else
            {
                len = new_quote.name.length();
            }
            for(int x = 0; x < len+2; x++)
            {
                n.push_back(" ");
            }
            final_output_quote.push_back(n);
            final_output_quote.push_back(n);
            put_quote_in(new_quote);
        }

        void put_quote_in(quote_strc quote_in)
        {
            final_output_quote.at(0).at(0) = "\"";
            for(int i = 0 ;i < quote_in.quote.length(); i++)
            {
                final_output_quote.at(0).at(i+1) = quote_in.quote[i];
            }
            final_output_quote.at(0).at(quote_in.quote.length()+1) = "\"";
            final_output_quote.at(1).at(0) = "-";
            final_output_quote.at(1).at(1) = " ";
            for(int i = 0 ;i < quote_in.name.length(); i++)
            {
                final_output_quote.at(1).at(i+2) = quote_in.name[i];
            }
        }

};