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

#ifndef NDN_CXX_INTEREST_PRIORITY_HPP
#define NDN_CXX_INTEREST_PRIORITY_HPP

#include "ndn-cxx/encoding/tlv.hpp"

#include <cstdint>
#include <optional>

namespace ndn {

inline constexpr uint8_t DEFAULT_INTEREST_PRIORITY_VALUE = 0;
inline constexpr uint8_t MAX_INTEREST_PRIORITY_VALUE = 3;

class InterestPriority
{
public:
  class Error : public tlv::Error
  {
  public:
    using tlv::Error::Error;
  };

  InterestPriority() = default;

  InterestPriority(uint8_t value);

  InterestPriority(const InterestPriority& other);

  InterestPriority&
  operator=(const InterestPriority& other);

  operator uint8_t() const noexcept;

  InterestPriority&
  unset() noexcept;

public:
  friend std::ostream&
  operator<<(std::ostream& os, const InterestPriority& interestPriority);

private:
  void
  validate() const;

private:
  std::optional<uint8_t> m_value;
};

} // namespace ndn

#endif // NDN_CXX_INTEREST_PRIORITY_HPP
