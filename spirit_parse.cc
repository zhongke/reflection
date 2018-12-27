#include <boost/spirit/include/qi.hpp>

#include <string>
#include <vector>
#include <map>
#include <iostream>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

// struct Expression
// {
//         // std::map<std::string(), std::vector<std::pair<std::string,std::string>()>> result;

//         std::string expression;
// };

// BOOST_FUSION_ADAPT_STRUCT(
//         Expression,
//         (std::string, expression)
//         )

template <typename Iterator>
struct queryString_grammar
  : qi::grammar<Iterator, std::string>
{
public:
    queryString_grammar()
      : queryString_grammar::base_type(expression)
    {
        using qi::lexeme;
        using ascii::char_;

        token %= lexeme[+(char_)];
        key %= token;
        subKey %= token;
        subValue %= token;
        item %= subKey >> - (":" >> subValue);
        array %= item >> * ("," >> item);
        value %= token | "{" >> array >>"}";
        condition %= key >>  "=" >> value;
        expression %= condition >> *(&condition);
    }
private:
    qi::rule<Iterator, std::string()> token;
    qi::rule<Iterator, std::string()> key;
    qi::rule<Iterator, std::string()> value;
    qi::rule<Iterator, std::string()> subKey;
    qi::rule<Iterator, std::string()> subValue;
    qi::rule<Iterator, std::pair<std::string,std::string>()> item;
    qi::rule<Iterator, std::map<std::string,std::string>()> array;
    qi::rule<Iterator, std::pair<std::string(), std::vector<std::pair<std::string,std::string>()>>> condition;
    qi::rule<Iterator, std::map<std::string(), std::vector<std::pair<std::string,std::string>()>>> expression;
};

int main()
{
        std::map<std::string(), std::vector<std::pair<std::string,std::string>()>> result;
        using boost::spirit::ascii::space;
        queryString_grammar<std::string::const_iterator> grammar;
        std::string input{"customerId=ezhonke&trafficId=kevinZhong"};

        bool r = phrase_parse(input.cbegin(), input.cend(), grammar, space, result);

        std::cout << "result: [" << r << "]" << std::endl;


}
