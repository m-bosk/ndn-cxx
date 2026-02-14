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

#include "interest-priority.hpp"

#include <string>

namespace ndn {

InterestPriority::InterestPriority(uint8_t value)
  : m_value(value)
{
  validate();
}

InterestPriority::InterestPriority(const InterestPriority& other)
  : m_value(other)
{
  validate();
}

InterestPriority&
InterestPriority::operator=(const InterestPriority& other)
{
  m_value.emplace(other);
  validate();
  return *this;
}

InterestPriority::operator uint8_t() const noexcept
{
  return m_value.value_or(DEFAULT_INTEREST_PRIORITY_VALUE);
}

InterestPriority&
InterestPriority::unset() noexcept
{
  m_value.reset();
  return *this;
}

void
InterestPriority::validate() const
{
  if (*this > MAX_INTEREST_PRIORITY_VALUE) {
    NDN_THROW(Error("Interest priority must be between 0 and " +
                    std::to_string(MAX_INTEREST_PRIORITY_VALUE)));
  }
}

std::ostream&
operator<<(std::ostream& os, const InterestPriority& interestPriority)
{
  return os << std::to_string(interestPriority);
}

} // namespace ndn
