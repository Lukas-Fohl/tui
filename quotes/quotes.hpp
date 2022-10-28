#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>
#include <time.h>   
#include "quote_dictionary.hpp"

using namespace std;


class quote
{
    public:
        const int qouteLenght = 11;
        vector<vector<string>> output;
        quote()
        {
            srand (time(NULL));
            quoteStrc newQuote = returnRndQuote(rand() % qouteLenght + 1);
            vector<string> n;
            int len;
            if(newQuote.quote.length() > newQuote.name.length())
            {
                len = newQuote.quote.length();
            }else
            {
                len = newQuote.name.length();
            }
            for(int x = 0; x < len+2; x++)
            {
                n.push_back(" ");
            }
            output.push_back(n);
            output.push_back(n);
            putQuoteIn(newQuote);
        }

        void putQuoteIn(quoteStrc quoteIn)
        {
            output.at(0).at(0) = "\"";
            for(int i = 0 ;i < quoteIn.quote.length(); i++)
            {
                output.at(0).at(i+1) = quoteIn.quote[i];
            }
            output.at(0).at(quoteIn.quote.length()+1) = "\"";
            output.at(1).at(0) = "-";
            output.at(1).at(1) = " ";
            for(int i = 0 ;i < quoteIn.name.length(); i++)
            {
                output.at(1).at(i+2) = quoteIn.name[i];
            }
        }

};