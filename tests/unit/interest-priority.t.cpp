/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013-2024 Regents of the University of California.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 *
 * ndn-cxx library is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * ndn-cxx library is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received copies of the GNU General Public License and GNU Lesser
 * General Public License along with ndn-cxx, e.g., in COPYING.md file.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * @author Oluwatobiloba Olalusi <hello@tobiolalusi.com>
 */

#include "ndn-cxx/interest-priority.hpp"

#include "tests/boost-test.hpp"

#include <boost/lexical_cast.hpp>

namespace ndn::tests {

BOOST_AUTO_TEST_SUITE(TestInterestPriority)

BOOST_AUTO_TEST_CASE(Constructor)
{
  // default constructor
  InterestPriority ip0;
  BOOST_CHECK(!ip0);
  BOOST_CHECK_EQUAL(ip0, 0);

  // constructor with value
  InterestPriority ip1 = InterestPriority{2};
  BOOST_CHECK(ip1);
  BOOST_CHECK_EQUAL(ip1, 2);
}

BOOST_AUTO_TEST_CASE(Assignment)
{
  InterestPriority ip0 = 0;
  BOOST_CHECK(!ip0);
  BOOST_CHECK_EQUAL(ip0, 0);

  InterestPriority ip1 = 2;
  BOOST_CHECK(ip1);
  BOOST_CHECK_EQUAL(ip1, 2);

  InterestPriority ip2 = ip1;
  BOOST_CHECK(ip2);
  BOOST_CHECK_EQUAL(ip2, ip1);
}

BOOST_AUTO_TEST_CASE(Validation)
{
  BOOST_CHECK_NO_THROW(InterestPriority{3});

  InterestPriority i;
  BOOST_CHECK_THROW(i = -2, InterestPriority::Error);

  BOOST_CHECK_THROW(InterestPriority{9}, InterestPriority::Error);
}

BOOST_AUTO_TEST_CASE(Unset)
{
  InterestPriority i = InterestPriority{3};
  BOOST_REQUIRE(i);

  i.unset();
  BOOST_CHECK(!i);
  BOOST_CHECK_EQUAL(i, 0);
}

BOOST_AUTO_TEST_CASE(Print)
{
  BOOST_CHECK_EQUAL(boost::lexical_cast<std::string>(InterestPriority{}), "0");
  BOOST_CHECK_EQUAL(boost::lexical_cast<std::string>(InterestPriority{2}), "2");
}

BOOST_AUTO_TEST_SUITE_END() // TestInterestPriority

} // namespace ndn::tests
