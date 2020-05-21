#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>
#include <boost/test/test_tools.hpp>

#include "test_common.h"

#include <queue>
#include "conditional_contextual_bandit.h"
#include "parse_example.cc"
#include "parse_dispatch_loop.h"
#include "io_to_queue.h"

BOOST_AUTO_TEST_CASE(mock_out_io_to_queue)
{

    auto vw = VW::initialize("--no_stdin --quiet", nullptr , false, nullptr, nullptr);

    std::queue<IO_Item> *input_lines = new std::queue<IO_Item>;

    std::string text = R"(0 | price:.23 sqft:.25 age:.05 2006  
    1 | price:.18 sqft:.15 age:.35 1976
    0 | price:.53 sqft:.32 age:.87 1924
    0 | price:.23 sqft:.25 age:.05 2006)";

    vw->p->input->set((char *)text.c_str());

    BOOST_CHECK_EQUAL(input_lines->size(), 0);
    
    io_lines_toqueue(*vw, input_lines);

    //text.size() = 157 chars, adds each char separately
    //this passes :) BUT FIX PARSING SO PARSES EACH LINE
    BOOST_CHECK_EQUAL(input_lines->size(), 157);
    
    VW::finish(*vw);

}

BOOST_AUTO_TEST_CASE(mock_out_parser)
{
    std::queue<IO_Item> *mock_input_lines = new std::queue<IO_Item>;

    for(int i=0; i<10; i++){
        std::string added_string = "0 | price:.23 sqft:.25 age:.05 2006";
        IO_Item my_item(added_string, added_string.size());
        mock_input_lines->push(my_item);
    }

    BOOST_CHECK_EQUAL(mock_input_lines->size(), 10);

   
   //need to pops the correct io queue, set io queue then pop 
   //finish the test after you refactor your code
   // pop_io_queue()

}

BOOST_AUTO_TEST_CASE(sleep_parser)
{

}

BOOST_AUTO_TEST_CASE(sleep_io)
{

}
