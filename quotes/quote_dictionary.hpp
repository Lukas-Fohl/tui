#include <iostream>
#include <vector>

using namespace std;

struct quoteStrc
{
    string name;
    string quote;
};

quoteStrc returnRndQuote(int input)
{
    quoteStrc newQuote;
    switch(input)
    {
        case 1:
            newQuote.quote = "das ist auf keine Fall ein Platzhalter";
            newQuote.name  = "ich";
        break;
        case 2:
            newQuote.quote = "20€ sind 20€";
            newQuote.name  = "sun tzu";
        break;
        case 3:
            newQuote.quote = "Hmmmmmm Monkey";
            newQuote.name  = "Oogway";
        break;
        case 4:
            newQuote.quote = "Fuck You And Your Eyebrows";
            newQuote.name  = "w.w.";
        break;
        case 5:
            newQuote.quote = "お兄ちゃんやめてください";
            newQuote.name  = "¯\\_(ツ)_/¯ ";
        break;
        case 6:
            newQuote.quote = "Stehtisch";
            newQuote.name  = ":(";
        break;
        case 7:
            newQuote.quote = "I'm not just sure, Butters. I'm HIV Positive";
            newQuote.name  = "Cartman";
        break;
        case 8:
            newQuote.quote = "Do British people count as an ethnicity for hate crimes?";
            newQuote.name  = "Cartman";
        break;
        case 9:
            newQuote.quote = "you're worse then Hiler, cuz he cared about germans";
            newQuote.name  = "Morty";
        break;
        case 10:
            newQuote.quote = "9/10 Menschen leiden an Durchfall, ich geniesse es";
            newQuote.name  = "So nen Hase";
        break;
        default:
            newQuote.quote = "kennst du Mort";
            newQuote.name  = "meinen Morts cock";
        break;
    }
    return newQuote;
}