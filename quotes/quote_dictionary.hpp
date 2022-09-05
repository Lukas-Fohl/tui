#include <iostream>
#include <vector>

using namespace std;

struct quote_strc
{
    string name;
    string quote;
};

quote_strc return_rnd_quote(int input)
{
    quote_strc new_quote;
    switch(input)
    {
        case 1:
            new_quote.quote = "das ist auf keine Fall ein Platzhalter";
            new_quote.name  = "ich";
        break;
        case 2:
            new_quote.quote = "20€ sind 20€";
            new_quote.name  = "sun tzu";
        break;
        case 3:
            new_quote.quote = "Hmmmmmm Monkey";
            new_quote.name  = "Oogway";
        break;
        case 4:
            new_quote.quote = "Fuck You And Your Eyebrows";
            new_quote.name  = "w.w.";
        break;
        case 5:
            new_quote.quote = "お兄ちゃんやめてください";
            new_quote.name  = "¯\\_(ツ)_/¯ ";
        break;
        case 6:
            new_quote.quote = "Stehtisch";
            new_quote.name  = ":(";
        break;
        case 7:
            new_quote.quote = "I'm not just sure, Butters. I'm HIV Positive";
            new_quote.name  = "Cartman";
        break;
        case 8:
            new_quote.quote = "Do British people count as an ethnicity for hate crimes?";
            new_quote.name  = "Cartman";
        break;
        case 9:
            new_quote.quote = "you're worse then Hiler, cuz he cared about germans";
            new_quote.name  = "Morty";
        break;
        case 10:
            new_quote.quote = "9/10 Menschen leiden an Durchfall, ich geniesse es";
            new_quote.name  = "So nen Hase";
        break;
        default:
            new_quote.quote = "kennst du Mort";
            new_quote.name  = "meinen Morts cock";
        break;
    }
    return new_quote;
}