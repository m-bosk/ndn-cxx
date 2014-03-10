/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/*
 * Copyright (c) 2013, Regents of the University of California
 * BSD license, See the LICENSE file for more information
 * Author: Yingdi Yu <yingdi@cs.ucla.edu>
 */

#ifndef NDNSEC_SET_ACL_HPP
#define NDNSEC_SET_ACL_HPP

#include "ndnsec-util.hpp"

int
ndnsec_set_acl(int argc, char** argv)
{
  using namespace ndn;
  namespace po = boost::program_options;

  std::string keyName; 
  std::string appPath;

  po::options_description desc("General Usage\n  ndnsec set-acl [-h] keyName appPath \nGeneral options");
  desc.add_options()
    ("help,h", "produce help message")
    ("keyName,k", po::value<std::string>(&keyName), "Key name.")
    ("appPath,p", po::value<std::string>(&appPath), "Application path.")
    ;

  po::positional_options_description p;
  p.add("keyName", 1);
  p.add("appPath", 1);

  po::variables_map vm;
  try
    {
      po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
      po::notify(vm);
    }
  catch (std::exception &e)
    {
      std::cerr << "ERROR: " << e.what() << std::endl;
      return 1;
    }

  if (vm.count("help"))
    {
      std::cerr << desc << std::endl;
      return 0;
    }

  try
    {
      KeyChain keyChain;
      keyChain.addAppToACL(keyName, KEY_CLASS_PRIVATE, appPath, ACL_TYPE_PRIVATE);

    }
  catch(const SecTpm::Error& e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
  catch(const SecPublicInfo::Error& e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }

  
  return 0;
}

#endif //NDNSEC_SET_ACL_HPP