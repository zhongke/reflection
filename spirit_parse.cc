#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/foreach.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include <boost/spirit/include/qi.hpp>

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace fusion = boost::fusion;
namespace phoenix = boost::phoenix;

// struct Expression
// {
//         // std::map<std::string(), std::vector<std::pair<std::string,std::string>()>> result;

//         std::string expression;
// };

// BOOST_FUSION_ADAPT_STRUCT(
//         Expression,
//         (std::string, expression)
//         )

// template <typename Iterator>
// struct queryString_grammar
//     : qi::grammar<Iterator, std::string>
// {
// public:
//     queryString_grammar()
//         : queryString_grammar::base_type(expression)
//     {
//         using qi::lexeme;
//         using ascii::char_;

//         token %= lexeme[+(char_)];
//         key %= token;
//         subKey %= token;
//         subValue %= token;
//         item %= subKey >> - (":" >> subValue);
//         array %= item >> * ("," >> item);
//         value %= token | "{" >> array >> "}";
//         condition %= key >>  "=" >> value;
//         expression %= condition >> *(&condition);
//     }
// private:
//     qi::rule<Iterator, std::string()> token;
//     qi::rule<Iterator, std::string()> key;
//     qi::rule<Iterator, std::string()> value;
//     qi::rule<Iterator, std::string()> subKey;
//     qi::rule<Iterator, std::string()> subValue;
//     qi::rule<Iterator, std::pair<std::string, std::string>()> item;
//     qi::rule<Iterator, std::map<std::string, std::string>()> array;
//     qi::rule<Iterator, std::pair<std::string(), std::vector<std::pair<std::string, std::string>()>>> condition;
//     qi::rule<Iterator, std::map<std::string(), std::vector<std::pair<std::string, std::string>()>>> expression;
// };

using StringVector = std::vector<std::string>;

template <typename Iterator>
class QueryStringGrammar : qi::grammar<Iterator, std::string(), ascii::space_type>
{
public:
    QueryStringGrammar() : QueryStringGrammar::base_type(token)
    {
        using qi::lexeme;
        using ascii::char_;
        using qi::lit;
        using ascii::string;
        using namespace qi::labels;

        token = lexeme[+(char_ - '<')        [std::cout << _1]];
    }

private:
    qi::rule<Iterator, std::string(), ascii::space_type> token;
};

